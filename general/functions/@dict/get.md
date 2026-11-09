---
layout: "default"
permalink: "/functions/@dict/9_dictget/"
pkg_name: "general"
pkg_version: "2.1.5"
pkg_description: "General tools for Octave."
title: "General Toolkit - @dict/get"
category: "Various Functions"
func_name: "@dict/get"
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
<dt class="deftypefn def-line" id="index-get"><span class="category-def">Function File: </span><span><strong class="def-name">get</strong> <code class="def-code-arguments">(d, key, defv)</code></span></dt>
<dd><p>Queries for the values of specified key(s). Unlike indexing, however,
 this does not throw an error if a key is missing but rather substitutes
 a default value. If <var class="var">key</var> is a cell array, <var class="var">defv</var> should be either
 a cell array of the same shape as <var class="var">key</var>, or a singleton cell.
 Non-cell values will be converted to a singleton cell.
 </p></dd></dl>