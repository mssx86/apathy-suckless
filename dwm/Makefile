CC      ?= x86_64-apathy-linux-musl-gcc
CFLAGS  += -std=c99 -DXINERAMA -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=200809L -DVERSION=\"6.2-apathy\" -I/usr/include/freetype2
LDFLAGS += -s -lX11 -lXft -lXinerama -lfontconfig 

SRC      = drw.c dwm.c util.c
OBJ      = ${SRC:.c=.o}

all: dwm

.c.o:
	${CC} -c ${CFLAGS} $<

dwm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm     -f dwm ${OBJ}

install: all
	mkdir  -p      ${DESTDIR}/usr/bin
	cp     -f  dwm ${DESTDIR}/usr/bin
	chmod  755     ${DESTDIR}/usr/bin/dwm

.PHONY: all clean install
