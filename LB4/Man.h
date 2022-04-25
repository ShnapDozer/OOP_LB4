#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> Temp);


struct FIO 
{
	std::string FName, LName, Patronymic;

	bool operator==(FIO f);
};

class man
{
public:

	man();
	man(FIO F, std::string T = "MAN");

	FIO getFIO() const;
	std::string getType() const;

	virtual void C_enter();
	virtual void Print(std::ostream& out) const;
	
	bool operator==(man& m);

	friend std::istream& operator>>(std::istream&, man& M);
	friend std::ostream& operator<<(std::ostream& out, const man& M);

	static int countMans;
public:
	FIO fio;
	std::string type;
};

class student : public man
{
public:
	student();
	student(FIO f, std::string Fac, int Grup);
	student(const student& S);

	std::string getFac() const { return Faculty; }
	int getGrup() const { return grupNumber; }

	void C_enter() override;
	void Print(std::ostream& out) const override;

	bool operator==(man& m);

	friend std::istream& operator>>(std::istream&, student& S);
	friend std::ostream& operator<<(std::ostream& out, const student& S);

private:
	std::string Faculty;
	int grupNumber;
};

class teacher : public man
{
public:
	teacher();
	teacher(FIO F, std::vector<std::string> Facs, std::string SC);
	teacher(const teacher& T) = default;

	std::vector<std::string> getFacs() const;
	std::string getStudyCourse() const;

	void C_enter() override;
	void Print(std::ostream& out) const override;

	friend std::istream& operator>>(std::istream&, teacher& T);
	friend std::ostream& operator<<(std::ostream& out, const teacher& T);

private:
	std::vector<std::string> Facultys;
	std::string StudyCourse;
};

bool Mcomp(man a, man b);
bool Scomp(student a, student b);


void FIO_enter(FIO& f);

std::istream& operator>>(std::istream& in, man& M);
std::istream& operator>>(std::istream& in, student& S);
std::istream& operator>>(std::istream& in, teacher& T);

std::ostream& operator<<(std::ostream& out, const man& M);
std::ostream& operator<<(std::ostream& out, const student& S);
std::ostream& operator<<(std::ostream& out, const teacher& T);


