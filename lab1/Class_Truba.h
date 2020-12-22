#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Class_Truba
{
	int id;
	static int MaxID;
	bool repair;
public:
	double Length;
	int Diameter;
	Class_Truba();
	int getid() const;
	static int getMaxID();
	bool getrepair() const;
	friend istream& operator >> (istream& in, Class_Truba& t);
	friend ostream& operator << (ostream& out, const Class_Truba& t);
	friend ifstream& operator >> (ifstream& in, Class_Truba& t);
	friend ofstream& operator << (ofstream& out, const Class_Truba& t);

	void ChangeStatus();
};

