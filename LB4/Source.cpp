#include "Menu.h"

int man::countMans = 0;

int main()
{
	StudBase* General_Base = new StudBase;
	Task_Manager TM(General_Base);

	TM.start_SW_Task();
	TM.general_SW_Task();


	return 0;
}