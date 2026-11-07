---
layout: "default"
permalink: "/functions/5_majle/"
pkg_name: "general"
pkg_version: "2.1.4"
pkg_description: "General tools for Octave."
title: "General Toolkit - majle"
category: "Various Functions"
func_name: "majle"
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
<dt class="deftypefn def-line" id="index-majle"><span class="category-def">Function File: </span><span><code class="def-type"><var class="var">S</var> =</code> <strong class="def-name">majle</strong> <code class="def-code-arguments">(<var class="var">X</var>, <var class="var">Y</var>)</code></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-majle-1"><span class="category-def">Function File: </span><span><code class="def-type"><var class="var">S</var> =</code> <strong class="def-name">majle</strong> <code class="def-code-arguments">(<var class="var">X</var>, <var class="var">Y</var>, <var class="var">MAJLETOL</var>)</code></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-majle-2"><span class="category-def">Function File: </span><span><code class="def-type"><var class="var">[S, Z]</var> =</code> <strong class="def-name">majle</strong> <code class="def-code-arguments">(<var class="var">X</var>, <var class="var">Y</var>, <var class="var">MAJLETOL</var>)</code></span></dt>
<dd><p>(Weak) Majorization check
</p>
<p>S = MAJLE(X,Y) checks if the real part of X is (weakly) majorized by
 the real part of Y, where X and Y must be numeric (full or sparse)
 arrays.
</p>
<p>It returns S=0, if there is no weak majorization of X by Y,
 S=1, if there is a weak majorization of X by Y, or S=2, if there is a
 strong majorization of X by Y.
</p>
<p>The shapes of X and Y are ignored.
</p>
<p>numel(X) and numel(Y) may be different, in which case one of them is
 appended with zeros to match the sizes with the other and, in case of
 any negative components, a special warning is issued.  
</p>
<p>S = MAJLE(X,Y,MAJLETOL) allows in addition to specify the tolerance in
 all inequalities
</p>
<p>[S,Z] = MAJLE(X,Y,MAJLETOL) also outputs a row vector
 Z, which appears in the definition of the (weak) majorization. In the
 traditional case, where the real vectors X and Y are of the same size,
 Z = CUMSUM(SORT(Y,&rsquo;descend&rsquo;)-SORT(X,&rsquo;descend&rsquo;)).
</p>
<p>Here, X is weakly majorized by Y, if MIN(Z)&gt;0, and strongly
 majorized if MIN(Z)=0, see
 http://en.wikipedia.org/wiki/Majorization
</p>
<p>The value of MAJLETOL depends on how X and Y have been computed, i.e.,
 on what the level of error in X or Y is. A good minimal starting point
 should be MAJLETOL=eps*MAX(NUMEL(X),NUMEL(Y)). The default is 0. 
</p>
<div class="example">
<pre class="example-preformatted"> </pre><div class="group"><pre class="example-preformatted"> % Examples:
 x = [2 2 2]; y = [1 2 3]; s = majle(x,y)
 % returns the value 2.
 x = [2 2 2]; y = [1 2 4]; s = majle(x,y)
 % returns the value 1.
 x = [2 2 2]; y = [1 2 2]; s = majle(x,y)
 % returns the value 0.
 x = [2 2 2]; y = [1 2 2]; [s,z] = majle(x,y)
 % also returns the vector z = [ 0 0 -1].
 x = [2 2 2]; y = [1 2 2]; s = majle(x,y,1)
 % returns the value 2.
 x = [2 2]; y = [1 2 2]; s = majle(x,y)
 % returns the value 1 and warns on tailing with zeros
 x = [2 2]; y = [-1 2 2]; s = majle(x,y)
 % returns the value 0 and gives two warnings on tailing with zeros
 x = [2 -inf]; y = [4 inf]; [s,z] = majle(x,y)
 % returns s = 1 and z = [Inf   Inf].
 x = [2 inf]; y = [4 inf]; [s,z] = majle(x,y)
 % returns  s = 1 and z = [NaN NaN] and a warning on NaNs in z.
 x=speye(2); y=sparse([0 2; -1 1]); s = majle(x,y) 
 % returns the value 2.
 x = [2 2; 2 2]; y = [1 3 4]; [s,z] = majle(x,y) %and 
 x = [2 2; 2 2]+i; y = [1 3 4]-2*i; [s,z] = majle(x,y)
 % both return s = 2 and z = [2 3 2 0]. 
 x = [1 1 1 1 0]; y = [1 1 1 1 1 0 0]'; s = majle(x,y)
 % returns the value 1 and warns on tailing with zeros
 </pre></div><pre class="example-preformatted"> </pre></div>

<p>One can use this function to check numerically the validity of the
 Schur-Horn,Lidskii-Mirsky-Wielandt, and Gelfand-Naimark theorems: 
 </p><div class="example">
<pre class="example-preformatted"> </pre><div class="group"><pre class="example-preformatted"> clear all; n=100; majleTol=n*n*eps;
 A = randn(n,n); A = A'+A; eA = -sort(-eig(A)); dA = diag(A);
 majle(dA,eA,majleTol) % returns the value 2
 % which is the Schur-Horn theorem; and 
 B=randn(n,n); B=B'+B; eB=-sort(-eig(B)); 
 eAmB=-sort(-eig(A-B));
 majle(eA-eB,eAmB,majleTol) % returns the value 2 
 % which is the Lidskii-Mirsky-Wielandt theorem; finally
 A = randn(n,n); sA = -sort(-svd(A)); 
 B = randn(n,n); sB = -sort(-svd(B));
 sAB = -sort(-svd(A*B));
 majle(log2(sAB)-log2(sA), log2(sB), majleTol) % retuns the value 2
 majle(log2(sAB)-log2(sB), log2(sA), majleTol) % retuns the value 2
 % which are the log versions of the Gelfand-Naimark theorems
 </pre></div><pre class="example-preformatted"> </pre></div>
</dd></dl>