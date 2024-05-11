#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//数组指针vs指针数组
    //数组指针，指向的是一个数组的地址
    //指针数组，其实是存放指针的数组，即该数组的元素是地址
    //实际上可以用二位数组来模拟指针数组因为我们知道，*(arr+1) 等于 arr[i],*(arr[i]+j) = arr[i][j]
    //但实际上二维数组与二级指针稍有不同，二维数组元素的地址是连续的，但二级指针指向的分别指向的地址不一定连续
    //二级指针，指向的是一级指针的地址
//数组名vs&数组名
    //我们知道数组名就是数组首元素的地址
    //而&数组名，其实整个数组的地址
    // arr+1,首元素下一个元素的地址，int跳过4个字节
    // &arr+1，跳过整个数组所有字节，后内存单元的地址


// void print1(int arr1[3][5],int r,int c)
// {
//     int i;
//         for(int i=0;i<3;i++)
//     {
//         for(int j=0;j<5;j++)
//         {
//             printf("%d ",arr1[i][j]);
//         }
//         printf("\n");
//     }
// }

// void print2(int (*arr)[5], int row, int col)
// {
//     int i = 0;
//     for(i=0; i<row; i++)
//     {
//         for(int j=0; j<col; j++)
//         {
//         printf("%d ", *(*(arr+i)+j));//arr二维数组名是指向行的地址，arr+i即下一行的地址
//                                      //*（arr+i）即该行首元素的地址，*(arr+i)+j即该行元素的地址
//                                      //所以，*(*(arr+i)+j)为该行的元素
//         }
//     printf("\n");
//     }
// }
// int main()
// {   
//     //一级指针
//     int a = 10;
//     int *pa = &a;
//     //二级指针
//     int**pp = &pa;
//     //数组指针
//     int arr[] = {1,2,3,4};
//     int (*p)[4] = &arr;
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     for(int i =0;i<sz;i++)
//     {
//         printf("%d ",*(*p+i));//p指向整个数组，*p相当于数组名，所以*p是数组首元素的地址
//                                 //*p+i仍然是地址，所以访问地址下内容仍然要*((*p+i))
//     }
//     printf("\n");
//     int arr1[3][5] = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
//     print1(arr1,3,5);
//     printf("\n");
//     print2(arr1,3,5);
// return 0;
// }



//数组参数，指针参数
    //只要类型匹配的上都行

//函数指针

    // int Add(int x,int y)
    // {
    //     return x+y;
    // }
    // int main()
    // {
    //     int x =10;
    //     int y =100;
    //     int ans =Add(x,y);
    //     //&函数名，取出的就是函数的地址
    //     printf("%p ",&Add);
    //     //&函数名与函数名都是函数的地址
    //     int (*pf)(int,int) =&Add;
    //     //(*(void(*)())0)
    //     //(int ,int)函数参数的类型
    //     //作用利用指针来调用数组
    //     int ans1 = (*pf)(x,y);
    //     printf("%d",ans); 
    //     return 0;
    // }

    // typedef void(*pf_t)(int)
    // int main1()
    // {
    //     void(*/*signal(int,void(*)(int))*/)(int);
    //     void(*signal(int,void(*)(int)))(int);
    //     pf_t signal(int,pf_t);
    //     return 0;
    // }
//函数指针的实际案例（回调函数）
// void menu()
// {
//     printf("************************\n");
//     printf("*******1+,2-,3*,4/******\n");
//     printf("************************\n");
//     printf("************************\n");
//     printf("************************\n");
// }
// int add(int x,int y)
// {
//     return x+y;
// }
// int Dec(int x,int y)
// {
//     return x-y;
// }
// int Mul(int x,int y)
// {
//     return x*y;
// }
// int Div(int x,int y)
// {
//     return x/y;
// }
// void cal(int(*p)(int ,int))
// {
//     int x=0,y=0;
//     int ans =0;
//     printf("input 2 numbers:>");
//     scanf("%d %d",&x,&y);
//     ans =p(x,y);
//     printf("%d\n",ans);
// }
// int main()
// {   
//     int ret =0;
//     int input =0;
//     int (*arr[])(int,int) = {0,add,Dec,Mul,Div};//转移表
//     do
//     {
//             menu();
//             printf("select:>");
//             scanf("%d",&input);
//         if(input==0)
//         {
//             printf("goodbye");
//             break;
//         }
       
//         else if(input>=1&&input<=4)
//         {   
//             int x=0;int y=0;
//             printf("input two nums:>");
//             scanf("%d %d",&x,&y);
//             ret = arr[input](x,y);
//             printf("%d\n",ret);
//         }
//         else
//         {
//             printf("input again/n");
//             continue;
//         }
//     }while (input);
//     return 0;
// }

//函数指针数组
    // 参考上例
    //若有函数返回类型相同，函数参数类型相同的若干个函数
        // 可以把他们放在一个函数指针数组当中
        //int (*arr[4])(int,int) = {add,Dec,Mul,Div};

        //可以简化代码，当我们功能非常多的时候，不可能一直再switch case这是我们就需要
        //函数指针数组

//回调函数
    // callback()
        // void*指针如何解引用
            // 无具体类型，可以接收任何类型的指针。
            //但不能解引用也不能+-整数
            //当在使用，需要访问数据时，强制类型转换为所需类型
// void test();
// int cmp(void*p1,void*p2)//p1,p2分别指向两个参数 
// {
//     return (*(int*)p2-*(int*)p1);
// }
// int main()
// {
//     int arr[]={1,5,2,7,8,1,23,19,9};
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     qsort(arr,sz,sizeof(arr[0]),cmp);
//     int i=0;
//     for(i=0;i<sz;i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     // qsort(void*base,size_t num,size_t width,int(*cmp)(const void*p1,const void*p2));
//                                                 //    cmp()函数针对不同的数据类型
//     printf("\n");
//     test();
//     return 0;
// }
// struct Stu
// {
//     char name[20];
//     int age;
// };
// int cmp_struct_byname(const void*p1,const void*p2)
// {
//     return ((struct Stu*)p1)->age-((struct Stu*)p2)->age;
// }
// void test()
// {
//     struct Stu S[] = {{"zhangsan",90},{"lisi",15},{"wangwu",78}};
//     int sz = sizeof(S)/sizeof(S[0]);
//     qsort(S,sz,sizeof(S[0]),cmp_struct_byname);
// }

//手动模拟冒泡排序
int cmp(const void * p1, const void * p2)
{
        return *( int *)p1 - *(int *) p2;
}

void Swap(void*buf1,void*buf2,int width)
{
    for(int i=0;i<width;i++)
    {
        char temp = *((char* )buf1+i);
        *((char* )buf1+i) = *((char* )buf2+i);
        *((char* )buf2+i) = temp;
        // buf1++;
        // buf2++;
    }
}
void bubble(void* base,int num,int width,int(*cmp)(const void* ,const void* ))
{
    int i =0;
    int j =0;
    int flag = 1;
    for(i=0;i<num;i++)
    {
        for(j=0;j<num-1;j++)
        {
            if(cmp(((char*)base+j*width),((char*)base+(j+1)*width))>0)
            {
                    Swap(((char* )base+j * width),((char* )base+(j+1) * width),width);
                    flag =0;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
}
int main()
{
    int arr[]={9,8,7,6,5,4,3,2,1};
    int sz = sizeof(arr)/sizeof(arr[0]);
    bubble(arr,sz,sizeof(arr[0]),cmp);
    int i =0;
    for(i=0;i<sz;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}