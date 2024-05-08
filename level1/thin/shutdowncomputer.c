#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char input[20]= {0};
    char target[] = "半糖小子";
again:
    system("shutdown -s -t 60");
    printf("你的电脑将在六十秒内关机,请输入“半糖小子”来取消操作\n");
    scanf("%s",input);
    if(strcmp(input,target)==0)
    {
        system("shutdown -a");
    }
    else
    {
    goto again;

    }
return 0;
}