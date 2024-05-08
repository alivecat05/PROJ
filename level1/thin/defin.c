#include<stdio.h>
#define NUM 10//define定义标识符常量
#define add(x,y) x*y//define 定义宏，有参数：宏名add；宏参：x，y；宏体
int main(){

    int a[NUM] = {1,2,3,4,5};
     int k=add(a[1],a[4]);
     printf("%d",k);
     return 0;
}