CC = cc
CPPFLAGS = -D_BSD_SOURCE -DVERSION=\"0.1-apathy\"
CFLAGS   = -std=c89 -pedantic -Wall -Os
LDFLAGS  = -s

SRC      = slmenu.c
OBJ      = ${SRC:.c=.o}

all: slmenu

.c.o:
	${CC} -c ${CFLAGS} ${CPPFLAGS} $<

slmenu: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f slmenu ${OBJ}

install: all
	mkdir -p        ${DESTDIR}/usr/bin
	cp    -f slmenu ${DESTDIR}/usr/bin
	chmod 755       ${DESTDIR}/usr/bin/slmenu

.PHONY: all clean install
