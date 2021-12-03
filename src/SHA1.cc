// Copyright (C) 1999 Andy Adler <adler@sce.carleton.ca>
// Copyright (C) 2018-2020 John Donoghue <john.donogue@ieee.org>
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

// Note that part of the code below is on the public domain. That part will
// marked as such.

#include <octave/oct.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_NETTLE
  #include <nettle/sha1.h>
#endif


DEFUN_DLD (SHA1, args, ,
  "-*- texinfo -*-\n\
@deftypefn {Loadable Function} @var{hash} = SHA1(@var{byte_stream}\n\
@deftypefnx {Loadable Function} @var{hash} = SHA1(@var{byte_stream}, @var{hash_initial})\n\
\n\
SHA1 implements the Secure Hash Algorithm Cryptographic\n\
Hashing (One-Way) function.  (FIPS PUB 180-1)\n\
\n\
@var{hash} is a Row Vector of 20 byte values\n\
\n\
@var{hash_initial} default is 67452301 EFCDAB89 98BADCFE 10325476 C3D2E1F0\n\
\n\
Note: while it is possible to create a \"poor-man's\" MAC (message\n\
authenticity code) by setting hash_initial to a private value,\n\
it is better to use an algorithm like HMAC.\n\
\n\
HMAC = SHA1( [ passcode, SHA1( [passcode, data ] ) );\n \
@end deftypefn")
{
#ifndef HAVE_NETTLE
  error ("SHA1: Your system doesn't support or wasnt compiled with the SHA1 interface");
  return octave_value ();
#else
   octave_value_list retval;
   struct sha1_ctx ctx;
   uint8_t digest[SHA1_DIGEST_SIZE];

   int nargin = args.length ();
   if (nargin > 2 || nargin == 0) {
      print_usage ();
      return retval;
   }
   else if (nargin == 2 ) {
      ColumnVector init( args(1).vector_value() );
      if (init.numel() != SHA1_DIGEST_SIZE) {
         error("hash initializer must have %d bytes", SHA1_DIGEST_SIZE);
      }

      sha1_init (&ctx);
      for ( int i=0,k=0; i<5; i++) {
         ctx.state[i]= 0;
         for( int j=0; j<4; j++) 
            ctx.state[i]|= ( (uint8_t) init(k++) ) << (24 - 8*j);
      }
   }
   else {
      sha1_init (&ctx);
   }

   ColumnVector data( args(0).vector_value() );
   int len=data.numel();

   for ( int i=0; i< len; i++) {
      uint8_t d = (uint8_t) data(i);
      sha1_update( &ctx, 1, &d);
   }

   sha1_digest(&ctx, SHA1_DIGEST_SIZE, digest);

   RowVector hash(SHA1_DIGEST_SIZE);
   for ( int i=0; i<SHA1_DIGEST_SIZE; i++) {
      hash(i) = digest[i];
   }

   retval(0)= hash;

   return retval;
#endif
}

#if 0
%!test
%! expected = double([
%!   0xA9 0x99 0x3E 0x36 ...
%!   0x47 0x06 0x81 0x6A ...
%!   0xBA 0x3E 0x25 0x71 ...
%!   0x78 0x50 0xC2 0x6C ...
%!   0x9C 0xD0 0xD8 0x9D ]);
%! result = SHA1(uint8("abc"));
%! assert (result, expected)
#endif

