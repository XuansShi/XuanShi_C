#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu() {
	printf("*************************\n");
	printf("*******����1.play********\n"); 
	printf("*******����0.exit********\n");
	printf("*************************\n");
	printf("*******���Ϊ*��*********\n");
	printf("*************************\n");
}
void game() {
	char ret = 'a';
	char Add[3][3] = { 0 };
	Add1(Add, 3, 3);//��ʼ������
	Add2(Add, 3, 3);//��ӡ����
	while (1) {
		player(Add,3,3);
		ret = vs(Add, 3, 3);//�ж���Ӯ
		if (ret != 'C') {
			break;
		}
		Add2(Add, 3, 3);
		computer(Add,3,3);
		ret = vs(Add, 3, 3);//�ж���Ӯ
		if (ret != 'C') {
			break;
		}
		system("cls");
		Add2(Add, 3, 3);
	}
	system("cls");
	if (ret == '*') {
		printf("���Ӯ��\n\a");
	}
	else if (ret == '#') {
		printf("����Ӯ��\n\a");
	}
	else{
		printf("ƽ��\n\a");
	}
	Add2(Add, 3, 3);
}
int main() {
	int input = 0;
	srand((unsigned int)time(NULL));//������������������;
	do {
		menu();
		printf("��ѡ��:>\n\a");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("��������Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������1��0\n");
			break;
		}
	} while (input);
	return 0;
}