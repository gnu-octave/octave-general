#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
#
### Copyright (C) 2015-2017 Olaf Till <i7tiol@t-online.de>
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
AC_INIT([general], [2.1.0])
AC_CONFIG_SRCDIR([packfields.cc])
AC_CONFIG_HEADERS([config.h])

# Avoid warnings for redefining AH-generated preprocessor symbols of
# Octave.
AH_TOP([#include "undef-ah-octave.h"])

AC_CONFIG_MACRO_DIRS([m4])

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
## We need Octaves include path both with and without '/octave'
## appended. The path without '/octave' is needed to selectively test
## for Octave headers, like octave/....h. The path with '/octave' is
## needed since some Octave headers contain include directives for
## other Octave headers with <> instead of "".
OCTINCLUDEDIR=${OCTINCLUDEDIR:-`$MKOCTFILE -p INCFLAGS`}
AC_LANG_PUSH([C++])
TCXXFLAGS=$CXXFLAGS
TLDFLAGS=$LDFLAGS
TLIBS=$LIBS
TCPPFLAGS=$CPPFLAGS
LDFLAGS="-L$OCTLIBDIR $LDFLAGS"
LIBS="-loctinterp $LIBS"
# CXXFLAGS=
CPPFLAGS="$OCTINCLUDEDIR $CPPFLAGS"

## Simple symbol alternatives of different Octave versions.
OF_OCTAVE_LIST_ALT_SYMS([

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

AC_CHECK_HEADERS([octave/interpreter.h],
  [],
  [],
  [#include <octave/oct.h>]
)

LIBS=$TLIBS
LDFLAGS=$TLDFLAGS
CXXFLAGS=$TCXXFLAGS
CPPFLAGS=$TCPPFLAGS
AC_LANG_POP([C++])
# End of checks for Octave features.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
