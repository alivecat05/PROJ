#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 9
#define COL 9

#define ROWS ROW+2///设置11行列的原因时因为，在排查是否有雷的情况时便于查找
#define COLS COL+2///

#define BOOMNUM 10//雷的个数
void Initboard(char board[ROWS][COLS],int rows,int cols,char symbol);
void Displayboard(char board[ROWS][COLS],int row,int col);
void Setmine(char board[ROWS][COLS], int rows, int cols);
void Findmine(char mine[ROWS][COLS],char show[ROWS][COLS],int rows,int cols);

void Unfold(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* win);
