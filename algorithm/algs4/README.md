# Demo Cases

Here is the demos for exch algorithms. The usage of each demo is the same for all language implementation. For example:

```bash
# java
% java Bag < tobe.txt 

# python
% python bag.py < tobe.txt

# c++
% ./bag_tests < tobe.txt
```

All data files are downloaded from the [course website](http://algs4.cs.princeton.edu/code/algs4-data.zip)

## Base 

### `class Bag`

```bash
% more tobe.txt 
to be or not to - be - - that - - - is
% java Bag < tobe.txt
size of bag = 14
is
-
-
-
that
-
-
be
-
to
not
or
be
to
```

### `class Stack`

```bash
% more tobe.txt 
to be or not to - be - - that - - - is
% java Stack < tobe.txt
to be not that or be (2 left on stack)
```

### `class Queue`

```bash
% java Queue < tobe.txt 
to be or not to be (2 left on queue)
```

### `class UF`

```bash
% java UF < tinyUF.txt
4 3
3 8
6 5
9 4
2 1
5 0
7 2
6 1
2 components

% java UF < mediumUF.txt
528 503
548 523
389 414
446 421
552 553
154 155
173 174
373 348
567 542
44 43
370 345
546 547
204 229
404 429
240 215
364 389
612 611
513 512
377 376
... ...
3 components.

% java UF < largeUF.txt
786321 134521
696834 98245
135991 549478
44723 265931
698410 385074
605706 520899
462258 656850
807101 778785
400066 73310
51236 774849
73567 396244
131311 706500
460661 848448
516872 565515
527941 319687
798741 997522
271929 192591
911577 210982
791065 737806
 ... ...
6 components.
```

## Sorting

### `class Selection`

```bash
% more tiny.txt
S O R T E X A M P L E
% java Selection < tiny.txt
A E E L M O P R S T X                 [ one string per line ]
  
% more words3.txt
bed bug dad yes zoo ... all bad yet

% java Selection < words3.txt
all bad bed bug dad ... yes yet zoo    [ one string per line ]
```

### `class Insertion`

```bash
% more tiny.txt
S O R T E X A M P L E
% java Insertion < tiny.txt
A E E L M O P R S T X                 [ one string per line ]
% more words3.txt
bed bug dad yes zoo ... all bad yet
% java Insertion < words3.txt
all bad bed bug dad ... yes yet zoo   [ one string per line ]
```

### `class Shell`

```bash
% more tiny.txt
S O R T E X A M P L E
% java Shell < tiny.txt
A E E L M O P R S T X                 [ one string per line ]
  
% more words3.txt
bed bug dad yes zoo ... all bad yet

% java Shell < words3.txt
all bad bed bug dad ... yes yet zoo    [ one string per line ]
```

### `class Merge`

```bash
% more tiny.txt
S O R T E X A M P L E
% java Merge < tiny.txt
A E E L M O P R S T X                 [ one string per line ]
  
% more words3.txt
bed bug dad yes zoo ... all bad yet

% java Merge < words3.txt
all bad bed bug dad ... yes yet zoo    [ one string per line ]

```

### `class MergeBU`

```bash
% more tiny.txt
S O R T E X A M P L E
% java MergeBU < tiny.txt
A E E L M O P R S T X                 [ one string per line ]
  
% more words3.txt
bed bug dad yes zoo ... all bad yet

% java MergeBU < words3.txt
all bad bed bug dad ... yes yet zoo    [ one string per line ]
```

### `class Quick`

```bash
% more tiny.txt
S O R T E X A M P L E
% java Quick < tiny.txt
A E E L M O P R S T X                 [ one string per line ]
% more words3.txt
bed bug dad yes zoo ... all bad yet
     
% java Quick < words3.txt
all bad bed bug dad ... yes yet zoo    [ one string per line ]
Remark: For a type-safe version that uses static generics, see
  http://algs4.cs.princeton.edu/23quicksort/QuickPedantic.java
```

### `class Quick3way`

```bash
% more tiny.txt
S O R T E X A M P L E
% java Quick3way < tiny.txt
A E E L M O P R S T X                 [ one string per line ]
  
% more words3.txt
bed bug dad yes zoo ... all bad yet

% java Quick3way < words3.txt
all bad bed bug dad ... yes yet zoo    [ one string per line ]
```

### `class MinPQ`

```bash
% java MinPQ < tinyPQ.txt
E A E (6 left on pq)
We use a one-based array to simplify parent and child calculations.
Can be optimized by replacing full exchanges with half exchanges
(ala insertion sort).
```

### `class Heap`

```bash
% more tiny.txt
S O R T E X A M P L E
% java Heap < tiny.txt
A E E L M O P R S T X                 [ one string per line ]
% more words3.txt
bed bug dad yes zoo ... all bad yet
% java Heap < words3.txt
all bad bed bug dad ... yes yet zoo   [ one string per line ]
```
## Searching

### `class SequentialSearchST`

```bash
% more tinyST.txt
S E A R C H E X A M P L E
% java SequentialSearchST < tiny.txt 
L 11
P 10
M 9
X 7
H 5
C 4
R 3
A 8
E 12
S 0
```

### `class BinarySearch`

```bash
% java BinarySearch tinyW.txt < tinyT.txt
50
99
13
% java BinarySearch largeW.txt < largeT.txt | more
499569
984875
295754
207807
140925
161828
[367,966 total values]

```

### `class BinarySearchST`

```bash
% more tinyST.txt
S E A R C H E X A M P L E

% java BinarySearchST < tinyST.txt
A 8
C 4
E 12
H 5
L 11
M 9
P 10
R 3
S 0
X 7
```

### `class BST`

```bash
% more tinyST.txt
S E A R C H E X A M P L E

% java BST < tinyST.txt
A 8
C 4
E 12
H 5
L 11
M 9
P 10
R 3
S 0
X 7
```

### `class RedBlackBST`

```bash
% more tinyST.txt
S E A R C H E X A M P L E

% java RedBlackBST < tinyST.txt
A 8
C 4
E 12
H 5
L 11
M 9
P 10
R 3
S 0
X 7
```
## Graph

### `class Graph`

```bash
% java Graph tinyG.txt
13 vertices, 13 edges 
0: 6 2 1 5 
1: 0 
2: 0 
3: 5 4 
4: 5 6 3 
5: 3 4 0 
6: 0 4 
7: 8 
8: 7 
9: 11 10 12 
10: 9 
11: 9 12 
12: 11 9 
% java Graph mediumG.txt
250 vertices, 1273 edges 
0: 225 222 211 209 204 202 191 176 163 160 149 114 97 80 68 59 58 49 44 24 15 
1: 220 203 200 194 189 164 150 130 107 72 
2: 141 110 108 86 79 51 42 18 14 
...

```

### `class Digraph`

```bash
% java Digraph tinyDG.txt
13 vertices, 22 edges
0: 5 1 
1: 
2: 0 3 
3: 5 2 
4: 3 2 
5: 4 
6: 9 4 8 0 
7: 6 9
8: 6 
9: 11 10 
10: 12 
11: 4 12 
12: 9 

```

### `class Edge`

```bash
```

### `class EdgeWeightedGraph`

```bash
% java EdgeWeightedGraph tinyEWG.txt 
8 16
0: 6-0 0.58000  0-2 0.26000  0-4 0.38000  0-7 0.16000  
1: 1-3 0.29000  1-2 0.36000  1-7 0.19000  1-5 0.32000  
2: 6-2 0.40000  2-7 0.34000  1-2 0.36000  0-2 0.26000  2-3 0.17000  
3: 3-6 0.52000  1-3 0.29000  2-3 0.17000  
4: 6-4 0.93000  0-4 0.38000  4-7 0.37000  4-5 0.35000  
5: 1-5 0.32000  5-7 0.28000  4-5 0.35000  
6: 6-4 0.93000  6-0 0.58000  3-6 0.52000  6-2 0.40000
7: 2-7 0.34000  1-7 0.19000  0-7 0.16000  5-7 0.28000  4-7 0.37000
```

### `class DirectedEdge`

```bash
```

### `class EdgeWeightedDigraph`

```bash
```

### `class DepthFirstPaths`

```bash
%  java Graph tinyCG.txt
6 8
0: 2 1 5 
1: 0 2 
2: 0 1 3 4 
3: 5 4 2 
4: 3 2 
5: 3 0 
% java DepthFirstPaths tinyCG.txt 0
0 to 0:  0
0 to 1:  0-2-1
0 to 2:  0-2
0 to 3:  0-2-3
0 to 4:  0-2-3-4
0 to 5:  0-2-3-5
```

### `class BreadthFirstPaths`

```bash
%  java Graph tinyCG.txt
6 8
0: 2 1 5 
1: 0 2 
2: 0 1 3 4 
3: 5 4 2 
4: 3 2 
5: 3 0 
%  java BreadthFirstPaths tinyCG.txt 0
0 to 0 (0):  0
0 to 1 (1):  0-1
0 to 2 (1):  0-2
0 to 3 (2):  0-2-3
0 to 4 (2):  0-2-4
0 to 5 (1):  0-5
%  java BreadthFirstPaths largeG.txt 0
0 to 0 (0):  0
0 to 1 (418):  0-932942-474885-82707-879889-971961-...
0 to 2 (323):  0-460790-53370-594358-780059-287921-...
0 to 3 (168):  0-713461-75230-953125-568284-350405-...
0 to 4 (144):  0-460790-53370-310931-440226-380102-...
0 to 5 (566):  0-932942-474885-82707-879889-971961-...
0 to 6 (349):  0-932942-474885-82707-879889-971961-...
```

### `class Cycle`

```bash
% java Cycle tinyG.txt
3 4 5 3 
% java Cycle mediumG.txt 
15 0 225 15 
% java Cycle largeG.txt 
996673 762 840164 4619 785187 194717 996673 
```

### `class Bipartite`

```bash
```

### `class CC`

```bash
% java CC tinyG.txt
3 components
0 1 2 3 4 5 6
7 8 
9 10 11 12
% java CC mediumG.txt 
1 components
0 1 2 3 4 5 6 7 8 9 10 ...
% java -Xss50m CC largeG.txt 
1 components
0 1 2 3 4 5 6 7 8 9 10 ...
Note: This implementation uses a recursive DFS. To avoid needing
      a potentially very large stack size, replace with a non-recurisve
      DFS ala NonrecursiveDFS.java.
```

### `class DirectedDFS`

```bash
% java DirectedDFS tinyDG.txt 1
1
% java DirectedDFS tinyDG.txt 2
0 1 2 3 4 5
% java DirectedDFS tinyDG.txt 1 2 6
0 1 2 3 4 5 6 8 9 10 11 12 
```

### `class DepthFirstOrder`

```bash
% java DepthFirstOrder tinyDAG.txt
   v  pre post
--------------
   0    0    8
   1    3    2
   2    9   10
   3   10    9
   4    2    0
   5    1    1
   6    4    7
   7   11   11
   8   12   12
   9    5    6
  10    8    5
  11    6    4
  12    7    3
Preorder:  0 5 4 1 6 9 11 12 10 2 3 7 8 
Postorder: 4 5 1 12 11 10 9 6 0 3 2 7 8 
Reverse postorder: 8 7 2 3 0 6 9 10 11 12 1 5 4 
```

### `class DirectedCycle`

```bash
% java DirectedCycle tinyDG.txt 
Directed cycle: 3 5 4 3 
%  java DirectedCycle tinyDAG.txt 
No directed cycle
```

### `class EdgeWeightedDirectedCycle`

```bash
```

### `class Topological`

```bash
% java Topological jobs.txt "/"
Calculus
Linear Algebra
Introduction to CS
Advanced Programming
Algorithms
Theoretical CS
Artificial Intelligence
Robotics
Machine Learning
Neural Networks
Databases
Scientific Computing
Computational Biology
```

### `class KosarajuSharirSCC`

```bash
% java KosarajuSharirSCC tinyDG.txt
5 strong components
1 
0 2 3 4 5 
9 10 11 12 
6 8 
7
% java KosarajuSharirSCC mediumDG.txt 
10 strong components
21 
2 5 6 8 9 11 12 13 15 16 18 19 22 23 25 26 28 29 30 31 32 33 34 35 37 38 39 40 42 43 44 46 47 48 49 
14 
3 4 17 20 24 27 36 
41 
7 
45 
1 
0 
10 
% java -Xss50m KosarajuSharirSCC mediumDG.txt 
25 strong components
7 11 32 36 61 84 95 116 121 128 230   ...
28 73 80 104 115 143 149 164 184 185  ...
38 40 200 201 207 218 286 387 418 422 ...
12 14 56 78 87 103 216 269 271 272    ...
42 48 112 135 160 217 243 246 273 346 ...
46 76 96 97 224 237 297 303 308 309   ...
9 15 21 22 27 90 167 214 220 225 227  ...
74 99 133 146 161 166 202 205 245 262 ...
43 83 94 120 125 183 195 206 244 254  ...
1 13 54 91 92 93 106 140 156 194 208  ...
10 39 67 69 131 144 145 154 168 258   ...
6 52 66 113 118 122 139 147 212 213   ...
8 127 150 182 203 204 249 367 400 432 ...
63 65 101 107 108 136 169 170 171 173 ...
55 71 102 155 159 198 228 252 325 419 ...
4 25 34 58 70 152 172 196 199 210 226 ...
2 44 50 88 109 138 141 178 197 211    ...
57 89 129 162 174 179 188 209 238 276 ...
33 41 49 119 126 132 148 181 215 221  ...
3 18 23 26 35 64 105 124 157 186 251  ...
5 16 17 20 31 47 81 98 158 180 187    ...
24 29 51 59 75 82 100 114 117 134 151 ...
30 45 53 60 72 85 111 130 137 142 163 ...
19 37 62 77 79 110 153 352 353 361    ...
0 68 86 123 165 176 193 239 289 336   ...
```

### `class PrimMST`

```bash
%  java PrimMST tinyEWG.txt 
1-7 0.19000
0-2 0.26000
2-3 0.17000
4-5 0.35000
5-7 0.28000
6-2 0.40000
0-7 0.16000
1.81000
% java PrimMST mediumEWG.txt
1-72   0.06506
2-86   0.05980
3-67   0.09725
4-55   0.06425
5-102  0.03834
6-129  0.05363
7-157  0.00516
...
10.46351
% java PrimMST largeEWG.txt
...
647.66307
```

### `class LazyPrimMST`

```bash
%  java LazyPrimMST tinyEWG.txt 
0-7 0.16000
1-7 0.19000
0-2 0.26000
2-3 0.17000
5-7 0.28000
4-5 0.35000
6-2 0.40000
1.81000
% java LazyPrimMST mediumEWG.txt
0-225   0.02383
49-225  0.03314
44-49   0.02107
44-204  0.01774
49-97   0.03121
202-204 0.04207
176-202 0.04299
176-191 0.02089
68-176  0.04396
58-68   0.04795
10.46351
% java LazyPrimMST largeEWG.txt
...
647.66307
```

### `class KruskalMST`

```bash
%  java KruskalMST tinyEWG.txt 
0-7 0.16000
2-3 0.17000
1-7 0.19000
0-2 0.26000
5-7 0.28000
4-5 0.35000
6-2 0.40000
1.81000
% java KruskalMST mediumEWG.txt
168-231 0.00268
151-208 0.00391
7-157   0.00516
122-205 0.00647
8-152   0.00702
156-219 0.00745
28-198  0.00775
38-126  0.00845
10-123  0.00886
...
10.46351
```

### `class DijkstraSP`

```bash
% java DijkstraSP tinyEWD.txt 0
0 to 0 (0.00)  
0 to 1 (1.05)  0->4  0.38   4->5  0.35   5->1  0.32   
0 to 2 (0.26)  0->2  0.26   
0 to 3 (0.99)  0->2  0.26   2->7  0.34   7->3  0.39   
0 to 4 (0.38)  0->4  0.38   
0 to 5 (0.73)  0->4  0.38   4->5  0.35   
0 to 6 (1.51)  0->2  0.26   2->7  0.34   7->3  0.39   3->6  0.52   
0 to 7 (0.60)  0->2  0.26   2->7  0.34   
% java DijkstraSP mediumEWD.txt 0
0 to 0 (0.00)  
0 to 1 (0.71)  0->44  0.06   44->93  0.07   ...  107->1  0.07   
0 to 2 (0.65)  0->44  0.06   44->231  0.10  ...  42->2  0.11   
0 to 3 (0.46)  0->97  0.08   97->248  0.09  ...  45->3  0.12   
0 to 4 (0.42)  0->44  0.06   44->93  0.07   ...  77->4  0.11   
...
```

### `class AcyclicSP`

```bash
% java AcyclicSP tinyEWDAG.txt 5
5 to 0 (0.73)  5->4  0.35   4->0  0.38   
5 to 1 (0.32)  5->1  0.32   
5 to 2 (0.62)  5->7  0.28   7->2  0.34   
5 to 3 (0.61)  5->1  0.32   1->3  0.29   
5 to 4 (0.35)  5->4  0.35   
5 to 5 (0.00)  
5 to 6 (1.13)  5->1  0.32   1->3  0.29   3->6  0.52   
5 to 7 (0.28)  5->7  0.28   
```

### `class BellmanFordSP`

```bash
% java BellmanFordSP tinyEWDn.txt 0
0 to 0 ( 0.00)  
0 to 1 ( 0.93)  0->2  0.26   2->7  0.34   7->3  0.39   3->6  0.52   6->4 -1.25   4->5  0.35   5->1  0.32
0 to 2 ( 0.26)  0->2  0.26   
0 to 3 ( 0.99)  0->2  0.26   2->7  0.34   7->3  0.39   
0 to 4 ( 0.26)  0->2  0.26   2->7  0.34   7->3  0.39   3->6  0.52   6->4 -1.25   
0 to 5 ( 0.61)  0->2  0.26   2->7  0.34   7->3  0.39   3->6  0.52   6->4 -1.25   4->5  0.35
0 to 6 ( 1.51)  0->2  0.26   2->7  0.34   7->3  0.39   3->6  0.52   
0 to 7 ( 0.60)  0->2  0.26   2->7  0.34   
% java BellmanFordSP tinyEWDnc.txt 0
4->5  0.35
5->4 -0.66
```
## String

### `class LSD`

```bash
% java LSD < words3.txt
all
bad
bed
bug
dad
...
yes
yet
zoo
```

### `class MSD`

```bash
% java MSD < shells.txt 
are
by
sea
seashells
seashells
sells
sells
she
she
shells
shore
surely
the
the
```

### `class Quick3string`

```bash
% java Quick3string < shell.txt
are
by
sea
seashells
seashells
sells
sells
she
she
shells
shore
surely
the
the
```

### `class TrieST`

```bash
% java TrieST < shellsST.txt 
by 4
sea 6
sells 1
she 0
shells 3
shore 7
the 5
```

### `class TST`

```bash
% java TST < shellsST.txt
keys(""):
by 4
sea 6
sells 1
she 0
shells 3
shore 7
the 5
longestPrefixOf("shellsort"):
shells
keysWithPrefix("shor"):
shore
keysThatMatch(".he.l."):
shells
% java TST
theory the now is the time for all good men
Remarks
--------
  - can't use a key that is the empty string ""
```

### `class KMP`

```bash
% java KMP abracadabra abacadabrabracabracadabrabrabracad
text:    abacadabrabracabracadabrabrabracad 
pattern:               abracadabra          
% java KMP rab abacadabrabracabracadabrabrabracad
text:    abacadabrabracabracadabrabrabracad 
pattern:         rab
% java KMP bcara abacadabrabracabracadabrabrabracad
text:    abacadabrabracabracadabrabrabracad 
pattern:                                   bcara
% java KMP rabrabracad abacadabrabracabracadabrabrabracad 
text:    abacadabrabracabracadabrabrabracad
pattern:                        rabrabracad
% java KMP abacad abacadabrabracabracadabrabrabracad
text:    abacadabrabracabracadabrabrabracad
pattern: abacad
```

### `class BoyerMoore`

```bash
% java BoyerMoore abracadabra abacadabrabracabracadabrabrabracad
text:    abacadabrabracabracadabrabrabracad 
pattern:               abracadabra
% java BoyerMoore rab abacadabrabracabracadabrabrabracad
text:    abacadabrabracabracadabrabrabracad 
pattern:         rab
% java BoyerMoore bcara abacadabrabracabracadabrabrabracad
text:    abacadabrabracabracadabrabrabracad 
pattern:                                   bcara
% java BoyerMoore rabrabracad abacadabrabracabracadabrabrabracad
text:    abacadabrabracabracadabrabrabracad
pattern:                        rabrabracad
% java BoyerMoore abacad abacadabrabracabracadabrabrabracad
text:    abacadabrabracabracadabrabrabracad
pattern: abacad
```

### `class RabinKarp`

```bash
% java RabinKarp abracadabra abacadabrabracabracadabrabrabracad
pattern: abracadabra
text:    abacadabrabracabracadabrabrabracad 
match:                 abracadabra          
% java RabinKarp rab abacadabrabracabracadabrabrabracad
pattern: rab
text:    abacadabrabracabracadabrabrabracad 
match:           rab                         
% java RabinKarp bcara abacadabrabracabracadabrabrabracad
pattern: bcara
text:         abacadabrabracabracadabrabrabracad 
%  java RabinKarp rabrabracad abacadabrabracabracadabrabrabracad
text:    abacadabrabracabracadabrabrabracad
pattern:                        rabrabracad
% java RabinKarp abacad abacadabrabracabracadabrabrabracad
text:    abacadabrabracabracadabrabrabracad
pattern: abacad
```

### `class GREP`

```bash
% more tinyL.txt
AC
AD
AAA
ABD
ADD
BCD
ABCCBD
BABAAA
BABBAAA
%  java GREP "(A*B|AC)D" < tinyL.txt
ABD
ABCCBD
```

### `class Huffman`

```bash
% java Huffman - < abra.txt | java BinaryDump 60
010100000100101000100010010000110100001101010100101010000100
000000000000000000000000000110001111100101101000111110010100
120 bits
% java Huffman - < abra.txt | java Huffman +
ABRACADABRA!
```

### `class LZW`

```bash
```

