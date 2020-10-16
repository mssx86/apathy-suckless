CC      ?= x86_64-apathy-linux-musl-gcc
CFLAGS  += -std=c99 -D_BSD_SOURCE -DVERSION=\"0.1-apathy\"
LDFLAGS += -s

SRC      = slmenu.c
OBJ      = ${SRC:.c=.o}

all: slmenu

.c.o:
	${CC} -c ${CFLAGS} $<

slmenu: ${OBJ}
	${CC} -o $@ ${OBJ} ${CFLAGS} ${LDFLAGS}

clean:
	rm -f slmenu ${OBJ}

install: all
	mkdir -p        ${DESTDIR}/usr/bin
	cp    -f slmenu ${DESTDIR}/usr/bin
	chmod 755       ${DESTDIR}/usr/bin/slmenu

.PHONY: all clean install
