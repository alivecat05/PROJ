#include<stdio.h>
// 两种情况之外，所有的数组名都表示数组首元素的地址（视频59中18:46处）
// sizeof(数组名)，计算整个数组的大小，sizeof内部单独放一个数组名，数组名表示整个数组
// &数组名，取出的是数组的地址。&数组名，数组名表示整个数组


// //冒泡排序
// void bubble(int arr[],int sz)
// {
//     int i=0;
//     int j=0;
//     for(i=0;i<=sz-1;i++)//一共有n-1趟
//     {
//         for(j=0;j<sz-1;j++)//每一趟交换n-1次
//         {
//             if(arr[j]>arr[j+1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
// }
// int main()
// {
//     int arr[] = {1,5,1,9,2,6,5};
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     bubble(arr,sz);
//     for(int i=0;i<sz;i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }
// void init(int arr[],int sz)
// {
//     for(int i=0;i<sz;i++)
//     {
//         arr[i] = 0;
//     }
//     return *arr;
// }
// void print(int *arr,int sz)
// {
//     for(int i=0;i<sz;i++)
//     {
//         printf("%d ",arr[i]);
//     }
// }
// int reverse(int arr[],int sz)
// {
//     int left =0;
//     int right = sz-1;
//     while(left<right)
//     {
//         int temp = arr[left];
//         arr[left] = arr[right];
//         arr[right] = temp;

//         left++;
//         right--;
//     }
//     return *arr;
// }
int main()
{
    int arr1[]={1,2,3,4};
    int arr2[]={5,6,7,8};
    for(int i =0;i<4;i++)
    {
        int temp =0;
        temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
        printf("%d ",arr1[i]);
        
    }
    printf("\n");
    for(int j=0;j<4;j++)
    {
      
      printf("%d ",arr2[j]);  
    }
    
    return 0;
}