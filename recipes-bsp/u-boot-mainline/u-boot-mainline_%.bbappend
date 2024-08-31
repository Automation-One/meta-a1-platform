FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append:a1-imx6ull-gw = " \
  file://0001-kontron-sl-mx6ul-Reduce-list-of-supported-boot-devic.patch \
  file://0002-kontron_mx6ul-Retrieve-the-MAC-address-for-ENET2.patch \
	file://0003-kontron-sl-mx6ul-Use-default-to-get-env-location.patch \
	file://0004-kontron-Enable-sysreset-through-watchdog.patch \
	"


SRC_URI:append:a1-imx-gw = " \
	file://boot.cmd \
	file://fw_env.config \
	"