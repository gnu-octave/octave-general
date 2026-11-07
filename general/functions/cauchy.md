---
layout: "default"
permalink: "/functions/6_cauchy/"
pkg_name: "general"
pkg_version: "2.1.4"
pkg_description: "General tools for Octave."
title: "General Toolkit - cauchy"
category: "Various Functions"
func_name: "cauchy"
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
<dt class="deftypefn def-line" id="index-cauchy"><span class="category-def">Function File: </span><span><strong class="def-name">cauchy</strong> <code class="def-code-arguments">(<var class="var">N</var>, <var class="var">r</var>, <var class="var">x</var>, <var class="var">f</var> )</code></span></dt>
<dd><p>Return the Taylor coefficients and numerical differentiation of a function.
</p>
<p><var class="var">f</var> for the first <var class="var">N-1</var> coefficients or derivatives using the fft.<br>
 <var class="var">N</var> is the number of points to evaluate,<br>
 <var class="var">r</var> is the radius of convergence, needs to be chosen less then the smallest singularity,<br>
 <var class="var">x</var> is point to evaluate the Taylor expansion or differentiation. For example,
</p>
<p>If <var class="var">x</var> is a scalar, the function <var class="var">f</var> is evaluated in a row vector
 of length <var class="var">N</var>. If <var class="var">x</var> is a column vector, <var class="var">f</var> is evaluated in a
 matrix of length(x)-by-N elements and must return a matrix of the same size.
</p>
<div class="example">
<pre class="example-preformatted"> </pre><div class="group"><pre class="example-preformatted"> d = cauchy(16, 1.5, 0, @(x) exp(x));
 d(2) = 1.0000 # first (2-1) derivative of function f (index starts from zero)
 </pre></div><pre class="example-preformatted"> </pre></div>
</dd></dl>