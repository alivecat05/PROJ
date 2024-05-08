#include <stdio.h>
int main(){
    int i,j,k;
    int n =12;
for(i=0;i<6;i++){


    for(j=0;j<n;j++){
        if(i==0|i==1){
            if(j<5|j>6){
            printf(" ")  ; 
            }
            else{
                printf("*");
            }
            }
        if(i==2|i==3){
            printf("*");
        }
        if(i==4|i==5){
            if(j<=3|j>=8){
                printf(" ");
            }
            else if(j==5|j==6){
                printf(" ");
            }
            else {
                printf("*");
            }
        }
        }
       printf("\n");
    }
return 0;    
}

