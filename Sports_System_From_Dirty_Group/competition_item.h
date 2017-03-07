#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

typedef struct item
{
	char item_id[3];											//��Ŀ����
	char item_name[10];									//��Ŀ����
	int item_nature;										//��Ŀ����,1��������,2������
	char item_time[10];									//����ʱ��
	char item_location[10];								//�����ص�
	int item_stu[8] = {-1};								//�μӸ���Ŀ��ѧ��
	int item_number_of_students;					//�μӱ�����ѧ������
	item* pNext = NULL;									//��һ��������Ŀ
}ITEMNODE;

//���������ͷ��β
ITEMNODE* i_pHead = NULL;
ITEMNODE* i_pEnd = NULL;


//ע��һ��������Ŀ
void register_item(char* item_id, char* item_name, int item_nature, char* item_time, char* item_location) {
	ITEMNODE* pNode = (ITEMNODE*)malloc(sizeof(ITEMNODE));	 //����һ����Ŀ

	strcpy(pNode->item_id, item_id);
	strcpy(pNode->item_name, item_name);
	pNode->item_nature = item_nature;
	strcpy(pNode->item_time, item_time);
	strcpy(pNode->item_location, item_location);

	//���Ϊ�գ�ͷ��βָ�붼ָ���׽ڵ�
	if (NULL == i_pHead || NULL == i_pEnd)
	{
		i_pHead = pNode;
		i_pEnd = pNode;
		pNode->pNext = NULL;
		return;
	}

	ITEMNODE* pTemp = i_pHead;	//��������ÿһ���ڵ�
	ITEMNODE* tTemp = NULL;			//���ǰ�ýڵ�


	//�������Ϊ��,����Ŀ�����С�������ڵ�
	while (atoi(pNode->item_id) <= atoi(item_id))
	{
		//�������ѧ����ȣ�ֱ���˳�
		if (pTemp->item_id == pNode->item_id)
		{
			printf_s("error: �Ѵ��ڸ���Ŀ!\n");
			return;
		}

		tTemp = pTemp;
		pTemp = pTemp->pNext;

		if (pTemp == NULL)
			break;
	}

	//�պò���ͷ��
	if (pTemp == i_pHead)
	{
		pNode->pNext = pTemp;
		i_pHead = pNode;
		pTemp = NULL;
		return;
	}
	//����β��
	else if (pTemp == NULL) {
		tTemp->pNext = pNode;
		i_pEnd = pNode;
		pNode->pNext = NULL;
		return;
	}

	//�����м�
	else {
		tTemp->pNext = pNode;
		pNode->pNext = pTemp;
	}
}


//����ָ���ı�����Ŀ
ITEMNODE* Find_Item_By_ID_Or_Nmae(char* DATA)
{
	//�������ĺϷ���
	if (NULL == DATA)
	{
		//printf_s("�������!\n");
		return NULL;
	}

	//�ж������Ƿ�Ϊ��
	if (NULL == i_pHead || NULL == i_pEnd)
	{
		//printf_s("�޴˽ڵ�!\n");
		return NULL;
	}

	//��������
	ITEMNODE* pTemp = i_pHead;
	while (pTemp)
	{

		if ((0 == strcmp(pTemp->item_id, DATA)) || (0 == strcmp(pTemp->item_name, DATA)))
			return pTemp;
		pTemp = pTemp->pNext;
	}

	//printf_s("���޴˽ڵ�");
	return NULL;
}


//��Ŀ����
void Sign_Up_Item(char* stu_data, char* item_data) {

	//Ҫ��������Ŀ
	ITEMNODE* i_pTemp = Find_Item_By_ID_Or_Nmae(item_data);

	//������ѧ��
	STUNODE*  s_pTemp = Find_STU_By_ID_Or_Nmae(stu_data);

	//��������ĺϷ���
	if (NULL == stu_data || NULL == item_data)
	{
		printf_s("��Ч����Ŀ����ѧ����Ϣ!");
		return;
	}

	//ѧ���ѱ�����Ŀ��Ŀ���
	if (s_pTemp->item_count >= 3)
	{
		printf_s("�Բ���һ�����ֻ�ܱ�������������Ŀ!");
		return;
	}

	if (i_pTemp->item_number_of_students >= 8)
	{
		printf_s("����ʧ�ܣ�����Ŀ����!");
		return;
	}

	//��Ŀ�����ѧ�������ָ��

	//STUNODE** p_strArray = i_pTemp->item_stu;

	//������Ŀ�е�ѧ������
	int i = 0;
	while (i_pTemp->item_stu[i] == -1)
		i++;

	//����ѧ����ѧ����ӵ�����Ŀ��
	i_pTemp->item_stu[i] = atoi(s_pTemp->ID);
	//p_strArray[i - 1] = s_pTemp;

	//��ѧ����Ϣ����ӱ�������Ŀ

	for (int i=0;i<3;i++)
	{
		if (s_pTemp->item_score[i][0] == -1)
		{
			s_pTemp->item_score[i][0] = atoi(i_pTemp->item_id);
		}
	}
	
	//������ѧ������һ
	i_pTemp->item_number_of_students++;
}


