#include<stdio.h>
void task(int i,int j,int n)
{
    while(i<=n)
    {
	j=1;
    	while(j<=i)
		{
			printf("%dx%d=%d ",j,i,i*j);
			if(i*j<10)
			{
            printf("   ");
			}
			else
			{
			printf(" ");
			}	
		     j++ ; 
			} 
	if(i<n)	{
	printf("\n");
	}	
			i++;	
	}
}
int main()
{
	int i=0;
	int j=0;
    int n;
    scanf("%d",&n);
    task(i,j,n);
	return 0;
 } 