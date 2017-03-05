
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

typedef struct item
{
	int id;							//��Ŀ����
	char item_name[10];		//��Ŀ����
	int item_nature;			//��Ŀ����,1��������,2������
	char item_time[10];			    //����ʱ��
	char item_location[10];			//�����ص�
	STUNODE* stu[100] = { NULL };				//�μӸ���Ŀ��ĳ��ѧ��
	//int item_number_of_students;  //�μӱ�����ѧ������
	float item_grade = 0;			//�����ɼ�
	int item_score = 0;				//���˵÷�;
	item* pNext = NULL;;					//��һ���μӸ���Ŀ��ѧ������
}ITEMNODE;

//���������ͷ��β
ITEMNODE* i_pHead = NULL;
ITEMNODE* i_pEnd = NULL;


//ע��һ��������Ŀ
void register_item(int id, char* item_name, int item_nature, char* item_time, char* item_location) {
	ITEMNODE* pNode = (ITEMNODE*)malloc(sizeof(ITEMNODE));	 //����һ����Ŀ
	pNode->id = id;
	strcpy(pNode->item_name, item_name);
	pNode->item_nature = item_nature;
	strcpy(pNode->item_time, item_time);
	strcpy(pNode->item_location, item_location);

	//ͷ��βָ�붼ָ���׽ڵ�
	i_pHead = pNode;
	i_pEnd = pNode;
}


