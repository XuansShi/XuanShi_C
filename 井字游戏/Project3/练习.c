#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu() {
	printf("*************************\n");
	printf("*******输入1.play********\n"); 
	printf("*******输入0.exit********\n");
	printf("*************************\n");
	printf("*******玩家为*号*********\n");
	printf("*************************\n");
}
void game() {
	char ret = 'a';
	char Add[3][3] = { 0 };
	Add1(Add, 3, 3);//初始化棋盘
	Add2(Add, 3, 3);//打印棋盘
	while (1) {
		player(Add,3,3);
		ret = vs(Add, 3, 3);//判断输赢
		if (ret != 'C') {
			break;
		}
		Add2(Add, 3, 3);
		computer(Add,3,3);
		ret = vs(Add, 3, 3);//判断输赢
		if (ret != 'C') {
			break;
		}
		system("cls");
		Add2(Add, 3, 3);
	}
	system("cls");
	if (ret == '*') {
		printf("玩家赢了\n\a");
	}
	else if (ret == '#') {
		printf("电脑赢了\n\a");
	}
	else{
		printf("平局\n\a");
	}
	Add2(Add, 3, 3);
}
int main() {
	int input = 0;
	srand((unsigned int)time(NULL));//设置随机数的生成起点;
	do {
		menu();
		printf("请选择:>\n\a");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("三子棋游戏开始\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请输入1或0\n");
			break;
		}
	} while (input);
	return 0;
}