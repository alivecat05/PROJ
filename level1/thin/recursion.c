// #include<stdio.h>
// #include<string.h>
//实现strlen函数
// int mystrlen(const char *str)
// {
//     if(*str=='\0')
//         return 0;
//     else
//         return 1+mystrlen(str+1);
// }
// int main()
// {
//     char *c  ="abc";
//     int len = mystrlen(c);
//     printf("%d",len);
//     return 0;
// }

//分别打印数字每一位
// void print(int n)//1234
// {	if(n>9)
//  {
//      print(n/10);
// }
//  printf("%d ",n%10);
// }

// int main()
// {
//  unsigned int num =1234;
//  print(num);
//  return 0;}

//实现一个数的阶乘
// int jiecheng(int n)
// {
//     if(n==1)
//     {
//         return 1;
//     }
//     else
//     {
//         int ans = n*jiecheng(n-1);
//         return ans;
//     }
// }
// int main()
// {
//     int n=0;
//     scanf("%d",&n);
//     int result = jiecheng(n);
//     printf("%d",result);
//     return 0;
// }
// //反转字符串
// #include<stdio.h>
// #include<string.h>
// void reverse_string(char* arr)
// {
// 	int len = strlen(arr);
// 	char temp = *arr;
// 	*arr = *(arr+len-1);
// 	*(arr+len-1) = '\0';
// 	if((strlen(arr+1))>=2)
// 	{
// 		reverse_string(arr+1);
// 	}

// 		*(arr+len-1) = temp;	
// }
// int main()
// {
// 	char str[]= "abcdef";
// 	reverse_string(str);
// 	printf("%s",str);
// 	return 0;
// }
//实现一个数的每位相加
// int DigitSum(int num)//1729
// {
//     static int sum = 0;
//     if(num>9)
//     {
//         DigitSum(num/10);
        
//     }
//     sum+=num%10;
//     return sum;
// }
// int main()
// {
//     int num =0;
//     scanf("%d",&num);
//    int ans =  DigitSum(num);
//     printf("%d",ans);
//     return 0;
// }
//实现n的k次方
// int PlusPlus(int n,int k)//2,4
// {
//     static int result=1;
//     if(k!=1)
//     {
//         k--;
//         PlusPlus(n,k);
        
//     }
//     result*=n;
//     return result;  
// }
// int main()
// {
//     int n,k;
//     scanf("%d %d",&n,&k);
//     int ans = PlusPlus(n,k);
//     printf("%d",ans);
//     return 0;
// }

//实现第n个斐波那契数
//F(n)=F(n - 1)+F(n - 2)
//非递归
// long long int feibo(int n)
// {
//     long long  int a =1;
//     long long  int b =1;
//     long long  int c =1;
// while(n>2)
// {
//     c=a+b;
//     a = b;
//     b=c;
//     n--;
// }
// return c;
// }
////递归
// int feibo(int n)
// {
//     if(n<3)
//     {
//         return 1;
//     }
//     else
//     {
//         return feibo(n-1)+feibo(n-2);
//     }
// }
// int main()
// {   
//     int ans;
//     int n;
//     scanf("%d",&n);
//     ans = feibo(n);
//     printf("%d",ans);
//     return 0;
// }

//青蛙跳台阶的问题
//递归法
// int frog(int n)
// {
//     int con = (int)1e9+7;
//     if(n==1)
//     {
//         return 1;
//     }
//     else if(n==2)
//     {
//         return 2;
//     }
//     else if(n==0)
//     {
//         return 0;
//     }
//     else
//     {
//         int ans = frog(n-1)%con+frog(n-2)%con;
//         return ans;
//     }
// }

//斐波那契法
// int frog(int n)
// {
//     int con = (int)1e9+7;
//     int first  =0;
//     int temp =0;
//     int second =1;
//     while(n>0)
//     {   
//         temp = first+second;
//         first = second%con;
//         second = temp%con;
//         n--;
//     }
//     return first;
// }
// int climb(int n)
// {
//     return frog(n+1);
// }
// int main()
// {
//     int result =0;
//     int n =0;
//     scanf("%d",&n);
//     result = climb(n);
//     printf("%d",result);
//     return 0;
// }

//汉诺塔问题
// void print(char x,char y)//打印步骤
// {
//     printf("%c->%c ",x,y);
// }
// void move(int n,char start,char temp,char end)//变量为n层汉诺塔,起始杆'A',中转杆'B',目标杆'C'
// {
//     if(n==1)                                  //当只有一层汉诺塔时直接可以从起始移动到目标杆
//     {
//         print(start,end);
//     }
//     else
//     {
//         move(n-1,start,end,temp);           //否则，将除底层外的盘子，以C杆作为中转杆移动到B杆
//         print(start,end);                   //此时起始杆上只有一个最大的盘子可以直接移动到C杆目标杆
//         move(n-1,temp,start,end);           //最后再把B杆中作为起始杆，把B杆中剩余的盘子，经过A杆最后到达目标杆C杆结束整个搬运过程
//     }
// }
// int main()
// {   int n =0;
//     scanf("%d",&n);
//     move(n,'A','B','C');
//     return 0;
// }