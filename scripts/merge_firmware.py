Import("env")

APP_BIN = "$BUILD_DIR/${PROGNAME}.bin"
MERGED_BIN = "$BUILD_DIR/${PROGNAME}_merged.bin"
FS_BIN = "$BUILD_DIR/littlefs.bin"
BOARD_CONFIG = env.BoardConfig()


def merge_bin(source, target, env):
    # The list contains all extra images (bootloader, partitions, eboot) and
    # the final application binary
    flash_images = env.Flatten(env.get("FLASH_EXTRA_IMAGES", [])) + [
        "$ESP32_APP_OFFSET",
        APP_BIN,
    ]

    flash_images.append("0x390000")
    flash_images.append(FS_BIN)

    # Run esptool to merge images into a single binary
    env.Execute(
        " ".join(
            [
                "$PYTHONEXE",
                "$OBJCOPY",
                "--chip",
                BOARD_CONFIG.get("build.mcu", "esp32"),
                "merge_bin",
                "--fill-flash-size",
                BOARD_CONFIG.get("upload.flash_size", "4MB"),
                "-o",
                MERGED_BIN,
            ]
            + flash_images
        )
    )


# Add a post action that runs esptoolpy to merge available flash images
env.AddPostAction(APP_BIN, merge_bin)

# Also ensure the merged binary exists before upload even if the program binary
# wasn't rebuilt in this invocation (e.g., when only uploading an unchanged build).
env.AddPreAction("upload", merge_bin)

# Patch the upload command to flash the merged binary at address 0x0
# Keep PlatformIO's default uploader flags (chip/port/baud/reset/write_flash options),
# but replace the individual address/file pairs with our single merged image.
original_upload_flags = list(env.get("UPLOADERFLAGS", []))
first_addr_idx = next(
    (i for i, flag in enumerate(original_upload_flags) if str(flag).startswith("0x")),
    None,
)

if first_addr_idx is None:
    # Unexpected shape; fall back to appending.
    new_upload_flags = original_upload_flags + ["0x0", MERGED_BIN]
else:
    new_upload_flags = original_upload_flags[:first_addr_idx] + ["0x0", MERGED_BIN]

env.Replace(UPLOADERFLAGS=new_upload_flags, UPLOADCMD='"$PYTHONEXE" "$UPLOADER" $UPLOADERFLAGS')
