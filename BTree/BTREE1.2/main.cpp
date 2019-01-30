#include <iostream>
#include "node.h"
#include "btree.h"
using namespace std;
int main()
{
              BTREE* b = new BTREE;

              int val;
              while(cin>>val)
              {
              	    b->insertKey(val);
                    cout<<"__________________________________________________"<<endl;
              	    b->postOrderTrav();
              	    cout<<"__________________________________________________"<<endl;
              }

 


                   cout<<"__________________________________________________"<<endl;
                   cout<<"height of the tree is "<<b->height()<<endl;    
}