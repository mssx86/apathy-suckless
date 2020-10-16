CC      ?= x86_64-apathy-linux-musl-gcc
CFLAGS  += -std=c99 -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=2
LDFLAGS += -s -lX11

SRC      = dwmblocks.c
OBJ      = ${SRC:.c=.o}

all: dwmblocks

.c.o:
	${CC} -c ${CFLAGS} $<

dwmblocks: ${OBJ}
	${CC} -o $@ ${OBJ} ${CFLAGS} ${LDFLAGS}

clean:
	rm     -f dwmblocks ${OBJ}

install: all
	mkdir  -p            ${DESTDIR}/usr/bin
	cp     -f  dwmblocks ${DESTDIR}/usr/bin
	chmod  755           ${DESTDIR}/usr/bin/dwmblocks

.PHONY: all clean install
