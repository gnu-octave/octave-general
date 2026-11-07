Introduction
============

The Octave General Package contains some general tools for GNU Octave.

Requirements
============

* Octave >= 4.0.0

* nettle-devel for the SHA function


Installing
==========

To install, run the octave package manager:

1. If running Windows, the package may already be installed:

   pkg list general

2. To install from internet sources:
   pkg install -forge general

3. To install from a local tarball.
   pkg install general-XXXXXXX.tar.gz
   Where XXXXXXX is the version of the downloaded tarball.

Usage:
======

1. Load the package.
   pkg load general
   (Required each time Octave is started)

2. Start using the functions!

Documentation
==============

See the function list for octave-general on [octave github](https://gnu-octave.github.io/octave-general/functions/) for function documentation.

Known limitations and bugs
==========================

Report bugs at https://github.com/gnu-octave/octave-general/issues

