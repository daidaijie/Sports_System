// Sports_System_From_Dirty_Group.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include "login_page.h"
#include "login_operate.h"
#include "initialize_file.h"
#include "students.h"
#define MAX 1000

int main()
{
	ReadSTUFromFile();
	display();
	Login();
}

