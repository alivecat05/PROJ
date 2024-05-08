#include<stdio.h>
#include<string.h>
//左移有x2的效果，左移右移操作符只针对整数，对浮点数无效 

//不创建临时变量，实现两个数交换
//a^a = 0;
//0^a = a;
//异或操作符支持交换律
// int main()
// {
//     int a =3;
//     int b=5;
//     printf("a=%d,b=%d\n",a,b);
//     a =a ^ b;//3^5
//     b = a^ b;//3^5^3=5
//     a = a^ b;//3^5^5 =3;
//     printf("a=%d,b=%d\n",a,b);
//     return 0;
// }

//求补码的二进制中1的个数
// int count_one_bit(int n)
// {
// 	int count = 0;

// 	while(n)
// 	{
// 		n = n&(n-1);

// 		count++;
// 	}
// 	return count;
// }

// int main()
// {
//         int a = 6;//0000000000101  5
//                   //0000000000100  4
//                   //0000000000100  4
//                   //0000000000011  3
//                   //0000000000000  0
//         int cnt = count_one_bit(a);
//         printf("%d",cnt);
//     return 0;
// }


// int main()
// {
//     int a =3;
//     int b=++a;
//     //++a 先++，后使用，即a自增1，再赋值给b
//     //a++ 先使用后++
//     // 在for循环中没有太大区别
//     //在指针中不论什么类型的数据都是占4个字节
//     printf("%d ",a++);//3
//     printf("%d",a);//4
//     printf("%d ",a);
//     printf("%d",b);

//     return 0;
// }

// int main()
// {
//     //变量本身为零，即为假，正数负数为真
//     int i=0,a=0,b=-2,c=3,d=4;
//     // i = a++ && b++ && d++;
//     //与操作符，&&有一假为假其余都不算
//     i = a++ || ++b | d++;
//     //或操作符，有一真则后面都不算
//     printf("a=%d\nb=%d\nc=%d\nd=%d\n",a,b,c,d);
//     return 0;
// }

//三目操作符
// int main()
// {
//     int a =3;
//     int b =5;
//     int max = (b>a)?b:a;
//     printf("%d",max);
//     return 0;
//  }

//逗号表达式
//从左到右依次计算，最后一个表达式的结果就是该逗号表达式的结果
// int main()
// {
//     int a=10;
//     int b=2;
//     int c=(a>b,a=b+10,b=a+b,a+b);
//     printf("%d",c);
//     return 0;
// }

///[]操作符
// int main()
// {
//     int arr[10] = {0};
//     arr[7]=8;//尽量这样写
//     7[arr] = 9;
//     //实质不论是arr[7]还是7[arr]都是*(arr+7)/*(7+arr) 支持交换
//     return 0;
// }
// #include<string.h>
// //结构体/
// //节省内存空间
// struct stu 
// {
//     char c[10];
//     int name;
//     int age;
// };
// void set_struct(struct stu *ss)
// {
//     strcpy( (*ss).c,"abcdefg"); 
//     (*ss).age = 10;
//      (*ss).name = 123;
// }
// void print(struct stu *s)
// {
//     printf("%s %d %d ",(*s).c,(*s).age,(*s).name);
// }
// int main()
// {
//     struct stu s={0};
//     set_struct(&s);
//     print(&s);
    
//     return 0;
// }

//求两个数二进制中不同位的个数
// int count_bits(int m,int n)
// {
//     int temp = m^n;
//     int cnt=0;
//     while(temp)
//     {
//         temp =temp&(temp-1);
//         cnt++;
//     }
//     return cnt;
// }
// int main()
// {
//     int m =0;
//     int n =0;
//     int count =0;
//     while(scanf("%d %d",&m,&n))
//     {
//         count = count_bits(m,n);
//         printf("%d",count);
//     }
//     return 0;
// }




//打印整数二进制的奇数位和偶数位
// int main()
// {
// int num = 10;//1010
// int i=0;
// printf("奇数位=");
// for(i=31;i>=1;i-=2)
// {
//     int k =0;
//     k=num>>i&1;
//     printf("%d",k);
// }
// printf("\n");
// printf("偶数位=");
// for(i=30;i>=0;i-=2)
// {
//     int k =0;
//     k=num>>i&1;
//     printf("%d",k);
// }
//     return 0;
// }


// #include<math.h>
// #include <stdio.h>
// int main()
// {
// int a =0;
// scanf("%d",&a);
// int sum=0;
// for(int i=0;i<5;i++)
// {
//      int temp;
//     // 2*10+ 2*10+2 + 2*10*10+2*10+2 +2*10*10*10+2*10*10+2*10+2
//    temp+=a*pow(10,i)  ;
// sum+=temp;
    
// }
// printf("%d",sum);
//     return 0;
// }
void print(int *arr,int sz)
{
    for(int i=0;i<sz;i++)
    {
        printf("%d ",*arr);
        *arr++;
    }
}
int main()
{

    int arr[] = {1,23,45,6,7,78,9};
    int sz = sizeof(arr)/sizeof(arr[0]);
    print(arr,sz);
    return 0;
}