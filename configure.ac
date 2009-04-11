#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT(wxMUN, 0.27, g.besjes@student.science.ru.nl)

if test `pwd | wc -w` -ne 1; then
        AC_MSG_ERROR([
You are attempting to build in a path that contains spaces.  This
will fail.  Relocate this source tree to a path that does not contain
spaces and run configure again.
])
fi

AC_CONFIG_SRCDIR([src/committee.cpp])
AM_CONFIG_HEADER(config.h)
AM_MAINTAINER_MODE

# display notice and initialize automake
AC_MSG_NOTICE([configuring AC_PACKAGE_TARNAME AC_PACKAGE_VERSION])
AM_INIT_AUTOMAKE(AC_PACKAGE_TARNAME,AC_PACKAGE_VERSION,dist-bzip2)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AM_PROG_LIBTOOL

# Checks for libraries.
AM_OPTIONS_WXCONFIG
reqwx=2.8.0
AM_PATH_WXCONFIG($reqwx, wxWin=1)
if test "$wxWin" != 1; then
	AC_MSG_ERROR([
		wxWidgets must be installed on your system.
 
		Please check that wx-config is in path, the directory
		where wxWidgets libraries are installed (returned by
		'wx-config --libs' or 'wx-config --static --libs' command)
		is in LD_LIBRARY_PATH or equivalent variable and
		wxWidgets version is $reqwx or above.
		])
fi

AX_LIB_XERCES
if test $HAVE_XERCES != "yes"; then
	AC_MSG_ERROR([
		Xerces-C++ must be installed on your system.
	])
fi

CPPFLAGS="$CPPFLAGS $WX_CPPFLAGS $XERCES_CPPFLAGS"
CXXFLAGS="$CXXFLAGS $WX_CXXFLAGS_ONLY"
CFLAGS="$CFLAGS $WX_CFLAGS_ONLY"
LIBS="$LIBS $WX_LIBS $XERCES_LIBS"
LDFLAGS="$LDFLAGS $XERCES_LDFLAGS"

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST

# Checks for library functions.

AC_CONFIG_FILES([Makefile src/Makefile include/Makefile data/Makefile data/flags/Makefile images/Makefile MSVC/Makefile m4/Makefile])
AC_OUTPUT
