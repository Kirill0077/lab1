
#include <iostream>
#include <string>
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
	int ciw;// цехов в работе
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
	cin >> r.ciw;
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
	cout<< "Количество рабочих цехов = " << c.ciw;
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	CreatNewTruba();
	CreatNewKS();
	PrintTruba(CreatNewTruba());
	PrintKS(CreatNewKS());

}
