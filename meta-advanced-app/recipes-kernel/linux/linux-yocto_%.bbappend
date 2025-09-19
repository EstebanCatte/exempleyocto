SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "Recipe created by bitbake-layers"
LICENSE = "MIT"

python do_display_banner() {
    bb.plain("***********************************************");
    bb.plain("*                                             *");
    bb.plain("*  Example recipe created by bitbake-layers   *");
    bb.plain("*                                             *");
    bb.plain("***********************************************");
}

addtask display_banner before do_build
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append = " file://my-kernel-patch.patch \
                    file://newconfig"

KCONFIG_FILE = "${THISDIR}/files/newconfig"