## kd tree
In this repository we implement kd tree with efficient time complexity and interesting methods, which we will discuss below 👇

#### 1) construction of the tree 
To construct the tree we divide our domain in each level and choose the middle point to split the new domain.
So the backbone of the algorithm is sorting. As a result to improve our time complexity efficiency, We use merge sort to have complexity of O(K n log n).
   ![image](https://user-images.githubusercontent.com/67281513/158078588-44d8930c-712e-4b83-8fe0-6bfbcf88488c.png)


#### 2) search 
It considered one of the most interesting methods in  the tree as it has same time complexity of binary search tree which is O(log n).
We have optained that Time complexity by having balanced tree.so we have constructed the tree by the way shown previous.
#### 3) insertion
After we have constructed our tree we wanted to insert a point.
That tree is not as red-black tree self balancing tree.so to guarantee our tree still balanced we search a point need to insert,then we extend a children
From the last traversed node .

## Referances
An interesting paper helped me to improve algorithm efficiency 

Russell A. Brown :Building a Balanced k-d Tree in O(kn log n) Time. Journal of Computer Graphics Techniques (JCGT), vol. 4, no. 1, 50-68, 2015.https://doi.org/10.48550/arXiv.1410.5420

I have made an open discussion about kd tree

1)Talking about the algorithm of that data structure and what problem has been solved by using that DS [https://drive.google.com/file/d/1vvEwUNimux1wrepcEbxDQ1a8Xyr5hniv/view?usp=sharing]

2)Talking about Algorithm insights and some methods{construction,search,insertion} [https://drive.google.com/file/d/1AhomqTLPO6xb35fBthFaT3mPR4hmdVAQ/view?usp=sharing]

