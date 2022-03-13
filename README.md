## kd tree
In this repository we implement kd tree with efficient time complexity and interesting methods, which we will discuss below 👇

#### 1) construction of the tree 
To construct the tree we divide our domain in each level and choose the middle point to split the new domain.
So the backbone of the algorithm is sorting. As a result to improve our time complexity efficiency, We use merge sort to have complexity of O(n log n).

#### 2) search 
It considered one of the most interesting methods in  the tree as it has same time complexity of binary search tree which is O(log n).
We have optained that Time complexity by having balanced tree.so we have constructed the tree by the way shown previous.
#### 3) insertion
After we have constructed our tree we wanted to insert a point.
That tree is not as red-black tree self balancing tree.so to guarantee our tree still balanced we search a point need to insert,then we extend a children
From the last traversed node .
