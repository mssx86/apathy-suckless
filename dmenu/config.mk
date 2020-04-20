VERSION       = 4.9-apathy

PREFIX        = /usr

X11INC        = /usr/include/X11
X11LIB        = /usr/lib/X11
XINERAMALIBS  = -lXinerama
XINERAMAFLAGS = -DXINERAMA
FREETYPELIBS  = -lfontconfig -lXft
FREETYPEINC   = /usr/include/freetype2

# includes and libs
INCS          = -I$(X11INC) -I$(FREETYPEINC)
LIBS          = -L$(X11LIB) -lX11 $(XINERAMALIBS) $(FREETYPELIBS)

# flags
CPPFLAGS      = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -DVERSION=\"$(VERSION)\" $(XINERAMAFLAGS)
CFLAGS        = -std=c99 -pedantic -Wall -Os $(INCS) $(CPPFLAGS)
LDFLAGS       = $(LIBS)

CC            = x86_64-apathy-linux-musl-gcc
