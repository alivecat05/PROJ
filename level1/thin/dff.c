#include<stdio.h>
#include<assert.h>
void strcapy(char* dest,char* src)
{
    assert(src!=NULL);
    assert(dest!=NULL);
    while(*src++=*dest++)
    {
        ;
    }
}
int main()
{
    char arr1[] ="abcdefg";
    char arr2[] = "xxxxxxxxxxxxxxxx";
    strcapy(arr1,arr2);
    printf("%s",arr2);
return 0;
}