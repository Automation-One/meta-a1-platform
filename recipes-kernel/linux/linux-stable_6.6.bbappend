FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

KBRANCH:a1-imx-gw ?= "linux-6.6.y"
KMACHINE:a1-imx6ull-gw ?= "a1-imx6ull-gw"
COMPATIBLE_MACHINE:a1-imx6ull-gw = "(a1-imx6ull-gw)"

DEPENDS:append:a1-imx-gw = " lzop-native "

SRC_URI:append:a1-imx6ull-gw = " \
	file://${BPV}/a1-imx6ull-gw;type=kmeta;destsuffix=${BPV}/a1-imx6ull-gw \
	file://common/a1-imx6ull-gw;type=kmeta;destsuffix=common/a1-imx6ull-gw \
	"
KERNEL_FEATURES:a1-imx6ull-gw = " a1-imx6ull-gw-standard.scc "
