## Process this file with automake to produce Makefile.in

## Created by Anjuta


uidir = $(pkgdatadir)/ui
ui_DATA = gnome_mplayer.ui


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(GNOME_MPLAYER_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = gnome_mplayer

gnome_mplayer_SOURCES = \
	main.c \
	gnome-mplayer.h \
	gnome-mplayer.c	


gnome_mplayer_LDFLAGS =

gnome_mplayer_LDADD = $(GNOME_MPLAYER_LIBS)


if PLATFORM_WIN32
gnome_mplayer_LDFLAGS += -Wl,--export-all-symbols
else
gnome_mplayer_LDFLAGS += -Wl,--export-dynamic
endif

if NATIVE_WIN32
gnome_mplayer_LDFLAGS += -mwindows
endif


EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(pkgdatadir)

