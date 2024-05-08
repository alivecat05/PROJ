#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
//此程序实现多个字符从两端移动，汇聚到中间
int main(){
char arr1[] = "Welcome to bit!!!";
char arr2[] = "#################";
int left=0;
int right =sizeof(arr1)/sizeof(arr1[0]);
int i;
for(i=0;i<=right;i++){
    if(left<=right){
        arr2[left] = arr1[left];
        arr2[right]= arr1[right];
        printf("%s\n",arr2);
        Sleep(500);
        system("cls");
        left++;
        right--;
    }
    else if(left>right){
        break;
    }
}
    printf("%s\n",arr2);
// printf("%s",arr2);
    return 0;
}