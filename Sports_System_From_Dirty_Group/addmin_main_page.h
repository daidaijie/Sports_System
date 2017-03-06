#pragma once
#include <stdio.h>
#include <windows.h>
#include "competition_item.h"


//ȫ�ֱ���
char id[3];							//��Ŀ����
char item_name[10];		//��Ŀ����
int item_nature;			//��Ŀ����,1��������,2������
char item_time[10];			    //����ʱ��
char item_location[10];			//�����ص�

void Show_Admin_Menu()
{
	system("cls");
	printf_s("*************************�˶������ϵͳ*************************\n");
	printf_s("***********************��ӭ�����Ĺ���Ա***********************\n");
	printf_s("***********************��ϵͳ����ָ������***********************\n");
	printf_s("1. ����һ���˶�Ա��Ϣ\n");
	printf_s("2. ����ָ����ѧ����Ϣ(����/ѧ��)\n");
	printf_s("3. �޸�ָ��ѧ������Ϣ\n");
	printf_s("4. ���ӱ�����Ŀ\n");
	printf_s("5. ���Ӳ���\n");
	printf_s("6. ���Ʋ���\n");
	printf_s("7. �鿴ѧԺ�÷�\n");
	printf_s("8. ��ʾ��Ŀ�������\n");
	printf_s("9. ��ʾ����ѧ����Ϣ\n");
	printf_s("10. �˳�ϵͳ\n");
	printf_s("*****************************************************************\n\n");
	printf_s("����ָ�\n");
}

void Return_To_Admin_Main_Menu() {
	printf_s("�Ƿ񷵻���ҳ��: y/n\n");
	//getchar();
	scanf_s("%c", &bOrder);
	if (bOrder == 'y')
		Show_Admin_Menu();
	else flag = 0;
}


void Show_Admin_Main_Page()
{
	while (flag) {
		setColor(10, 0);
		int iOrder = -1;
		Show_Admin_Menu();
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
				scanf_s("%d", &college);
				printf_s("����ѧ��: ");
				getchar();
				gets_s(ID);
				printf_s("��������: ");
				gets_s(Name);
				printf_s("�����Ա�(��1/Ů0): ");
				scanf_s("%d", &gender);
				getchar();
				Add_Stu_MSG(college, ID, Name, gender);
				printf_s("�Ƿ��������: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					Return_To_Admin_Main_Menu();
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
				//showSingleSTU(FindSTUByIDOrNmae(sOrder));
				printf_s("�Ƿ������ѯ: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					//ReturnToMainMenu();
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
				//ModifyStuData(FindSTUByIDOrNmae(sOrder));
				printf_s("�Ƿ�����޸�: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					//ReturnToMainMenu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}

				//����ѧ����Ϣ
		case 4: {
			getchar();
			printf_s("���������Ŀ����: ");
			scanf_s("%d", &id);
			printf_s("�����������: ");
			getchar();
			gets_s(item_name);
			printf_s("�����������(1����2����): ");
			scanf_s("%d", &item_nature);
			getchar();
			printf_s("�������ʱ��: ");
			gets_s(item_time);
			//puts(item_time);
			printf_s("��������ص�: ");
			gets_s(item_location);
			//puts(item_location); 
			register_item(id, item_name, item_nature, item_time, item_location);
			printf_s("�Ƿ��������: y/n\n");
			scanf_s("%c", &bOrder);
			if (bOrder != 'y') {
				Return_To_Admin_Main_Menu();
				flag = 0;
			}
		}

				//��ȡ�ļ���Ϣ
		case 5: {
			
		}

		case 6: {
			while (flag)
			{
				printf_s("������Ҫɾ����ѧ��ѧ�Ż�����: ");
				getchar();
				gets_s(sOrder);
				char a = 'q';
				Show_Single_STU(Find_STU_By_ID_Or_Nmae(sOrder));
				printf_s("\nȷ��Ҫɾ������ѧ����Ϣ��? y/n\n");
				scanf_s("%c", &a);
				if (a == 'y') {
					DeleteStuData(Find_STU_By_ID_Or_Nmae(sOrder));
					printf_s("ɾ���ɹ�!\n");

				}
				getchar();
				printf_s("�Ƿ����ɾ��: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					Return_To_Admin_Main_Menu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}

		case 9: {
			
		}

		case 10: {
			flag = 0;
			break;
		}

		default: {
			printf_s("ָ������!\n");
			getchar();
			Return_To_Admin_Main_Menu();
			break;
		}

		}
	}

	//SaveStuToFile();
	Free_Admin_LinkedData();
}