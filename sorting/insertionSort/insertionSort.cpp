#include <iostream>
using namespace std;
void insertionSort(int array[], int start, int end);
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

               insertionSort(array,0,size-1);
             
               cout<<"sorted array --> ";
               printArray(array,0,size-1);	


}

void insertionSort(int array[], int start, int end)
{
	 			
                //we assume that arr[0..i-1] is sorted
                 int temp;
                 int j;
                 for(int i=start+1;i<=end;i++)
                   {
                      //find the currect location of arr[i] in the array[0..i-1]
                      if(array[i]<array[i-1])
                      {
                               temp = array[i];
                               j = i-1;
                               while(j>=start && array[j]>temp)
                               {
                                   array[j+1]= array[j];
                                   j--;
                               }
                               array[j+1] = temp;

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