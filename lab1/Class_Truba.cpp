#include "Class_Truba.h"
#include "utils.h"

using namespace std;

int Class_Truba::MaxID = 0;

Class_Truba::Class_Truba()
{
	id = ++MaxID;
	Length = 0.0;
	Diameter = 0;
	repair = false;
	start = -1;
	finish = -1;
	wt = 0.0;
}

int Class_Truba::getid() const
{
	return id;
}

int Class_Truba::getMaxID()
{
	return MaxID;
}

bool Class_Truba::getrepair() const
{
	return repair;
}

int Class_Truba::getwt() const
{
	return wt;
}

int Class_Truba::getLength() const
{
	return Length;
}

int Class_Truba::getDiameter() const
{
	return Diameter;
}

void Class_Truba::setStart(int new_start)
{
	start = new_start;
}

void Class_Truba::setFinish(int new_finish)
{
	finish = new_finish;
}

int Class_Truba::getStart() const
{
	return start;
}

int Class_Truba::getFinish() const
{
	return finish;
}

void Class_Truba::ChangeStatus()
{
	repair = !repair;
}

istream& operator >> (istream& in, Class_Truba& t)
{
	t.Length = GetCorrectNumber( "Введите длину трубы ", 0.0, 1000.0);
	t.Diameter = GetCorrectNumber("Введите диаметр трубы ", 0, 2500);
	t.repair = false;
	return in;
}


ostream& operator << (ostream& out, const Class_Truba& t)
{
	out << "\nИнтендификатор трубы: " << t.id << "\n"
		<< "Длина трубы: " << t.Length << "\n"
		<< "Диаметр трубы: " << t.Diameter << "\n"
		<< "Статус трубы " << t.repair
		<< endl;
	return out;
}

ifstream& operator>>(ifstream& fin, Class_Truba& t)
{
	fin >> t.id >> t.Length >> t.Diameter >> t.repair;
	return fin;
}

ofstream& operator<<(ofstream& fout, const Class_Truba& t)
{
	fout << t.id << endl << t.Length << endl<< t.Diameter << endl << t.repair << endl;
	return fout;
}
