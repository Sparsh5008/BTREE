#include "node.h"
#include <iostream>
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;


node::node()
{
	  numKeys = 0;
	  isLeaf = false;
	  parent = NULL;
}
void node::printNode(int depth)
{
     cout<<"(";
     for(int i=0;i<numKeys-1;i++)
       {
            cout<<key[i]<<",";
       }
       cout<<key[numKeys-1];
       cout<<" "<<"leaf_status = "<<isLeaf;
       cout<<" "<<"numkeys = "<<numKeys;
       cout<<" "<<"depth = "<<depth;
       cout<<" "<<"full_status = "<<isFull();
       if(parent == NULL)
       	cout<<" "<<"parent = NULL"<<")"<<endl;
       else
        cout<<" "<<"parent = NonNULL"<<")"<<endl;

}

bool node::isFull()
{
	    if(numKeys == 2*T-1) return true;
	    else return false;
}

node* node::splitNode()
{
	       assert(this->isFull());
	       cout<<"@: "<<"splitNode called "<<endl;
	       node * p = new node ; //we have created a new node
     	   p->numKeys = T-1;
     	   this->numKeys = T-1;
     	   //pass the children to the node p
     	   //T children with first one and T with the next
     	   for(int j=0;j<T; j++)
     	 	            p->child[j] = this->child[j+T];
     	 //pass the keys // first T-1 Keys on one side and one is the median and remaning on the other side
     	   for(int j=0; j<T-1; j++)
     	 	            p->key[j] = this->key[j+T];
     	    p->isLeaf = this->isLeaf ;
     	   
     	    return p;
}

