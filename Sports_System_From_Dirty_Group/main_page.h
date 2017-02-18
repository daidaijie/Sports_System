#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logic.h"
#include <Windows.Applicationmodel.Activation.h>

char ID[20]; //ѧ��
char Name[10];  //ѧ������
int gender; //�Ա�
float Mark_Running;
float Mark_Jumping;
float Mark_shot;
char bOrder = 'q';
char sOrder[20];
int flag = 1;


void Show_Menu()
{
	system("cls");
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
	printf_s("����ָ�\n");
}

void ReturnToMainMenu() {
	printf_s("�Ƿ񷵻���ҳ��: y/n\n");
	getchar();
	scanf_s("%c", &bOrder);
	if (bOrder == 'y')
		Show_Menu();
}


void Show_Main_Page()
{
	while (flag) {
		setColor(10, 0);
		int iOrder = -1;
		Show_Menu();
		setColor(6, 0);
		scanf_s("%d", &iOrder);

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
			scanf_s("%d", &gender);
			printf_s("����100�׳ɼ�(��λ: ��),δ�μ���������: ");
			scanf_s("%f", &Mark_Running);
			printf_s("������Զ�ɼ�(��λ: ��),δ�μ���������: ");
			scanf_s("%f", &Mark_Jumping);
			printf_s("����Ǧ��ɼ�(��λ: ��)��δ�μ���������: ");
			scanf_s("%f", &Mark_shot);

			AddStuMSG(ID, Name, gender, Mark_Running, Mark_Jumping, Mark_shot);
			printf_s("�Ƿ񷵻���ҳ��: y/n\n");
			getchar();
			scanf_s("%c", &bOrder);
			ReturnToMainMenu();
			break;

		case 2:
			printf_s("������ѧ����ѧ�Ż�������: \n");
			getchar();
			gets_s(sOrder);
			showSingleSTU(FindSTUByIDOrNmae(sOrder));
			printf_s("�Ƿ񷵻���ҳ��: y/n\n");
			getchar();
			scanf_s("%c", &bOrder);
			ReturnToMainMenu();
			break;

		case 9:
			ShowStuData();
			ReturnToMainMenu();
			break;

		default:
			printf_s("ָ������!\n");
			printf_s("�Ƿ񷵻���ҳ��: y/n\n");
			getchar();
			scanf_s("%c", &bOrder);
			ReturnToMainMenu();
			break;
		}
		FreeLinkedData();
	}
}