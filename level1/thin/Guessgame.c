#include<stdio.h>
#include<stdlib.h>
#include<time.h>    

void menu(){
    printf("###############################\n");
    printf("###############################\n");
    printf("########## 1.PLAY #############\n");
    printf("########## 0.EXIT #############\n");
    printf("###############################\n");
    printf("###############################\n");
}
void game(){
    int ans = 0;
    int ret = rand()%100+1;
   
    while(1)
    {
    printf("Please input your ans\n");
    scanf("%d",&ans);
        if(ans>ret){
            printf("It should be smaller\n");
        }
        else if(ans<ret){
            printf("It should be bigger\n");
        }
        else{
            printf("Awesome!!!!\n");
            break;
        }
    }
}
int main(){
    srand((unsigned int)time(NULL));
   int input =0;
   do{
    menu();
    printf("SELECT:>");
   scanf("%d",&input);
   switch(input)
   {
    case 1:
        game();
        break;
    case 0:
        printf("Goodbye!!!");
        break;
    default:
        printf("Wrong choice\nPlease select again");
        break;
   } 
   }while(input);
return 0;
}