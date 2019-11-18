#define _CRT_SECURE_NO_WARNINGS

#define fees 500;
#define abank 1;
#define bbank 2;
#define cbank 3;

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>


typedef struct acc {
	int account;
	int id;
	int bank;
	int password;
	int money;
}ACC;

void accountcheck()
{
}

void passwordcheck()
{
}

void createaccount()
{
}
void deposit()
{
}
void withdraw()
{
}
void checkmoney()
{
}
void transfer()
{
}
void record()
{
}
void deleteaccount()
{
}

int main(void)
{
	int menu;
	while (1)
	{
		printf("--------------------------\n");
		printf("-1.계좌계설---------------\n");//createaccount();
		printf("-2.출금-------------------\n");//withdraw();
		printf("-3.입금-------------------\n");//deposit();
		printf("-4.잔액조회---------------\n");//checkmoney();
		printf("-5.계좌이체---------------\n");//transfer();
		printf("-6.계좌삭제---------------\n");//deleteaccount();
		printf("-7.나가기-----------------\n");
		printf("--------------------------\n");
		printf("메뉴선택 : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			createaccount();
			break;
		case 2:
			withdraw();
			break;
		case 3:
			deposit();
			break;
		case 4:
			checkmoney();
			break;
		case 5:
			transfer();
			break;
		case 6:
			deleteaccount();
			break;
		default:
			break;
		}
		if (menu == 7)
			break;
	}
}
