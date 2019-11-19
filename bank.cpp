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

int accountcheck(int tempaccount) //�����ϴ� �����̸� 1, �������� �ʴ� �����̸� 0;
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

int passwordcheck(int tempaccount, int password) //�н����尡 ������ 1, �н����尡 Ʋ���� 0;
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

void createaccount()
{
	int flag;//�����ϴ� �����̸� 1, �������� �ʴ� �����̸� 0;
	ACC tempaccount;//�õ��ϴ� ��ī��Ʈ;
	int password;
	while (1)
	{
		printf("���¹�ȣ�� �Է��Ͻÿ�:");
		scanf("%d", &(tempaccount.account));
		flag = accountcheck(tempaccount.account);
		if (flag == 0)
			break;
		else
			printf("�̹� �����ϴ� �����Դϴ�. �ٽ� �Է��ϼ���!\n");
	}
	printf("����ȸ�縦 ���ʽÿ�(abank=1; bbank=2; cbank=3):");
	scanf("%d", &(tempaccount.bank));
	tempaccount.money = 0;
	while (1)
	{
		printf("�н����带 �Է��Ͻʽÿ� : ");
		scanf("%d", &(tempaccount.password));
		printf("�ٽ� �ѹ� �Է��Ͻʽÿ� : ");
		scanf("%d", &password);
		if (password == tempaccount.password)
			break;
		else
			printf("�н����尡 �������� �ʽ��ϴ�.\n");
	}
	account.push_back(tempaccount);
}
void deposit()
{
	int flag;//�����ϴ� �����̸� 1, �������� �ʴ� �����̸� 0;
	int tempaccount;//�õ��ϴ� ��ī��Ʈ;
	int password;
	int cnt = 0;
	int i;
	int money;
	while (1)//�Ա��ϰ��� �ϴ� ���¹�ȣ �ޱ�
	{
		printf("���¹�ȣ�� �Է��Ͻÿ�:");
		scanf("%d", &tempaccount);
		flag = accountcheck(tempaccount);
		if (flag == 1)
			break;
		else
			printf("�������� �ʴ� ���¹�ȣ �Դϴ�. �ٽ� �Է��ϼ���!\n");
	}
	while (1)//������ ��й�ȣ �ޱ�(3ȸ �߸��Է��ϸ� �Ա� ����)
	{
		printf("�н����带 �Է��Ͻʽÿ� : ");
		scanf("%d", &password);
		if (passwordcheck(tempaccount, password) == 1)
			break;
		else
		{
			printf("�н����尡 �������� �ʽ��ϴ�.\n");
			cnt++;
		}
		if (cnt == 3)
		{
			printf("��й�ȣ�� 3ȸ �߸� �Է��ϼ̽��ϴ�.\n");
			break;
		}
	}
	if (cnt == 3)
	{
		printf("�ٽ� ó������ �����Ͽ� �ֽʽÿ�.\n");
	}
	else
	{
		for (i = 0; i < account.size(); i++)
		{
			if (account[i].account == tempaccount)
				break;
		}
		printf("�󸶸� �Ա��Ͻðڽ��ϱ�(�ܾ� : %d) : ", account[i].money);
		scanf("%d", &money);
		account[i].money += money;
		printf("%d�� ���� �ԱݵǾ����ϴ�.(�ܾ� : %d) ", money, account[i].money);

	}
}
void withdraw()
{
	int flag;//�����ϴ� �����̸� 1, �������� �ʴ� �����̸� 0;
	int tempaccount;//�õ��ϴ� ��ī��Ʈ;
	int password;
	int cnt = 0;
	int i;
	int money;
	while (1)//����ϰ��� �ϴ� ���¹�ȣ �ޱ�
	{
		printf("���¹�ȣ�� �Է��Ͻÿ�:");
		scanf("%d", &tempaccount);
		flag = accountcheck(tempaccount);
		if (flag == 1)
			break;
		else
			printf("�������� �ʴ� ���¹�ȣ �Դϴ�. �ٽ� �Է��ϼ���!\n");
	}
	while (1)//������ ��й�ȣ �ޱ�(3ȸ �߸��Է��ϸ� ��� ����)
	{
		printf("�н����带 �Է��Ͻʽÿ� : ");
		scanf("%d", &password);
		if (passwordcheck(tempaccount, password) == 1)
			break;
		else
		{
			printf("�н����尡 �������� �ʽ��ϴ�.\n");
			cnt++;
		}
		if (cnt == 3)
		{
			printf("��й�ȣ�� 3ȸ �߸� �Է��ϼ̽��ϴ�.\n");
			break;
		}
	}
	if (cnt == 3)
	{
		printf("�ٽ� ó������ �����Ͽ� �ֽʽÿ�.\n");
	}
	else
	{
		for (i = 0; i < account.size(); i++)
		{
			if (account[i].account == tempaccount)
				break;
		}
		while (1)
		{
			printf("�󸶸� ����Ͻðڽ��ϱ�(�ܾ� : %d) : ", account[i].money);
			scanf("%d", &money);
			if (money <= account[i].money)
			{
				account[i].money -= money;
				printf("%d�� ���� ��ݵǾ����ϴ�.(�ܾ� : %d) ", money, account[i].money);
				break;
			}
			else {
				printf("�ܾ��� �����մϴ�. �ٽ� �Է��Ͽ� �ֽʽÿ�.\n");
			}
		}

	}
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
		printf("-1.���°輳---------------\n");//createaccount();
		printf("-2.���-------------------\n");//withdraw();
		printf("-3.�Ա�-------------------\n");//deposit();
		printf("-4.�ܾ���ȸ---------------\n");//checkmoney();
		printf("-5.������ü---------------\n");//transfer();
		printf("-6.���»���---------------\n");//deleteaccount();
		printf("-7.������-----------------\n");
		printf("--------------------------\n");
		printf("�޴����� : ");
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
