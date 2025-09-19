DESCRIPTION = "calc library"
SECTION = "libs"
PRIORITY = "optional"

LICENSE = "GPL-2.0-only"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0-only;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI = "file://calc.c \
           file://calc.h \
           file://Makefile"

S = "${WORKDIR}"

do_compile() {
    bbwarn "Compilation de la bibliothèque"
    oe_runmake
}

do_install(){
   bbwarn "Installation started"
   install -d ${D}/${includedir}
   install -d ${D}/${libdir}
   install -m 0644 calc.h ${D}/${includedir}
   install -m 0755 lib*so.* ${D}/${libdir}
   ln -sf libcalc.so.1.0 ${D}/${libdir}/libcalc.so
   ln -sf libcalc.so.1.0 ${D}/${libdir}/libcalc.so.1
   bbnote "Compilation Complete"
}
