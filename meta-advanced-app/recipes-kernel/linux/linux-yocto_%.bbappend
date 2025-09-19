SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "Recipe created by bitbake-layers"
LICENSE = "MIT"

addtask display_banner before do_build
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append = " file://my-kernel-patch.patch \
                    file://mydefconfig"

KCONFIG_FILE = "${THISDIR}/files/mydefconfig"
KBUILD_DEFCONFIG = "mydefconfig"

do_kernel_metadata:prepend() {
    # Ensure the defconfig is in the right place before kernel metadata is generated
    cp ${WORKDIR}/mydefconfig ${S}/arch/x86/configs/
}