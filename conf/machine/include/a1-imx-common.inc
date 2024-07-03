MACHINEOVERRIDES =. "a1-gw:a1-imx-gw:"

MACHINE_FEATURES ?= "apm serial usbhost 3g"

# U-Boot bootloader
UBOOT_ENV = "boot"
UBOOT_ENV_SUFFIX = "scr"
PREFERRED_PROVIDER_virtual/bootloader := "u-boot-mainline"
PREFERRED_PROVIDER_u-boot := "u-boot-mainline"
PREFERRED_PROVIDER_u-boot-native ?= "u-boot-mainline"
PREFERRED_PROVIDER_u-boot-fw-utils ?= "u-boot-mainline-fw-utils"
PREFERRED_PROVIDER_u-boot-fw-utils-native ?= "u-boot-mainline-fw-utils-native"
PREFERRED_PROVIDER_u-boot-tools ?= "u-boot-mainline-tools"
PREFERRED_PROVIDER_u-boot-tools-native ?= "u-boot-mainline-tools-native"
PREFERRED_PROVIDER_u-boot-mkimage-native ?= "u-boot-mainline-tools-native"

UBOOT_MAINLINE_VERSION = "2024.04%"
PREFERRED_VERSION_u-boot-mainline ?= "${UBOOT_MAINLINE_VERSION}"
PREFERRED_VERSION_u-boot-mainline-native ?= "${UBOOT_MAINLINE_VERSION}"
PREFERRED_VERSION_u-boot-mainline-fw-utils ?= "${UBOOT_MAINLINE_VERSION}"
PREFERRED_VERSION_u-boot-mainline-fw-utils-native ?= "${UBOOT_MAINLINE_VERSION}"
PREFERRED_VERSION_u-boot-mainline-tools ?= "${UBOOT_MAINLINE_VERSION}"
PREFERRED_VERSION_u-boot-mainline-tools-native ?= "${UBOOT_MAINLINE_VERSION}"


# Linux kernel
KERNEL_IMAGETYPE = "fitImage"
KERNEL_CLASSES += " kernel-fitimage "
PREFERRED_PROVIDER_virtual/kernel ?= "linux-stable"


# Ship kernel modules
MACHINE_ESSENTIAL_EXTRA_RDEPENDS += " \
	kernel-modules kernel-devicetree \
	"

# List of images to be built
IMAGE_FSTYPES ?= "tar.xz wic.xz wic.gz"
#TODO: UBIFS
INITRAMFS_FSTYPES ?= "cpio.xz"

EXTRA_IMAGEDEPENDS += "u-boot-mainline"
IMAGE_BOOT_FILES ?= "${KERNEL_IMAGETYPE}"
IMAGE_INSTALL:append = " kernel-devicetree kernel-image-fitimage u-boot-mainline"
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot u-boot-mainline:do_deploy"

# Add any optional config files that might be present e.g. in other layers
include conf/machine/${MACHINE}-extra.conf