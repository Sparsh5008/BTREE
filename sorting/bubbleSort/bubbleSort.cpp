#include <iostream>
using namespace std;
void bubbleSort(int array[], int start, int end);
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

               bubbleSort(array,0,size-1);
             
               cout<<"sorted array --> ";
               printArray(array,0,size-1);	


}

void bubbleSort(int array[], int start, int end)
{
	 			
				

				for(int i=end;i>=start;i--)
				{
                   
                    for(int j=start;j<i;j++)
                    	{
                           //finding the correct value for the ith location
                   // 		cout<<"array[j] = "<<array[j]<<"array[j+1] = "<<array[j+1]<<endl;
                    		if(array[j]>array[j+1]) swap(array[j],array[j+1]);
                    //		cout<<"array[j] = "<<array[j]<<"array[j+1] = "<<array[j+1]<<endl;
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