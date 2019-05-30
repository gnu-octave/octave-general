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
DEFMETHOD_DLD (packfields, interp, args, ,
#else
DEFUN_DLD (packfields, args, ,
#endif
  "-*- texinfo -*-\n\
@deftypefn {Loadable Function} {} packfields (@var{s_name}, @var{var1}, @var{var2}, @dots{})\n\
Create struct from variables.\n\
\n\
Inserts the named variables @var{var1}, @var{var2}, @dots{} as fields into\n\
the struct named @var{s_name}.  If it does not exist, a struct with that name\n\
is created.\n\
\n\
This is equivalent to the code:\n\
@example\n\
@group\n\
  s_name.var1 = var1;\n\
  s_name.var2 = var2;\n\
          :          \n\
@end group\n\
@end example\n\
but more efficient and more concise.\n\
\n\
@seealso{setfield, setfields, struct, unpackfields}\n\
@end deftypefn")
{
  int nargin = args.length ();

  if (nargin > 0)
    {
#ifdef DEFMETHOD_DLD
#ifndef OCTAVE_HAVE_INTERPRETER_VARVAL
      octave::symbol_table::scope curr_scope
       = interp.require_current_scope ("packfields");
#endif
#endif

      std::string struct_name = args (0).string_value ();
      string_vector fld_names(nargin-1);
      octave_value_list fld_vals(nargin-1);

      if (! error_state && ! OCTAVE__VALID_IDENTIFIER (struct_name))
        error ("packfields: invalid variable name: %s", struct_name.c_str ());

      for (octave_idx_type i = 0; i < nargin-1; i++)
        {
          if (error_state)
            break;

          std::string fld_name = args(i+1).string_value ();

          if (error_state)
            break;

          if (OCTAVE__VALID_IDENTIFIER (fld_name))
            {
              fld_names(i) = fld_name;

#ifdef DEFMETHOD_DLD
#ifdef OCTAVE_HAVE_INTERPRETER_VARVAL
              octave_value fld_val = interp.varval (fld_name);
#else
              octave_value fld_val = curr_scope.varval (fld_name);
#endif
#else
              octave_value fld_val = symbol_table::varval (fld_name);
#endif
              if (fld_val.is_defined ())
                fld_vals(i) = fld_val;
              else
                error ("packfields: variable %s not defined", fld_name.c_str ());
            }
          else
            error ("packfields: invalid field name: %s", fld_name.c_str ());
        }

      if (! error_state)
        {
#ifdef DEFMETHOD_DLD
#ifdef OCTAVE_HAVE_INTERPRETER_VARVAL
          octave_value struct_val = interp.varval (struct_name);
#else
          octave_value struct_val = curr_scope.varval (struct_name);
#endif
#else
          octave_value struct_val = symbol_table::varval (struct_name);
#endif
          octave_scalar_map map;

          if (struct_val.is_defined () && struct_val.OV_ISMAP ())
            map = struct_val.scalar_map_value ();

          for (octave_idx_type i = 0; i < nargin-1; i++)
            map.assign (fld_names(i), fld_vals(i));

          struct_val = map;

#ifdef DEFMETHOD_DLD
#ifdef OCTAVE_HAVE_INTERPRETER_ASSIGN
          interp.assign (struct_name, struct_val);
#else
          curr_scope.assign (struct_name, struct_val);
#endif
#else
          symbol_table::assign (struct_name, struct_val);
#endif
        }
    }
  else
    print_usage ();

  return octave_value_list ();
}

/*
%!test
%! foo = "hello";
%! bar = 42;
%! packfields ("s", "foo", "bar");
%! assert (s, struct ("foo", "hello", "bar", 42));
*/
