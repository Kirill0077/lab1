
#include <iostream>
#include <string>
#include < fstream >
using namespace std;

struct Truba
{
	float l; //длина 
	string id;//интендификатор 
	int dim;// диаметр
	bool pz;// в ремонте
};
struct KS
{
	string id;
	string name;
	int cahi; // кол-во цехов
	int inwork;// цехов в работе
	float proiz;// эффективность
};

Truba CreatNewTruba()
{	
	Truba t;
	cout << "Cчитайте данные для трубы: " << endl;
	t.id = "0";
	t.pz = false;
	cout << "\n введите длинну трубы (в м): ";
	cin >> t.l;
	cout << "\n введите диамтр трубы (в мм): ";
	cin >> t.dim;
	return t;
}
KS CreatNewKS() 
{
	KS r;
	cout << "Считайте данные для компрессарных станций: " << endl;
	r.id = "1";
	cout << "Введите имя трубы" <<endl;
	cin >> r.name;
	cout << "Введите количество цехов" << endl;
	cin >> r.cahi;
	cout << "Введите количество цехов в работе" << endl;
	cin >> r.inwork;
	cout << "Введите эффективность трубы" << endl;
	cin >> r.proiz;
	return r;

}

void PrintTruba(Truba p)
{
	cout << "\n Интендификатор трубы id = " << p.id;
	cout << "Длинна трубы = " << p.l;
	cout << "Диаметр трубы = " << p.l;

}

void PrintKS(KS c)
{
	cout << "\n Интендификатор кс id = " << c.id;
	cout << "Имя трубы = " << c.name;
	cout << "Количество цехов = " << c.cahi;
	cout<< "Количество рабочих цехов = " << c.inwork;
}

void outputTruba(Truba p)
{
	ofstream fout;
	fout.open("output.txt");
	if (fout.is_open())
	{
		cout << "\n Интендификатор трубы id = " << p.id;
		cout << "Длинна трубы = " << p.l;
		cout << "Диаметр трубы = " << p.l;
	}

}

void outputKS(KS c)
{
	ofstream fout;
	fout.open("output.txt");
	if (fout.is_open())
	{
		cout << "\n Интендификатор кс id = " << c.id;
		cout << "Имя трубы = " << c.name;
		cout << "Количество цехов = " << c.cahi;
		cout << "Количество рабочих цехов = " << c.inwork;
	}

}

int main() 
{
	setlocale(LC_ALL, "Russian");
	CreatNewTruba();
	CreatNewKS();
	PrintTruba(CreatNewTruba());
	PrintKS(CreatNewKS());

}
