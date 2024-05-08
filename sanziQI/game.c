#include "game.h"
void Initboard(char board[ROW][COL],int row,int col)
{
    int i=0;
    int j=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            board[i][j] = ' ';
        }
    }

}

void Displayboard(char board[ROW][COL],int row,int col)
{ 
    int i=0;
    for(i=0;i<row;i++)
    {   
        int j=0;
        for(j=0;j<col;j++)
        {
            printf(" %c ",board[i][j]);
            if(j<col-1)
            {
                printf("|");
            }
        }
        printf("\n");
        if(i<row-1)
        {
            int j=0;
          for(j=0;j<col;j++)
          {
            printf("---");
            if(j<col-1)
            {
                printf("|");
            }
          }
          printf("\n");
        }
    }
    printf("\n");
}


void Playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋>:\n");
	while (1)
	{
		printf("请输入下棋的坐标，中间使用空格>:");
		scanf("%d %d", &x, &y);
		//坐标合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占有，不能落子,重新输入坐标\n");
			}
		}
		else
		{
			printf("坐标非法，重新输入\n");
		}
	}
}
void Computermove(char board[ROW][COL],int row,int col)
{
//生成随机数
int x=0;
int y =0;

    while(1)
    {
        x = rand()%row;
        y = rand()%col;
        if(board[x][y]==' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

int isFull(char board[ROW][COL],int row,int col)
{
    int i=0;
    int j=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(board[i][j]==' ')
            {
                return 0;
            }
            
        }
    }
    return 1;
}


char isWin(char board[ROW][COL], int row, int col)
{
int i=0;
int j=0;
	//赢
	//行
	// for (int i = 0; i < row; i++)
	// {
	// 	if (board[i][0] == board[i][i+1] && board[i][i+1] != ' ')
	// 		return board[i][0];//如果是玩家赢就返回'*'如果是电脑赢就返回''
	// }
	// //列
	// for (int i = 0; i < col; i++)
	// {
	// 	if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
	// 		return board[0][i];
	// }
	// //对角线
	// if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	// 	return board[1][1];
	// if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
    //     return board[1][1];
    //赢
//行

	for (i = 0; i < row; i++)
	{
		j = 0;
		for (j = 0; j <col - 1; j++)
		{
			if (board[i][j] != board[i][j + 1] || board[i][j] == ' ')
            {
                break;
            }
				
		}
		if (j == col - 1)
        {
            return board[i][j];
        }
			
	}
	//列
	for (j = 0; j < col; j++)
	{
		i = 0;
		for (i = 0; i <row - 1; i++)
		{
			if (board[i][j] != board[i + 1][j] || board[i][j] == ' ')
            {
                break;
            }
				
		}
		if (i == row - 1)
        {
            return board[i][j];
        }
			
	}
	//主对角线
	i = 0;
	j = 0;
	for (int i = 0; i < ROW && i < COL; i++) {
        // 检查当前位置是否非空
        if (board[i][i] != ' ') {
            // 检查主对角线上的其余位置是否与当前位置相同
            for (int j = i + 1; j < ROW && j < COL; j++) {
                if (board[i][i] != board[j][j]) {
                    break; 
                }
            }
            // 如果全部一致，返回获胜的符号
			if(i==row-1)
			{
				return board[i][i];
			}
            
        }
    }
 
	//副对角线

 		char symbol = board[0][COL - 1]; // 取得右上角的符号作为起始符号
    for (int i = 0; i <ROW ; i++) 
	{ // 假设 ROW 是行数，COL 是列数
        if (board[i][COL - 1 - i] != symbol || board[i][COL - 1 - i] == ' ')
		{
            //如果当前符号与起始符号不一致或为空格，则没有获胜
            break;
        }
		if(i==ROW-1)//4
	{
		return symbol;
	}
    }
    // 如果成功检查完所有符号且都相同，则返回获胜的符号
	

	//平局
	if (isFull(board, row, col))
	{
		return 'Q';
	}
	//继续
return 'C';
}