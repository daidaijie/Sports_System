// Sports_System_From_Dirty_Group.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include "display.h"
#define MAX 1000


struct Student
{
	char ID[20]; //ѧ��
	char Name[10];  //ѧ������
	bool gender; //�Ա�
	float Mark_Running;
	float Mark_Juming;
	float Mark_shot;
	float Credits; //����
};

struct Student students[100];



int main()
{
	display();
}