//��Ŀ����
void sign_up_item(STUNODE* pNode) {
	return;
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

	system("cls");
	printf_s(" ѧԺ\t\tѧ��\t\t����\t\t�Ա�\n");

	while (pTemp != NULL)
	{
		if (pTemp->college == 1)
			printf_s("��ѧԺ\t\t");
		else if (pTemp->college == 2)
			printf_s("ҽѧԺ\t\t");
		else if (pTemp->college == 3)
			printf_s("��ѧԺ\t\t");
		printf_s("%10s\t%4s\t\t", pTemp->ID, pTemp->Name);
		char* sOrder_Male = "��";
		char* sOrder_Female = "Ů";
		if (pTemp->gender == 1)
			printf_s("%4s\n", sOrder_Male);
		else printf_s("%4s\n", sOrder_Female);

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

	setColor(10, 0);
	system("cls");
	printf_s(" ѧԺ\t\tѧ��\t\t����\t\t�Ա�\n");
	if (pTemp->college == 1)
		printf_s("��ѧԺ\t\t");
	else if (pTemp->college == 2)
		printf_s("ҽѧԺ\t\t");
	else if (pTemp->college == 3)
		printf_s("��ѧԺ\t\t");
	printf_s("%10s\t%4s\t\t", pTemp->ID, pTemp->Name);
	char* sOrder_Male = "��";
	char* sOrder_Female = "Ů";
	if (pTemp->gender == 1)
		printf_s("%4s\n", sOrder_Male);
	else printf_s("%4s\n", sOrder_Female);
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

	//printf_s("���޴˽ڵ�");
	return NULL;
}



void ModifyStuData(STUNODE* pTemp)
{
	setColor(10, 0);
	char cOrder = 'q';
	int flag = 1;

	if (NULL == pTemp)
	{
		printf_s("���޴���!\n");
		return;
	}

	showSingleSTU(pTemp);
	printf_s("\n");


	//�޸�ѧ����Ϣ
	int college;			//ѧԺ
	char ID[20];			//ѧ��
	char Name[10];    //ѧ������
	int gender;		   //�Ա�

					   //�޸�ѧԺ
	printf_s("�������µ�ѧԺ(��1ҽ2��3--�����޸�������0): ");
	getchar();
	scanf_s("%d", &college);
	if (college != 0) {
		while (flag) {
			printf_s("�Ƿ�Ҫ��ѧԺ����%d�޸�Ϊ%d�� y/n\n", pTemp->college, college);
			scanf_s("%c", &cOrder);
			if (cOrder == 'y') {
				pTemp->college = college;
				flag = 0;
			}
		}
		flag = 1;
	}

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
	if (gender != 0) {
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
}

//ɾ��ѧ����Ϣ
void DeleteStuData(STUNODE* pNode) {
	if (NULL == pNode)
	{
		printf_s("���޴���!\n");
		return;
	}

	//ֻ��һ���ڵ�
	if (g_pHead == g_pEnd)
	{
		//printf_s("����1\n");
		free(g_pHead);
		g_pHead = NULL;
		g_pEnd = NULL;
	}
	// ֻ�������ڵ�
	else if (g_pHead->pnext == g_pEnd) {
		//printf_s("����2\n");
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
	}

	//�ڵ������ڵ�����
	else {
		//printf_s("����3\n");
		STUNODE* pTemp = g_pHead;

		//�ж�ͷ
		if (g_pHead == pNode)
		{
			//��סͷ
			//printf_s("%s���ǲ���1\n", g_pHead->ID);
			pTemp = g_pHead;
			g_pHead = g_pHead->pnext;
			//printf_s("%s���ǲ���2\n", g_pHead->ID);
			free(pTemp);
			pTemp = NULL;
			return;
		}

		//printf_s("%s���ǲ���3\n", pNode->ID);
		while (pTemp)
		{
			if (pTemp->pnext == pNode)
			{

				//�ж�β
				if (g_pEnd == pNode)
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
				return;
			}
			pTemp = pTemp->pnext;
		}
	}
}


//������Ϣ���ļ���
void SaveStuToFile()
{
	FILE* pFile = NULL;
	STUNODE* pTemp = g_pHead;
	char strBuf[60] = { '\0' };
	char strScore[20] = { '\0' };

	//�ж������Ƿ�Ϊ��
	if (NULL == g_pHead)
	{
		printf_s("ѧ����ϢΪ��!");
		return;
	}

	//���ļ�
	pFile = fopen("students.txt", "wb+");
	if (NULL == pFile)
	{
		printf_s("�ļ���ʧ��\n");
		return;
	}


	//�����ļ�ָ��
	while (pTemp)
	{
		//����ѧԺ
		if (pTemp->college == 1)
			strcat(strBuf, "1");
		else if (pTemp->college == 2)
			strcat(strBuf, "2");
		else if (pTemp->college == 3)
			strcat(strBuf, "3");
		strcat(strBuf, "#");
		//ѧ�Ÿ��ƽ�ȥ
		strcpy(strBuf, pTemp->ID);
		strcat(strBuf, "#");
		//����
		strcat(strBuf, pTemp->Name);
		strcat(strBuf, "#");
		//�Ա�
		//itoa(pTemp->gender,strScore,10);
		if (pTemp->gender == 0)
			strcat(strBuf, "0");
		else strcat(strBuf, "1");
		//strcat(strBuf,strScore);
		strcat(strBuf, "#");

		//д���ļ�
		fwrite(strBuf, 1, strlen(strBuf), pFile);
		fwrite("\r\n", 1, strlen("\r\n"), pFile);

		pTemp = pTemp->pnext;
	}

	//�ر��ļ�
	fclose(pFile);
}


//��ȡ�ļ��е�ѧ����Ϣ
void ReadSTUFromFile()
{
	FILE *pFile = fopen("students.txt", "rb+");
	if (NULL == pFile)
	{
		printf_s("�ļ���ʧ��\n");
		return;
	}

	char strBuf[60] = { '\0' };
	int college;			//ѧԺ
	char ID[20];			//ѧ��
	char Name[10];    //ѧ������
	int gender;		   //�Ա�

					   //����ָ�룬��ȡ����
	while (fgets(strBuf, 60, pFile))
	{
		int nCount = 0;
		char delims[] = "#";
		char *result = NULL;

		//�ַ����и�
		result = strtok(strBuf, delims);
		college = atoi(result);

		while (NULL != result)
		{
			//�������оͽ���
			if (strcmp(result, "\r\n") == 0)
				break;

			result = strtok(NULL, delims);
			if (0 == nCount)
				strcpy(ID, result);
			//puts(Name);

			if (1 == nCount) {
				strcpy(Name, result);
				//printf_s("%d\n", gender);
			}
			if (2 == nCount)
			{
				gender = atoi(result);
				//printf_s("%f\n", Mark_Running);
			}
			nCount++;

		}

		//���ļ��е���Ϣ��ӵ�������
		AddStuMSG(college, ID, Name, gender);
	}
	fclose(pFile);
}