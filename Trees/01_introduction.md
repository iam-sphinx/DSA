INTRODUCTION OF TREE MODULE

TREE - A heirarchical data structure.

BINARY TREE - Binary Tree is a tree in which any node consist of at most two node.


            ( ) ---> Root
            / \
          ( ) ( ) ---> Children
          /   / \
         ( ) ( ) ( )
           \     /
            ( ) ( )
            /
           ( ) ---> Leaf Node

IMPORTANT TERMINOLGY - 
Root : A node which does not have any parent.
Leaf : A node which does not have any child.
Children : A node is a children of its parent node.
Parent : A node is parent of its children node.
Sub Tree : A node and a tree beneth it is called sub tree of a node.
Ancesters : Upside heirarchy of parent, grand parents, ...  are called ancestors of a node.

TYPES OF BINARY TREE - 
1> Full Binary Tree - Either 0 or 2 children.
        ( )
        / \
      ( ) ( )
      / \
    ( ) ( )

2> Complete Binary Tree - All levels are completely filled and last level as left as possible.
        ( )
        / \
      ( ) ( )
      / 
     ( )

3> Perfect Binary Tree -  All leaf nodes are at same level.
        ( )
        / \
      ( ) ( )
      /     \ 
     ( )    ( )  

4> Balanced Binary Tree - Max Height should be log(n) of base 2 where n is number of node.

5> Degenerate Binary Tree - Skew Tree.
        ( )
        /
       ( )
       /
      ( )