//�ͷ���Ŀ����
void Free_Item_LinkedData()
{
	ITEMNODE* pTemp = i_pHead;
	while (i_pHead != NULL)
	{
		//��¼�ڵ�
		pTemp = i_pHead;

		//����ƶ�һλ
		i_pHead = i_pHead->pNext;

		//�ͷ�����
		free(pTemp);
	}
}

//���������Ϣ���ļ���
void Save_Item_To_File()
{
	FILE* pFile = NULL;
	ITEMNODE* pTemp = i_pHead;
	char strBuf[120] = { '\0' };
	char strScore[20] = { '\0' };
	char* buf;

	//�ж������Ƿ�Ϊ��
	if (NULL == i_pHead)
	{
		printf_s("��Ŀ��ϢΪ��!");
		return;
	}

	//���ļ�
	pFile = fopen("item.txt", "wb+");
	if (NULL == pFile)
	{
		printf_s("�ļ���ʧ��\n");
		return;
	}


	//�����ļ�ָ��
	while (pTemp)
	{
		//������Ŀ����
		strcat(strBuf, pTemp->item_name);
		strcat(strBuf, "#");
		//������Ŀ����
		strcat(strBuf, pTemp->item_name);
		strcat(strBuf, "#");
		//��Ŀ����
		if (pTemp->item_nature == 1)
			strcat(strBuf, "1");
		else if (pTemp->item_nature == 2)
			strcat(strBuf, "2");
		strcat(strBuf, "#");
		//���Ʊ���ʱ��
		strcat(strBuf, pTemp->item_time);
		strcat(strBuf, "#");
		//���Ʊ����ص�
		strcat(strBuf, pTemp->item_location);
		strcat(strBuf, "#");
		puts(strBuf);
		//���Ʊ�������
		itoa(pTemp->item_number_of_students,buf,10);
		strcat(strBuf, buf);
		strcat(strBuf, "#");
		//���Ʊ�����ѧ����Ϣ
		for (int i=0;i<8;i++)
		{
			if (pTemp->item_stu[i] != -1)
			{
			    itoa(pTemp->item_stu[i],buf,10);
				strcat(strBuf, buf);
				strcat(strBuf, "#");
			}
		}

		//д���ļ�
		fwrite(strBuf, 1, strlen(strBuf), pFile);
		fwrite("\r\n", 1, strlen("\r\n"), pFile);

		pTemp = pTemp->pNext;
	}

	//�ر��ļ�
	fclose(pFile);
}

//��ȡ�ļ��еı�����Ŀ��Ϣ
void Read_Item_From_File()
{
	FILE *pFile = fopen("item.txt", "rb+");
	if (NULL == pFile)
	{
		printf_s("�ļ���ʧ��\n");
		return;
	}

	char strBuf[120] = { '\0' };
	char item_id[3];											//��Ŀ����
	char item_name[10];									//��Ŀ����
	int item_nature;										//��Ŀ����,1��������,2������
	char item_time[10];									//����ʱ��
	char item_location[10];								//�����ص�
	int item_stu[8] = { -1 };								//�μӸ���Ŀ��ĳ��ѧ��
	int item_number_of_students;					//�μӱ�����ѧ������

	//����ָ�룬��ȡ����
	while (fgets(strBuf, 120, pFile))
	{
		int nCount = 0;
		char delims[] = "#";
		char *result = NULL;

		//�ַ����и�
		result = strtok(strBuf, delims);
		strcpy(item_id,result);

		while (NULL != result)
		{
			//�������оͽ���
			if (strcmp(result, "\r\n") == 0)
				break;

			result = strtok(NULL, delims);
			if (0 == nCount)
				strcpy(item_name, result);
			if (1 == nCount) 
				item_nature = atoi(result);
			if (2 == nCount)
				strcpy(item_time, result);
			if (3 == nCount)
				strcpy(item_location, result);
			if (4 == nCount)
			{
				for (int i = 0; i < 8; i++)
				{
					if (item_stu[i] != -1)
					{
						item_stu[i] = atoi(result);
					}
				}
			}
			nCount++;

		}

		//���ļ��е���Ϣ��ӵ�������
		Add_Stu_MSG(college, ID, Name, gender);
	}
	fclose(pFile);
}



//��ʾ��Ŀ��Ϣ
void Show_Com_info()
{
	setColor(10, 0);
	ITEMNODE* pTemp = i_pHead;

	if (NULL == i_pHead | NULL == i_pEnd)
	{
		printf_s("������Ŀ��ϢΪ�գ�\n");
		return;
	}

	system("cls");
	printf_s("��Ŀ����\t��Ŀ����\t��Ŀ����\t��Ŀʱ��\t��Ŀ�ص�\t\n");

	while (pTemp != NULL)
	{
		printf_s("%s\t", pTemp->item_id);
		if (pTemp->item_nature == 1)
			printf_s("����\t");
		else if (pTemp->item_nature == 2)
			printf_s("����\t");
		else
			printf_s("\t");
		printf_s("%s\t%d\t%s\t$s\t\n", pTemp->item_name, pTemp->item_nature, pTemp->item_time, pTemp->item_location);

	}
}