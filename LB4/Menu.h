#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Man.h"
#include "StudBase.h"

class Task_Manager
{
public:
	Task_Manager(StudBase* Base);
	
	int start_menu();
	int general_menu();

	int Sort_submenu();
	int Add_submenu();
	int Find_submenu();
	int Print_submenu();


	void start_SW_Task();
	void subAdd_SW_Task();
	void subSort_SW_Task();
	void subFind_SW_Task();
	void subPrint_SW_Task();
	void general_SW_Task();

private:
	StudBase* G_B;
	std::string FP;
};
