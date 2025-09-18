DESCRIPTION = "cpustat"
PRIORITY = "optional"
SECTION = "cpustat"

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0-only;md5=801f80980d171dd6425610833a22dbe6"
SRC_URI = "file://cpustat.c"
S = "${WORKDIR}"

do_compile() {
    ${CC} ${CFLAGS} ${LDFLAGS} cpustat.c -o cpustat
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 cpustat ${D}${bindir}
}
