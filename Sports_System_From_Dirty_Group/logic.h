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
	float Mark_Shot;
	Student* pnext;  //ָ��
} STUNODE;

//���������ͷ��β
STUNODE* g_pHead = NULL;
STUNODE* g_pEnd = NULL;


//���ѧ����Ϣ
void AddStuMSG(char* arrStuID, char* arrStuName, int gender, float Mark_Running, float Mark_Jumping, float Mark_Shot)
{
	//��������ĺϷ���
	if (NULL == arrStuName|| NULL == arrStuID || Mark_Jumping<0 || Mark_Running<0 || Mark_Shot<0)
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
	pTemp->Mark_Shot = Mark_Shot;
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
	if (NULL == g_pHead || NULL == g_pEnd)
	{
		printf_s("ѧ����ϢΪ��!\n");
		return;
	}


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
		printf_s("%8.2f\t%8.2f\t%8.2f\n", pTemp->Mark_Running, pTemp->Mark_Jumping, pTemp->Mark_Shot);
		
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
	printf_s("%8.2f\t%8.2f\t%8.2f\n", pTemp->Mark_Running, pTemp->Mark_Jumping, pTemp->Mark_Shot);
}



//����ָ����ѧ��
STUNODE* FindSTUByIDOrNmae(char* DATA)
{
	//�������ĺϷ���
	if (NULL == DATA)
	{
		//printf_s("�������!\n");
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



void ModifyStuData(STUNODE* pTemp)
{
	setColor(10, 0);
	char cOrder = 'q';
	int flag = 1;

	if(NULL == pTemp)
	{
		printf_s("���޴���!\n");
		return;
	}

	showSingleSTU(pTemp);
	printf_s("\n");


	//�޸�ѧ����Ϣ
	char ID[20]; //ѧ��
	char Name[10];  //ѧ������
	int gender; //�Ա�
	float Mark_Running;
	float Mark_Jumping;
	float Mark_Shot;


	//�޸�ѧ��
	printf_s("�������µ�ѧ��(�����޸�������0): ");
	getchar();
	gets_s(ID);
	if (strcmp(ID, "0") != 0) {
		while (flag) {
			printf_s("�Ƿ�Ҫ��ѧ��%s�޸�Ϊ%s�� y/n\n", pTemp->ID, ID);
			scanf_s("%c", &cOrder);
			if (cOrder == 'y') {
				strcpy(pTemp->ID, ID);
				flag = 0;
			} 
		}
		flag = 1;
	}

	//�޸�����
	printf_s("�������µ�����(�����޸�������0): ");
	getchar();
	gets_s(Name);
	if (strcmp(Name, "0") != 0) {
		while (flag) {
			printf_s("�Ƿ�Ҫ������%s�޸�Ϊ%s�� y/n\n", pTemp->Name, Name);
			scanf_s("%c", &cOrder);
			if (cOrder == 'y') {
				strcpy(pTemp->Name, Name);
				flag = 0;
			}
		}
		flag = 1;
	}

	//�޸��Ա�
	printf_s("�������µ��Ա�(�����޸�������0): ");
	getchar();
	scanf_s("%d", &gender);
	if ( gender!=0 ) {
		while (flag) {
			printf_s("�Ƿ�Ҫ���ձ�%d�޸�Ϊ%d�� y/n\n", pTemp->gender, gender);
			scanf_s("%c", &cOrder);
			if (cOrder == 'y') {
				pTemp->gender = gender;
				flag = 0;
			}
		}
		flag = 1;
	}

	//�޸�100���ܳɼ�
	printf_s("�������µ�100���ܳɼ�(�����޸�������-1): ");
	getchar();
	scanf_s("%f", &Mark_Running);
	if ( Mark_Running!= -1) {
		while (flag) {
			printf_s("�Ƿ�Ҫ��100���ܳɼ�%.2f���޸�Ϊ%.2f�룿 y/n\n", pTemp->Mark_Running, Mark_Running);
			scanf_s("%c", &cOrder);
			if (cOrder == 'y') {
				pTemp->Mark_Running = Mark_Running;
				flag = 0;
			}
		}
		flag = 1;
	}


	//�޸���Զ�ɼ�
	printf_s("�������µ���Զ�ɼ�(�����޸�������-1): ");
	getchar();
	scanf_s("%f", &Mark_Jumping);
	if (Mark_Jumping != -1) {
		while (flag) {
			printf_s("�Ƿ�Ҫ����Զ�ɼ�%.2f���޸�Ϊ%.2f�ף� y/n\n", pTemp->Mark_Jumping, Mark_Jumping);
			scanf_s("%c", &cOrder);
			if (cOrder == 'y') {
				pTemp->Mark_Jumping = Mark_Jumping;
				flag = 0;
			}
		}
		flag = 1;
	}

	//�޸�Ǧ��ɼ�
	printf_s("�������µ�Ǧ��ɼ�(�����޸�������-1): ");
	getchar();
	scanf_s("%f", &Mark_Shot);
	if (Mark_Shot != -1) {
		while (flag) {
			printf_s("�Ƿ�Ҫ��Ǧ��ɼ�%.2f���޸�Ϊ%.2f�ף� y/n\n", pTemp->Mark_Shot, Mark_Shot);
			scanf_s("%c", &cOrder);
			if (cOrder == 'y') {
				pTemp->Mark_Shot = Mark_Shot;
				flag = 0;
			}
		}
		flag = 1;
	}
}

void DeleteStuData(STUNODE* pNode)
{
	if (NULL == pNode)
	{
		printf_s("���޴���!\n");
		return;
	}

	//ֻ��һ���ڵ�
	if (g_pHead == g_pEnd)
	{
		free(g_pHead);
		g_pHead = NULL;
		g_pEnd = NULL;
	}
	// ֻ�������ڵ�
	else if (g_pHead->pnext == g_pEnd) {
		//�������������ͷ
		if (g_pHead == pNode) {
			free(g_pHead);
			g_pHead = g_pEnd;
		}
		//�������������β
		if (g_pEnd == pNode) {
			free(g_pEnd);
			g_pEnd = g_pHead;
			g_pHead->pnext = NULL; //С��Ұָ��
		}
		//�ڵ������ڵ�����
		else {
			STUNODE* pTemp = g_pHead;

			//�ж�ͷ
			if (g_pHead == pNode)
			{
				//��סͷ
				pTemp = g_pHead;
				g_pHead = g_pHead->pnext;
				free(pTemp);
				pTemp = NULL;
				return;
			}

			while (pTemp)
			{
				if (pTemp->pnext == pNode) 
				{

					//�ж�β
					if (g_pEnd = pNode)
					{
						//ɾ��
						free(pNode);
						pNode = NULL;
						g_pEnd = pTemp;
						pTemp->pnext = NULL;
						return;
					}

					pTemp->pnext = pNode->pnext;
					free(pNode);
				}
					pTemp = pTemp->pnext;
			}
		}
	}
}
