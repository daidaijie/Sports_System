// Sports_System_From_Dirty_Group.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include "display.h"
#include "login.h"
#include "initialize_file.h"
#include "logic.h"
#define MAX 1000

int main()
{
	ReadSTUFromFile();
	display();
	Login();
}

