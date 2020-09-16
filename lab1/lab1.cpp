
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
	cout << "Введите имя трубы" ;
	cin >> r.name;
	cout << "Введите количество цехов";
	cin >> r.cahi;
	cout << "Введите количество цехов в работе";
	cin >> r.ciw;
	cout << "Введите эффективность трубы";
	cin >> r.proiz;
	return r;

}

Truba PrintTruba()
{
	Truba t;
	cout << "\n Интендификатор трубы id = " << t.id;
	cout << "Длинна трубы = " << t.l;
	cout << "Диаметр трубы = " << t.l;
	return t;
}

KS PrintKS()
{
	KS r;
	cout << "\n Интендификатор кс id = " << r.id;
	cout << "Имя трубы = " << r.name;
	cout << "Количество цехов = " << r.cahi;
	cout<< "Количество рабочих цехов = " << r.ciw;
	return r;
}
int main() 
{
	setlocale(LC_ALL, "Rus");
	CreatNewTruba();
	CreatNewKS();
	PrintTruba();
	PrintKS();
}
