#include "Man.h"

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> Temp)
{
	for (int i = 0; i < Temp.size(); i++)
	{
		if (i == Temp.size() - 1)
			out << Temp[i];
		else
			out << Temp[i] << " ";
	}
	return out;
}

std::string getValue(std::istream& in)
{
	std::string s, value = "NULL";
	if (in >> s) {

		int beg, end;
		beg = s.find_first_not_of(' ');
		end = s.find_first_of('|');

		value = s.substr(beg, (end - beg));
	}

	return value;
}

std::vector<std::string> getFacsValue(std::istream& in)
{
	std::string s;
	std::vector<std::string> Facsvalue;
	int beg, end;
	in >> s;
	while (s.back() != '|') {

		beg = s.find_first_not_of(' ');
		Facsvalue.push_back(s.substr(beg, (s.size() - beg)));
		if(!(in >> s))
			break;
	}

	beg = s.find_first_not_of(' ');
	end = s.find_first_of('|');
	Facsvalue.push_back(s.substr(beg, (end - beg)));

	return Facsvalue;
}
man::man()
{
	countMans++;
}

man::man(FIO F, std::string T)
	: fio(F), type(T)
{
	countMans++;
}

FIO man::getFIO() const
{
	return fio;
}

std::string man::getType() const
{
	return type;
}

void man::C_enter()
{
	type = "MAN";
	std::cout << "Enter first name: \n";
	std::cin >> fio.FName;
	std::cout << "Enter last name: \n";
	std::cin >> fio.LName;
	std::cout << "Enter patronymic: \n";
	std::cin >> fio.Patronymic;
}

void man::Print(std::ostream& out) const
{
	out << this;
}

student::student() {}

student::student(FIO F, std::string Fac, int Grup)
	: man(F, "STUDENT"), Faculty(Fac), grupNumber(Grup)
{
}

student::student(const student& S)
	: man(S.fio, "STUDENT"), Faculty(S.getFac()), grupNumber(S.getGrup())
{
}

void student::C_enter()
{
	man::C_enter();

	type = "STUDENT";
	std::cout << "Enter last faculty: \n";
	std::cin >> Faculty;
	std::cout << "Enter grupp: \n";
	std::cin >> grupNumber;

}

void student::Print(std::ostream& out) const
{
	out << this;
}

bool student::operator==(man& m)
{
	return  m.getFIO() == fio && m.getType() == type;
}

void FIO_enter(FIO& f)
{
	std::cout << "Enter first name: \n";
	std::cin >> f.FName;
	std::cout << "Enter last name: \n";
	std::cin >> f.LName;
	std::cout << "Enter patronymic: \n";
	std::cin >> f.Patronymic;
}

teacher::teacher() {}

teacher::teacher(FIO F, std::vector<std::string> Facs, std::string SC)
	: man(F, "TEACHER"), Facultys(Facs), StudyCourse(SC)
{
}

std::vector<std::string> teacher::getFacs() const
{
	return Facultys;
}

std::string teacher::getStudyCourse() const
{
	return StudyCourse;
}

void teacher::C_enter()
{
	man::C_enter();
	type = "TEACHER";
	std::string Faculty;

	std::cout << "Enter facultys (): \n";

	do
	{
		std::cin >> Faculty;
		Facultys.push_back(Faculty);
	} while (Faculty != "\n");

	std::cout << "Enter study course: \n";
	std::cin >> StudyCourse;
}

void teacher::Print(std::ostream& out) const
{
	out << this;
}

bool Mcomp(man a, man b)
{
	return a.getFIO().FName < b.getFIO().FName;
}

bool Scomp(student a, student b)
{
	return a.getGrup() < b.getGrup();
}

std::istream& operator>>(std::istream& in, man& M)
{
	M.type = getValue(in);
	if (M.type != "NULL") {
		M.fio.FName = getValue(in);
		M.fio.LName = getValue(in);
		M.fio.Patronymic = getValue(in);
	}
	return in;
}

std::istream& operator>>(std::istream& in, student& S)
{
	S.type = getValue(in);
	if (S.type != "NULL") {
		S.fio.FName = getValue(in);
		S.fio.LName = getValue(in);
		S.fio.Patronymic = getValue(in);

		S.Faculty = getValue(in);
		S.grupNumber = std::stoi(getValue(in));
	}
	return in;
}


std::istream& operator>>(std::istream& in, teacher& T)
{
	T.type = getValue(in);
	if (T.type != "NULL") {
		T.fio.FName = getValue(in);
		T.fio.LName = getValue(in);
		T.fio.Patronymic = getValue(in);

		T.Facultys = getFacsValue(in);
		T.StudyCourse = getValue(in);
	}
	return in;
}
std::ostream& operator<<(std::ostream& out, const man& M)
{
	out << std::setw(8) << M.type << "|"
		<< std::setw(10) << M.fio.FName << "|"
		<< std::setw(10) << M.fio.LName << "|"
		<< std::setw(10) << M.fio.Patronymic << "|"
		<< std::endl;

	return out;
}

std::ostream& operator<<(std::ostream& out, const student& S)
{
	out << std::setw(8) << S.type << "|"
		<< std::setw(10) << S.fio.FName << "|"
		<< std::setw(10) << S.fio.LName << "|"
		<< std::setw(10) << S.fio.Patronymic << "|"
		<< std::setw(10) << S.getFac() << "|"
		<< std::setw(6) << S.getGrup() << "|"
		<< std::endl;

	return out;
}

std::ostream& operator<<(std::ostream& out, const teacher& T)
{
	out << std::setw(8) << T.type << "|"
		<< std::setw(10) << T.fio.FName << "|"
		<< std::setw(10) << T.fio.LName << "|"
		<< std::setw(10) << T.fio.Patronymic << "|"
		<< std::setw(10) << T.getFacs() << "|"
		<< std::setw(10) << T.getStudyCourse() << "|"
		<< std::endl;

	return out;
}

bool FIO::operator==(FIO f)
{
	return FName == f.FName && LName == f.LName && Patronymic == f.Patronymic;
}
