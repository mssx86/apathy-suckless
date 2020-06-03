CC       = cc
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=2
CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os
LDFLAGS  = -s -lX11

SRC      = dwmblocks.c
OBJ      = ${SRC:.c=.o}

all: dwmblocks

.c.o:
	${CC} -c ${CFLAGS} ${CPPFLAGS} $<

dwmblocks: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm     -f dwmblocks ${OBJ}

install: all
	mkdir  -p            ${DESTDIR}/usr/bin
	cp     -f  dwmblocks ${DESTDIR}/usr/bin
	chmod  755           ${DESTDIR}/usr/bin/dwmblocks

.PHONY: all clean install
