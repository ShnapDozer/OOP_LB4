#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include <vector>
#include<algorithm>

#include "Man.h"

class StudBase
{
public:
	StudBase();
	StudBase(const StudBase& S) = default;

	std::vector<man> getMans() const { return Mans; }
	std::vector<student> getStudents() const { return Students; }
	std::vector<teacher> getTeachers() const { return Teachers; }
	
	size_t get_M_Size() const { return Mans.size(); }
	size_t get_S_Size() const { return Students.size(); }
	size_t get_T_Size() const { return Teachers.size(); }

	size_t get_M_Cap() const { return Mans.capacity(); }
	size_t get_S_Cap() const { return Students.capacity(); }
	size_t get_T_Cap() const { return Teachers.capacity(); }

	void open_exist_B(std::string filepath);
	void create_new_B();

	void push_back(man& m);
	void push_back(student& s);
	void push_back(teacher& t);
	
	std::vector<man> find_FIO(FIO& f);
	std::vector<student> find_S_fac(std::string fac);
	std::vector<teacher> find_T_facs(std::vector <std::string> facs);

	void SortAllBase();
	void Sort_M_Base();
	void Sort_S_Base();
	void Sort_T_Base();
	

	void PrintAllBase(std::ostream& out);
	void Print_M_Base(std::ostream& out);
	void Print_S_Base(std::ostream& out);
	void Print_T_Base(std::ostream& out);

	void Exit(std::string filepath); // save base in path


private:
	
	std::vector<man> Mans;
	std::vector<student> Students;
	std::vector<teacher> Teachers;

	std::string FilePath;
};


