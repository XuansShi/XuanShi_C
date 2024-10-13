#pragma once
#include<stdio.h>;
#include<stdlib.h>
#include<time.h>

#define ROW 9;
#define COL 9;
	
#define ROWS ROW+2;
#define COLS COL+2;

void InitBoard(char board[11][11], int rows, int cols, char a);

void DisplayBorad(char borad[11][11], int row, int col);

void setmine(char borad[11][11], int row, int col);

void findmine(char mine[11][11], char show[11][11], int row, int col);