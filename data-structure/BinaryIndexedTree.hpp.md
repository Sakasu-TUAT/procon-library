---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/BinaryIndexedTree.hpp\"\n/* BIT: \u533A\u9593\
    \u548C\u306E\u66F4\u65B0\u3084\u8A08\u7B97\u3092\u884C\u3046\u69CB\u9020\u4F53\
    \n    \u521D\u671F\u5024\u306F a_1 = a_2 = ... = a_n = 0\n    \u30FBadd(i,x):\
    \ a_i += x \u3068\u3059\u308B\n    \u30FBsum(i): a_1 + a_2 + ... + a_i \u3092\u8A08\
    \u7B97\u3059\u308B\n    \u8A08\u7B97\u91CF\u306F\u5168\u3066 O(logn)\n*/\ntemplate\
    \ <typename T>\nstruct BIT {\n    int n;             // \u8981\u7D20\u6570\n \
    \   vector<T> bit[2];  // \u30C7\u30FC\u30BF\u306E\u683C\u7D0D\u5148\n    BIT(int\
    \ n_) { init(n_); }\n    void init(int n_) {\n        n = n_ + 1;\n        for\
    \ (int p = 0; p < 2; p++) bit[p].assign(n, 0);\n    }\n    void add_sub(int p,\
    \ int i, T x) {\n        for (int idx = i; idx < n; idx += (idx & -idx)) {\n \
    \           bit[p][idx] += x;\n        }\n    }\n    void add(int l, int r, T\
    \ x) {  // [l,r) \u306B\u52A0\u7B97\n        add_sub(0, l, -x * (l - 1));\n  \
    \      add_sub(0, r, x * (r - 1));\n        add_sub(1, l, x);\n        add_sub(1,\
    \ r, -x);\n    }\n    T sum_sub(int p, int i) {\n        T s(0);\n        for\
    \ (int idx = i; idx > 0; idx -= (idx & -idx)) {\n            s += bit[p][idx];\n\
    \        }\n        return s;\n    }\n    T sum(int i) { return sum_sub(0, i)\
    \ + sum_sub(1, i) * i; }\n};\n"
  code: "/* BIT: \u533A\u9593\u548C\u306E\u66F4\u65B0\u3084\u8A08\u7B97\u3092\u884C\
    \u3046\u69CB\u9020\u4F53\n    \u521D\u671F\u5024\u306F a_1 = a_2 = ... = a_n =\
    \ 0\n    \u30FBadd(i,x): a_i += x \u3068\u3059\u308B\n    \u30FBsum(i): a_1 +\
    \ a_2 + ... + a_i \u3092\u8A08\u7B97\u3059\u308B\n    \u8A08\u7B97\u91CF\u306F\
    \u5168\u3066 O(logn)\n*/\ntemplate <typename T>\nstruct BIT {\n    int n;    \
    \         // \u8981\u7D20\u6570\n    vector<T> bit[2];  // \u30C7\u30FC\u30BF\u306E\
    \u683C\u7D0D\u5148\n    BIT(int n_) { init(n_); }\n    void init(int n_) {\n \
    \       n = n_ + 1;\n        for (int p = 0; p < 2; p++) bit[p].assign(n, 0);\n\
    \    }\n    void add_sub(int p, int i, T x) {\n        for (int idx = i; idx <\
    \ n; idx += (idx & -idx)) {\n            bit[p][idx] += x;\n        }\n    }\n\
    \    void add(int l, int r, T x) {  // [l,r) \u306B\u52A0\u7B97\n        add_sub(0,\
    \ l, -x * (l - 1));\n        add_sub(0, r, x * (r - 1));\n        add_sub(1, l,\
    \ x);\n        add_sub(1, r, -x);\n    }\n    T sum_sub(int p, int i) {\n    \
    \    T s(0);\n        for (int idx = i; idx > 0; idx -= (idx & -idx)) {\n    \
    \        s += bit[p][idx];\n        }\n        return s;\n    }\n    T sum(int\
    \ i) { return sum_sub(0, i) + sum_sub(1, i) * i; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2023-11-27 19:30:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/BinaryIndexedTree.hpp
layout: document
title: Binary Indexed Tree
---

# Binary Indexed Tree (フェニック木) 

数列 $a1,a2,a3,⋯,an$ が与えられた時に、以下のようなことがそれぞれ $O(\log N)$ で実現できるデータ構造のことです。

- $i$ と $x$ が与えられたとき、$ai$ に $x$ を加算する
- $i$ が与えられたとき、$a1+a2+⋯+ai$ を求める

## コンストラクタ

```cpp
BIT<T> b(int n)
```
