SUMMARY = "C hello library "
DESCRIPTION = "Hello world C dependency recipe "
HOMEPAGE = "https://github.com/techpioneerHC/TECHP_YOCTO-HELLOLIB"
SECTION = "apps"
LICENSE = "CLOSED"
SRC_URI = "git://github.com/techpioneerHC/TECHP_YOCTO-HELLOLIB.git;protocol=https;branch=main"
SRCREV = "6a08909ba21bfeb915de5473030f7a259ed326eb"

S = "${WORKDIR}/git"

do_install(){
   bbwarn “Installation started”
   install -d ${D}/${includedir}
   install -d ${D}/${libdir}
   install -m 0644 hellolib.h ${D}/${includedir}
   install -m 0755 lib*so.* ${D}/${libdir}
   ln -sf libhello.so.1.0 ${D}/${libdir}/libhello.so
   ln -sf libhello.so.1.0 ${D}/${libdir}/libhello.so.1
   bbnote “Compilation Complete”
}
