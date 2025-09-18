SUMMARY = "C hello"
DESCRIPTION = "Hello world C"
HOMEPAGE = "https://github.com/techpioneerHC/TECHP_YOCTO-HELLO"
SECTION = "apps"
LICENSE = "CLOSED"
SRC_URI = "git://github.com/techpioneerHC/TECHP_YOCTO-HELLO.git;protocol=https;branch=main"
SRCREV = "edcfb36e4218b39c01cdb3c277a5cf5c700aa219"

S = "${WORKDIR}/git"

DEPENDS += "hellolib"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 hello ${D}${bindir}
}
