#include <iostream>
using namespace std;
void stable_quickSort(int array[], int start, int end);
void printArray(int array[], int start, int end);
int partition_with_stability(int array[],int start,int end);
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

               stable_quickSort(array,0,size-1);
             
               cout<<"sorted array --> ";
               printArray(array,0,size-1);	


}


void stable_quickSort(int array[], int start, int end)
{
        //bottomUp function to merge two arrays
        

         int pivotIndex;

         if(start<end)
           {
              pivotIndex = partition_with_stability(array,start,end);
              stable_quickSort(array, start,pivotIndex-1);
              stable_quickSort(array,pivotIndex+1, end);
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


int partition_with_stability(int array[], int start, int end)
{
         if(start<end)
         {
                   int pivot = array[end];
                  int buffer[end-start+1];
                  int count=0;

                  int leftIndex=-1;
                  //count the number of elements which are less than or equal to the pivot
                  for(int i=start;i<=end;i++) if(array[i]<=pivot) count++;
                 
                  int pivotIndex = count-1;
                  
                  int rightIndex = pivotIndex;

                
                  //scan the original array
                  for(int i=start;i<=end;i++)
                   {
                          if(array[i]<=pivot)  buffer[++leftIndex]=array[i];
                          if(array[i]>pivot)   buffer[++rightIndex]=array[i];
                   }

                  //copy back
                  for(int i=start;i<=end;i++)
                    array[i] = buffer[i-start];  
                    return start+pivotIndex; 
         }
        if(start==end) return end;
         
}