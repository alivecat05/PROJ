#include "game.h"

void menu()
{
    printf("***********************\n");
    printf("***********************\n");
    printf("*****1.PLAY  0.EXIT****\n");
    printf("***********************\n");
    printf("***********************\n");
}
void game()
{
    char board[ROW][COL]={0};      
       int ret =0;
           //
    Initboard(board,ROW,COL);//初始化棋盘
    Displayboard(board,ROW,COL);//展示棋盘

    while (1)
    {
        Playermove(board,ROW,COL);//玩家下棋
        Displayboard(board,ROW,COL);
         ret = isWin(board,ROW,COL);      //判断胜负情况
        if(ret!='C')                     //如果返回不是‘C’则游戏继续，否则进行胜负判断
        {     
            break;
        }
        Computermove(board,ROW,COL);//电脑下棋
        Displayboard(board,ROW,COL);
        
        ret = isWin(board,ROW,COL);
        if(ret!='C')
        {
        
            break;
        }
    }
    if(ret=='*')
    {
        printf("玩家胜\n");
    }
    else if(ret=='#')
    {
        printf("电脑胜\n");
    }
    else if(ret=='Q')
    {
        printf("平局\n");
    }

}
int main()
{
    srand((unsigned int)time(NULL));
    int input=0;
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
            printf("Game Start\n");
            game();
                break;
            case 0:
       
            printf("Goodbye!!\n");
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
    }while(input);
}