#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Add1(char Add[3][3], int row, int col);//函数的声明
void Add2(char Add[3][3], int row, int col);//打印棋盘函数的声明
void player(char Add[3][3], int row, int col);//玩家下棋的声明
void computer(char Add[3][3], int row, int col);//电脑下棋的声明
char vs(char Add[3][3], int row, int col);//判断输赢的声明
//玩家赢'*'
//电脑赢'#’
//平局'Q'
//继续'C'
