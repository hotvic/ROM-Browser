AC_INIT([rombrowser], [0.1], [https://github.com/hotvic/ROM-Browser/issues], [rombrowser], [https://github.com/hotvic/ROM-Browser/])
AM_INIT_AUTOMAKE([-Wall -Wno-extra-portability -Wno-portability -Werror foreign])
LT_INIT

AC_PROG_CC

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])

dnl ============================================================================
dnl Dependencies libraries
dnl ============================================================================
PKG_CHECK_MODULES(GTK,
                  glib-2.0
                  gio-2.0
                  gtk+-3.0)

dnl ============================================================================
dnl gettext and intltool
dnl ============================================================================
IT_PROG_INTLTOOL([0.50.1])

AC_SUBST([GETTEXT_PACKAGE], [rombrowser])
AC_DEFINE_UNQUOTED([GETTEXT_PACKAGE], "$GETTEXT_PACKAGE", [Define to the gettext package name.])

dnl ============================================================================
dnl directories
dnl ============================================================================ 
AC_SUBST([DATADIR], "$datair")
AC_DEFINE_UNQUOTED([DATADIR], "$datadir", [Installation data dir])
AC_SUBST([LIBDIR], "$datair")
AC_DEFINE_UNQUOTED([LIBDIR], "$libdir", [Installation lib dir])

dnl ============================================================================
dnl GResource
dnl ============================================================================
AC_PATH_PROG(GLIB_COMPILE_RESOURCES, glib-compile-resources)


AC_CONFIG_FILES(
  Makefile
  data/ui.gresource.xml
  data/ui/menu.ui
  data/ui/rbmw.ui
  po/Makefile.in
  src/Makefile
)
AC_OUTPUT
