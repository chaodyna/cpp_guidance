# 交点间断Galerkin方法：算法、分析和应用

## 引言

考虑一维守恒律方程：

$$\frac{\partial u}{\partial t}+\frac{\partial f}{\partial x}=g, \qquad x\in \Omega \tag{1.1}$$

它受制于适当的初始条件及边界条件，其中$u(x,t)$为所要求的解, $f(u)$为流量, $g(x,t)$为强加的力函数。

首先考虑有限差分法。这种方法首先要建立一个空间网格$x^k(k=1,\cdots,K)$, 然后再用差分法逼近哪些空间导数, 即守恒律杯近似为:
$$\frac{du_h(x^k,t)}{dt}+\frac{f_h(x^{k+1},t)-f_h(x^{k-1},t)}{h^k+h^{k-1}}=g(x^k,t), \tag{1.2}$$
