## kd tree
In this repository we are implementing kd tree with efficient time complexity and interesting methods, which we will discuss below 👇

#### 1) construction of the tree 
To construct the tree we divide our domain in each level and choose the middle point to split the new domain.
So the backbone of the algorithm is sorting. As a result to improve our time complexity efficiency, We use merge sort to have complexity of O(K n log n).🦄🦄
   ![image](https://user-images.githubusercontent.com/67281513/158078588-44d8930c-712e-4b83-8fe0-6bfbcf88488c.png)


#### 2) search 
It considered one of the most interesting methods in  the tree as it has same time complexity of binary search tree which is O(log n).
We have optained that Time complexity by having balanced tree.so we have constructed the tree by the way shown previous.

#### 3) insertion
After we have constructed our tree we wanted to insert a point.
That tree is not as red-black tree self balancing tree.so to guarantee our tree still balanced we search a point need to insert,then we extend a children
From the last traversed node .

#### 4) the nearest neighbor (NN) search🦄
the most interesting operation provided by k-d trees, the
nearest neighbor (NN) search.

k-d tree, much like a sorted array, has structural information about the
relative distance and position of its elements, and we can leverage that information to
perform our search more efficiently.

the average running time for nearest neighbor search on a balanced
k-d tree is O(2**k + log(n)) : k is number of dimensions, n is number of points.

#### 5)Region search
 If that distance between our Target and surrounding points in our dataset is lower than or equal to the search region’s
radius, it means that there is still an area of intersection between that branch and the search region, and so we need to traverse the branch; otherwise, we can prune it.

![image](https://user-images.githubusercontent.com/67281513/159442810-0a52fbae-3268-49bb-9064-2792509a27ed.png)






## Referances
An interesting paper helped me to improve algorithm efficiency 

Russell A. Brown :Building a Balanced k-d Tree in O(kn log n) Time. Journal of Computer Graphics Techniques (JCGT), vol. 4, no. 1, 50-68, 2015.https://doi.org/10.48550/arXiv.1410.5420



I have made an open discussion about kd tree

1)Talking about the algorithm of that data structure and what problem has been solved by using that DS [https://www.youtube.com/watch?v=H0ViOzQGYaA]

2)Talking about Algorithm insights and some methods{construction,search,insertion} [https://www.youtube.com/watch?v=QrLQm0F9jTM]

