bin_PROGRAMS = rombrowser
noinst_LTLIBRARIES = librombrowser.la


librombrowser_la_SOURCES = rombrowserapp.c                                     \
                           rombrowserapp.h                                     \
                           rombrowserappwindow.c                               \
                           rombrowserappwindow.h                               \
                           rombrowsercmds-file.c                               \
                           rombrowsercmds-help.c                               \
                           rombrowsercmds.h                                    \
                           rombrowserdirs.c                                    \
                           rombrowserdirs.h                                    \
                           rombrowsersettings.c                                \
                           rombrowsersettings.h
librombrowser_la_CPPFLAGS = $(GTK_CFLAGS)
librombrowser_la_LIBADD = $(GTK_LIBS)


rombrowser_SOURCES = rombrowser.c ui-resources.c
rombrowser_CPPFLAGS = $(GTK_CFLAGS)
rombrowser_LDADD = librombrowser.la $(GTK_LIBS)

ui-resources.c:
	$(GLIB_COMPILE_RESOURCES) --generate-source --target="$@" --sourcedir="$(top_builddir)/data" "$(top_builddir)/data/ui.gresource.xml"

EXTRA_DIST = $(rombrowser_resource_deps)
CLEANFILES = ui-resources.c
BUILT_SOURCES = ui-resources.c
