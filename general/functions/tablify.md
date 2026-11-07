---
layout: "default"
permalink: "/functions/7_tablify/"
pkg_name: "general"
pkg_version: "2.1.4"
pkg_description: "General tools for Octave."
title: "General Toolkit - tablify"
category: "Various Functions"
func_name: "tablify"
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
<dt class="deftypefn def-line" id="index-tablify"><span class="category-def">Function File: </span><span><code class="def-type">[<var class="var">y1</var>, &hellip;] =</code> <strong class="def-name">tablify</strong> <code class="def-code-arguments">(<var class="var">x1</var>, &hellip;)</code></span></dt>
<dd>
<p>Create a table out of the input arguments, if possible.  The table is
 created by extending row and column vectors to like dimensions.  If
 the dimensions of input vectors are not commensurate an error will
 occur. Dimensions are commensurate if they have the same number of
 rows and columns, a single row and the same number of columns, or the
 same number of rows and a single column.  In other words, vectors
 will only be extended along singleton dimensions.
</p>
<p>For example:
</p>
<div class="example">
<pre class="example-preformatted"> </pre><div class="group"><pre class="example-preformatted"> [a, b] = tablify ([1 2; 3 4], 5) 
 &rArr; a = 
   1 2
   3 4
 &rArr; b = 
   5 5
   5 5 
 </pre></div><pre class="example-preformatted"> </pre></div>
<div class="example">
<pre class="example-preformatted"> </pre><div class="group"><pre class="example-preformatted"> [a, b, c] = tablify (1, [1 2 3 4], [5;6;7]) 
 &rArr; a =
   1 1 1 1
   1 1 1 1
   1 1 1 1
 &rArr; b =
   1 2 3 4
   1 2 3 4
   1 2 3 4
 &rArr; c = 
   5 5 5 5
   6 6 6 6
   7 7 7 7
 </pre></div><pre class="example-preformatted"> </pre></div>

<p>The following example attempts to expand vectors that do not have
 commensurate dimensions and will produce an error.
</p>
<div class="example">
<pre class="example-preformatted"> </pre><div class="group"><pre class="example-preformatted"> tablify([1 2],[3 4 5]) 
 </pre></div><pre class="example-preformatted"> </pre></div>

<p>Note that use of array operations and broadcasting is more efficient
 for many situations.
</p>

</dd></dl>