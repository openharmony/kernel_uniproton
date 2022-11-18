# UniProton介绍

UniProton主要目的在于为上层业务软件提供一个统一的操作系统平台，屏蔽底层硬件差异，并提供强大的调试功能。使得业务软件可在不同的硬件平台之间快速移植，方便产品芯片选型，降低硬件采购成本和软件维护成本。

## 功能介绍

- 任务
- 中断
- 事件
- 队列
- 信号量
- 内存管理
- 软件定时器
- 异常
- 错误处理
- cpu占用率

注: UniProton基础内核机制请参考[官方介绍](https://gitee.com/openeuler/UniProton)。

## 使用说明

OpenHarmony UniProton内核的编译构建系统是一个基于gn和ninja的组件化构建系统，支持按组件配置、裁剪和拼装，按需构建出定制化的产品。本文主要介绍如何基于gn和ninja编译UniProton工程。

### 搭建系统基础环境

在搭建各个开发板环境前，需要完成OpenHarmony系统基础环境搭建。系统基础环境主要是指OpenHarmony的编译环境和开发环境，详细介绍请参考官方站点[开发环境准备](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/quick-start/Readme-CN.md)。开发者需要根据环境搭建文档完成环境搭建。

### 获取OpenHarmony源码

详细的源码获取方式，请见[源码获取](https://gitee.com/openharmony/docs/blob/HEAD/zh-cn/device-dev/get-code/sourcecode-acquire.md)。获取OpenHarmony完整仓代码后，假设克隆目录为`~/openHarmony`。

### 编译工具链下载

安装GNU Arm Embedded Toolchain 32位编译器:

官方下载地址为: [GNU Arm Embedded Toolchain编译器](https://developer.arm.com/downloads/-/gnu-rm)，指定版本:10-2020-q4-major。

安装参考以下命令:
```
 tar -xvf gcc-arm-none-eabi-10-2020-q4-major-x86_64-linux.tar.bz2 -C user_install_path
```

注意: 安装完成后需要将安装目录加入***环境变量***中。

### 已支持的示例工程

[stm32f407zg](https://gitee.com/openharmony/device_soc_st/tree/master/stm32f407zg/uniproton)
```
alientek
   rtos_demo
   rtos_demo_xts
```

## 约束

- 当前开源版本仅支持cortex_m4芯片，默认编译脚本的安全编译选项仅支持栈保护，其他选项由用户根据需要自行添加。

- 遵循MulanPSL2开源许可协议。

[如何贡献](https://gitee.com/openharmony/docs/blob/HEAD/zh-cn/contribute/%E5%8F%82%E4%B8%8E%E8%B4%A1%E7%8C%AE.md)

## 相关仓

[kernel\_uniproton](https://gitee.com/openharmony/kernel_uniproton/blob/master/README.md)

