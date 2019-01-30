#ifndef BTREE_H
#define BTREE_H

#include "node.h"

class BTREE{
	         public:
              node* root;
              BTREE();
              void insertKey(int k);
              void insertNonFull(node* subTree,int k, node* pointer);
              void insert_with_query(node* subTree, int k); //insert key k into a subtree 
              void iterative_accomodate(node* root,int k, node* pointer);
              bool query(node* subTree, int median, node* p);
              void postOrder(node* p, int depth);
              void leftTransfer(node* par, int median,node* p,int i); //from child i to i-1
              void rightTransfer(node* par, int median,node* p,int i); //from child i to i+1
              void postOrderTrav();
              int height();
              int heightOfSubTree(node* subTree);
};

#endif //BTREE_H