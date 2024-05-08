#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
//此程序实现一个简单的登录界面
int main()
{
int cnt=0;
char arr[] = {0};
char target[]= "1234";
int n = sizeof(target)/sizeof(target[0]);
for(int i=0;i<n-1;i++)
{
 printf("please input password:");
 scanf("%s",arr);
  if(strcmp(target,arr)==0){
        printf("password correct!!");
        break;
    }
    else if(strcmp(target,arr)!=0){
        if(i<2){
        printf("password wrong\n");
        printf("please input again");
        Sleep(1000);
        system("cls");
        }
       
        if(i==2){
            printf("Fail");
            break; 
}
    }
}

return 0;
}