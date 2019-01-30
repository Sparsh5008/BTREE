#include "btree.h"
#include "node.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

BTREE::BTREE()
{
              //root is created
	      root = new node;
	      root->isLeaf = true;
	      root->numKeys = 0;
	      root->parent = NULL;
}

void BTREE::insertNonFull(node* subTree,int k,node* pointer)
{
	assert(!subTree->isFull());
	int i;
	 //find the correct location for k
	cout<<"@: "<<"insert in nonfull called with "<<k<<"on a non full node"<<endl;
	for(i=0;i<subTree->numKeys && subTree->key[i]<k; i++);
	//i is the index of insertion
	//shift the values 
	 for(int j=subTree->numKeys-1;j>=i;j--) subTree->key[j+1] = subTree->key[j];
	 if(pointer){
	                 for(int j=subTree->numKeys;j>i;j--) subTree->child[j+1] = subTree->child[j]; 	
                     subTree->child[i+1] = pointer;
                     pointer->parent = subTree;
	 }
     subTree->key[i] = k;
     subTree->numKeys++;
}

void BTREE::insert_with_query(node* subTree, int k)
{
          int i;
          for(i=0;i<subTree->numKeys && subTree->key[i]<k; i++);
          if(i<subTree->numKeys && subTree->key[i] == k) {
          	cout<<"not allowed to insert duplicates"<<endl;
          	return;
          }
          //other wise key[i]> k
          if(!subTree->isLeaf) insert_with_query(subTree->child[i],k);
          else {
          	//now node subTree is leaf node	
                  	iterative_accomodate(subTree,k, NULL);
          }
}

void BTREE::iterative_accomodate(node* subTree, int k, node* pointer)
{
          //iterative version of the function accomodate
	 node* p;
	 int median;
     assert(subTree);
	 //this function accomodates a key and pointer p into a given node
	 while(subTree)
	 {

	 	  if(!subTree->isFull())
			      {
			      	 //if the node is not full then proceed to insert the value k into the node
			      	  cout<<"@: "<<"iterative_accomodate called with "<<k<<"and pointer "<<p<<endl;
			      	  insertNonFull(subTree,k,pointer);
			      	  return;
			      }   
    	
    	      else{
    	      	           //if the subTree is full
    	      	           /*first try to make query and adjust if possible*/

                                if(query(subTree,k,pointer)) 
                                {
                                cout<<"@: "<<"query succeded"<<endl; 	
                                return; //if query can settle it
                                }


    	      	             /*now since query has failed split is mandatory*/
				     	     p = subTree->splitNode();  
				     	     median = subTree->key[T-1];
				     	    if(subTree == root)
				     	         {
				     	         	         //if the subTree is root handle separately
				     	    	               cout<<"@: "<<"iterative_accomodate called with root node and key = "<<k<<"and pointer "<<p<<endl;;
				                               node *newRoot = new node;
				                               newRoot->child[0] = root;
				    	    	               subTree->parent = newRoot;
				    	    	               root = newRoot;
				    	    	               insertNonFull(root,median,p);
				    	    	               if(k > median)  insertNonFull(p,k,pointer);
						     	               else insertNonFull(subTree,k,pointer);
				    	    	               cout<<"root has been changed to"<<root<<endl;
				                               return;

				     	         }
				     	    else{
				     	    	    //for non root node
						     	    if(k > median)  insertNonFull(p,k,pointer);
						     	    else insertNonFull(subTree,k,pointer);
						     	    //process the parent with median and p
						     	    subTree= subTree->parent;
						     	    k = median;
						     	    pointer = p;
				     	        }   

                } 
	 }
   
}

bool BTREE::query(node* subTree, int median, node* p)
{
	             int i;
	             cout<<"@: "<<"query made with median = "<<median<<"pointer = "<<p<<endl;
  	            if(subTree->parent)
  	            {
  	            	 int temp;
  	            	//if we have a non NULL parent
  	            	node* par = subTree->parent;
  	            	for(i=0;i<par->numKeys && par->key[i]<subTree->key[0]; i++);
  	            	//the sibLings are located at i+1 and i-1
  	           
  	            	if(i-1>=0 && !par->child[i-1]->isFull()){
  	            		         //left sibling is non full
  	            		  	       cout<<"@: "<<"query entertained a left transfer"<<endl;
  	            		           leftTransfer(par, median,p,i); 
  	            		           return true;
  	                    	  }
  	                else if( i+1<=par->numKeys && !par->child[i+1]->isFull() )
  	                    {
  	                    	  	 cout<<"@: "<<"query entertained a right transfer"<<endl;
  	                             rightTransfer(par,median,p,i);
  	                    	    	return true;
  	                    }     	  
  	                 else return false;  

  	            }
  	           else
  	               return false; 

}

