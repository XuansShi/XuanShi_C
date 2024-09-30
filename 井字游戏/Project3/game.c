#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void Add1(char Add[3][3], int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			Add[i][j] = ' ';
		}
	}
}
void Add2(char Add[3][3], int row, int col) {
	for (int i = 0; i < row; i++) {
		printf(" %c | %c | %c\n", Add[i][0], Add[i][1], Add[i][2]);
		if (i < row - 1) {
			printf("---|---|---\n");
		}
	}
}
int is_full(char Add[3][3], int row, int col) {
	int i, j;
	for (i = 0; i <= 2; i++) {
		for (j = 0; j <= 2; j++) {
			if (Add[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}
void computer(char Add[3][3], int row, int col){
	printf("电脑下棋(电脑下棋是随机的qwq)\n\a");
	int x, y;
	while (is_full(Add, 3, 3)!=1) {
		b:
		x = rand() % 3;
		y = rand() % 3;//生成0，1，2三个数的一个
		if (Add[x][y] == ' ') {
			Add[x][y] = '#';
			break;
		}
		else
			goto b;
	}
}
char vs(char Add[3][3], int row, int col) {
	for (int i = 0; i <= 2; i++) {
		if (Add[i][0] == Add[i][1] && Add[i][1] == Add[i][2] && Add[i][1] != ' ') {
			return Add[i][1];
		}
	}
	for (int j = 0; j <= 2; j++) {
		if (Add[0][j] == Add[1][j] && Add[1][j] == Add[2][j] && Add[1][j] != ' ') {
			return Add[1][j];
		}
	}
	if (Add[0][0] == Add[1][1] && Add[1][1] == Add[2][2] && Add[0][0] != ' ') {
		return Add[1][1];
    }
	if (Add[0][2] == Add[1][1] && Add[1][1] == Add[2][0] && Add[0][2] != ' ') {
		return Add[1][1];
	}
	 if (is_full(Add,3,3)) {
		return 'Q';
	}
	return 'C';
}
void player(char Add[3][3], int row, int col) {
	int x, y;
	printf("玩家下棋,输入格式:a b，其中a、b为1/2/3。a为行数，b为列数\n\a");
	printf("请输入坐标\n\a");
a:
	scanf("%d %d", &x, &y);
	while (1) {
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3) {
			if (Add[x - 1][y - 1] == ' ')
			{
				Add[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("坐标被占用，不可下棋\n\a");
				goto a;
				break;
			}
		}
		else {
			printf("非法坐标，请重新输入\n\a");
			goto a;
			break;
		}
	}
}