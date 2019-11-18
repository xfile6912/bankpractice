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

using namespace std;


typedef struct acc {
	int account;
	int bank;
	int password;
	int money;
}ACC;

vector<ACC> account;

int accountcheck(int tempaccount) //존재하는 계좌이면 1, 존재하지 않는 계좌이면 0;
{
	int i;
	int flag = 0;
	for (i = 0; i < account.size(); i++)
	{
		if (account[i].account == tempaccount)
			flag = 1;
	}
	return flag;
}

int passwordcheck() //패스워드가 맞으면 1, 패스워드가 틀리면 0;
{
	return 1;
}

void createaccount()
{
	int flag;//존재하는 계좌이면 1, 존재하지 않는 계좌이면 0;
	ACC tempaccount;//시도하는 어카운트;
	int password;
	while (1)
	{
		printf("계좌번호를 입력하시오:");
		scanf("%d", &(tempaccount.account));
		flag = accountcheck(tempaccount.account);
		if (flag == 0)
			break;
		else
			printf("이미 존재하는 계좌입니다. 다시 입력하세요!\n");
	}
	printf("은행회사를 고르십시오(abank=1; bbank=2; cbank=3):");
	scanf("%d", &(tempaccount.bank));
	tempaccount.money = 0;
	while (1)
	{
		printf("패스워드를 입력하십시오 : ");
		scanf("%d", &(tempaccount.password));
		printf("다시 한번 입력하십시오 : ");
		scanf("%d", &password);
		if (password == tempaccount.password)
			break;
		else
			printf("패스워드가 동일하지 않습니다.\n");
	}
	account.push_back(tempaccount);
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
