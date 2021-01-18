#pragma once
#include <string>
#include <fstream>

using namespace std;
class Class_KS
{
	int id;
	static int MaxID;
	string name;
	int shop ; // ����
	int inwork ; // ���� � ������
	int perfomance;
public:
	Class_KS();
	int getid() const;
	static int getMaxID();
	string getname() const;
	int getshops() const;
	int get_inworks() const;
	void edit_KS();
	void stop_KS();
	void run_KS();
	friend istream& operator >> (istream& in, Class_KS& s);
	friend ostream& operator << (ostream& out, const Class_KS& s);
	friend ifstream& operator >> (ifstream& in, Class_KS& s);
	friend ofstream& operator << (ofstream& out, const Class_KS& s);
};

