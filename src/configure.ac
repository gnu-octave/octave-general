#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
#
### Copyright (C) 2015-2017 Olaf Till <i7tiol@t-online.de>
### Copyright (C) 2018-2022 John Donoghue <john.donoghue@ieee.org>
###
### This program is free software; you can redistribute it and/or
### modify it under the terms of the GNU General Public License as
### published by the Free Software Foundation; either version 3 of the
### License, or (at your option) any later version.
###
### This program is distributed in the hope that it will be useful,
### but WITHOUT ANY WARRANTY; without even the implied warranty of
### MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
### General Public License for more details.
###
### You should have received a copy of the GNU General Public License
### along with this program; if not, see
### <http://www.gnu.org/licenses/>.

AC_PREREQ([2.67])
AC_INIT([general], [2.1.2])
AC_CONFIG_SRCDIR([packfields.cc])
AC_CONFIG_HEADERS([config.h])

# Avoid warnings for redefining AH-generated preprocessor symbols of
# Octave.
AH_TOP([#include "undef-ah-octave.h"])

AC_CONFIG_MACRO_DIRS([m4])

AC_CANONICAL_HOST
AC_CANONICAL_TARGET

# Checks for programs.
AC_CHECK_PROG(MKOCTFILE, mkoctfile, mkoctfile)
if test -z "$MKOCTFILE"; then
AC_MSG_ERROR([mkoctfile not found], 1);
fi
AC_CHECK_PROG(OCTAVE_CONFIG, octave-config, octave-config)
if test -z "$OCTAVE_CONFIG"; then
AC_MSG_ERROR([octave-config not found], 1);
fi

AC_PROG_AWK
if test -z "$ac_cv_prog_AWK"; then
AC_MSG_ERROR([AWK not found], 1);
fi

AC_PROG_GREP
AC_PROG_SED

# try get around possible spaces in the path
if test "X${IGNORE_MINGW_PATH_MODIFICATION}" == "X"; then
case $host_os in
  mingw*)
    # try demangle spaces in escaped input strings
    MKOCTFILE=`echo $MKOCTFILE | $SED "s,\\\\\ ,?,g"`
    OCTAVE_CONFIG=`echo $OCTAVE_CONFIG | $SED "s,\\\\\ ,?,g"`
    ;;
  *)
    ;;
esac
fi

# The same value of CXX as Octave was compiled with is supposed to be used.
CXX=${CXX:-`${MKOCTFILE} -p CXX`}
AC_PROG_CXX
  
AC_PROG_CXXCPP

# Checks for libraries.
PKG_CHECK_MODULES([NETTLE],[nettle],
 [AC_DEFINE([HAVE_NETTLE],[1], [Have nettle])],
 [AC_MSG_WARN([Nettle not found, SHA1 disabled])]
)

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

# Start of checks for Octave features, preparations for checks.
OCTLIBDIR=${OCTLIBDIR:-`$OCTAVE_CONFIG -p OCTLIBDIR`}
OCTINCLUDEDIR="${OCTINCLUDEDIR:-`$MKOCTFILE -p OCTINCLUDEDIR`}/.."

if test "X${IGNORE_MINGW_PATH_MODIFICATION}" == "X"; then
  MSYSTEM="${MSYSTEM}"
else
  MSYSTEM="none"
fi

case X$MSYSTEM in
  XMINGW64*)
    OCTAVE_HOME=`${MKOCTFILE} -p OCTAVE_HOME | $SED 's,\\\\,/,g'`
    # change \ to / and replace octave home part with mingw part
    OCTINCLUDEDIR=`echo $OCTINCLUDEDIR | $SED -e 's,\\\\,/,g' -e "s,${OCTAVE_HOME},/mingw64,g"`
    OCTLIBDIR=`echo $OCTLIBDIR | $SED -e 's,\\\\,/,g' -e "s,${OCTAVE_HOME},/mingw64,g"`
    ;;
  XMINGW32*)
    OCTAVE_HOME=`${MKOCTFILE} -p OCTAVE_HOME | $SED 's,\\\\,/,g'`
    # change \ to / and replace octave home part with mingw part
    OCTINCLUDEDIR=`echo $OCTINCLUDEDIR | $SED -e 's,\\\\,/,g' -e "s,${OCTAVE_HOME},/mingw32,g"`
    OCTLIBDIR=`echo $OCTLIBDIR | $SED -e 's,\\\\,/,g -e "s,${OCTAVE_HOME},/mingw32,g"'`
    ;;
  *)
    ;;
esac

AC_LANG_PUSH([C++])
TCXXFLAGS=$CXXFLAGS
TLDFLAGS=$LDFLAGS
TLIBS=$LIBS
TCPPFLAGS=$CPPFLAGS
LDFLAGS="-L$OCTLIBDIR $LDFLAGS"
LIBS="-loctinterp $LIBS"
# CXXFLAGS=
CPPFLAGS="-I$OCTINCLUDEDIR $CPPFLAGS"

AC_CHECK_HEADERS([octave/interpreter.h],
  [],
  [],
  [#include <octave/oct.h>]
)

## Simple symbol alternatives of different Octave versions.
OF_OCTAVE_LIST_ALT_SYMS([

[dnl
  [valid_identifier],
  [octave::valid_identifier],
  [[octave::valid_identifier ("");]],
  [OCTAVE__VALID_IDENTIFIER],
  [],
  []
],

[dnl
  [is_map],
  [isstruct],
  [[octave_value ().isstruct ();]],
  [OV_ISMAP],
  [],
  []
]

],
   [oct-alt-includes.h])

OF_OCTAVE_CHECK_SYM(
  [interpreter::varval],
  [[octave::interpreter *interp; interp->varval ("varname");]],
  [OCTAVE_HAVE_INTERPRETER_VARVAL],
  [[#include <octave/interpreter.h>]]
)

OF_OCTAVE_CHECK_SYM(
  [interpreter::assign],
  [[octave::interpreter *interp; interp->assign ("varname", octave_value ());]],
  [OCTAVE_HAVE_INTERPRETER_ASSIGN],
  [[#include <octave/interpreter.h>]]
)

OF_OCTAVE_CHECK_SYM(
  [interpreter::mark_for_deletion],
  [[octave::interpreter *interp; interp->mark_for_deletion ("varname");]],
  [OCTAVE_HAVE_INTERPRETER_MARK_FOR_DELETION],
  [[#include <octave/interpreter.h>]]
)

LIBS=$TLIBS
LDFLAGS=$TLDFLAGS
CXXFLAGS=$TCXXFLAGS
CPPFLAGS=$TCPPFLAGS
AC_LANG_POP([C++])

# End of checks for Octave features.
octave_major_ver=`$OCTAVE_CONFIG -p VERSION | $SED -e "s/\..*$//"`
if test -z "$octave_major_ver"; then
  octave_major_ver=4
fi
if test $octave_major_ver -gt 3; then
  ENABLE_SRC_BISTS=1
  AC_SUBST(ENABLE_SRC_BISTS)
fi

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
