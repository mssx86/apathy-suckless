CC       = clang
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=2 -DXINERAMA \
           -DVERSION=\"6.2-apathy\" -I/usr/include/freetype2
CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os
LDFLAGS  = -s -lX11 -lXinerama -lXft -lfontconfig

SRC      = drw.c dwm.c util.c
OBJ      = ${SRC:.c=.o}

all: dwm

.c.o:
	${CC} -c ${CFLAGS} ${CPPFLAGS} $<

dwm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm     -f dwm ${OBJ}

install: all
	mkdir  -p      ${DESTDIR}/usr/bin
	cp     -f  dwm ${DESTDIR}/usr/bin
	chmod  755     ${DESTDIR}/usr/bin/dwm

.PHONY: all clean install
