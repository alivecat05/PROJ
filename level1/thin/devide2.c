#include<stdio.h>
int main()
{
int arr[10]={1,2,3,4,5,6,7,8,9,10};
int key = 8;
int right = sizeof(arr)/sizeof(arr[0]);
int left =0;
int mid;

while(left<right){
	mid = left+(right-left)/2;//中值等于左右边界之和的1/2
	if(arr[mid]<key)//当中位值小于key时，left左边界右移缩小范围
	{
		left = mid+1;
	}
	else if(arr[mid]>key)//当中位值大于key时，右边界等于中值，缩小范围
	{
		right = mid;
	}
	else{
		printf("%d ",mid);
		break;
	}


}
	return 0;
}