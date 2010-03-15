#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.60)
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

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

AC_CACHE_SAVE

AC_ARG_ENABLE(locales, AC_HELP_STRING([--enable-locales], [Build message catalogs]), \
                [locales="$enableval"], [locales="yes"])

AC_ARG_ENABLE(localesonly, AC_HELP_STRING([--enable-localesonly], [Just build locales]), \
                [localesonly="$enableval"], [localesonly="no"])

if test "$locales" != "yes" -a "$localesonly" = "yes"; then
  AC_MSG_ERROR([invalid flags: --disable-locales cannot be used together with --enable-localesonly])
fi

if test "$localesonly" = "yes"; then
  buildmain="no"
else
  buildmain="yes"
fi

if ! test "$localesonly" = "yes"; then

  if test "X$GCC" = Xyes; then
    CFLAGS="$CFLAGS -Wall -g -fexceptions"
    CXXFLAGS="$CXXFLAGS -Wall -g -fexceptions"
  fi

  # Add build information to config.h
  # ---------------------------------

  # Add host to config.h
  AC_DEFINE_UNQUOTED(USED_HOST, ["$host"], [Host system under which the program will run.])
  AC_DEFINE_UNQUOTED(USED_BUILD, ["$build"], [Build system under which the program was compiled on.])

  # Add used CXXFLAGS to config.h
  AC_DEFINE_UNQUOTED(USED_CXXFLAGS, ["$CXXFLAGS"], [Define to the used CXXFLAGS to compile this package.])

  # Get compiler (version)
  AH_TEMPLATE(USED_COMPILER, [Define to name and version of used compiler])
  if COMPILER=`$CC --version | head -n 1`; then
    AC_DEFINE_UNQUOTED(USED_COMPILER, ["$COMPILER"])
  fi
fi


if test "$buildmain" = "yes"; then

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

	AC_CACHE_SAVE

	# Check for windres on MinGW builds
	# ---------------------------------

	# Small function to filter the flags for windres,
	# so that only includes and defines are passed to windres.
	parseflags() {
		WINDRESFLAGS=""
        	for opt in "$@"
        	do
        	        case "$opt" in
        	        	-I*)
        	          	      WINDRESFLAGS="$WINDRESFLAGS --include-dir=${opt#-I}"
               	        	 ;;
               	 	-D*)
               	        	WINDRESFLAGS="$WINDRESFLAGS $opt"
                        ;;
                	esac
        	done
  	}

	WINDRESFLAGS=
	use_resourcefile=
	AC_MSG_CHECKING([whether to use windres])
	if echo $host_os | grep "cygwin\|mingw" > /dev/null 2>&1; then
		if echo $WX_CPPFLAGS | grep __WXMSW__ > /dev/null 2>&1; then
	                if test -z "$host_alias"; then
	                        hostaliaswindres=
	                else
	                        hostaliaswindres="$host_alias-windres"
	                fi
	                AC_MSG_RESULT([yes])
       	       	 	AC_PATH_PROGS([WINDRES], [windres $hostaliaswindres $host_os-windres])
       	         	if test "x$WINDRES" = "x"; then
                        	AC_MSG_ERROR([windres could not be found, please make sure this program is within your path.])
                	fi
                	use_resourcefile=true
                	parseflags $WX_CPPFLAGS
        	else
                	AC_MSG_RESULT([no])
        	fi
  	else
        	AC_MSG_RESULT([no])
	fi
	AC_SUBST(WINDRES)
	AC_SUBST(WINDRESFLAGS)

	# version.rc.in needs a major, minor and micro version number
	vnumber=${PACKAGE_VERSION%-*}
	PACKAGE_VERSION_MAJOR=${vnumber%%.*}
	vnumber=${vnumber#$PACKAGE_VERSION_MAJOR}
	vnumber=${vnumber#.}
	PACKAGE_VERSION_MINOR=${vnumber%%.*}
	vnumber=${vnumber#$PACKAGE_VERSION_MINOR}
	vnumber=${vnumber#.}
	PACKAGE_VERSION_MICRO=${vnumber%%.*}
	vnumber=${vnumber#$PACKAGE_VERSION_MICRO}
	vnumber=${vnumber#.}
	PACKAGE_VERSION_NANO=${vnumber%%.*}

	if test -z "$PACKAGE_VERSION_MAJOR"; then
		PACKAGE_VERSION_MAJOR=0
	fi
	if test -z "$PACKAGE_VERSION_MINOR"; then
		PACKAGE_VERSION_MINOR=0
	fi
	if test -z "$PACKAGE_VERSION_MICRO"; then
		PACKAGE_VERSION_MICRO=0
	fi
	if test -z "$PACKAGE_VERSION_NANO"; then
		PACKAGE_VERSION_NANO=0
	fi

	AC_SUBST(PACKAGE_VERSION_MAJOR)
	AC_SUBST(PACKAGE_VERSION_MINOR)
	AC_SUBST(PACKAGE_VERSION_MICRO)
	AC_SUBST(PACKAGE_VERSION_NANO)

	# Create application bundle on OS X
	# ----------------------------

	if echo $WX_CPPFLAGS | grep __WXMAC__; then
	    macappbundle="yes"
	else
	    macappbundle="no"
	fi

	# Installer creation under Windows
	# --------------------------------

	# Create installer under Windows
	if echo $host_os | grep "mingw" > /dev/null 2>&1; then
		makensisscript="yes"
	else
		makensisscript="no"
	fi

	if echo $host_os | grep "mingw" > /dev/null 2>&1; then
		AC_CONFIG_FILES(data/install.nsi)
		AC_CONFIG_FILES(data/makezip.sh)
	fi	

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
AM_CONDITIONAL([MINGW], [echo $host_os | grep "mingw"])
AM_CONDITIONAL(MAKENSISSCRIPT, [test "$makensisscript" = "yes"])
AM_CONDITIONAL(USE_RESOURCEFILE, test "$use_resourcefile" = "true")

AC_CONFIG_FILES([Makefile 
		src/Makefile 
		src/resources/Makefile 
		src/resources/16x16/Makefile 
		src/resources/32x32/Makefile 
		src/resources/flags/Makefile 
		src/resources/MacInfo.plist
		src/resources/version.rc
		include/Makefile 
		doc/Makefile
		doc/manual/Makefile
		data/Makefile 
		images/Makefile 
		m4/Makefile
		po/Makefile])
AC_OUTPUT
