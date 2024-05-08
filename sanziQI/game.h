#define ROW 6
#define COL 6

#include<stdio.h>
#include<stdlib.h>
#include<time.h>



void Initboard(char board[ROW][COL],int row,int col);
void Displayboard(char board[ROW][COL],int row,int col);

void Playermove(char board[ROW][COL],int row,int col);
void Computermove(char board[ROW][COL],int row,int col);
char isWin(char board[ROW][COL],int row,int col);

int isFull(char board[ROW][COL],int row,int col);