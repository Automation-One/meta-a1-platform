load mmc 0 $loadaddr /boot/fitImage
setenv bootargs "console=ttymxc3,115200 root=/dev/mmcblk0p1 rootwait ro ubi.mtd=0"
bootm $loadaddr