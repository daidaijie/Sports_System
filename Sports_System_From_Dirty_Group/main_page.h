#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.Applicationmodel.Activation.h>

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

	printf_s("����ָ�\n");
	scanf_s("%d",&iOrder);
}