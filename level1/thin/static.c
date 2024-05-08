#include<stdio.h>
typedef unsigned int uint;
/*static修饰局部变量
使用static使得a在每次循环后不会重新定义
static修饰局部变量的时候，局部变量出了作用域，不销毁
本质上static修饰变量的时候改变了变量的存储位置
使变量的生命周期变长*/

/*static修饰全局变量
该全局变量的外部连接属性就变成了内存连接属性
即，其他源文件都不可以使用这个全局变量
*/

/*static修饰函数
类似于全局变量，链接属性导致的无法具有外部链接属性
*/
void test(void){
    static int a =1;  
    a++;   
    printf("%d",a);
}
extern int add(int x,int y);
int main()
{
    uint a = 10;
    printf("%d",a);
    int i =0;
    while(i<10){
        test();
        i++;
    }

    return 0;
}