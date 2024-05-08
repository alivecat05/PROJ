#include<stdio.h>
#include<assert.h>
int mystrlen(const char*str)//严格限制str内容不改变
{
    int cnt =0;
    assert(str!=NULL);//断言
    while(*str!='\0')
    {
        cnt++;
        str++;
    }
    return cnt;
}
int main()
{
    char arr2[]="adadadadad";
    int len = mystrlen(arr2);
    printf("%d",len);
    return 0;
}