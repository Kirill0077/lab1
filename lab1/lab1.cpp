#include <iostream>
#include <string>
#include < fstream >
using namespace std;

struct Truba
{
	float L = 0.0; 
	string id = "1";
	int D = 0;
	bool repair=false;
};
struct KS
{
	string id = "1";
	string name = "";
	int shop = 0; 
	int inwork = 0;
	int KPD = 1;
};

Truba CreatNewTruba()
{	
	Truba new_Truba;
	cout << "\n Cчитайте данные для трубы: " << endl;
	new_Truba.id = "0";
	new_Truba.repair = false;
	cout << "\n введите длинну трубы (в м): ";
	cin >> new_Truba.L;
	cout << "\n введите диамтр трубы (в мм): ";
	cin >> new_Truba.D;
	return new_Truba;
}
KS CreatNewKS() 
{
	KS new_KS;
	cout << "\n Считайте данные для компрессарных станций: " << endl;
	new_KS.id = "1";
	cout << "\n Введите имя КС: ";
	cin >> new_KS.name;
	cout << "\n Введите количество цехов: ";
	cin >> new_KS.shop;
	cout << "\n Введите количество цехов в работе: " ;
	cin >> new_KS.inwork;
	cout << "\n Введите эффективность трубы  (1-10): ";
	cin >> new_KS.KPD;
	return new_KS;

}

void PrintTruba(Truba t)
{
	cout << "\nИнтендификатор трубы id = " << t.id << endl;
	cout << "Длинна трубы = " << t.L << endl;
	cout << "Диаметр трубы = " << t.D << endl;
	cout << (t.repair ? "Труба в ремонте" : "Труба не в ремонте") << endl;
	 
}

void PrintKS(KS c)
{
	cout << "\nИнтендификатор кс id = " << c.id << endl;
	cout << "Имя трубы = " << c.name << endl;
	cout << "Количество цехов = " << c.shop << endl;
	cout << "Количество рабочих цехов = " << c.inwork << endl;
}

void SaveFileTruba(Truba t)
{
	ofstream fout;
	fout.open("output.txt", ios::out);
	if (fout.is_open())
	{
		fout << t.D << endl << t.id << endl << t.L << endl << t.repair << endl;
		fout.close();
	}

}

void SaveFileKS(KS c)
{
	ofstream fout;
	fout.open("output.txt", ios::app);
	if (fout.is_open())
	{
		fout << c.id << endl << c.inwork << endl << c.KPD << endl << c.name << endl<<c.shop ;
		fout.close();
	}

}

Truba ReadFileTruba()
{
	ifstream fin;
	fin.open("input.txt", ios::in);
	Truba t;
	if (fin.is_open())
	{
		fin >> t.D;
		fin >> t.id;
		fin >> t.L;
		fin >> t.repair;
		fin.close();
		return t;
	}
}

KS ReadFileKS()
{
	ifstream fin;
	fin.open("input.txt", ios::in);
	KS c;
	if (fin.is_open())
	{
		fin >> c.id;
		fin >> c.inwork;
		fin >> c.KPD;
		fin >> c.name;
		fin >> c.shop;
		fin.close();
		return c;
	}
}
void Menu()
{
	cout << "1. Считать данные из файла" << endl;
	cout << "2. Создать Трубу" << endl;
	cout << "3. Создать компрессарную станцию" << endl;
	cout << "4. Просмотр всех объектов" << endl;
	cout << "5. Редактировать трубу" << endl;
	cout << "6. Запуски и остановка цеха" << endl;
	cout << "7. Сохранить все данные в файл" << endl;
	cout << "0. Выход" << endl;
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	Truba t;
	KS c;
	int i;
	while (true) 
	{
		Menu();
		cin >> i;
		switch (i)
		{
		case 1:
			break;
		case 2:
			t = CreatNewTruba();
			break;
		case 3:
			c = CreatNewKS();
			break;
		case 4:
			PrintTruba(t);
			PrintKS(c);
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			SaveFileTruba(t);
			SaveFileKS(c);
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "Возникла ошибка" << endl;
			break;
		}
	}
	t=ReadFileTruba();
	PrintTruba(t);
}
