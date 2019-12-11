// Copyright (C) 2009 VZLU Prague
// Copyright (C) 2018 John Donoghue <john.donogue@ieee.org>
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

#include <octave/utils.h>
#ifdef HAVE_OCTAVE_INTERPRETER_H
# include <octave/interpreter.h>
#endif
#include <octave/symtab.h>
#include <octave/oct-map.h>

#ifdef DEFMETHOD_DLD
DEFMETHOD_DLD (unpackfields, interp, args, ,
#else
DEFUN_DLD (unpackfields, args, ,
#endif
  "-*- texinfo -*-\n\
@deftypefn {Loadable Function} {} unpackfields (@var{s_name}, @var{fld1}, @var{fld2}, @dots{})\n\
Create variables from fields of a struct.\n\
\n\
Inserts the named fields @var{fld1}, @var{fld2}, @dots{}, from the struct\n\
named @var{s_name}, into the current scope.  Note that @var{s_name} is the\n\
name of the struct in the current scope, not the struct itself.\n\
\n\
@example\n\
@group\n\
unpackfields (\"struct\", \"var1\", \"var2\")\n\
@end group\n\
@end example\n\
\n\
is equivalent to the code:\n\
@example\n\
@group\n\
  var1 = struct.var1;\n\
  var2 = struct.var2;\n\
          :          \n\
@end group\n\
@end example\n\
but more efficient and more concise.\n\
\n\
@seealso{getfield, getfields, packfields, struct}\n\
@end deftypefn")
{
  int nargin = args.length ();

  if (nargin > 0)
    {
#ifdef DEFMETHOD_DLD
#ifndef OCTAVE_HAVE_INTERPRETER_VARVAL
      octave::symbol_table::scope curr_scope
       = interp.require_current_scope ("unpackfields");
#endif
#endif
      if (! args (0).is_string ())
        {
            error ("unpackfields: expected variable name");
	    return octave_value ();
        }
 
      std::string struct_name = args (0).string_value ();
      string_vector fld_names(nargin-1);

      if (! OCTAVE__VALID_IDENTIFIER (struct_name))
        {
          error ("unpackfields: invalid variable name: %s",
                 struct_name.c_str ());
	    return octave_value ();
        }

      for (octave_idx_type i = 0; i < nargin-1; i++)
        {
          if (! args (i+1).is_string ())
            {
              error ("unpackfields: expected variable name for input %d", (int)i+1);
	      return octave_value ();
            }

          std::string fld_name = args(i+1).string_value ();

          if (OCTAVE__VALID_IDENTIFIER (fld_name))
            fld_names(i) = fld_name;
          else
            {
              error ("unpackfields: invalid field name: %s", fld_name.c_str ());
              return octave_value ();
            }
        }

      // Force the symbol to be inserted in caller's scope.
#ifdef DEFMETHOD_DLD
#ifdef OCTAVE_HAVE_INTERPRETER_VARVAL
      octave_value struct_val = interp.varval (struct_name);
#else
      octave_value struct_val = curr_scope.varval (struct_name);
#endif
#else
      octave_value struct_val = symbol_table::varval (struct_name);
#endif
      if (struct_val.OV_ISMAP ())
        {
	  if (struct_val.ndims () == 2)
            {
              // Fast code for a built-in struct.
              const octave_scalar_map map = struct_val.scalar_map_value ();

              // Do the actual work.
              for (octave_idx_type i = 0; i < nargin-1; i++)
                {
                  octave_scalar_map::const_iterator iter = map.seek (fld_names(i));
                  if (iter != map.end ())
#ifdef DEFMETHOD_DLD
#ifdef OCTAVE_HAVE_INTERPRETER_ASSIGN
                    interp.assign (fld_names(i), map.contents (iter));
#else
                    curr_scope.assign (fld_names(i), map.contents (iter));
#endif
#else
                    symbol_table::assign (fld_names(i), map.contents (iter));
#endif
                  else
                    {
                      error ("unpackfields: field %s does not exist", fld_names(i).c_str ());
                      break;
                    }
                }
            }
          else
            {
              error ("unpackfields: structure must have singleton dimensions");
              return octave_value ();
            }
        }
      else if (struct_val.is_defined ())
        {
          // General case.
          std::list<octave_value_list> idx (1);

          for (octave_idx_type i = 0; i < nargin-1; i++)
            {
              idx.front () = args(i+1); // Save one string->octave_value conversion.
              octave_value val = struct_val.subsref (".", idx);

              if (val.is_defined ())
#ifdef DEFMETHOD_DLD
#ifdef OCTAVE_HAVE_INTERPRETER_ASSIGN
                interp.assign (fld_names(i), val);
#else
                curr_scope.assign (fld_names(i), val);
#endif
#else
                symbol_table::assign (fld_names(i), val);
#endif
            }
        }
    }
  else
    print_usage ();

  return octave_value_list ();
}

/*
%!test
%! s.foo = "hello";
%! s.bar = 42;
%! unpackfields ("s", "foo", "bar");
%! assert (foo, "hello");
%! assert (bar, 42);
*/
