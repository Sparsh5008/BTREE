#ifndef NODE_H
#define NODE_H
#define T 2

class node{
	       public:
            int key[2*T-1];
            node* child[2*T];
            int numKeys; 
            bool isLeaf;
            node* parent;
            node();
            bool isFull();
            void printNode(int depth);
            node* splitNode();
 };
#endif //NODE_H