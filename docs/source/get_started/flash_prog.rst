.. _flash_prog_cfg:

Flash prog cfg.ini 的使用
=================================

在用户执行 ``make flash`` 会调用 **bouffalo_flash_cube** 下的可执行文件，并根据 **Flash prog cfg.ini** 进行烧录，
本节主要介绍一下 **Flash prog cfg.ini** 的语法。

常规 MCU 使用（不使用无线功能）
---------------------------------

.. code-block:: ini
   :linenos:

    [cfg]
    # 0: no erase, 1:programmed section erase, 2: chip erase
    erase = 1
    # skip mode set first para is skip addr, second para is skip len, multi-segment region with ; separated
    skip_mode = 0x0, 0x0
    # 0: not use isp mode, #1: isp mode
    boot2_isp_mode = 0

    [firmware]
    filedir = ./build/build_out/xxx*_$(CHIPNAME).bin
    address = 0x0000


- **cfg** 表示烧录时的一些配置，正常不需要改动
- **firmware** 要烧录的应用固件，必须使用 **firmware** 名称。

    - **filedir** 表示应用固件所在相对路径，正常来说是编译完后放在 `build/build_out` 目录。 ``_$(CHIPNAME).bin`` 是必须要的后缀，用于区分不同芯片。 ``xxx`` 表示应用固件名称，与 `CMakeLists.txt` 中 `project(xxx)` 中名称一致。 ``*`` 表示正则匹配，可用可不用。
    - **address** 必须使用 0 地址


常规 IOT 使用（使用无线功能）
---------------------------------

.. code-block:: ini
   :linenos:

    [cfg]
    # 0: no erase, 1:programmed section erase, 2: chip erase
    erase = 1
    # skip mode set first para is skip addr, second para is skip len, multi-segment region with ; separated
    skip_mode = 0x0, 0x0
    # 0: not use isp mode, #1: isp mode
    boot2_isp_mode = 0

    [firmware]
    filedir = ./build/build_out/xxx*_$(CHIPNAME).bin
    address = 0x10000

    [boot2]
    filedir = ./build/build_out/boot2_*.bin
    address = 0x000000

    [partition]
    filedir = ./build/build_out/partition*.bin
    address = 0xE000

    [mfg]
    filedir = ./build/build_out/mfg*.bin
    address = 0x210000

- **cfg** 表示烧录时的一些配置，正常不需要改动
- **firmware** 要烧录的应用固件，必须使用 **firmware** 名称。

    - **filedir** 表示应用固件所在相对路径，正常来说是编译完后放在 `build/build_out` 目录。 ``_$(CHIPNAME).bin`` 是必须要的后缀，用于区分不同芯片。 ``xxx`` 表示应用固件名称，与 `CMakeLists.txt` 中 `project(xxx)` 中名称一致。
    - **address** 由 `partition_xxx.toml` 指定

- **boot2** 要烧录的 boot2 固件，必须使用 **boot2** 名称。

    - **filedir** 表示 boot2 固件所在相对路径，正常来说是编译完后放在 `build/build_out` 目录。 **自动从 bsp/board/board_name/config 目录拷贝**。
    - **address** 必须使用 0 地址

- **partition** 要烧录的 partition 固件，必须使用 **partition** 名称。

    - **filedir** 表示 partition 固件所在相对路径，正常来说是编译完后放在 `build/build_out` 目录。 **自动从 bsp/board/board_name/config 目录 partition_xxx.toml 转换成 bin 文件并拷贝**。
    - **address** 由 `partition_xxx.toml` 指定

- **mfg** 要烧录的 mfg 固件，必须使用 **mfg** 名称。

    - **filedir** 表示 mfg 固件所在相对路径，正常来说是编译完后放在 `build/build_out` 目录。 **自动从 bsp/board/board_name/config 目录拷贝**。
    - **address** 由 `partition_xxx.toml` 指定
