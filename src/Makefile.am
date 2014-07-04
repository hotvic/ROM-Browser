bin_PROGRAMS = rombrowser
noinst_LTLIBRARIES = librombrowser.la


librombrowser_la_SOURCES =                \
                           rb-app.cc      \
                           rb-app.hh      \
                           rb-window.cc   \
                           rb-window.hh   \
                           rb-settings.hh

librombrowser_la_CPPFLAGS = $(GTKMM_CFLAGS)


ROMBROWSER_LIBS =                             \
                  librombrowser.la            \
                  $(BOOST_SYSTEM_LIBS)        \
                  $(BOOST_FILESYSTEM_LIBS)    \
                  $(GTKMM_LIBS)

rombrowser_SOURCES = main.cc rombrowser-resources.c
rombrowser_CPPFLAGS = $(GTKMM_CFLAGS) $(BOOST_CPPFLAGS)
rombrowser_LDADD = $(ROMBROWSER_LIBS) 

rombrowser-resources.c: $(top_srcdir)/data/rombrowser.gresource.xml $(shell $(GLIB_COMPILE_RESOURCES) --generate-dependencies --sourcedir="$(top_srcdir)/data" "$(top_srcdir)/data/rombrowser.gresource.xml")
	$(AM_V_GEN) $(GLIB_COMPILE_RESOURCES) --generate-source --target="$@" --sourcedir="$(top_srcdir)/data" "$(top_srcdir)/data/rombrowser.gresource.xml"

EXTRA_DIST = $(rombrowser_resource_deps)
CLEANFILES = rombrowser-resources.c
BUILT_SOURCES = rombrowser-resources.c
