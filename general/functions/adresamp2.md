---
layout: "default"
permalink: "/functions/9_adresamp2/"
pkg_name: "general"
pkg_version: "2.1.5"
pkg_description: "General tools for Octave."
title: "General Toolkit - adresamp2"
category: "Various Functions"
func_name: "adresamp2"
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
<dt class="deftypefn def-line" id="index-adresamp2"><span class="category-def">Function File: </span><span><code class="def-type">[<var class="var">xs</var>, <var class="var">ys</var>] =</code> <strong class="def-name">adresamp2</strong> <code class="def-code-arguments">(<var class="var">x</var>, <var class="var">y</var>, <var class="var">n</var>, <var class="var">eps</var>)</code></span></dt>
<dd><p>Perform an adaptive resampling of a planar curve.
 The arrays <var class="var">x</var> and <var class="var">y</var> specify x and y coordinates of the points of the curve.
 On return, the same curve is approximated by <var class="var">xs</var>, <var class="var">ys</var> that have length <var class="var">n</var>
 and the angles between successive segments are approximately equal.
 </p></dd></dl>