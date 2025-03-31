# Contributing to Squidbox

This document outlines the guidelines for contributing to the Squidbox project. We welcome contributions from everyone, whether it's code, documentation, or feedback. Please follow these guidelines to ensure a smooth collaboration.

## Getting started

Squidbox is built using PlatformIO, which is a cross-platform IDE and library manager for embedded development. To build and run the project, you need to have PlatformIO installed. You can find the installation instructions [here](https://platformio.org/install).

Once you have PlatformIO installed, you can either use the PlatformIO IDE to build and upload the project via the GUI, or you can use the command line interface (CLI) to build and upload the project.

Accessing the CLI:

```shell
pio --help
```

All the build configuration is handled by the [platformio.ini](./platformio.ini) file in the root directory of the project. You can modify this file to change the build settings, such as the target platform, build flags, and library dependencies. Currently, we are targetting 2 different boards: the Adafruit Feather ESP32 v2 and the ESP32 DevKit v1. The Adafruit Feather ESP32 v2 is the default target and what is actually installed onboard the Squibox. The ESP32 DevKit v1 is used for simulation purposes, which you can read more about [here](#simulation).

## Simulation

We developed a simulation of the Squidbox using [Wokwi](https://wokwi.com/). This helps developers who don't have access to hardware to test their code. To run the simulation, you need to install [Wokwi VSCode extension](https://docs.wokwi.com/vscode/getting-started#installation).

Once you Wokwi installed, you need to request a new Wokwi license as detailed in the same guide. After you have the license, you can run the simulation by pressing `F1` and selecting `Wokwi: Start Simulator`. Currently, options for testing out actual MIDI messages within the simulation are limited. Thus, we are only logging out the MIDI messages to the serial monitor.

[diagram.json](./diagram.json) contains the Wokwi diagram file while [wokwi.toml](./wokwi.toml) tells Wokwi where to look for the firmware, which has been set to be the ESP32 DevKit v1 build target.

To enable IDE integrations for the simulation target, you can uncomment the `default_envs` line under the `[platformio]` common target in [platformio.ini](./platformio.ini).
