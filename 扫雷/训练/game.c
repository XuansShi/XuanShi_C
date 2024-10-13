#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void InitBoard(char board[11][11], int rows, int cols,char a) {
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			board[i][j] = a;
		}
	}
}

void DisplayBorad(char borad[11][11], int row, int col) {
	int i, j;
	printf("扫雷游戏\n");
	for (i = 0; i <= col; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= col; i++) {
		printf("%d ", i);
		for (j = 1; j <= row; j++) {
			printf("%c ", borad[i][j]);
		}
		printf("\n");
	}
	printf("扫雷游戏\n");
}

void setmine(char borad[11][11], int row, int col) {
	int count = 10;//设置雷的数量
	while (count) {
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (borad[x][y] == '0') {
			borad[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[11][11], int x, int y) {
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x - 1][y + 1] - 8 * '0';
}

void findmine(char mine[11][11], char show[11][11], int row, int col) {
	printf("请输入坐标,输入格式：x x\n");
	int x, y;
	while (1) {
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9) {
			if (mine[x][y] == '1') {
				system("cls");
				printf("你被炸死了！");
				DisplayBorad(mine, 9, 9);
				break;
			}
			else {
				int count = get_mine_count(mine,x,y);
				show[x][y] = count + '0';
				system("cls");
				DisplayBorad(show, 9, 9);//打印
			}
		}
		else
			printf("输入坐标不合法\n");
	}
}