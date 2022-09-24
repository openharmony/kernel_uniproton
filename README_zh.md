# UniProton 内核

## 简介

UniProton主要目的在于为上层业务软件提供一个统一的操作系统平台，屏蔽底层硬件差异，并提供强大的调试功能。使得业务软件可在不同的硬件平台之间快速移植，方便产品芯片选型，降低硬件采购成本和软件维护成本。

详细介绍请参考[UniProton官网](https://gitee.com/openeuler/UniProton)

## 目录

```
/kernel/uniproton
├── UniProton   # UniProton 基础内核
└── config      # 内核模块控制开关配置
```

## 约束

开发语言：C/C++；

适用架构：详见目录结构arch层。

## 使用说明

UniProton内核的编译构建系统是一个基于gn和ninja的组件化构建系统，支持按组件配置、裁剪和拼装，按需构建出定制化的产品。本文主要介绍如何基于gn和ninja编译Uniproton工程，GCC+gn、IAR、Keil MDK等编译方式可以参考社区爱好者贡献的站点。

## 编译构建指导

### 1.搭建系统基础环境

在搭建各个开发板环境前，需要完成OpenHarmony系统基础环境搭建。系统基础环境主要是指OpenHarmony的编译环境和开发环境，详细介绍请参考官方站点[开发环境准备](https://gitee.com/openharmony/docs/blob/HEAD/zh-cn/device-dev/quick-start/quickstart-lite-env-setup.md)。开发者需要根据环境搭建文档完成环境搭建。

### 2.获取OpenHarmony源码

详细的源码获取方式，请见[源码获取](https://gitee.com/openharmony/docs/blob/HEAD/zh-cn/device-dev/get-code/sourcecode-acquire.md)。获取OpenHarmony完整仓代码后，假设克隆目录为`~/openHarmony`。

### 3.下载孵化仓

在//kernel目录下执行:
```
git clone https://gitee.com/openharmony-sig/kernel_uniproton.git

mv kernel_uniproton uniproton
```

在vendor目录下执行:
```
git clone https://gitee.com/openharmony-sig/vendor_alientek

mv vendor_alientek alientek
```

### 4.编译

在源码根目录执行:
```
hb set
```

选择: alientek下的rtos_demo

首次执行会报错，因为单板目录还不存在，需要手动修改一下***ohos_config.json***文件， 修改内容如下:
```
{
  ...

  "device_path": "/工程路径/device/soc/st/stm32f407zg/uniproton",

  ...

  "patch_cache": "/工程路径/vendor/alientek/rtos_demo/patch.yml",

  ...

  "device_config_path": "/工程路径/device/soc/st/stm32f407zg/uniproton"
}
```

上述***工程路径***是指OpenHarmony源码所在的绝对路径，可以参考ohos_config.json的上下文。

首次编译时执行命令:
```
hb build --patch
```

后续编译执行命令:
```
hb build -f
```

### 5.注意

目前整个孵化项目涉及到的除了上述两个sig仓以外，其它仓均使用OpenHarmony现有的仓，在OpenHarmony上有修改的仓有:

```
//device/soc/st

//third_party/musl

//build/lite
```

这三个仓在孵化阶段以patch的形式管理，孵化毕业时再同步提交至OpenHarmony社区。

patch的维护方法:

以//device/soc/st 为例子, 执行编译时已经将该仓的patch应用，如有修改，则直接修改即可，修改之后在本地提交所有修改，并产生一笔提交记录，然后通过命令:

```
git format-patch [本次提交的前一次提交的commit Id]

mv 0001-feat-xxx.patch ../../../vendor/alientek/patches/0001-device-soc-st-stm32f407zg.patch
```

然后到//vendor/alientek仓将该patch修改上库。

其它仓库方法类似，在这里不做过多讲述。

## 贡献

[如何贡献](https://gitee.com/openharmony/docs/blob/HEAD/zh-cn/contribute/%E5%8F%82%E4%B8%8E%E8%B4%A1%E7%8C%AE.md)

## 相关仓

[UniProton](https://gitee.com/openeuler/UniProton)
