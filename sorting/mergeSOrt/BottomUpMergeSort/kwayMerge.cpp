#include <iostream>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;
void k_way_merge_sort_bottomUp(int array[], int start, int end,const int k);
void merge(int array[], int start,int end, const int k,int list_size);
void printArray(int array[], int start, int end);

int main()
{
	          int k;
	          cin>>k;

              int size;
              cin>>size;

              int i=0;
              //reading the array
              int array[size];
              while(cin>>array[i])
              	 i++;

              //before sorting 
               cout<<"unsorted array --> ";
               printArray(array,0,size-1);

               k_way_merge_sort_bottomUp(array,0,size-1,k);
             
               cout<<"sorted array --> ";
               printArray(array,0,size-1);	


}

void k_way_merge_sort_bottomUp(int array[], int start, int end,const int k)
{
	 			//bottomUp function to merge two arrays
				int current_list_size = 1;
				int i=start;
				int left,right;
				int size = end-start+1;
				int j;
				while(current_list_size<=size)
				{
								for(i=start;i<=end;i+=k*current_list_size)
									 {
					  				 	  //for a particular value of current_list_size
	                                      left=i;
	                                      right=i+k*current_list_size-1;
	                                      if(right>end) right=end;                     
					                      merge(array,left,right,k,current_list_size);
									 }	
							     current_list_size=k*current_list_size;
				}
				


}

void merge(int array[], int start,int end, const int k,int list_size)
{
                     //     cout<<"____________________________________________________"<<endl;
             //initializing the index array
            // cout<<"merge called with start= "<<start<<"end = "<<end<<" list_size = "<<list_size<<")"<<endl;
			 
			 //duty of merge is to merge lists given list size

             //determine the number of lists
             //clearly the number of lists will be atmost k
             int size = end - start + 1;
             int numLists = size/list_size;
             if(size%list_size != 0) numLists++; 
             //cout<<"numLists = "<<numLists<<endl;
             //cout<<"size = "<<size<<endl;
             //there are numList such nonempty lists that we have to merge
             int left_index[numLists];
             int right_index[numLists];
             int running_index[numLists];

             //initializing the arrays of indices
             for(int i=0;i<numLists;i++)
              {
				  left_index[i]=start+i*list_size;
				  right_index[i]=left_index[i]+list_size-1;
				  running_index[i]=left_index[i];    				
              }             
             //since the last list could possibly be of size less than the list_size
              if(right_index[numLists-1]>end) right_index[numLists-1] = end;
             //cout<<"left_index --> ";printArray(left_index,0,numLists-1);
             //cout<<"right_index --> ";printArray(right_index,0,numLists-1);
             //cout<<"running_index --> ";printArray(running_index,0,numLists-1);
              //now the task of merging begins
              int buffer[size]; //creating a buffer of size equal to size
              //storing values into buffer
              int buffIndex = 0;
              int min;
              int j;
              //cout<<"int max is "<<INT_MAX<<endl;
              for(buffIndex=0;buffIndex<size;buffIndex++)
              {
              	  //finding the minimum of the values amongst the running indices
              	   min=INT_MAX;
              	  for(int i=0;i<numLists;i++)
              	   {
                        if(running_index[i]<=right_index[i]) 
                        	if(array[running_index[i]]<min)
                        	 {
                        	 	j=i;
                        	 	min=array[running_index[i]];
                        	 } 
              	            
              	    }
              	           //cout<<"j = "<<j<<endl; 
                           running_index[j]++;
              	  //now store the value in buffer
              	  buffer[buffIndex] = min; 
              }
             // cout<<"buffer--> ";printArray(buffer,0,size-1);
              //copy it to the original array
              for(buffIndex=0;buffIndex<size;buffIndex++)
              {
              	 array[start+buffIndex]=buffer[buffIndex];
              }
            //  cout<<"_______________________________________________________________"<<endl;
}  

void printArray(int array[], int start,int end)
{
	        int i;
	       cout<<"(";
	       	if(start<=end)
	       	{
	        for( i=start;i<end;i++)
	       	 {
	       	 	 cout<<array[i]<<",";
	       	 }
	       	 cout<<array[i]<<")"<<endl;
	       	}

}