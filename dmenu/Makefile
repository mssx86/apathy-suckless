CC      ?= x86_64-apathy-linux-musl-gcc
CFLAGS  += -std=c99 -DXINERAMA -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=200809L -DVERSION=\"4.9-apathy\" -D_XOPEN_SOURCE=700 -I/usr/include/freetype2
LDFLAGS += -s -lX11 -lXft -lXinerama -lfontconfig

SRC      = drw.c dmenu.c stest.c util.c
OBJ      = $(SRC:.c=.o)

all: dmenu stest

.c.o:
	${CC} -c ${CFLAGS} $<

dmenu: ${OBJ}
	${CC} -o $@ dmenu.o drw.o util.o ${CFLAGS} ${LDFLAGS}

stest: stest.o
	$(CC) -o $@ stest.o ${CFLAGS} $(LDFLAGS)

clean:
	rm -f dmenu stest $(OBJ)

install: all
	mkdir -p                       $(DESTDIR)/usr/bin
	cp    -f  dmenu stest          $(DESTDIR)/usr/bin
	cp    -f  dmenu_path dmenu_run $(DESTDIR)/usr/bin
	chmod 755                      $(DESTDIR)/usr/bin/dmenu
	chmod 755                      $(DESTDIR)/usr/bin/dmenu_path
	chmod 755                      $(DESTDIR)/usr/bin/dmenu_run
	chmod 755                      $(DESTDIR)/usr/bin/stest

.PHONY: all clean install
