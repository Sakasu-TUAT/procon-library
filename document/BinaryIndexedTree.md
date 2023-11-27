---
title: Binary Indexed Tree
documentation_of: //data-structure/BinaryIndexedTree.hpp
---

# Binary Indexed Tree (フェニック木) 

数列 $a1,a2,a3,⋯,an$ が与えられた時に、以下のようなことがそれぞれ $O(\log N)$ で実現できるデータ構造のことです。

- $i$ と $x$ が与えられたとき、$ai$ に $x$ を加算する
- $i$ が与えられたとき、$a1+a2+⋯+ai$ を求める

## コンストラクタ

```cpp
BIT<T> b(int n)
```
