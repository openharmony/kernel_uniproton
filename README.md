# UniProton kernel

## Introduction

UniProton main purpose is for the upper business software provides a unified operating system platform, shielding hardware differences, and provide powerful debugging. This enables business software to be quickly transplanted between different hardware platforms, facilitates product chip selection, and reduces hardware procurement cost and software maintenance cost.

## Directory Structure

```
/kernel/uniproton
├── UniProton   # UniProton base kernel
└── config      # Kernel module configuration
```

## Constraints

OpenHarmony uniproton supports only C and C++.

Applicable architecture: See the directory structure for the arch layer.

## Usage

The OpenHarmony uniproton kernel build system is a modular build system based on Generate Ninja (GN) and Ninja. It supports module-based configuration, tailoring, and assembling, and helps you build custom products. This document describes how to build a uniproton project based on GN and Ninja. For details about the methods such as GCC+gn, IAR, and Keil MDK, visit the community websites.

## Compilation and Building

### 1.Setting Up the Environment

Before setting up the environment for a development board, you must set up the basic system environment for OpenHarmony first. The basic system environment includes the OpenHarmony build environment and development environment. For details, see [Setting Up Development Environment](https://gitee.com/openharmony/docs/blob/HEAD/en/device-dev/quick-start/quickstart-lite-env-setup.md).

### 2.Obtaining the OpenHarmony Source Code

For details about how to obtain the source code, see [Source Code Acquisition](https://gitee.com/openharmony/docs/blob/HEAD/en/device-dev/get-code/sourcecode-acquire.md). This document assumes that the clone directory is ~/openHarmony after the complete OpenHarmony repository code is obtained.

### 3.Download the incubation project code

Execute it in the //kernel directory:
```
git clone https://gitee.com/openharmony-sig/kernel_uniproton.git

mv kernel_uniproton uniproton
```

Execute it in the //vendor directory:
```
git clone https://gitee.com/openharmony-sig/vendor_alientek

mv vendor_alientek alientek
```
### 4.Compilation

Execute in the source root directory:
```
hb set
```

Choice: alientek@rtos_demo

An error message is displayed for the first time because the board directory does not exist. You need to manually modify file ***ohos_config.json***， The modifications are as follows:
```
{
  ...

  "device_path": "/Project Path/device/soc/st/stm32f407zg/uniproton",

  ...

  "patch_cache": "/Project Path/vendor/alientek/rtos_demo/patch.yml",

  ...

  "device_config_path": "/Project Path/device/soc/st/stm32f407zg/uniproton"
}
```

The ***Project Path*** is the absolute path to the OpenHarmony source code, See the context of ohos_config.json.

The command at first compile time:
```
hb build --patch
```

Subsequent compilation command:
```
hb build -f
```

### 5.Notes

At present, except for the above two SIG repository involved in the whole incubation project, all other repository use the existing repository of OpenHarmony. The repository modified on OpenHarmony are as follows:

```
//device/soc/st

//third_party/musl

//build/lite
```

These three bins are managed in the form of patches during the incubation phase, and then synchronously submitted to the OpenHarmony community upon incubation graduation.

patch maintenance method:

With //device/soc/st example, The patch of the bin has been applied during compilation. If there is any modification, it can be directly modified. After modification, all modifications are submitted locally, and a submission record is generated.

```
git format-patch [commit Id]

mv 0001-feat-xxx.patch ../../../vendor/alientek/patches/0001-device-soc-st-stm32f407zg.patch
```
