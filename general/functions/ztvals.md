---
layout: "default"
permalink: "/functions/6_ztvals/"
pkg_name: "general"
pkg_version: "2.1.5"
pkg_description: "General tools for Octave."
title: "General Toolkit - ztvals"
category: "Various Functions"
func_name: "ztvals"
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
<dt class="deftypefn def-line" id="index-function"><span class="category-def">Function File: </span><span><strong class="def-name">function</strong> <code class="def-code-arguments">ztvals (<var class="var">x</var>, <var class="var">tol</var>)</code></span></dt>
<dd><p>Replaces tiny elements of the vector <var class="var">x</var> by zeros.
 Equivalent to 
 </p><div class="example">
<pre class="example-preformatted">   <var class="var">x</var>(abs(<var class="var">x</var>) &lt; <var class="var">tol</var> * norm (<var class="var">x</var>, Inf)) = 0
 </pre></div>
<p><var class="var">tol</var> specifies the chopping tolerance. It defaults to 
 1e-10 for double precision and 1e-5 for single precision inputs.
 </p></dd></dl>