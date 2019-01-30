#include <iostream>
using namespace std;
void unstable_quickSort(int array[], int start, int end);
void printArray(int array[], int start, int end);
int normal_partition(int array[],int start,int end);
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

               unstable_quickSort(array,0,size-1);
             
               cout<<"sorted array --> ";
               printArray(array,0,size-1);	


}

void unstable_quickSort(int array[], int start, int end)
{
	 			//bottomUp function to merge two arrays
				

				 int pivotIndex;

         if(start<end)
           {
              pivotIndex = normal_partition(array,start,end);
              unstable_quickSort(array, start,pivotIndex-1);
              unstable_quickSort(array,pivotIndex+1, end);
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

int normal_partition(int array[],int start,int end)
{
                   //select a pivot element
                   int pivot= array[start];
                   int lower = start+1;
                   int upper = end;
                   while(lower<=upper)
                   {
                        
                           while(pivot>array[lower]) lower++;
                           while(pivot<array[upper]) upper--;

                           if(lower<upper)
                             swap(array[lower],array[upper]);
                           else
                              lower++;
                   }

                  //partitioned..
                   swap(array[start],array[upper]);
                  return upper; 
}

