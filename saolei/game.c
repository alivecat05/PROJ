#include"game.h"
void Initboard(char board[ROWS][COLS],int rows,int cols,char symbol)//版面初始化
{
    int i;
    for(i=0;i<rows;i++)
    {
        int j=0;
        for(j=0;j<cols;j++)
        {
          board[i][j] = symbol;
        }
    }
}

void Displayboard(char board[ROWS][COLS], int rows, int cols) //展示版面
{
    int i, j;
    printf("----------------GAME--------------------\n");
    // 打印列标题，如果不需要可以注释掉
    for (j = 0; j <= cols; j++) {
        printf("%d ", j);
    }
    printf("\n");
    // 打印棋盘内容
    for (i = 1; i <=rows; i++) {
        printf("%d ", i ); // 打印行标题，加1是因为棋盘通常从1开始计数
        for (j = 1; j <=cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("----------------GAME--------------------\n");
}

void Setmine(char board[ROWS][COLS], int rows, int cols)//设置雷的位置
{
    int count = BOOMNUM;
    while(count!=0)
    {
        int x =rand()%rows+1;
        int y =rand()%cols+1;
        if(board[x][y]=='0')
        {
            board[x][y] = '1';
             count--;
        }
    }
}
void Findmine(char mine[ROWS][COLS],char show[ROWS][COLS],int rows,int cols)//查雷
{
int x=0;
int y=0;
int win =0;//找到费雷个数
    while(win<rows*cols-BOOMNUM)
    {
        printf("输入坐标:>");
        scanf("%d %d",&x,&y);
        if(x>=1&&x<=rows &&y>=1&&y<=cols)
        {
            if(show[x][y]!='*')//排查重复输入的情况
            {
                printf("已被排查请重新输入\n");
            }
            else
            {
                if(mine[x][y]=='1')
                    {
                        printf("哈哈哈你被炸死了!!!!!\n");
                        Displayboard(mine,ROW,COL);
                        break;
                    }
                    else
                    {
                        Unfold(mine,show,x,y,&win);
                        Displayboard(show,ROW,COL);
                    }
            }
        }
        else
        {
                printf("坐标非法，请重新输入\n");
        }
    }
    if(win==(rows*cols-(BOOMNUM)))
    {
        printf("恭喜！！！！游戏胜利\n");
        Displayboard(mine,ROW,COL);
    }
}


int get_mine_count(char board[ROWS][COLS],int x,int y)//数雷的个数
{
   return (board[x-1][y-1]+board[x-1][y]+
   board[x-1][y+1]+board[x][y+1]
    +board[x-1][y+1]+board[x+1][y]
    +board[x+1][y-1]+board[x][y-1]-8*'0');
}

void Unfold(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* win)//无雷展开
{

	if (x<1||x>ROW||y<1||y>COL)       //判断坐标是否越界
	{
		return;
	}
	if (show[x][y]!= '*')             //判断是否被排查过
	{
		return;
	}
	int count = get_mine_count(mine, x, y);     //获取该坐标位四周雷的个数
	if (count > 0)                          //如果周围雷大于零
	{
		(*win)++;                           //该区域为非雷，非雷区域数加一
		show[x][y] = count + '0';           //该区域填入雷的个数
		return;
	}
	else if (count == 0)      //如果无雷
	{
		(*win)++;              //该区域为非雷，非雷区域数加一
		show[x][y] = ' ';     //该区域填入空格展现，非雷区展开的效果
		Unfold(mine, show, x - 1, y, win);//然后对周围八个区域递归
		Unfold(mine, show, x - 1, y + 1, win);
		Unfold(mine, show, x, y + 1, win);
		Unfold(mine, show, x + 1, y + 1, win);
		Unfold(mine, show, x + 1, y, win);
		Unfold(mine, show, x + 1, y - 1, win);
		Unfold(mine, show, x, y - 1, win);
		Unfold(mine, show, x - 1, y - 1, win);
	}
}


