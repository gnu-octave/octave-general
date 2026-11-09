---
layout: "default"
permalink: "/functions/6_unvech/"
pkg_name: "general"
pkg_version: "2.1.5"
pkg_description: "General tools for Octave."
title: "General Toolkit - unvech"
category: "Various Functions"
func_name: "unvech"
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
<dt class="deftypefn def-line" id="index-unvech"><span class="category-def">Function File: </span><span><code class="def-type"><var class="var">m</var> =</code> <strong class="def-name">unvech</strong> <code class="def-code-arguments">(<var class="var">v</var>, <var class="var">scale</var>)</code></span></dt>
<dd><p>Performs the reverse of <code class="code">vech</code> on the vector <var class="var">v</var>.
</p>
<p>Given a Nx1 array <var class="var">v</var> describing the lower triangular part of a
 matrix (as obtained from <code class="code">vech</code>), it returns the full matrix.
</p>
<p>The upper triangular part of the matrix will be multiplied by <var class="var">scale</var> such
 that 1 and -1 can be used for symmetric and antisymmetric matrix respectively.
 <var class="var">scale</var> must be a scalar and defaults to 1.
</p>

<p><strong class="strong">See also:</strong> vech, ind2sub.
 </p></dd></dl>