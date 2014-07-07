<TeXmacs|1.0.7.21>

<style|generic>

<\body>
  <section|Relativistic Lorentz Force>

  The first equation of motion is Newton's second law:

  <\eqnarray*>
    <tformat|<table|<row|<cell|<frac|d <wide|p|\<vect\>>|d
    t>>|<cell|=>|<cell|<wide|F|\<vect\>><around*|(|<wide|r|\<vect\>>,<wide|p|\<vect\>>|)>.>>>>
  </eqnarray*>

  Non-relativistically,

  <\eqnarray*>
    <tformat|<table|<row|<cell|m<frac|d <wide|<wide|x|\<vect\>>|\<dot\>>|d
    t>+<wide|<wide|x|\<vect\>>|\<dot\>><frac|d m|d
    t>>|<cell|=>|<cell|<wide|F|\<vect\>><around*|(|<wide|r|\<vect\>>,<wide|p|\<vect\>>|)>.>>>>
  </eqnarray*>

  Now, assume constant mass particles, then, in full relativity, (for
  something like the lorentz force)

  <\eqnarray*>
    <tformat|<table|<row|<cell|<frac|d|d t><wide|p|\<vect\>>>|<cell|=>|<cell|<wide|F|\<vect\>><around*|(|<wide|r|\<vect\>>,<wide|p|\<vect\>>|)>>>|<row|<cell|=m<around*|(|<frac|d<around*|(|\<gamma\><wide|<wide|x|\<vect\>>|\<dot\>>|)>|d
    t>|)>>|<cell|=>|<cell|<wide|F|\<vect\>><around*|(|<wide|r|\<vect\>>,<wide|p|\<vect\>>|)>>>|<row|<cell|=m<wide|\<gamma\>|\<dot\>><wide|<wide|x|\<vect\>>|\<dot\>>+m\<gamma\><wide|<wide|x|\<vect\>>|\<ddot\>>>|<cell|=>|<cell|<wide|F|\<vect\>><around*|(|<wide|r|\<vect\>>,<wide|p|\<vect\>>|)>>>>>
  </eqnarray*>

  where the first term is a relativistic drag term. We have that

  <\eqnarray*>
    <tformat|<table|<row|<cell|<wide|\<gamma\>|\<dot\>>>|<cell|=>|<cell|<frac|d|d
    t><around*|(|<frac|1|<sqrt|1-<around*|\||<wide|<wide|x|\<vect\>>|\<dot\>>|\|><rsup|2>/c<rsup|2>>>|)>>>|<row|<cell|>|<cell|=>|<cell|-<frac|-<frac|1|c<rsup|2>><frac|d|d
    t><around*|(|<around|\||<wide|<wide|x|\<vect\>>|\<dot\>>|\|><rsup|2>|)>|2<around*|(|1-<around*|\||<wide|<wide|x|\<vect\>>|\<dot\>>|\|><rsup|2>/c<rsup|2>|)><rsup|3/2>>>>|<row|<cell|>|<cell|=>|<cell|<frac|1|2<around*|(|1-\<beta\><rsup|2>|)><rsup|3/2>><frac|1|c<rsup|2>><frac|d|d
    t><around*|(|<around|\||<wide|<wide|x|\<vect\>>|\<dot\>>|\|><rsup|2>|)>>>>>
  </eqnarray*>

  We have that

  <\eqnarray*>
    <tformat|<table|<row|<cell|<frac|d|d t><around*|(|v<rsup|2>|)>>|<cell|=>|<cell|<frac|d|d
    t><around*|(|<big|sum><rsub|i>v<rsub|i>v<rsub|i>|)>>>|<row|<cell|>|<cell|=>|<cell|2<big|sum><rsub|i><wide|v<rsub|i>|\<dot\>>v<rsub|i>>>|<row|<cell|>|<cell|=>|<cell|2<wide|a|\<vect\>>\<cdot\><wide|v|\<vect\>>.>>>>
  </eqnarray*>

  So,

  <\eqnarray*>
    <tformat|<table|<row|<cell|<wide|\<gamma\>|\<dot\>>>|<cell|=>|<cell|<frac|\<gamma\>|2c<rsup|2><around*|(|1-\<beta\><rsup|2>|)>>2<around*|(|<wide|a|\<vect\>>\<cdot\><wide|v|\<vect\>>|)>>>|<row|<cell|>|<cell|=>|<cell|<frac|\<gamma\>|c<rsup|2><around*|(|1-\<beta\><rsup|2>|)>><around*|(|<wide|a|\<vect\>>\<cdot\><wide|v|\<vect\>>|)>>>>>
  </eqnarray*>

  Therefore,

  <\eqnarray*>
    <tformat|<table|<row|<cell|<frac|\<gamma\>|c<rsup|2><around*|(|1-\<beta\><rsup|2>|)>><around*|(|<wide|<wide|x|\<vect\>>|\<ddot\>>\<cdot\><wide|<wide|x|\<vect\>>|\<dot\>>|)><wide|<wide|x|\<vect\>>|\<dot\>>+\<gamma\><wide|<wide|x|\<vect\>>|\<ddot\>>>|<cell|=>|<cell|<frac|1|m><wide|F|\<vect\>><around*|(|<wide|r|\<vect\>>,<wide|p|\<vect\>>|)>>>|<row|<cell|\<Rightarrow\>\<gamma\><around*|(|I+<frac|1|c<rsup|2><around*|(|1-\<beta\><rsup|2>|)>><wide|<wide|x|\<vect\>>|\<dot\>>\<otimes\><wide|<wide|x|\<vect\>>|\<dot\>>|)>\<cdot\><wide|<wide|x|\<vect\>>|\<ddot\>>>|<cell|=>|<cell|<frac|1|m><wide|F|\<vect\>><around*|(|<wide|r|\<vect\>>,<wide|p|\<vect\>>|)>>>>>
  </eqnarray*>

  where <math|I> is the identity tensor. Now, for the lorentz force,

  <\eqnarray*>
    <tformat|<table|<row|<cell|\<gamma\><wide|<wide|x|\<vect\>>|\<ddot\>>\<cdot\><around*|(|I+<frac|<wide|<wide|x|\<vect\>>|\<dot\>>\<otimes\><wide|<wide|x|\<vect\>>|\<dot\>>|c<rsup|2>-v<rsup|2>>|)>>|<cell|=>|<cell|<frac|e|m><around*|[|<wide|E|\<vect\>><around*|(|<wide|r|\<vect\>>,t|)>+<frac|<wide|v|\<vect\>>|c>\<times\><wide|B|\<vect\>>|]>.>>>>
  </eqnarray*>

  Given a time with <math|<wide|x|\<vect\>><around*|(|t|)>=<big|sum><rsub|i>x<rsub|i><around*|(|t|)><wide|x|^><rsub|i>>
  and <math|<wide|p|\<vect\>><around*|(|t|)>=m\<gamma\><around*|(|t|)><wide|v|\<vect\>>=m
  \<gamma\><around*|(|t|)><big|sum><rsub|i>v<rsub|i><around*|(|t|)><wide|x|^><rsub|i>>,
  we have in matrix notation,

  <\eqnarray*>
    <tformat|<table|<row|<cell|<matrix|<tformat|<table|<row|<cell|1+<frac|v<rsub|x><rsup|2>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|x>v<rsub|y>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|x>v<rsub|z>|c<rsup|2>-v<rsup|2>>>>|<row|<cell|<frac|v<rsub|x>v<rsub|y>|c<rsup|2>-v<rsup|2>>>|<cell|1+<frac|v<rsub|y><rsup|2>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|y>v<rsub|z>|c<rsup|2>-v<rsup|2>>>>|<row|<cell|<frac|v<rsub|x>v<rsub|z>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|y>v<rsub|z>|c<rsup|2>-v<rsup|2>>>|<cell|1+<frac|v<rsub|z><rsup|2>|c<rsup|2>-v<rsup|2>>>>>>><matrix|<tformat|<table|<row|<cell|a<rsub|x>>>|<row|<cell|a<rsub|y>>>|<row|<cell|a<rsub|z>>>>>>>|<cell|=>|<cell|<frac|e<sqrt|1-v<rsup|2>/c<rsup|2>>|m><around*|[|<matrix|<tformat|<table|<row|<cell|E<rsub|x>>>|<row|<cell|E<rsub|y>>>|<row|<cell|E<rsub|z>>>>>>+<frac|1|c><matrix|<tformat|<table|<row|<cell|v<rsub|y>B<rsub|z>-v<rsub|z>B<rsub|y>>>|<row|<cell|v<rsub|z>B<rsub|x>-v<rsub|x>B<rsub|z>>>|<row|<cell|v<rsub|x>B<rsub|y>-v<rsub|y>B<rsub|x>>>>>>|]>>>|<row|<cell|\<Rightarrow\>\<Gamma\><wide|a|\<vect\>>>|<cell|=>|<cell|<frac|e|m\<gamma\>><around*|(|<wide|E|\<vect\>>+<frac|<wide|v|\<vect\>>|c>\<times\><wide|B|\<vect\>>|)>>>|<row|<cell|\<Rightarrow\><wide|a|\<vect\>>>|<cell|=>|<cell|<frac|\<Gamma\><rsup|-1>|\<gamma\>><frac|e|m><around*|(|<wide|E|\<vect\>>+<frac|<wide|v|\<vect\>>|c>\<times\><wide|B|\<vect\>>|)>.>>>>
  </eqnarray*>

  We see that the this is the old lorentz force in a rest frame with a matrix
  correction

  <\eqnarray*>
    <tformat|<table|<row|<cell|>|<cell|>|<cell|<frac|1|\<gamma\>><matrix|<tformat|<table|<row|<cell|1+<frac|v<rsub|x><rsup|2>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|x>v<rsub|y>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|x>v<rsub|z>|c<rsup|2>-v<rsup|2>>>>|<row|<cell|<frac|v<rsub|x>v<rsub|y>|c<rsup|2>-v<rsup|2>>>|<cell|1+<frac|v<rsub|y><rsup|2>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|y>v<rsub|z>|c<rsup|2>-v<rsup|2>>>>|<row|<cell|<frac|v<rsub|x>v<rsub|z>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|y>v<rsub|z>|c<rsup|2>-v<rsup|2>>>|<cell|1+<frac|v<rsub|z><rsup|2>|c<rsup|2>-v<rsup|2>>>>>>><rsup|-1>.>>>>
  </eqnarray*>

  Note that <math|\<Gamma\>> can be written

  <\eqnarray*>
    <tformat|<table|<row|<cell|>|<cell|>|<cell|<matrix|<tformat|<table|<row|<cell|1+<frac|v<rsub|x><rsup|2>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|x>v<rsub|y>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|x>v<rsub|z>|c<rsup|2>-v<rsup|2>>>>|<row|<cell|<frac|v<rsub|x>v<rsub|y>|c<rsup|2>-v<rsup|2>>>|<cell|1+<frac|v<rsub|y><rsup|2>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|y>v<rsub|z>|c<rsup|2>-v<rsup|2>>>>|<row|<cell|<frac|v<rsub|x>v<rsub|z>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|y>v<rsub|z>|c<rsup|2>-v<rsup|2>>>|<cell|1+<frac|v<rsub|z><rsup|2>|c<rsup|2>-v<rsup|2>>>>>>>>>|<row|<cell|>|<cell|=>|<cell|<matrix|<tformat|<table|<row|<cell|<frac|c<rsup|2>-v<rsup|2>+v<rsub|x><rsup|2>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|x>v<rsub|y>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|x>v<rsub|z>|c<rsup|2>-v<rsup|2>>>>|<row|<cell|<frac|v<rsub|x>v<rsub|y>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|c<rsup|2>-v<rsup|2>+v<rsub|y><rsup|2>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|y>v<rsub|z>|c<rsup|2>-v<rsup|2>>>>|<row|<cell|<frac|v<rsub|x>v<rsub|z>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|y>v<rsub|z>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|c<rsup|2>-v<rsup|2>+v<rsub|z><rsup|2>|c<rsup|2>-v<rsup|2>>>>>>>>>|<row|<cell|>|<cell|=>|<cell|<matrix|<tformat|<table|<row|<cell|<frac|c<rsup|2>-v<rsub|y><rsup|2>-v<rsub|z><rsup|2>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|x>v<rsub|y>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|x>v<rsub|z>|c<rsup|2>-v<rsup|2>>>>|<row|<cell|<frac|v<rsub|x>v<rsub|y>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|c<rsup|2>-v<rsub|x><rsup|2>-v<rsub|z><rsup|2>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|y>v<rsub|z>|c<rsup|2>-v<rsup|2>>>>|<row|<cell|<frac|v<rsub|x>v<rsub|z>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|v<rsub|y>v<rsub|z>|c<rsup|2>-v<rsup|2>>>|<cell|<frac|c<rsup|2>-v<rsub|x><rsup|2>-v<rsub|y><rsup|2>|c<rsup|2>-v<rsup|2>>>>>>>>>|<row|<cell|>|<cell|=>|<cell|<frac|1|c<rsup|2>-v<rsup|2>><matrix|<tformat|<table|<row|<cell|c<rsup|2>-v<rsub|y><rsup|2>-v<rsub|z><rsup|2>>|<cell|v<rsub|x>v<rsub|y>>|<cell|v<rsub|x>v<rsub|z>>>|<row|<cell|v<rsub|x>v<rsub|y>>|<cell|c<rsup|2>-v<rsub|x><rsup|2>-v<rsub|z><rsup|2>>|<cell|v<rsub|y>v<rsub|z>>>|<row|<cell|v<rsub|x>v<rsub|z>>|<cell|v<rsub|y>v<rsub|z>>|<cell|c<rsup|2>-v<rsub|x><rsup|2>-v<rsub|y><rsup|2>>>>>>>>|<row|<cell|>|<cell|=>|<cell|<frac|1|c<rsup|2>>\<gamma\><rsup|2><matrix|<tformat|<table|<row|<cell|c<rsup|2>-v<rsub|y><rsup|2>-v<rsub|z><rsup|2>>|<cell|v<rsub|x>v<rsub|y>>|<cell|v<rsub|x>v<rsub|z>>>|<row|<cell|v<rsub|x>v<rsub|y>>|<cell|c<rsup|2>-v<rsub|x><rsup|2>-v<rsub|z><rsup|2>>|<cell|v<rsub|y>v<rsub|z>>>|<row|<cell|v<rsub|x>v<rsub|z>>|<cell|v<rsub|y>v<rsub|z>>|<cell|c<rsup|2>-v<rsub|x><rsup|2>-v<rsub|y><rsup|2>>>>>>>>|<row|<cell|\<Rightarrow\>\<Gamma\><rsup|-1>>|<cell|=>|<cell|<frac|c<rsup|2>|\<gamma\><rsup|2>><around*|[|<matrix|<tformat|<table|<row|<cell|c<rsup|2>-v<rsub|y><rsup|2>-v<rsub|z><rsup|2>>|<cell|v<rsub|x>v<rsub|y>>|<cell|v<rsub|x>v<rsub|z>>>|<row|<cell|v<rsub|x>v<rsub|y>>|<cell|c<rsup|2>-v<rsub|x><rsup|2>-v<rsub|z><rsup|2>>|<cell|v<rsub|y>v<rsub|z>>>|<row|<cell|v<rsub|x>v<rsub|z>>|<cell|v<rsub|y>v<rsub|z>>|<cell|c<rsup|2>-v<rsub|x><rsup|2>-v<rsub|y><rsup|2>>>>>>|]><rsup|-1>>>>>
  </eqnarray*>

  Therefore, we have that

  <\eqnarray*>
    <tformat|<table|<row|<cell|<wide|a|\<vect\>>>|<cell|=>|<cell|<frac|c<rsup|2>|\<gamma\><rsup|3>><matrix|<tformat|<table|<row|<cell|c<rsup|2>-v<rsub|y><rsup|2>-v<rsub|z><rsup|2>>|<cell|v<rsub|x>v<rsub|y>>|<cell|v<rsub|x>v<rsub|z>>>|<row|<cell|v<rsub|x>v<rsub|y>>|<cell|c<rsup|2>-v<rsub|x><rsup|2>-v<rsub|z><rsup|2>>|<cell|v<rsub|y>v<rsub|z>>>|<row|<cell|v<rsub|x>v<rsub|z>>|<cell|v<rsub|y>v<rsub|z>>|<cell|c<rsup|2>-v<rsub|x><rsup|2>-v<rsub|y><rsup|2>>>>>><rsup|-1><frac|e|m><around*|(|<wide|E|\<vect\>>+<frac|<wide|v|\<vect\>>|c>\<times\><wide|B|\<vect\>>|)>.>>>>
  </eqnarray*>
</body>

<\references>
  <\collection>
    <associate|auto-1|<tuple|1|?>>
  </collection>
</references>

<\auxiliary>
  <\collection>
    <\associate|toc>
      <vspace*|1fn><with|font-series|<quote|bold>|math-font-series|<quote|bold>|1<space|2spc>Relativistic
      Lorentz Force> <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-1><vspace|0.5fn>
    </associate>
  </collection>
</auxiliary>