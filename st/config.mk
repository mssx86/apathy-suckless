VERSION = 0.8.2-apathy

PREFIX = /usr
PKG_CONFIG = pkg-config

CFLAGS  += -std=c99 -march=native -mtune=native -O2
LDFLAGS += -s

# includes and libs
X11INC = /usr/include/X11
X11LIB = /usr/lib/X11

INCS = -I$(X11INC) \
       `$(PKG_CONFIG) --cflags fontconfig` \
       `$(PKG_CONFIG) --cflags freetype2`
LIBS = -L$(X11LIB) -lm -lrt -lX11 -lutil -lXft -lXrender \
       `$(PKG_CONFIG) --libs fontconfig` \
       `$(PKG_CONFIG) --libs freetype2`

# flags
STCPPFLAGS = -DVERSION=\"$(VERSION)\" -D_XOPEN_SOURCE=600
STCFLAGS = $(INCS) $(STCPPFLAGS) $(CPPFLAGS) $(CFLAGS)
STLDFLAGS = $(LIBS) $(LDFLAGS)

CC = x86_64-apathy-linux-musl-gcc 
