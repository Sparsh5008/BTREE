#include <iostream>
using namespace std;
void two_way_merge_sort_bottomUp(int array[], int start, int end);
void merge(int array[], int start, int mid, int end);
void printArray(int array[], int start, int end);

int main()
{
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

               two_way_merge_sort_bottomUp(array,0,size-1);
             
               cout<<"sorted array --> ";
               printArray(array,0,size-1);	


}

void two_way_merge_sort_bottomUp(int array[], int start, int end)
{
	 			//bottomUp function to merge two arrays
				int current_list_size = 1;
				int left,right, mid;
				int i=start;
				int size = end-start+1;
				while(current_list_size<=size)
				{
								for(i=start;i<=end;i+=2*current_list_size)
									 {
									 	  //for a particular value of current_list_size
									 	  left = i;
									 	  mid = i+current_list_size-1;
									 	  right= (i+2*current_list_size-1);
					                      if(right>end) right=end;
					                      merge(array,left,mid,right);
									 }	
							     current_list_size=2*current_list_size;
				}
				


}

void merge(int array[], int start,int mid,int end)
{
	 if(start<=mid && mid<=end)
	 {
				//merging two arrays which are sorted on their own
				 int index1 = start;
				 int index2 = mid+1;
				 int size=end-start+1;

				 int buffIndex;
				 int buffer[size];
				// cout<<"_____________________________________________"<<endl;
				 //cout<<"merge called"<<endl;
				 //cout<<"calculated size = "<<size<<endl;
				// cout<<"mid = "<<mid<<" start="<<start<<" end="<<end<<endl;
			     //cout<<"array -->";
				// printArray(array,index1,mid);
				 //cout<<"array--> ";
				// printArray(array,mid+1,end);
				 for(buffIndex=0;buffIndex<size; buffIndex++)
				 {
				 	     if(index1<=mid)
				 	     {
				 	     	 if(index2<=end)
				 	     	 {
				 	     	 	 if(array[index1]<array[index2])
				 	     	 	 	buffer[buffIndex]=array[index1++];
				 	     	     else
				 	     	     	buffer[buffIndex]=array[index2++];
				 	     	 }
				 	     	else
				 	     	       buffer[buffIndex]= array[index1++]; 
				 	     }
				 	    else{
				 	    	 if(index2<=end) buffer[buffIndex]= array[index2++];
				 	    	 else
				    	 	 cout<<"situation cant arise..code is wrong";
				 	    } 
				 }

			     // cout<<"buffer--> ";
			     // printArray(buffer,0,size-1);
				 //copying into the original array
				  for(buffIndex = 0;buffIndex<size;buffIndex++)
				  	 {
				  	 	 array[start+buffIndex] = buffer[buffIndex];
				  	 }
				  // cout<<"___________________________________________"<<endl;	 
	 }
	
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