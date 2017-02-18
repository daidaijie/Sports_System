#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student
{
	char ID[20]; //ѧ��
	char Name[10];  //ѧ������
	int gender; //�Ա�
	float Mark_Running;
	float Mark_Jumping;
	float Mark_shot;
	Student* pnext;  //ָ��
} STUNODE;

//���������ͷ��β
STUNODE* g_pHead = NULL;
STUNODE* g_pEnd = NULL;


//���ѧ����Ϣ
void AddStuMSG(char* arrStuID, char* arrStuName, int gender, float Mark_Running, float Mark_Jumping, float Mark_shot)
{
	//��������ĺϷ���
	if (NULL == arrStuName|| NULL == arrStuID || Mark_Jumping<0 || Mark_Running<0 || Mark_shot<0)
	{
		printf_s("ѧ����Ϣ����");
		return;
	}

	//�߼�
	//����һ���ڵ�
	STUNODE* pTemp = (STUNODE*)malloc(sizeof(STUNODE));
	//�ڵ��Ա��ʼ��
	strcpy(pTemp->ID, arrStuID);
	strcpy(pTemp->Name, arrStuName);
	pTemp->Mark_Jumping = Mark_Jumping;
	pTemp->Mark_Running = Mark_Running;
	pTemp->Mark_shot = Mark_shot;
	pTemp->pnext = NULL;

	//��������β����
	if (NULL == g_pHead || NULL == g_pEnd)
	{
		g_pHead = pTemp;
		g_pEnd = pTemp;
	}
	else {
		g_pEnd->pnext = pTemp;	//����
		g_pEnd = pTemp;  //�ƶ�
	}

	/*��������ͷ����
	if (g_pHead == NULL || g_pEnd == NULL)
	{
		g_pHead = pTemp;
		g_pEnd = pTemp;
	}
	else{
		pTemp->pnext = g_pHead;
		g_pHead = pTemp;
	}
	*/
}

void FreeLinkedData()
{
	STUNODE* pTemp = g_pHead;
	while (g_pHead != NULL)
	{
		//��¼�ڵ�
		pTemp = g_pHead;

		//����ƶ�һλ
		g_pHead = g_pHead->pnext;

		//�ͷ�����
		free(pTemp);
	}
}

//��ʾ����ѧ����Ϣ
void ShowStuData()
{
	setColor(10, 0);
	STUNODE* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		system("cls");
		printf_s("  ѧ��\t\t����\t\t�Ա�\t\t�ܲ�\t\t��Զ \t\tǦ��\n");
		printf_s("%10s\t%4s\t",pTemp->ID, pTemp->Name);
		char* sOrder_Male = "��";
		char* sOrder_Female = "Ů";
		if (pTemp->gender == 1)
			printf_s("%8s\t",sOrder_Male);
		else printf_s("%8s\t",sOrder_Female);
		printf_s("%8.2f\t%8.2f\t%8.2f\n", pTemp->Mark_Running, pTemp->Mark_Jumping, pTemp->Mark_shot);
		
		//������һ��
		pTemp = pTemp->pnext;
	}
}

//��ʾָ��ѧ����Ϣ
void showSingleSTU(STUNODE* pTemp)
{
	if (NULL == pTemp)
	{
		printf_s("���޴���!\n");
		return;
	}

	system("cls");
	printf_s("  ѧ��\t\t����\t\t�Ա�\t\t�ܲ�\t\t��Զ \t\tǦ��\n");
	printf_s("%10s\t%4s\t", pTemp->ID, pTemp->Name);
	char* sOrder_Male = "��";
	char* sOrder_Female = "Ů";
	if (pTemp->gender == 1)
		printf_s("%8s\t", sOrder_Male);
	else printf_s("%8s\t", sOrder_Female);
	printf_s("%8.2f\t%8.2f\t%8.2f\n", pTemp->Mark_Running, pTemp->Mark_Jumping, pTemp->Mark_shot);
}



//����ָ����ѧ��
STUNODE* FindSTUByIDOrNmae(char* DATA)
{
	//�������ĺϷ���
	if (NULL == DATA)
	{
		printf_s("ѧ���������!\n");
		return NULL;
	}

	//�ж������Ƿ�Ϊ��
	if (NULL == g_pHead || NULL == g_pEnd)
	{
		//printf_s("�޴˽ڵ�!\n");
		return NULL;
	}

	//��������
	STUNODE* pTemp = g_pHead;
	while (pTemp)
	{

		if ((0 == strcmp(pTemp->ID, DATA)) || (0 == strcmp(pTemp->Name, DATA)))
			return pTemp;
		pTemp = pTemp->pnext;
	}

	printf_s("���޴˽ڵ�");
	return NULL;
}
