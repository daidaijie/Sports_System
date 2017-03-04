#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "login_page.h"
#include "main_page.h"


char Account[20];
char Password[20];
char Property;
FILE *fp = NULL;
char filebuf[30];

int read_from_file(FILE* pFile, char* account,char* password);

int Password_judge(char* account, char* password, char property)
{
	//�ж��˻�����
	switch (property)
	{
	case '1': {
		FILE *pFile = fopen("students_password.txt", "rb+");
		if (NULL == pFile)
		{
			printf_s("�ļ���ʧ��\n");
			return 0;
		}

		//�����ļ�ָ�룬��ȡ����
		int s = read_from_file(pFile, account, password);
		return s;
		break;
	}

	case '2': {
		FILE *pFile = fopen("teachers_password.txt", "rb+");
		if (NULL == pFile)
		{
			printf_s("�ļ���ʧ��\n");
			return 0;
		}

		//�����ļ�ָ�룬��ȡ����
		int s = read_from_file(pFile, account, password);
		return s;
		break;
	}

	case 'x': {
		FILE *pFile = fopen("admin_password.txt", "rb+");
		if (NULL == pFile)
		{
			printf_s("�ļ���ʧ��\n");
			return 0;
		}

		//�����ļ�ָ�룬��ȡ����
		int s = read_from_file(pFile, account, password);
		return s;
		break;
	}

	default:
		break;
	}

}


void read_account_password_property()
{
	SetPos(25, 5);
	gets_s(Account);
	SetPos(25, 6);
	gets_s(Password);
	SetPos(25,7);
	Property = getchar();
	getchar();
}


void Login()
{	
	read_account_password_property();

	int s = Password_judge(Account, Password,Property);  //s���������Ƿ���ȷ���ж�
	if (s == 0)
	{
		SetPos(20,8);
		printf_s("������˺Ŵ�������������!");
		read_account_password_property();
	}

	if (s == 1)
	{
		Show_Main_Page();
	}
}

//�ļ���ȡ����
int read_from_file(FILE* pFile, char* account, char* password) 
{
	while (fgets(filebuf, 30, pFile)) {
		int nCount = 0;
		char delims[] = "#";
		char *result = NULL;

		//�ַ����и�
		result = strtok(filebuf, delims);
		if (strcmp(account, result) == 0) {
			result = strtok(filebuf, delims);
			if (strcmp(account, result) == 0) {
				return 1;
			}
		}

	}
	return 0;
}