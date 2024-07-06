FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append:a1-imx6ull-gw = " \
  file://0001-kontron-sl-mx6ul-Reduce-list-of-supported-boot-devic.patch \
  file://0002-kontron_mx6ul-Retrieve-the-MAC-address-for-ENET2.patch \
	"


SRC_URI:append:a1-imx-gw = " \
	file://boot.cmd \
	"