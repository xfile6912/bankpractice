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
#include <windows.h>

using namespace std;


typedef struct acc {
	int account;
	int bank;
	int password;
	int money;
}ACC;

int flag;//존재하는 계좌이면 1, 존재하지 않는 계좌이면 0;
int tempaccount;//시도하는 어카운트;
int password;
int cnt = 0;
int i;
int money;

vector<ACC> account;
void init()
{
	FILE* fp;
	int res;
	int account1, bank1, password1, money1;
	ACC tempaccount;
	fp = fopen("input.txt", "r");
	while (1)
	{
		res = fscanf(fp, "%d %d %d %d", &account1, &bank1, &password1, &money1);
		if (res == EOF)
			break;
		tempaccount.account = account1;
		tempaccount.bank = bank1;
		tempaccount.password = password1;
		tempaccount.money = money1;
		account.push_back(tempaccount);
	}
	fclose(fp);
}
void save()
{
	FILE* fp;
	fp = fopen("input.txt", "w");
	int i;
	for (i = 0; i < account.size(); i++)
	{
		fprintf(fp, "%d %d %d %d\n", account[i].account, account[i].bank, account[i].password, account[i].money);
	}
	fclose(fp);
}
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

int passwordcheck(int tempaccount, int password) //패스워드가 맞으면 1, 패스워드가 틀리면 0;
{
	int result = 0;
	int i;
	for (i = 0; i < account.size(); i++)
	{
		if (account[i].account == tempaccount)
			break;
	}
	if (account[i].password == password)
		result = 1;
	return result;
}
int input()
{
	cnt = 0;
	while (1)//입금하고자 하는 계좌번호 받기
	{
		printf("계좌번호를 입력하시오:");
		scanf("%d", &tempaccount);
		flag = accountcheck(tempaccount);
		if (flag == 1)
			break;
		else
			printf("존재하지 않는 계좌번호 입니다. 다시 입력하세요!\n");
	}
	while (1)//계좌의 비밀번호 받기(3회 잘못입력하면 입금 종료)
	{
		printf("패스워드를 입력하십시오 : ");
		scanf("%d", &password);
		if (passwordcheck(tempaccount, password) == 1)
			break;
		else
		{
			printf("패스워드가 동일하지 않습니다.\n");
			cnt++;
		}
		if (cnt == 3)
		{
			printf("비밀번호를 3회 잘못 입력하셨습니다.\n");
			break;
		}
	}
	if (cnt == 3)
	{
		printf("다시 처음부터 진행하여 주십시오.\n");
		return -1;
	}
	else
	{
		for (i = 0; i < account.size(); i++)
		{
			if (account[i].account == tempaccount)
				break;
		}
		return i;
	}
}
void createaccount()//xx
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
void deposit()//oo
{
	if (input() == -1)
	{

	}
	else
	{
		printf("얼마를 입금하시겠습니까(잔액 : %d) : ", account[i].money);
		scanf("%d", &money);
		account[i].money += money;
		printf("%d의 돈이 입금되었습니다.(잔액 : %d) \n", money, account[i].money);
	}
}
void withdraw()//oo
{
	if (input() == -1)
	{

	}
	else
	{
		while (1)
		{
			printf("얼마를 출금하시겠습니까(잔액 : %d) : ", account[i].money);
			scanf("%d", &money);
			if (money <= account[i].money)
			{
				account[i].money -= money;
				printf("%d원의 돈이 출금되었습니다.(잔액 : %d) \n", money, account[i].money);
				break;
			}
			else {
				printf("잔액이 부족합니다. 다시 입력하여 주십시오.\n");
			}
		}

	}
}
void checkmoney()//oo
{
	if (input() == -1)
	{

	}
	else
		printf("%d원의 잔액이 남아있습니다.\n", account[i].money);
}

void transfer()
{
	int fromaccount;
	int toaccount;
	int password;
	int cnt = 0;
	int i;
	int money;
	acc* pointer = NULL;//출금하고자 하는 계좌의 주소 저장.
	int flag;
	while (1)//출금하고자 하는 계좌번호 받기
	{
		printf("계좌번호를 입력하시오:");
		scanf("%d", &(fromaccount));
		flag = accountcheck(fromaccount);
		if (flag == 1)
			break;
		else
			printf("존재하지 않는 계좌번호 입니다. 다시 입력하세요!\n");
	}
	while (1)//계좌의 비밀번호 받기(3회 잘못입력하면 출금 종료)
	{
		printf("패스워드를 입력하십시오 : ");
		scanf("%d", &password);
		if (passwordcheck(fromaccount, password) == 1)
			break;
		else
		{
			printf("패스워드가 동일하지 않습니다.\n");
			cnt++;
		}
		if (cnt == 3)
		{
			printf("비밀번호를 3회 잘못 입력하셨습니다.\n");
			break;
		}
	}
	if (cnt == 3)
	{
		printf("다시 처음부터 진행하여 주십시오.\n");
	}
	else
	{
		for (i = 0; i < account.size(); i++)
		{
			if (account[i].account == fromaccount)
			{
				pointer = &(account[i]);//출금하려고 하는 주소 저장.
				break;
			}
		}
		while (1)//보내고자 하는 계좌번호 받기
		{
			printf("보낼 계좌번호를 입력하시오:");
			scanf("%d", &(toaccount));
			flag = accountcheck(toaccount);
			if (flag == 1)
				break;
			else
				printf("존재하지 않는 계좌번호 입니다. 다시 입력하세요!\n");
		}
		while (1)
		{
			printf("얼마를 보내시겠습니까(잔액 : %d) : ", (*pointer).money);
			scanf("%d", &money);
			if (money <= (*pointer).money)
			{
				(*pointer).money -= money;
				for (i = 0; i < account.size(); i++)
				{
					if (account[i].account == toaccount)
					{
						account[i].money += money;
						break;
					}
				}
				printf("%d원의 돈을 보냈습니다.(잔액 : %d) \n", money, (*pointer).money);
				break;
			}
			else {
				printf("잔액이 부족합니다. 다시 입력하여 주십시오.\n");
			}
		}
	}
}
void record()
{
}
void deleteaccount()//oo
{
	if (input() == -1)
	{

	}
	else
	{
		account.erase(account.begin() + i);//계좌 삭제
		printf("%d 계좌가 삭제되었습니다.\n", tempaccount);
	}
}

int main(void)
{
	int menu;
	init();
	while (1)
	{
		//system("cls");
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
	save();
}
