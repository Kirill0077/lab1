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
	int start;
	int finish;
	int Diameter;
	double wt;
	double Length;
public:
	Class_Truba();
	void setStart(int);
	void setFinish(int);
	int getStart() const;
	int getFinish() const;
	int getid() const;
	static int getMaxID();
	bool getrepair() const;
	int getwt() const;
	int getLength() const;
	int getDiameter() const;
	friend istream& operator >> (istream& in, Class_Truba& t);
	friend ostream& operator << (ostream& out, const Class_Truba& t);
	friend ifstream& operator >> (ifstream& in, Class_Truba& t);
	friend ofstream& operator << (ofstream& out, const Class_Truba& t);
	void ChangeStatus();
};

