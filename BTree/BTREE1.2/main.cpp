#include <iostream>
#include "node.h"
#include "btree.h"
using namespace std;
int main()
{
              BTREE* b = new BTREE;

              // testing the software
              int val;
              while(cin>>val)
              {
              	    b->insertKey(val);
                    cout<<"__________________________________________________"<<endl;
              	    b->postOrderTrav();
              	    cout<<"__________________________________________________"<<endl;
              }

 
                 //printing the output

                   cout<<"__________________________________________________"<<endl;
                   cout<<"height of the tree is "<<b->height()<<endl;    
}