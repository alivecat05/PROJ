#include<stdio.h>
#include<string.h>
void reverse_string(char* arr)
{
	int len = strlen(arr);
	char temp = *arr;
	*arr = *(arr+len-1);
	*(arr+len-1) = '\0';
	if((strlen(arr+1))>=2)
	{
		reverse_string(arr+1);
	}

		*(arr+len-1) = temp;	
}
int main()
{
	char str[]= "abcdefg";
	reverse_string(str);
	printf("%s",str);
	return 0;
}