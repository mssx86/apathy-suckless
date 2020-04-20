# version
VERSION = 6.2-apathy

# paths
PREFIX = /usr

# lib/include
X11INC = /usr/include/X11
X11LIB = /usr/lib/X11

XINERAMALIBS  = -lXinerama
XINERAMAFLAGS = -DXINERAMA
FREETYPELIBS = -lfontconfig -lXft
FREETYPEINC = /usr/include/freetype2

INCS = -I${X11INC} -I${FREETYPEINC}
LIBS = -L${X11LIB} -lX11 ${XINERAMALIBS} ${FREETYPELIBS}

# flags
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=2 -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -O2 ${INCS} ${CPPFLAGS}
LDFLAGS  = ${LIBS}

# compiler and linker
CC = x86_64-apathy-linux-musl-gcc
