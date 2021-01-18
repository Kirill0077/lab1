#include "Class_KS.h"
#include "utils.h"
#include <iostream>
using namespace std;
int Class_KS::MaxID = 0;
Class_KS::Class_KS()
{
	id = ++MaxID;
	string name = "Unknown"; // ���
	 shop = 0; // ����
     inwork = 0; // ���� � ������
	 perfomance = 0; // �������������
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
	inwork = GetCorrectNumber("������� ���������� ������� �����:", 0, shop);
}

void Class_KS::stop_KS()
{
	if (inwork > 0) {
		inwork--;
	}
	else {
		cout << "��� ������� �����" << endl;
	}
}

void Class_KS::run_KS()
{
	if (inwork < shop) {
		inwork++;
	}
	else {
		cout << "��� ���� ������" << endl;
	}
}

istream& operator>>(istream& in, Class_KS& s)
{
	cout << "������� ��� �� ";
	cin.get();
	getline(cin, s.name);
	s.shop = GetCorrectNumber("������� ���������� �����: ", 0, 100);
	s.inwork = GetCorrectNumber("������� ���������� ������� �����: ", 0, s.shop);
	s.perfomance = GetCorrectNumber("������� �������������: ", 1, 10);
	return in;
}

ostream& operator<<(ostream& out, const Class_KS& s)
{
	out << "\n������������� ��: " << s.id << "\n"
		<< "��� ��: " << s.name << "\n"
		<< "���������� �����: " << s.shop << "\n"
		<< "���������� ����� � ������: " << s.inwork << "\n"
		<< "������������ ��: " << s.perfomance << endl;
	return out;
}

ifstream& operator>>(ifstream& fin, Class_KS& s)
{
	fin >> s.id >> s.name >> s.shop>> s.inwork >> s.perfomance;
	return fin;
}

ofstream& operator<<(ofstream& fout, const Class_KS& s)
{
	fout << s.id << endl << s.name << endl << s.shop<< endl << s.inwork << endl << s.perfomance << endl;
	return fout;
}
