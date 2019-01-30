#include <iostream>
using namespace std;
void stableSelectionSort(int array[], int start, int end);
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

               stableSelectionSort(array,0,size-1);
             
               cout<<"sorted array --> ";
               printArray(array,0,size-1);	


}

void stableSelectionSort(int array[], int start, int end)
{
	 			 //arr[0..i-1] is sorted and for element i we are locating smallest element in i to end
	             int minIndex;
               int temp;
	             for(int i=start;i<=end;i++)
	              {
	              	    minIndex =i;
                        for(int j=i;j<=end;j++)
                        {
                           if(array[j]<array[minIndex]) minIndex = j;    
                        }
                        if(minIndex!=i) 
                        {
                           //here we have to bring element at minIndex to location i
                          //shift i->i+1 .. minIndex-1->minIndex
                          temp = array[minIndex];
                          for(int j=minIndex-1;j>=i;j--)
                             array[j+1] = array[j];

                          //store temp in array[i]
                           array[i] = temp; 
                        }
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