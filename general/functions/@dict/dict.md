---
layout: "default"
permalink: "/functions/@dict/10_dictdict/"
pkg_name: "general"
pkg_version: "2.1.5"
pkg_description: "General tools for Octave."
title: "General Toolkit - @dict/dict"
category: "Various Functions"
func_name: "@dict/dict"
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
<dt class="deftypefn def-line" id="index-dict"><span class="category-def">Function File: </span><span><strong class="def-name">dict</strong> <code class="def-code-arguments">()</code></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-dict-1"><span class="category-def">Function File: </span><span><strong class="def-name">dict</strong> <code class="def-code-arguments">(<var class="var">keys</var>, <var class="var">values</var>)</code></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-dict-2"><span class="category-def">Function File: </span><span><strong class="def-name">dict</strong> <code class="def-code-arguments">(<var class="var">str</var>)</code></span></dt>
<dd><p>Creates a dictionary object with given keys and values.
</p>
<p>The class <code class="code">dict</code> has been deprecated in favour of using Octave
 structs.  The advantage of dict over structs was that dict allowed any
 string, not only valid Octave identifiers, as fieldnames.  This has
 since change and any string is now a valid fieldname.
</p>
<div class="example">
<pre class="example-preformatted"> </pre><div class="group"><pre class="example-preformatted"> s = struct (&quot;7&quot;, &quot;value 7&quot;, &quot;  &quot;, &quot;just spaces&quot;);
 s.(&quot;7&quot;)
   &rArr; ans = value 7
 s.(&quot;  &quot;)
   &rArr; ans = just spaces
 </pre></div><pre class="example-preformatted"> </pre></div>

<p><var class="var">keys</var>
 should be a cell array of strings; <var class="var">values</var> should be a cell array
 with matching size. <var class="var">values</var> can also be a singleton array, in
 which case it is expanded to the proper size; or omitted, in which case
 the default value of empty matrix is used.
 If neither <var class="var">keys</var> nor <var class="var">values</var> are supplied, an empty dictionary
 is constructed.
 If a scalar structure is supplied as an argument, it is converted to 
 a dictionary using field names as keys.
</p>
<p>A dictionary can be indexed either by a single string or cell array of
 strings, like this:
</p>
<div class="example">
<pre class="example-preformatted"> </pre><div class="group"><pre class="example-preformatted">   d = dict (keys, values);
   d(str) # result is a single value
   d(cellstr) # result is a cell array
 </pre></div><pre class="example-preformatted"> </pre></div>

<p>In the first case, the stored value is returned directly; in the second case,
 a cell array is returned. The cell array returned inherits the shape of the index.
</p> 
<p>Similarly, indexed assignment works like this:
</p>
<div class="example">
<pre class="example-preformatted"> </pre><div class="group"><pre class="example-preformatted">   d = dict (keys, values);
   d(str) = val; # store a single value
   d(cellstr) = vals; # store a cell array
   d(cellstr) = []; # delete a range of keys
 </pre></div><pre class="example-preformatted"> </pre></div>

<p>Any keys that are not present in the dictionary are added. The values of
 existing keys are overwritten. In the second case, the lengths of index and
 rhs should match or rhs should be a singleton array, in which case it is
 broadcasted. 
</p>
<p>It is also possible to retrieve keys and values as cell arrays, using the
 &quot;keys&quot; and &quot;values&quot; properties. These properties are read-only.
</p>
</dd></dl>