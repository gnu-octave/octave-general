---
layout: "default"
permalink: "/functions/12_unpackfields/"
pkg_name: "general"
pkg_version: "2.1.5"
pkg_description: "General tools for Octave."
title: "General Toolkit - unpackfields"
category: "Various Functions"
func_name: "unpackfields"
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
<dt class="deftypefn def-line" id="index-unpackfields"><span class="category-def">Loadable Function: </span><span><strong class="def-name">unpackfields</strong> <code class="def-code-arguments">(<var class="var">s_name</var>, <var class="var">fld1</var>, <var class="var">fld2</var>, &hellip;)</code></span></dt>
<dd><p>Create variables from fields of a struct.
</p>
<p>Inserts the named fields <var class="var">fld1</var>, <var class="var">fld2</var>, &hellip;, from the struct
named <var class="var">s_name</var>, into the current scope.  Note that <var class="var">s_name</var> is the
name of the struct in the current scope, not the struct itself.
</p>
<div class="example">
<div class="group"><pre class="example-preformatted">unpackfields (&quot;struct&quot;, &quot;var1&quot;, &quot;var2&quot;)
</pre></div></div>

<p>is equivalent to the code:
</p><div class="example">
<div class="group"><pre class="example-preformatted">  var1 = struct.var1;
  var2 = struct.var2;
          :          
</pre></div></div>
<p>but more efficient and more concise.
</p>

<p><strong class="strong">See also:</strong> getfield, getfields, packfields, struct.
</p></dd></dl>