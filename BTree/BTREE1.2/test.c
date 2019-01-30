#include <stdio.h>
#include <stdlib.h>
int main()
{
	   FILE* fp;
       fp = fopen("input.txt","w");

       long long int i;
scanf("%lld",&i);

        while(i--)
         {
               fprintf(fp,"%d\n",rand()%1000000);
         }
           fclose(fp);
}
