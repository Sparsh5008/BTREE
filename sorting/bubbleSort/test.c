#include <stdio.h>
#include <stdlib.h>
int main()
{
	       FILE *fp;
	       fp = fopen("input.txt","w");

           int x;
	       scanf("%d",&x);

	       fprintf(fp, "%d\n", x);

	       while(x--)
	       {
	       	   fprintf(fp, "%d\n",rand()%100);
	       }

	       fclose(fp);
}