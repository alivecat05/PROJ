#include <stdio.h>
#include <math.h>
int main() {
    double t;
    double w,h;
    printf("请输入体重身高：");
	scanf("%lf%lf",&w,&h);
	t = w/pow(h,2.0);
    if(t<18){
    	printf("低体重"); 
	}
	else if(t>18&&t<25){
		printf("正常体重"); 
	}
	else if(t>25&&t<27){
		printf("超重体重"); 
	}
    else if(t>27){
		printf("肥胖"); 
	}
	return 0;
}