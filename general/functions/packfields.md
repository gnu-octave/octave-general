---
layout: "default"
permalink: "/functions/10_packfields/"
pkg_name: "general"
pkg_version: "2.1.5"
pkg_description: "General tools for Octave."
title: "General Toolkit - packfields"
category: "Various Functions"
func_name: "packfields"
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
<dt class="deftypefn def-line" id="index-packfields"><span class="category-def">Loadable Function: </span><span><strong class="def-name">packfields</strong> <code class="def-code-arguments">(<var class="var">s_name</var>, <var class="var">var1</var>, <var class="var">var2</var>, &hellip;)</code></span></dt>
<dd><p>Create struct from variables.
</p>
<p>Inserts the named variables <var class="var">var1</var>, <var class="var">var2</var>, &hellip; as fields into
the struct named <var class="var">s_name</var>.  If it does not exist, a struct with that name
is created.
</p>
<p>This is equivalent to the code:
</p><div class="example">
<div class="group"><pre class="example-preformatted">  s_name.var1 = var1;
  s_name.var2 = var2;
          :          
</pre></div></div>
<p>but more efficient and more concise.
</p>

<p><strong class="strong">See also:</strong> setfield, setfields, struct, unpackfields.
</p></dd></dl>