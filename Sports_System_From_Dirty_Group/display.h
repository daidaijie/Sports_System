#pragma once
#include <stdio.h>
#include <windows.h>

void setColor(unsigned short ForeColor = 7, unsigned short BackGroundColor = 0)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  //��ȡ��ǰ���ھ��
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);  //������ɫ
}


//���ù��λ��
void SetPos(int x, int y)
{
	COORD pos;
	HANDLE handle;
	pos.X = x;
	pos.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void display()
{
	SetPos(25,0);
	setColor(10, 0);
	printf_s("******************��ӭʹ���˶������ϵͳ******************\n");
	SetPos(20,5);
	setColor(12,0);
	printf_s("�˺�: \n");
	SetPos(20, 6);
	printf_s("����: \n");
	setColor(10, 0);
}