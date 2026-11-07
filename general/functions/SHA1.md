---
layout: "default"
permalink: "/functions/4_SHA1/"
pkg_name: "general"
pkg_version: "2.1.4"
pkg_description: "General tools for Octave."
title: "General Toolkit - SHA1"
category: "Various Functions"
func_name: "SHA1"
navigation:
- id: "overview"
  name: "Overview"
  url: "/index"
- id: "Functions"
  name: "Function Reference"
  url: "/functions"
- id: "12_Dictionaries"
  name: "&nbsp;&nbsp;Dictionaries"
  url: "/functions/#12_Dictionaries"
  subitems:
- id: "17_VariousFunctions"
  name: "&nbsp;&nbsp;Various Functions"
  url: "/functions/#17_VariousFunctions"
  subitems:
- id: "news"
  name: "News"
  url: "/news"
---
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d"><span class="category-def">Loadable Function: </span><span><code class="def-type"><var class="var">hash</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">SHA1(<var class="var">byte_stream</var></code></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-1"><span class="category-def">Loadable Function: </span><span><code class="def-type"><var class="var">hash</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">SHA1(<var class="var">byte_stream</var>, <var class="var">hash_initial</var>)</code></span></dt>
<dd>
<p>SHA1 implements the Secure Hash Algorithm Cryptographic
Hashing (One-Way) function.  (FIPS PUB 180-1)
</p>
<p><var class="var">hash</var> is a Row Vector of 20 byte values
</p>
<p><var class="var">hash_initial</var> default is 67452301 EFCDAB89 98BADCFE 10325476 C3D2E1F0
</p>
<p>Note: while it is possible to create a &quot;poor-man&rsquo;s&quot; MAC (message
authenticity code) by setting hash_initial to a private value,
it is better to use an algorithm like HMAC.
</p>
<p>HMAC = SHA1( [ passcode, SHA1( [passcode, data ] ) );
 </p></dd></dl>