void BTREE::leftTransfer(node* par, int median,node* p,int i)
{
				  assert(i-1>=0);
				  //we have to transfer the content of ith child to the i-1 th child of a parent par
				  assert(!par->child[i-1]->isFull()) ; //the left child must not be full

                  //initializing some variables
                 int temp;
                 node* subTree = par->child[i];
                 node* leftChild = par->child[i-1];
                 node* pointer = subTree->child[0];;
	             temp = par->key[i-1]; //here the parent is the index i-1
	             par->key[i-1] = subTree->key[0];

                //if median is less than the smallest value in the subtree
	             if(median<subTree->key[0])
	             {
	                        par->key[i-1] = median;
	                        leftChild->numKeys++;
	                        leftChild->key[leftChild->numKeys-1] =temp;
	                        leftChild->child[leftChild->numKeys] = subTree->child[0];
	                        if(subTree->child[0])
	                        subTree->child[0]->parent = leftChild;

	                        subTree->child[0] = p;
	                        if(p)
	                        p->parent = subTree;
	                        return;
	             }
	             //adjusting the subTRee.. here the median is not less than the smallest number 
	             for(int j=1;j<subTree->numKeys;j++) subTree->key[j-1] = subTree->key[j];
	             for(int j=1;j<=subTree->numKeys;j++) subTree->child[j-1] = subTree->child[j]; // shifting the children
	             subTree->numKeys--; 
	             //adjusting the left child
	             leftChild->key[leftChild->numKeys] = temp;
	             leftChild->child[leftChild->numKeys + 1] = pointer;
	             if(pointer)
	             pointer->parent = leftChild;
	             leftChild->numKeys++;
	             insertNonFull(subTree, median,p);

}

void BTREE::rightTransfer(node* par, int median,node* p,int i)
{			      assert(i+1<=par->numKeys);
				  //we have to transfer the content of ith child to the i-1 th child
				  assert(!par->child[i+1]->isFull()) ; //the left child must not be full

                 int temp;
                 node* subTree = par->child[i];
                 node* rightChild = par->child[i+1];
                 node* pointer = subTree->child[subTree->numKeys];
	             temp = par->key[i]; //here the parent is the index i-1
	             par->key[i] = subTree->key[subTree->numKeys-1];
                 //shift values to the right in the right child
                 for(int j=rightChild->numKeys-1;j>=0;j--) rightChild->key[j+1] = rightChild->key[j];
                 for(int j=rightChild->numKeys;j>=0;j--) rightChild->child[j+1] = rightChild->child[j];	
                //shifted the pointers one place
                 rightChild->numKeys++;
                 rightChild->key[0] = temp;
	             if(median>subTree->key[subTree->numKeys-1])
	             {
	                        par->key[i] = median;
                            rightChild->child[0] = p;
                            if(p)	
                            p->parent = rightChild;
	                        return;
	             }
	             //adjusting the subTRee.. here the median is not greater than the larger number
                else
                {
                             subTree->numKeys--; 
                             rightChild->child[0] = pointer;
                             if(pointer)
                             pointer->parent = rightChild;
                             //adjusting the left child
	                        insertNonFull(subTree, median,p);
                }	             

	      
	                     


}
void BTREE::postOrder(node* p, int depth)
{
          int numNodes = p->numKeys;
          if(!p->isLeaf)
           {
                   //first print the children
                 for(int i=0;i<=numNodes;i++)
                  {
                       postOrder(p->child[i],depth+1);
                  } 

           }
          //print the node p
          p->printNode(depth); 

}
void BTREE::postOrderTrav()
{
          if(root) postOrder(root,0);
}

void BTREE::insertKey(int k)
{
            insert_with_query(root,k);
}
int BTREE::height()
{
            return heightOfSubTree(root);
}
int BTREE::heightOfSubTree(node* subTree)
{
          if(!subTree->isLeaf)
          	       return 1 + heightOfSubTree(subTree->child[0]);
          else     return 1;

}

