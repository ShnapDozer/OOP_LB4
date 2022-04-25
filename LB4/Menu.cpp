#include"Menu.h"

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> Temp) 
// данная функция реализованна в двух местах т.к. 
//выдаётся ошибка линковки, при объявлении ее в man.h и реализации в man.cpp
{
	for (auto i : Temp)
		out << i << " ";
	return out;
}


Task_Manager::Task_Manager(StudBase* Base) 
	:G_B(Base), FP("save.txt") {}

int Task_Manager::start_menu()
{
	int code;
	std::cout << std::endl;
	std::cout << "1. Enter the base\n";
	std::cout << "2. Open exist from file\n";
	std::cout << "3. Open default file\n";
	std::cout << "0. Exit\n";
	std::cout << "Enter task: ";
	std::cin >> code;
	std::cout << std::endl;
	return code;
}
int Task_Manager::general_menu()
{
	int code;
	std::cout << std::endl;
	std::cout << "1. Add new human\n";
	std::cout << "2. Find in bases\n";
	std::cout << "3. Sort  base\n";
	std::cout << "4. Print base\n";
	std::cout << "0. Exit\n";
	std::cout << "Enter task: ";
	std::cin >> code;
	std::cout << std::endl;
	return code;
}

int Task_Manager::Sort_submenu()
{
	int code;
	std::cout << std::endl;
	std::cout << "1. Sort all base\n";
	std::cout << "2. Sort Man base\n";
	std::cout << "3. Sort Students base\n";
	std::cout << "4. Sort Teachers base\n";
	std::cout << "0. Exit sort submenu\n";
	std::cout << "Enter task: ";
	std::cin >> code;
	std::cout << std::endl;
	return code;
}
int Task_Manager::Add_submenu()
{
	int code;
	std::cout << std::endl;
	std::cout << "1. Add a Man\n";
	std::cout << "2. Add a Student\n";
	std::cout << "3. Add a Teacher\n";
	std::cout << "0. Exit add submenu\n";
	std::cout << "Enter task: ";
	std::cin >> code;
	std::cout << std::endl;
	return code;
}
int Task_Manager::Find_submenu()
{
	int code;
	std::cout << std::endl;
	std::cout << "1. Find from FIO\n";
	std::cout << "2. Find from faculty\n";
	std::cout << "0. Exit find submenu\n";
	std::cout << "Enter task: ";
	std::cin >> code;
	std::cout << std::endl;
	return code;
}
int Task_Manager::Print_submenu()
{
	int code;
	std::cout << std::endl;
	std::cout << "1. Print all bases\n";
	std::cout << "2. Print Mans base\n";
	std::cout << "3. Print Students base\n";
	std::cout << "4. Print Teachers base\n";
	std::cout << "0. Exit find submenu\n";
	std::cout << "Enter task: ";
	std::cin >> code;
	std::cout << std::endl;
	return code;
}

void Task_Manager::start_SW_Task()
{
	int code = start_menu();

	switch (code)
	{
	case 1:
		G_B->create_new_B();
		break;
	case 2:
		std::cout << "Enter filepath: \n";
		std::cin >> FP;
		G_B->open_exist_B(FP);
		break;
	case 3:
		G_B->open_exist_B(FP);
		break;

	}
}

void Task_Manager::subAdd_SW_Task() 
{
	int code = Add_submenu();

	man M;
	student S;
	teacher T;

	while (code != 0)
	{
		switch (code)
		{
		case 1:
			M.C_enter();
			G_B->push_back(M);
			break;
		case 2:
			S.C_enter();
			G_B->push_back(S);
			break;
		case 3:
			T.C_enter();
			G_B->push_back(T);
			break;

		}
		code = Add_submenu();
	}
}
void Task_Manager::subSort_SW_Task()
{
	int code = Sort_submenu();

	while (code != 0)
	{
		switch (code)
		{
		case 1:
			G_B->SortAllBase();
			break;
		case 2:
			G_B->Sort_M_Base();
			break;
		case 3:
			G_B->Sort_S_Base();
			break;
		case 4:
			G_B->Sort_T_Base();
			break;
		}
		code = Sort_submenu();
	}
}
void Task_Manager::subFind_SW_Task()
{
	int code = Find_submenu();
	
	std::string Fac, fName, lName;
	FIO fio;

	while (code != 0)
	{
		switch (code)
		{
		case 1:
			FIO_enter(fio);
			std::cout << G_B->find_FIO(fio);
			break;
		case 2:
			std::cout << "Enter faculty: \n";
			std::cin >> Fac;
			std::cout << G_B->find_S_fac(Fac);
			break;
		}
		code = Find_submenu();
	}
}
void Task_Manager::subPrint_SW_Task()
{
	int code = Print_submenu();

	while (code != 0)
	{
		switch (code)
		{
		case 1:
			G_B->PrintAllBase(std::cout);
			break;
		case 2:
			G_B->Print_M_Base(std::cout);
			break;
		case 3:
			G_B->Print_S_Base(std::cout);
			break;
		case 4:
			G_B->Print_T_Base(std::cout);
			break;
		}
		code = Print_submenu();
	}
}

void Task_Manager::general_SW_Task()
{
	system("cls");
	int code = general_menu();

	while (code != 0)
	{
		system("cls");
		switch (code)
		{
		case 1:
			subAdd_SW_Task();
			break;
		case 2:
			subFind_SW_Task();
			break;
		case 3:
			subSort_SW_Task();
			break;
		case 4:
			subPrint_SW_Task();
			break;
		}
		code = general_menu();
	}
	G_B->Exit(FP);
}
