#include <iostream>
using namespace std;
void selectionSort(int array[], int start, int end);
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

               selectionSort(array,0,size-1);
             
               cout<<"sorted array --> ";
               printArray(array,0,size-1);	


}

void selectionSort(int array[], int start, int end)
{
	 			 //arr[0..i-1] is sorted and for element i we are locating smallest element in i to end
	             int minIndex;
	             for(int i=start;i<=end;i++)
	              {
	              	    minIndex =i;
                        for(int j=i;j<=end;j++)
                        {
                           if(array[j]<=array[minIndex]) minIndex = j;    
                        }
                        if(minIndex!=i) swap(array[minIndex],array[i]);
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