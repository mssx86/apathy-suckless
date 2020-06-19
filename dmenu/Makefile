CC       = clang
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700           \
           -D_POSIX_C_SOURCE=200809L -DXINERAMA -I/usr/include/freetype2 \
           -DVERSION=\"4.9-apathy\"
CFLAGS   = -std=c99 -pedantic -Wall -Os
LDFLAGS  = -s -lX11 -lXinerama -lfontconfig -lXft

SRC      = drw.c dmenu.c stest.c util.c
OBJ      = $(SRC:.c=.o)

all: dmenu stest

.c.o:
	${CC} -c ${CFLAGS} ${CPPFLAGS} $<

dmenu: ${OBJ}
	${CC} -o $@ dmenu.o drw.o util.o ${LDFLAGS}

stest: stest.o
	$(CC) -o $@ stest.o $(LDFLAGS)

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
