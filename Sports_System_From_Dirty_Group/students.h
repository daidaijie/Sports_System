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
	int item_count = 0;  //��¼�ѱ�����Ŀ����Ŀ

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
	STUNODE* pNode = (STUNODE*)malloc(sizeof(STUNODE));
	//�ڵ��Ա��ʼ��
	strcpy(pNode->ID, arrStuID);
	strcpy(pNode->Name, arrStuName);
	pNode->gender = gender;
	pNode->Mark_Jumping = Mark_Jumping;
	pNode->Mark_Running = Mark_Running;
	pNode->Mark_Shot = Mark_Shot;
	pNode->pnext = NULL;

	//��������β����
	//�������Ϊ��
	if (NULL == g_pHead || NULL == g_pEnd)
	{
		g_pHead = pNode;
		g_pEnd = pNode;
		return;
	}

	STUNODE* pTemp = g_pHead; //��������ÿһ���ڵ�
	STUNODE* tTemp = NULL;	//���ǰ�ýڵ�


	//�������Ϊ��,��ѧ�Ŵ�С�������ڵ�
 	while (atoi(pTemp->ID) <= atoi(pNode->ID))
	{
		//�������ѧ����ȣ�ֱ���˳�
		if (atoi(pTemp->ID) == atoi(pNode->ID))
		{
			printf_s("error: �Ѵ��ڸ�ѧ�ŵ�ѧ��!\n");
			return;
		}

		tTemp = pTemp;
		pTemp = pTemp->pnext;

		if (pTemp == NULL)
			break;
	}

	//�պò���ͷ��
	if (pTemp == g_pHead)
	{
		pNode->pnext = pTemp;
		g_pHead = pNode;
		pTemp = NULL;
		return;
	}
	//����β��
	else if (pTemp == NULL){
		tTemp->pnext = pNode;
		g_pEnd = pNode;
		pNode->pnext = NULL;
		return;
	}

	//�����м�
	else {
		tTemp->pnext = pNode;
		pNode->pnext = pTemp;
	}
	//else {
	//	g_pEnd->pnext = pNode;	//����
	//	g_pEnd = pNode;  //�ƶ�
	//}

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

	system("cls");
	printf_s("   ѧ��\t\t����\t\t�Ա�\t\t100��(��λ:��)\t\t��Զ(��λ:��) \t\tǦ��(��λ:��)\n");

	while (pTemp != NULL)
	{
		printf_s("%10s\t%4s\t\t",pTemp->ID, pTemp->Name);
		char* sOrder_Male = "��";
		char* sOrder_Female = "Ů";
		if (pTemp->gender == 1)
			printf_s("%4s\t\t", sOrder_Male);
		else printf_s("%4s\t\t", sOrder_Female);
		printf_s("%8.2f\t\t%8.2f\t\t%8.2f\n", pTemp->Mark_Running, pTemp->Mark_Jumping, pTemp->Mark_Shot);
		
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
	printf_s("  ѧ��\t\t����\t\t�Ա�\t\t�ܲ�\t\t��Զ \t\tǦ��\n");
	printf_s("%10s\t%4s\t\t", pTemp->ID, pTemp->Name);
	char* sOrder_Male = "��";
	char* sOrder_Female = "Ů";
	if (pTemp->gender == 1)
		printf_s("%8s\t\t", sOrder_Male);
	else printf_s("%8s\t\t", sOrder_Female);
	printf_s("%8.2f\t\t%8.2f\t\t%8.2f\n", pTemp->Mark_Running, pTemp->Mark_Jumping, pTemp->Mark_Shot);
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

//ɾ��ѧ����Ϣ
void DeleteStuData(STUNODE* pNode)
{
	//printf_s("����ɾ�����,ͷ��%s\n",g_pHead->ID);
	//printf_s("����ɾ�����,β��%s\n", g_pEnd->ID);
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
	char strBuf[60] = {'\0'};
	char strScore[20] = { '\0' };

	//�ж������Ƿ�Ϊ��
	if (NULL == g_pHead)
	{
		printf_s("ѧ����ϢΪ��!");
		return;
	}

	//���ļ�
	pFile = fopen("students.txt","wb+");
	if (NULL == pFile)
	{
		printf_s("�ļ���ʧ��\n");
		return;
	}


	//�����ļ�ָ��
	while (pTemp)
	{
		//ѧ�Ÿ��ƽ�ȥ
		strcpy(strBuf,pTemp->ID);
		strcat(strBuf,"#");
		//����
		strcat(strBuf,pTemp->Name);
		strcat(strBuf, "#");
		//�Ա�
		//itoa(pTemp->gender,strScore,10);
		if (pTemp->gender==0)
			strcat(strBuf, "0");
		else strcat(strBuf, "1");
		//strcat(strBuf,strScore);
		strcat(strBuf, "#");
		//100���ܳɼ�
		sprintf(strScore, "%.3f", pTemp->Mark_Running);
		//itoa(pTemp->Mark_Running, strScore, 10);
		strcat(strBuf, strScore);
		strcat(strBuf, "#");
		//��Զ�ɼ�
		sprintf(strScore, "%.3f", pTemp->Mark_Jumping);
		//itoa(pTemp->Mark_Jumping, strScore, 10);
		strcat(strBuf, strScore);
		strcat(strBuf, "#");
		//Ǧ��ɼ�
		sprintf(strScore, "%.3f", pTemp->Mark_Shot);
		//itoa(pTemp->Mark_Shot, strScore, 10);
		strcat(strBuf, strScore);
		strcat(strBuf, "#");

		//д���ļ�
		fwrite(strBuf, 1 , strlen(strBuf) , pFile );
		fwrite("\r\n",1,strlen("\r\n"),pFile);

		pTemp = pTemp->pnext;	
	}

	//�ر��ļ�
	fclose(pFile);
}


//��ȡ�ļ��е�ѧ����Ϣ
void ReadSTUFromFile()
{
	FILE *pFile = fopen("students.txt","rb+");
	if (NULL == pFile)
	{
		printf_s("�ļ���ʧ��\n");
		return;
	}

	char strBuf[60] = { '\0' };
	char ID[20]; //ѧ��
	char Name[10];  //ѧ������
	int gender; //�Ա�
	float Mark_Running;
	float Mark_Jumping;
	float Mark_Shot;

	//����ָ�룬��ȡ����
	while (fgets(strBuf, 60, pFile))
	{
		int nCount = 0;
		char delims[] = "#";
		char *result = NULL;

		//�ַ����и�
		result = strtok(strBuf, delims);
		strcpy(ID, result);

		while (NULL != result)
		{
			//�������оͽ���
			if (strcmp(result,"\r\n")==0)
				break;

			result = strtok(NULL, delims);
			if (0 == nCount)
				strcpy(Name, result);
			//puts(Name);

			if (1 == nCount) {
				gender = atoi(result);
				//printf_s("%d\n", gender);
			}
			if (2 == nCount)
			{
				Mark_Running = atof(result);
				//printf_s("%f\n", Mark_Running);
			}
			if (3 == nCount)
			{
				Mark_Jumping = atof(result);
				//printf_s("%f\n", Mark_Jumping);
			}
			if (4 == nCount)
			{
				Mark_Shot = atof(result);
				//printf_s("%f\n", Mark_Shot);
			}
			nCount++;

		}

		//���ļ��е���Ϣ��ӵ�������
		AddStuMSG(ID, Name, gender, Mark_Running, Mark_Jumping, Mark_Shot);
	}
	fclose(pFile);
}


//��ʾ100������Ϣ
void ShowRunningMes()
{
	setColor(10, 0);
	printf_s("   ѧ��\t\t����\t\t�ɼ�\t\t����\n");

}