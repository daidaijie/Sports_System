#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "logic.h"
#include <Windows.Applicationmodel.Activation.h>

char ID[20]; //ѧ��
char Name[10];  //ѧ������
int gender; //�Ա�
float Mark_Running;
float Mark_Jumping;
float Mark_shot;


void Show_Main_Page()
{
	system("cls");

	int iOrder = -1;
	printf_s("*************************�˶������ϵͳ*************************\n");
	printf_s("***********************��ϵͳ����ָ������***********************\n");
	printf_s("1. ����һ��ѧ����Ϣ\n");
	printf_s("2. ����ָ����ѧ����Ϣ(����/ѧ��)\n");
	printf_s("3. �޸�ָ��ѧ������Ϣ\n");
	printf_s("4. ����ѧ����Ϣ���ļ���\n");
	printf_s("5. ��ȡ�ļ��е�ѧ����Ϣ\n");
	printf_s("6. ɾ��ָ��ѧ������Ϣ\n");
	printf_s("7. �ָ�ɾ����ѧ����Ϣ\n");
	printf_s("8. ��ʾ��Ŀ�������\n");
	printf_s("9. ��ʾ����ѧ���ɼ�\n");
	printf_s("10. �˳�ϵͳ\n");
	printf_s("*****************************************************************\n\n");

	setColor(6, 0);
	printf_s("����ָ�\n");
	scanf_s("%d",&iOrder);

	switch (iOrder)
	{
	case 1: 
		//���ѧ����Ϣ
		printf_s("����ѧ��: ");
		getchar();
		gets_s(ID);
		printf_s("��������: ");
		gets_s(Name);
		printf_s("�����Ա�(��1/Ů0): ");
		scanf_s("%d",&gender);
		printf_s("�����ܲ��ɼ�,δ�μ���������: ");
		scanf_s("%f",&Mark_Running);
		printf_s("������Զ�ɼ�,δ�μ���������: ");
		scanf_s("%f", &Mark_Jumping);
		printf_s("����Ǧ��ɼ���δ�μ���������: ");
		scanf_s("%f", &Mark_shot);

		AddStuMSG(ID,Name,gender,Mark_Running, Mark_Jumping, Mark_shot);

		break;
	default:
		printf_s("ָ������!\n");
		break;
	}
}