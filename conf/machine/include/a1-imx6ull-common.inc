MACHINEOVERRIDES =. "a1-imx6ull-gw:"

require conf/machine/include/a1-imx-common.inc

DEFAULTTUNE ?= "cortexa7thf-neon-vfpv4"
SOC_FAMILY ?= "imx6ull"

include conf/machine/include/arm/armv7a/tune-cortexa7.inc
require conf/machine/include/soc-family.inc

SERIAL_CONSOLES = "115200;ttymxc3"

# Linux kernel
PREFERRED_VERSION_linux-stable ?= "6.6%"
KERNEL_DTBVENDORED = "0"
KERNEL_DTC_FLAGS += "-@"

# U-Boot bootloader
UBOOT_ENTRYPOINT = "0x81000000"
UBOOT_MAKE_TARGET := "flash.bin"
UBOOT_BINARY := "flash.bin"
UBOOT_SUFFIX ?= "bin"

WKS_FILE = "sdimage-imx6ull.wks"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += " \
    linux-firmware-imx-sdma-imx6q \
  "

# Add any optional config files that might be present e.g. in other layers
include conf/machine/include/ux-imx6ull-common-extra.inc
