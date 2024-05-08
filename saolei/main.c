#include"game.h"
void menu()
{
    printf("*********************************\n");
    printf("*********************************\n");
    printf("*******1.PLAY   0.EXIT***********\n");
    printf("*********************************\n");
    printf("*********************************\n");
}

void game()
{
    char mine[ROWS][COLS] = {0};//存放布置好类
    char show[ROWS][COLS]= {0};////存放排查出雷的信息
    //mine数组 未布置雷为0
    Initboard(mine,ROWS,COLS,'0'); 
    //show数组 没排查为*
    Initboard(show,ROWS,COLS,'*');
    //设置雷
      Setmine(mine,ROW,COL);
    Displayboard(show,ROW,COL);
    //排查雷
    Findmine(mine,show,ROW,COL);
}
int main()
{
    srand((unsigned int)time(NULL));
    int input =0;
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                printf("Game start\n");
                game();
                break;
            case 0:
                printf("GOODBYE!!!!!\n");
                break;
            default:
                printf("Wrong choice!!!\n");
            break;
        }
    } while (input);

    return 0;
    
}