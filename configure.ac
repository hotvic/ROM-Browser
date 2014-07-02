AC_INIT([rombrowser], [0.1], [https://github.com/hotvic/ROM-Browser/issues], [rombrowser], [https://github.com/hotvic/ROM-Browser/])
AM_INIT_AUTOMAKE([-Wall -Wno-extra-portability -Wno-portability -Werror foreign])
LT_INIT

AC_PROG_CXX

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])

dnl ============================================================================
dnl Dependencies libraries
dnl ============================================================================
PKG_CHECK_MODULES(GTKMM,
                  glibmm-2.4
                  giomm-2.4
                  gtkmm-3.0)

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
  src/Makefile
)
AC_OUTPUT
