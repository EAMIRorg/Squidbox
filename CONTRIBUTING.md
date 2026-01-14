# Contributing to Squidbox

This document outlines the guidelines for contributing to the Squidbox project. We welcome contributions from everyone, whether it's code, documentation, or feedback. Please follow these guidelines to ensure a smooth collaboration.

Our CLA allows Squidbox to remain open source while also offering commercial licenses. Contributors retain ownership of their contributions, and their work will continue to be available under the project’s open-source license.

If you submit work that you do not fully own (for example, code written as part of your employment), you must ensure you have the legal right to submit it and that any required approvals have been obtained.

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

You can follow the instructions in the [Wokwi documentation](https://docs.wokwi.com/vscode/project-config#serial-port-forwarding) to interact with the simulation via a serial monitor.


# Why we use a Contributor License Agreement (CLA)

Squidbox is released as open-source software, and we welcome community contributions of all kinds. To keep the project healthy and sustainable over time, we ask contributors to agree to a Contributor License Agreement (CLA).

WHAT THE CLA DOES

The CLA ensures that:

You keep ownership of your contributions.
Signing the CLA does not transfer copyright to us.

We have the legal right to include your contribution in the project.
This allows us to distribute Puke Studio under its open-source license and to maintain the project without legal ambiguity.

We can offer both open-source and commercial licenses.
Puke Studio is available under the AGPLv3, and we may also offer commercial licenses to developers who need to build proprietary applications. The CLA makes this possible while keeping the open-source version available to everyone.

WHAT THE CLA DOES NOT DO

It does not affect music, audio, or other creative works you create using Puke Studio.
Anything you compose, record, or produce with the software is entirely yours.

It does not restrict your ability to fork, modify, or use Puke Studio under its open-source license.

It does not require paper forms or manual signatures.
The CLA is accepted electronically via GitHub when you submit a pull request.

WHY THIS MATTERS

Without a CLA, contributions from multiple authors can make it difficult or impossible to evolve the project’s licensing over time, offer commercial licenses when appropriate, or protect contributors and maintainers from unintended legal risk.

The CLA helps us keep Puke Studio open, usable, and sustainable for the long term — for researchers, musicians, developers, and commercial users alike.

If you have questions about the CLA or how it applies to a specific contribution, feel free to open an issue or start a discussion before submitting a pull request.