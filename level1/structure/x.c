#include<stdio.h>
int main()
{
    int len =9;
    int i=0,j=0;
    int arr[i][j];
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            if(i==j)
            {
                arr[i][j]='*';
                printf("%c",arr[i][j]);
            }
            else if(j==len-i-1)
            {
               arr[i][j]='*';
                printf("%c",arr[i][j]); 
            }
            else{
                printf(" ");
            }
        }

printf("\n");
    }
    return 0;
}