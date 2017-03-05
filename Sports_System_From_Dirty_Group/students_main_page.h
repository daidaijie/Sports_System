#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"
#include <Windows.Applicationmodel.Activation.h>

int college;  //ѧԺ
char ID[20]; //ѧ��
char Name[10];  //ѧ������
int gender; //�Ա�
char bOrder = 'q';
char sOrder[20];
int flag = 1;


void Show_Menu_Stu()
{
	system("cls");
	printf_s("*************************�˶������ϵͳ*************************\n");
	printf_s("***********************��ϵͳ����ָ������***********************\n");
	printf_s("1. ������Ŀ\n");
	printf_s("2. ��ѡ��Ŀ\n");
	printf_s("3. �鿴��������\n");
	printf_s("4. �鿴�������\n");
	printf_s("5. �鿴���˵÷�\n");
	printf_s("6. �鿴ѧԺ�÷�\n");
	printf_s("10. �˳�ϵͳ\n");
	printf_s("*****************************************************************\n\n");
	printf_s("����ָ�\n");
}

void ReturnToMainMenu() {
	printf_s("�Ƿ񷵻���ҳ��: y/n\n");
	//getchar();
	scanf_s("%c", &bOrder);
	if (bOrder == 'y')
		Show_Menu_Stu();
	else flag = 0;
}


void Show_Stu_Main_Page()
{
	while (flag) {
		setColor(10, 0);
		int iOrder = -1;
		Show_Menu_Stu();
		setColor(6, 0);
		scanf_s("%d", &iOrder);

		switch (iOrder)
		{
		case 1: {
			while (flag)
			{
				//���ѧ����Ϣ
				printf_s("����ѧԺ(��1ҽ2��3): ");
				getchar();
				scanf_s("%d",&college);
				printf_s("����ѧ��: ");
				getchar();
				gets_s(ID);
				printf_s("��������: ");
				gets_s(Name);
				printf_s("�����Ա�(��1/Ů0): ");
				scanf_s("%d", &gender);
				getchar();
				AddStuMSG(college,ID, Name, gender);
				printf_s("�Ƿ��������: y/n\n");
				scanf_s("%c",&bOrder);
				if (bOrder != 'y'){
					ReturnToMainMenu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}

		case 2:
		{
			while (flag)
			{
				printf_s("������ѧ����ѧ�Ż�������: \n");
				getchar();
				gets_s(sOrder);
				showSingleSTU(FindSTUByIDOrNmae(sOrder));
				printf_s("�Ƿ������ѯ: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					ReturnToMainMenu();
					flag = 0;
				}	
			}
			flag = 1;
			break;
		}


		case 3: {
			while (flag)
			{
				printf_s("������Ҫ�޸���Ϣ��ѧ��ѧ�Ż�����: ");
				getchar();
				gets_s(sOrder);
				ModifyStuData(FindSTUByIDOrNmae(sOrder));
				printf_s("�Ƿ�����޸�: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					ReturnToMainMenu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}

		//����ѧ����Ϣ
		case 4: {
			printf_s("����ɹ�\n");
			getchar();
			ReturnToMainMenu();
			break;
		}
		
		//��ȡ�ļ���Ϣ
		case 5: {
			printf_s("��ȡ�ɹ�\n");
			getchar();
			ReturnToMainMenu();
			break;
		}

		case 6: {
			while (flag)
			{
				printf_s("������Ҫɾ����ѧ��ѧ�Ż�����: ");
				getchar();
				gets_s(sOrder);
				char a = 'q';
				showSingleSTU(FindSTUByIDOrNmae(sOrder));
				printf_s("\nȷ��Ҫɾ������ѧ����Ϣ��? y/n\n");
				scanf_s("%c", &a);
				if (a == 'y') {
					DeleteStuData(FindSTUByIDOrNmae(sOrder));
					printf_s("ɾ���ɹ�!\n");

				}
				getchar();
				printf_s("�Ƿ����ɾ��: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					ReturnToMainMenu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}
		
		case 9: {
			ShowStuData();
			getchar();
			ReturnToMainMenu();
			break;
		}

		case 10: {
			flag = 0;
			break;
		}

		default: {
			printf_s("ָ������!\n");
			getchar();
			ReturnToMainMenu();
			break;
		}
			
		}
	}

	SaveStuToFile();
	FreeLinkedData();
}