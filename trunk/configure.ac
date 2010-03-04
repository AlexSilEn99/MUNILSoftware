#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT(wxMUN, 0.38, g.besjes@student.science.ru.nl)

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

# Create application bundle on OS X
# ----------------------------

if echo $WX_CPPFLAGS | grep __WXMAC__; then
    macappbundle="yes"
else
    macappbundle="no"
fi

# Everything translation related
# ------------------------------

WXMUN_LINGUAS=
WXMUN_LINGUAS_PO=
WXMUN_LINGUAS_MO=
WXMUN_LINGUAS_PO_NEW=

if test "$locales" = "yes"; then
  AC_PATH_PROG(xgettext, xgettext)
  if test -z "$xgettext"; then
    AC_MSG_ERROR([xgettext not found, please install the GNU gettext package and make sure xgettext is in the path.])
  fi

  AC_PATH_PROG(msgfmt, msgfmt)
  if test -z "$msgfmt"; then
    AC_MSG_ERROR([ msgfmt not found, please install the GNU gettext package and make sure  msgfmt is in the path.])
  fi

  FZ_PATH_PROG_VER(msgmerge, msgmerge, 0.11.0)
  if test -z "$msgmerge"; then
    AC_MSG_ERROR([msgmerge not found or too old, please install a current version of the GNU gettext package and make sure msgmerge is in the path.])
  fi

  AC_MSG_CHECKING([available message catalogs])

  WXMUN_LINGUAS_PO=
  WXMUN_LINGUAS=

  if /bin/ls > /dev/null; then
    LSPROG='/bin/ls'
  else
    LSPROG='ls'
  fi

  if test x$srcdir = x; then
    path="po"
  else
    path="$srcdir/po"
  fi
  for i in `$LSPROG $path/*.po`; do
    i=${i%.*}
    i=${i##*/}
    WXMUN_LINGUAS_PO=$WXMUN_LINGUAS_PO${WXMUN_LINGUAS_PO:+ }\$\(srcdir\)/$i.po
    WXMUN_LINGUAS_PO_NEW=$WXMUN_LINGUAS_PO_NEW${WXMUN_LINGUAS_PO_NEW:+ }$i.po.new
    WXMUN_LINGUAS=$WXMUN_LINGUAS${WXMUN_LINGUAS:+ }$i
    WXMUN_LINGUAS_MO=$WXMUN_LINGUAS_MO${WXMUN_LINGUAS_MO:+ }$i.mo
  done

  AC_MSG_RESULT([$WXMUN_LINGUAS])

fi

AC_SUBST(WXMUN_LINGUAS)
AC_SUBST(WXMUN_LINGUAS_PO)
AC_SUBST(WXMUN_LINGUAS_PO_NEW)
AC_SUBST(WXMUN_LINGUAS_MO)

# Output automake conditionals
# ----------------------------

AM_CONDITIONAL([LOCALES_ONLY], [test "$localesonly" = "yes"])
AM_CONDITIONAL([LOCALES], [test "$locales" = "yes"])
AM_CONDITIONAL(MACAPPBUNDLE, [test "$macappbundle" = "yes"])

AC_CONFIG_FILES([Makefile 
		src/Makefile 
		include/Makefile 
		doc/Makefile
		data/Makefile 
		data/flags/Makefile 
		images/Makefile 
		MSVC/Makefile 
		m4/Makefile
		po/Makefile
		MacInfo.plist ])
AC_OUTPUT
