// Copyright (C) 2002-2020 Andy Adler
//
// This program is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation; either version 3 of the License, or (at your option) any later
// version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, see <http://www.gnu.org/licenses/>.

#include <octave/oct.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef OCTAVE_HAVE_INTERPRETER_MARK_FOR_DELETION
# include <octave/file-io.h>
#endif

#ifdef HAVE_OCTAVE_INTERPRETER_H
# include <octave/interpreter.h>
#endif


#ifdef DEFMETHOD_DLD
DEFMETHOD_DLD (mark_for_deletion, interp, args, ,
#else
DEFUN_DLD (mark_for_deletion, args,,
#endif
"-*- texinfo -*-\n \
@deftypefn {Loadable Function} mark_for_deletion (@var{filename}, ...);\n\
Put filenames in the list of files to be deleted\n\
when octave terminates.\n\
\n \
This is useful for any function which uses temporary files.\n \
@end deftypefn")
{
  octave_value retval;
  for ( int i=0; i< args.length(); i++) {
    if( ! args(i).is_string() ) {
      error ("mark_for_deletion: arguments must be string filenames");
      return retval;
    } else {

#ifdef OCTAVE_HAVE_INTERPRETER_MARK_FOR_DELETION
      interp.mark_for_deletion( args(i).string_value() );
#else
      mark_for_deletion( args(i).string_value() );
#endif
    }
  }
  return retval;
}

#if 0
%!test
%! testname = tempname;
%! mark_for_deletion(testname);
%! mark_for_deletion(testname, testname);

%!error <arguments must be string filenames> mark_for_deletion(1)
#endif
