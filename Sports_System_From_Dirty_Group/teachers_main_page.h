
#include <stdio.h>
#include "login_page.h"
#include <windows.h>

//һЩ��ֵ�ȫ�ֱ�����������



void Show_Tea_Menu()
{
	system("cls");
	printf_s("*************************�˶������ϵͳ*************************\n");
	printf_s("*************************�װ�����ʦ����*************************\n");
	printf_s("***********************��ϵͳ����ָ������***********************\n");
	printf_s("1. ����һ��ѧ����Ϣ\n");
	printf_s("2. ����ָ����ѧ����Ϣ(����/ѧ��)\n");
	printf_s("3. �޸�ָ��ѧ������Ϣ\n");
	printf_s("4. ����ѧ����Ϣ���ļ���\n");
	printf_s("5. ��ȡ�ļ��е�ѧ����Ϣ\n");
	printf_s("6. ɾ��ָ��ѧ������Ϣ\n");
	printf_s("7. �ָ�ɾ����ѧ����Ϣ\n");
	printf_s("8. ��ʾ��Ŀ�������\n");
	printf_s("9. ��ʾ����ѧ����Ϣ\n");
	printf_s("10. �˳�ϵͳ\n");
	printf_s("*****************************************************************\n\n");
	printf_s("����ָ�\n");
}

void ReturnToTeaMainMenu() {
	printf_s("�Ƿ񷵻���ҳ��: y/n\n");
	//getchar();
	scanf_s("%c", &bOrder);
	if (bOrder == 'y')
		Show_Tea_Menu();
	else flag = 0;
}

void Show_Tea_Main_Page()
{
	while (flag) {
		setColor(10, 0);
		int iOrder = -1;
		Show_Tea_Menu();
		setColor(6, 0);
	}
}