#include<string.h>
#include<stdio.h>
#include<assert.h>
//实现strcpy
// char* mystrcpy(char*str,const const char*source)
// {
//     assert(str);
//     assert(source);
//     char* temp = str;
//     while(*source!='\0')
//     {
//         *str = *source;
//         str++;
//         source++;
//     }
//     return temp;
// }
// int main()
// {
// char arr1[] = "NIUBI";
// char arr2[20]={0};
// mystrcpy(arr2,arr1);
// printf("%s\n",arr2);
// printf("%s",arr1);
//     return 0;
// }
//实现strcat
// char* mystrcat(char*dest,const char* src)
// {
//     assert(dest);
//     assert(src);
//     char*OG = dest;
//     while(*dest!='/0')
//     {
//         dest++;
//         if(*dest=='\0')
//         {
//             while(*dest++=*src++)
//             {
//                 ;
//             }
//             break;
//         }

//     }
//     return OG;
// }
// int main()
// {
// char arr1[20] = "I ";
// char arr2[]="Luv u";
// mystrcat(arr1,arr2);
// printf("%s\n",arr1);

//     return 0;
// }
// 模拟实现strcmp
// int mystrcmp(char*str1,char*str2)
// {
//     assert(str1);
//     assert(str2);
//     while(*str1==*str2)
//     {
//         if(*str1=='\0')        
//             return 0;        
//         str1++;
//         str2++;
//     }
//     if(*str1>*str2)
//         return 1;
//     else
//         return -1;  
// }
// int main()
// {
//     char *arr1 = "shabi";
//     char *arr2 = "dasahbi";
//     int ret = mystrcmp(arr1,arr2);
//     if(ret==0)
//         printf("same");
//     else if(ret>0)
//         printf(">");
//     else
//         printf("<");
//     return 0;
// }
//模拟strstr字串函数
// char* mystrstr(char*str1,char*str2)
// {
// assert(str1&&str2);
// const char* s1 = str1;
// const char* s2 = str2;
// const char* p = str1;
// while(*p)
// {
//     s1 = p;
//     s2 = str2;
//     while (*s1!='\0'&&*s2!='\0'&&*s1==*s2)
//     {
//        s1++;
//        s2++;
//     }
//     if(*s2=='\0')
//     {
//         return (char*)p;
//     }
//     p++;
// }
// }
// int main()
// {
//     char arr1[] = "abcdefg";
//     char arr2[] = "def";
//     char* ret=mystrstr(arr1,arr2);
//  if(ret==NULL)
//  {
//     printf("NULL\n");
//  }
//  else
//  {
//         printf("%s",ret);
//  }
//     return 0;
// }
// strtok函数
// int main()
// {
//     const char* sep = "@.";
//     char email[] = "zhangpengwei@vitejiuyeke.com";
//     char cp[30] = {0};
//     strcpy(cp,email);
//     char* ret=NULL;
//     for(ret=strtok(cp,sep);ret!=NULL;ret=strtok(NULL,sep))
//     {
//         printf("%s\n",ret);
//     }
//     return 0;
// }
