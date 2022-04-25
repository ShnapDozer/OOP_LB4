#include "StudBase.h"

void PrintStudents(std::ostream& out, std::vector<student> s)
{
	out << "---------------------------------------------------------" << std::endl;
	for (auto i : s)
		out << i;
	out << "---------------------------------------------------------" << std::endl;
}

template <typename T>
void PrintBase(std::ostream& out,const std::vector<T> &vec) 
{
	for (auto i : vec)
		out << i;
	out << "---------------------------------------------------------" << std::endl;
}



StudBase::StudBase()
{
}

void StudBase::open_exist_B(std::string filepath)
{
	std::ifstream Save("save_M.txt");
	if (!Save) return;
	typedef std::istream_iterator<man> input_Man;
	std::copy(input_Man(Save), input_Man(), std::back_inserter(Mans));
	Save.close();

	Save.open("save_S.txt");
	if (!Save.is_open()) return;
	typedef std::istream_iterator<student> input_Student;
	std::copy(input_Student(Save), input_Student(), std::back_inserter(Students));
	Save.close();

	Save.open("save_T.txt");
	if (!Save) return;
	typedef std::istream_iterator<teacher> input_Teacher;
	std::copy(input_Teacher(Save), input_Teacher(), std::back_inserter(Teachers));
	Save.close();
}

void StudBase::create_new_B() // для удобства сделана автозаполнялка БД
{
	FIO FM, SM, TM, FoM;
	std::vector<std::string> facs = { "PRIT", "SPINTEH" };

	FM.FName = "Reger";
	FM.LName = "Philips";
	FM.Patronymic = "Patato";

	SM.FName = "Simon";
	SM.LName = "Werenger";
	SM.Patronymic = "Katato";

	TM.FName = "Rina";
	TM.LName = "Pavlova";
	TM.Patronymic = "Ratato";

	FoM.FName = "Masha";
	FoM.LName = "Typova";
	FoM.Patronymic = "Gatato";

	student sq(FM, "PRIT", 21);
	student sw(SM, "SPINTEH", 42);

	teacher ft(TM, facs, "OOP");
	teacher st(FoM, facs, "DiffUr");
	

	for (int i = 0; i < 4; i++)
	{
		push_back(sq);
		push_back(sw);
		push_back(ft);
		push_back(st);
	}
}

void StudBase::push_back(man& m)
{
	Mans.push_back(m);
}

void StudBase::push_back(student& s)
{
	Mans.push_back(s);
	Students.push_back(s);
}

void StudBase::push_back(teacher& t)
{
	Mans.push_back(t);
	Teachers.push_back(t);
}

std::vector<student> StudBase::find_S_fac(std::string fac)
{
	std::vector<student> FacBase;
	for (auto i : Students)
		if (i.getFac() == fac)
			FacBase.push_back(i);
	return FacBase;
}

std::vector<teacher> StudBase::find_T_facs(std::vector<std::string> facs)
{
	std::vector<teacher> FacsBase;
	for (auto i : Teachers)
		if (i.getFacs() == facs)
			FacsBase.push_back(i);
	return FacsBase;
}

std::vector<man> StudBase::find_FIO(FIO& f)
{
	std::vector<man> FIOBase;
	for (auto i : Students)
		if (i.getFIO() == f)
			FIOBase.push_back(i);
	return FIOBase;
}

void StudBase::PrintAllBase(std::ostream& out)
{
	Print_M_Base(out);
	Print_S_Base(out);
	Print_T_Base(out);

}

void StudBase::Print_M_Base(std::ostream& out)
{
	out << "----------------------------Mans----------------------------" << std::endl;
	PrintBase(out, Mans);
}

void StudBase::Print_S_Base(std::ostream& out)
{
	out << "----------------------------Students----------------------------" << std::endl;
	PrintBase(out, Students);
}

void StudBase::Print_T_Base(std::ostream& out)
{
	out << "----------------------------Teachers----------------------------" << std::endl;
	PrintBase(out, Teachers);
}

void StudBase::Exit(std::string filepath)
{
	std::ofstream Save_M("save_M.txt");
	if (!Save_M) return;
	std::copy(Mans.begin(), Mans.end(), std::ostream_iterator<man>(Save_M, "\n"));

	std::ofstream Save_S("save_S.txt");
	if (!Save_S) return;
	std::copy(Students.begin(), Students.end(), std::ostream_iterator<student>(Save_S, "\n"));

	std::ofstream Save_T("save_T.txt");
	if (!Save_T) return;
	std::copy(Teachers.begin(), Teachers.end(), std::ostream_iterator<teacher>(Save_T, "\n"));
}

void StudBase::SortAllBase()
{
	std::sort(Mans.begin(), Mans.end(), Mcomp);
	std::sort(Students.begin(), Students.end(), Scomp);
	std::sort(Teachers.begin(), Teachers.end(), Mcomp);
}

void StudBase::Sort_M_Base()
{
	std::sort(Mans.begin(), Mans.end(), Mcomp);
}

void StudBase::Sort_S_Base()
{
	std::sort(Students.begin(), Students.end(), Scomp);
}

void StudBase::Sort_T_Base()
{
	std::sort(Teachers.begin(), Teachers.end(), Mcomp);
}
