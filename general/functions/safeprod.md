---
layout: "default"
permalink: "/functions/8_safeprod/"
pkg_name: "general"
pkg_version: "2.1.5"
pkg_description: "General tools for Octave."
title: "General Toolkit - safeprod"
category: "Various Functions"
func_name: "safeprod"
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
<dt class="deftypefn def-line" id="index-safeprod"><span class="category-def">Function File: </span><span><code class="def-type"><var class="var">p</var> =</code> <strong class="def-name">safeprod</strong> <code class="def-code-arguments">(<var class="var">x</var>, <var class="var">dim</var>)</code></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-safeprod-1"><span class="category-def">Function File: </span><span><code class="def-type">[<var class="var">p</var>, <var class="var">e</var>] =</code> <strong class="def-name">safeprod</strong> <code class="def-code-arguments">(<var class="var">x</var>, <var class="var">dim</var>)</code></span></dt>
<dd><p>This function forms product(s) of elements of the array <var class="var">x</var> along the dimension 
 specified by <var class="var">dim</var>, analogically to <code class="code">prod</code>, but avoids overflows and underflows 
 if possible. If called with 2 output arguments, <var class="var">p</var> and <var class="var">e</var> are computed 
 so that the product is <code class="code"><var class="var">p</var> * 2^<var class="var">e</var></code>.
 </p>
<p><strong class="strong">See also:</strong> prod,log2.
 </p></dd></dl>