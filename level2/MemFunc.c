#include<stdio.h>
#include<string.h>
#include<assert.h>
//模拟memcpy函数
//负责拷贝两块独立空间的数据
// void* mymemcpy(void*dest,void*source,int num)///无法处理重叠的内存之间的数据拷贝
// {
//     assert(dest&&source);
//     void*ret =dest;
//     while(num--)
//     {
//    *((char*)dest)= *((char*)source);
//    dest = (char*)dest+1;
//    source = (char*)source+1;

//     }
//     return ret;
// }
// int main()
// {
// int arr1[]={1,4,5,6,8,2,4};
// int arr2[10]={0};
// mymemcpy(arr2,arr1,28);
// int sz = sizeof(arr1)/sizeof(arr1[0]);
// for(int i=0;i<sz;i++)
// {

// printf("%d ",arr2[i]);
// }
// return 0;
// }


//模拟memove函数
//处理重叠内存空间之间的数据拷贝
// char*mymemmove(void*dest,const void*src,size_t num)
// {   
//     assert(dest&&src);
//     char* ret  = dest; 
//     if((char*)dest<(char*)src)//从前向后拷贝
//     {   
//         while(num--)
//         {
//              *(char*)dest = *(char*)src;
//              dest = (char*)dest++;
//              src =  (char*)src++;
//         }
       
//     }
//     else if((char*)dest>(char*)src)//从后向前拷贝
//     {
//         while(num--)
//         {
//            *((char*)dest+num) =*((char*)src+num); 
              
//         }
//     }
//     return ret;
// }
// int main()
// {
// int arr1[]={1,4,5,6,8,2,4};
// mymemmove(arr1,arr1+2,8);
// int sz = sizeof(arr1)/sizeof(arr1[0]);
// for(int i=0;i<sz;i++)
// {
// printf("%d ",arr1[i]);

// }
//     return 0;
// }


//模拟实现memcmp
// int mymemcmp(void*dest,void*src,size_t num)
// {
//     assert(dest&&src);
//     while(*(char*)dest==*(char*)src)
//     {
//         if((char*)src==NULL)
//         {
//             return 0;
//         }
//         dest = (char*)dest+1;
//         src = (char*)src+1;
//     }
//     if(*(char*)dest>*(char*)src)
//     {
//         return 1;
//     }
//     else if(*(char*)dest<*(char*)src)
//     {
//         return -1;
//     }
// }
// int main()
// {
//     int arr1[] = {1,23,4,6};
//     int arr2[] = {1,23,4,5,6,7,8,10};
//     int ret  = memcmp(arr1,arr2,32);
//     printf("%d",ret);
//     return 0;
// }