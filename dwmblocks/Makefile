PREFIX = /usr

CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=2
CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -O2 ${CPPFLAGS}
LDFLAGS  = -lX11

CC = x86_64-apathy-linux-musl-gcc

SRC = dwmblocks.c
OBJ = ${SRC:.c=.o}

all: options dwmblocks

options:
	@echo dwmblocks build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h

config.h:
	cp config.def.h $@

dwmblocks: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm     -f dwmblocks ${OBJ}

install: all
	mkdir  -p           ${DESTDIR}${PREFIX}/bin
	cp     -f dwmblocks ${DESTDIR}${PREFIX}/bin
	chmod 755           ${DESTDIR}${PREFIX}/bin/dwmblocks

uninstall:
	rm     -f           ${DESTDIR}${PREFIX}/bin/dwmblocks

.PHONY: all options clean install uninstall
