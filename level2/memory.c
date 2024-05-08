//数据存储
#include<stdio.h>
//大小端
    //以字节为单位讨论字节在内存中的存储形式
    //大端（存储）模式，是指数据的低位保存在内存的高地址中，而数据的高位，保存在内存的低地址中；
    //小端（存储）模式，是指数据的低位保存在内存的低地址中，而数据的高位,，保存在内存的高地址中。
    /*为什么有大端和小端：
        为什么会有大小端模式之分呢？这是因为在计算机系统中，我们是以字节为单位的，每个地址单元
        都对应着一个字节，一个字节为8bit。
            但是在C语言中除了8 bit的char之外，还有16 bit的short型，32 bit的long型
            （要看具体的编译器），另外，对于位数大于8位
            的处理器，例如16位或者32位的处理器，由于寄存器宽度大于一个字节，那么必然存在着一个如
            何将多个字节安排的问题。因此就
            导致了大端存储模式和小端存储模式。*/
            //0x11223344       11 22 33 44从高位到低位
     //百度面试     
// int check_sys(void)
// {
//     int a =1;
//     return (*(char*)&a);//char在内存中只占一个字节,整形强制转换位char，再取其中数据，即去第一位.
// }  
// int main()
// {
//     int ret = check_sys();
//     if(ret==1 )
//     {
//         printf("小端\n");
//     }
//     else if(ret==0)
//     {
//         printf("大端\n");
//     }
//     return 0;
// }

// int main()
// {
// char a= -1; //10000000000000000000000000000001  OG
//             //11111111111111111111111111111110  
//             //11111111111111111111111111111111 
//             //截断
//             // 11111111 
//             //00000000000000000000000001111111
//             //整形提升
//             //11111111111111111111111111111111 补码
//             //10000000000000000000000000000001
// signed char b=-1;
// unsigned char c=-1;
//             //10000000000000000000000000000001 原
//             //11111111111111111111111111111110  反码
//             //11111111111111111111111111111111  补码
//             ///整形提升
//             // 截断（数据存储的时候）
//             //11111111
//             //000000000000000000000000011111111 补码
//             //高位补1
//             //111111111111111111111111111111111  255
//             printf("a=%d,b=%d,c=%d",a,b,c);//%d打印有符号整型
// return 0;
// }


// int main()
// {
//     char a=-128;           //000000000000000000000000010000000
//                         // 00000000000000000000000010000000
//                         // 11111111111111111111111110000000 当作原码
//     printf("%d\n",a);   //10000000000000000000000010000000 
//                         //11111111111111111111111101111111
//     return 0;
// }

// int main()
// {
//    int i =-20;
//    unsigned int j=10;
//     printf("%d\n",i+j);           //有符号整型读原码             
//     return 0;
// }
//1000000000000000000000000010100
//1111111111111111111111111101011
//1111111111111111111111111101100   -----20

//0000000000000000000000000001010  -------10 补
//
#include<string.h>
// int main()
// {
//     char a[1000];
//     int i;

//     for(i=0;i<1000;i++)
//     {
//        a[i] = -1-i;         ///arr[i] --->char   -128~127
//                             //-1,-2,-3,-4........-128/127 126.......-1
//     }            
//     printf("%d",strlen(a));
//     return 0;
// }

// unsigned char i =0; //0~255
// int main()
// {
//     for(i=0;i<=255;i++)
//     {
//         printf("hello world\n");
//     }
//     return 0;

// }
// 当i==255的时候
//00000000000000000000000010000000原
//00000000000000000000000010000000补   取二进制补码
//截断
//11111111111111111111111110000000

// 故类型不匹配的时候尤其是char，再存储数据的过程中会发生截断，即取补码后八位，高位补零。


//-3
//10000000000000000000000000000011
// int main()
// {
//     int a =9;
//     //00000000000000000000000000001001
//     //0 00000000 00000000000000000001001

//     //E = -126
//     //M= 0.0000000000000000000000000001001
//     // +0.0000000000000000000000000001001*2^-126
//     float *pfloat  =(float*)&a;
//     printf("%f\n",*pfloat);//仅打印小数点后六位
//     *pfloat =9.0;
//     // 1001.0
//     // S =0
//     //M = 1.001
//     //E = 3
//     printf("%f\n",*pfloat);
//     return 0;
// }
//00000101.1
//1.011;
//0000000000000000000000000000000011001000
//0000000000000000000000000000000001100100
//0000000000000000000000000000000011101100
int main()
{
    unsigned int a =0x1234;
    unsigned char b = *(unsigned char*)&a;
    printf("%d",&b);
    return 0;
}