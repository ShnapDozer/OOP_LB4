# Отчет по лабораторным работам 3 и 4

По заданию было необходимо создать "common" класс и от него наследовать классы "student" и "teaher".
#### Таким образом был создан класс man, с методами:
```C++
class man
{
public:

	man(); // стандартный конструктор
	man(FIO F, std::string T = "MAN"); 

	FIO getFIO() const; // геттеры
	std::string getType() const;

// виртуальные функции ввода и вывода
//для переопределения в других классах
	virtual void C_enter(); 
	virtual void Print(std::ostream& out) const; 
	
	bool operator==(man& m);

	friend std::istream& operator>>(std::istream&, man& M); // операторы ввода\вывода для вывода и сохранения в файл
	friend std::ostream& operator<<(std::ostream& out, const man& M);

	static int countMans;
public:
	FIO fio; // структура с полями ФИО
	std::string type; // тип объекта
};
```

#### А также классы-предатки "student" и "teaher", со своими полями, переопределенными функциями и некоторыми новыми методами:

```c++
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
```
```c++
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
```

Данные классы и некоторые вспомагательные функции располагаются в файле man.h

#### Также для управления базами данных был создан класс "StudBase", в нем реализованны все функции для создания, удаления и отрисовки всех баз:
```C++
class StudBase
{
public:
	StudBase();
	StudBase(const StudBase& S) = default;

// геттеры
	std::vector<man> getMans() const { return Mans; }
	std::vector<student> getStudents() const { return Students; }
	std::vector<teacher> getTeachers() const { return Teachers; }
	
	size_t get_M_Size() const { return Mans.size(); }
	size_t get_S_Size() const { return Students.size(); }
	size_t get_T_Size() const { return Teachers.size(); }

	size_t get_M_Cap() const { return Mans.capacity(); }
	size_t get_S_Cap() const { return Students.capacity(); }
	size_t get_T_Cap() const { return Teachers.capacity(); }

// Функции для создания БД и открытия ее:
	void open_exist_B(std::string filepath);
	void create_new_B();
  
// Добавление в БД
	void push_back(man& m);
	void push_back(student& s);
	void push_back(teacher& t);
  
// Методы поиска по БД
	std::vector<man> find_FIO(FIO& f);
	std::vector<student> find_S_fac(std::string fac);
	std::vector<teacher> find_T_facs(std::vector <std::string> facs);
  
// Методы сортировки
	void SortAllBase();
	void Sort_M_Base();
	void Sort_S_Base();
	void Sort_T_Base();
	
// Методы отрисовки
	void PrintAllBase(std::ostream& out);
	void Print_M_Base(std::ostream& out);
	void Print_S_Base(std::ostream& out);
	void Print_T_Base(std::ostream& out);

	void Exit(std::string filepath); // save base in path


private:
	
	std::vector<man> Mans; // общая база всех людей
	std::vector<student> Students; // только студенты
	std::vector<teacher> Teachers; // только преподаватели

	std::string FilePath;// Содержит путь к сохраняемому файлу
};
```

#### Ну и для функциальности нашей БД был создан класс меню, который реализовывает взаимодействие пользователя с БД:

```C++
class Task_Manager
{
public:
	Task_Manager(StudBase* Base);// передаем нашу БД
	
	int start_menu();// Выводит в поток вывода нумерацию пунктов меню
	int general_menu();

	int Sort_submenu();// Выводит в поток вывода нумерацию подпунктов меню
	int Add_submenu();
	int Find_submenu();
	int Print_submenu();


	void start_SW_Task(); // Сам обработчик событий выбора пункта меню, его и вызываем для вывода меню на экран
	void subAdd_SW_Task();
	void subSort_SW_Task();
	void subFind_SW_Task();
	void subPrint_SW_Task();
	void general_SW_Task();

private:
	StudBase* G_B; //  ссылка на бд
	std::string FP; // Путь к сохраняемым файлам
};
```
