#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

typedef struct item
{
	char item_name[10];		//��Ŀ����
	int item_nature;			//��Ŀ����,1��������,2������
	STUNODE* stu = NULL;				//�μӸ���Ŀ��ĳ��ѧ��
	//int item_number_of_students;  //�μӱ�����ѧ������
	float item_grade = 0;			//�����ɼ�
	int item_score = 0;				//���˵÷�;
	item* pNext = NULL;;					//��һ���μӸ���Ŀ��ѧ������
}ITEMNODE;

//���������ͷ��β
ITEMNODE* i_pHead = NULL;
ITEMNODE* i_pEnd = NULL;


//ע��һ��������Ŀ
void regiter_item(char* item_name, int item_nature, ) {
	ITEMNODE* pNode = (ITEMNODE*)malloc(sizeof(ITEMNODE));	 //����һ����Ŀ
	strcpy(pNode->item_name, item_name);
	pNode->item_nature = item_nature;

	//ͷ��βָ�붼ָ���׽ڵ�
	i_pHead = pNode;
	i_pEnd = pNode;
}


//��Ŀ����
void sign_up_item(STUNODE* pNode, ) {

}