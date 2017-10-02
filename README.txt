Author: Jack Chen
Project 2 
CSCI 33500

The assignment was fully completed.

Errors/Known Bugs:
The values outputted by BST and AVL trees are nearly identical, expect for:
BST 5b (8.6% relative error) 
AVL 5b (9.3% relative error)
AVL 6b and 6c (1.8% relative error)

Other Notes:
Within the two tree's I've made the following modifications...

1) For the equal condition in the insert() method, a merge function was added. 
Therefore, the trees now work under the assumption that the element is 
both comparable AND mergable.

2) Addition of the following methods to the trees:
  i) totalNode() 
  ii) averageDepth()
  iii) totalRecursiveCalls()
