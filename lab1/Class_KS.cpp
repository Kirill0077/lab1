#include "Class_KS.h"
#include "utils.h"
#include <iostream>
using namespace std;
int Class_KS::MaxID = 0;
Class_KS::Class_KS()
{
	id = ++MaxID;
	string name = "Unknown"; // имя
	 shop = 0; // цехи
     inwork = 0; // цехи в работе
	 perfomance = 0; // эффективность
}

int Class_KS::getid() const
{
	return id;
}

int Class_KS::getMaxID()
{
	return MaxID;
}

string Class_KS::getname() const
{
	return name;
}

int Class_KS::getshops() const
{
	return shop;
}

int Class_KS::get_inworks() const
{
	return inwork;
}

void Class_KS::edit_KS()
{
	inwork = GetCorrectNumber("Введите количество рабочих цехов:", 0, shop);
}

istream& operator>>(istream& in, Class_KS& s)
{
	cout << "Введите имя КС " << endl;
	cin.get();
	getline(cin, s.name);
	s.shop = GetCorrectNumber("Введите количесвто цехов ", 0, 100);
	s.inwork = GetCorrectNumber("Введите количество рабочих цехов: ", 0, s.shop);
	s.perfomance = GetCorrectNumber("Введите эффективность", 1, 10);
	return in;
}

ostream& operator<<(ostream& out, const Class_KS& s)
{
	out << "\nИнтедификатор КС" << s.id << "\n"
		<< "Имя КС" << s.name << "\n"
		<< "Количество цехов " << s.shop << "\n"
		<< "Количесвто цехов в работе " << s.inwork << "\n"
		<< "Эфективность КС " << s.perfomance << endl;
	return out;
}

ifstream& operator>>(ifstream& fin, Class_KS& s)
{
	fin >> s.id >> s.name >> s.shop
		>> s.inwork >> s.perfomance;
	return fin;
}

ofstream& operator<<(ofstream& fout, const Class_KS& s)
{
	fout << s.id << endl << s.name << endl << s.shop
		<< endl << s.inwork << endl << s.perfomance << endl;
	return fout;
}
