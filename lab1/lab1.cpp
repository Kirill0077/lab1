﻿#include <iostream>
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
	unsigned int shop = 0; 
	unsigned int inwork = 0;
	unsigned int perfomance = 1;
};
int GetCorrectNumber(int min, int max)
{
	int x;
	do
	{
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "Выберите пункт от "<<min <<" до "<<max<<": ";
		cin >> x;
	} while (cin.fail() || x<min || x>max); 
	return x;
}
template <typename T>
bool CheckPositiveValue(T x)
{
	return x > 0 ? true : false;
}
Truba CreatNewTruba()
{	
	Truba newTruba;
	cout << "\n Cчитайте данные для трубы: " << endl;
	newTruba.id = "0";
	newTruba.repair = false;
	do
	{
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "\n введите длинну трубы (в м): ";
		cin >> newTruba.L;
	} while (cin.fail() || !CheckPositiveValue(newTruba.L) );
	do
	{
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "\n введите диамтр трубы (в мм): ";
		cin >> newTruba.D;
	} while (cin.fail() || !CheckPositiveValue(newTruba.D));
	return newTruba;
}
KS CreatNewKS() 
{
	KS newKS;
	cout << "\n Считайте данные для компрессарных станций: " << endl;
	newKS.id = "1";
	cout << "\n Введите имя КС: ";
	cin.get();
	getline(cin, newKS.name);
	do
	{
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "\n Введите количество цехов: ";
		cin >> newKS.shop;
	} while (cin.fail());
	do
	{
		cout << "\n Введите количество цехов в работе: ";
		cin >> newKS.inwork;
	} while (cin.fail() || newKS.inwork>newKS.shop);
	cout << "\n Введите эффективность трубы. " << endl;
	newKS.perfomance=GetCorrectNumber(1,10);
	return newKS;

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
	fout.open("file.txt", ios::out);
	if (fout.is_open())
	{
		fout << t.D << endl << t.id << endl << t.L << endl << t.repair << endl;
		fout.close();
	}

}

void SaveFileKS(KS c)
{
	ofstream fout;
	fout.open("file.txt", ios::app);
	if (fout.is_open())
	{
		fout << c.id << endl << c.inwork << endl << c.perfomance << endl << c.name << endl<<c.shop ;
		fout.close();
	}

}

Truba ReadFileTruba(ifstream& fin)
{
	Truba t;
	fin >> t.D;
	fin >> t.id;
	fin >> t.L;
	fin >> t.repair;
	return t;
}

KS ReadFileKS(ifstream& fin)
{
	KS c;
	fin >> c.id;
	fin >> c.inwork;
	fin >> c.perfomance;
	fin >> c.name;
	fin >> c.shop;
		return c;
}
void Menu()
{
	cout << "1. Считать данные из файла" << endl;
	cout << "2. Создать Трубу" << endl;
	cout << "3. Создать компрессарную станцию" << endl;
	cout << "4. Просмотр всех объектов" << endl;
	cout << "5. Изменить статус трубу в ремонте/не в ремонте" << endl;
	cout << "6. Запуск и остановка цеха" << endl;
	cout << "7. Сохранить все данные в файл" << endl;
	cout << "0. Выход" << endl;
}

void ChangeStatus(bool& status)
{
	status = !status;
}
void StopWork(KS& c) {
	c.inwork--;
}
void StartWork(KS& c) {
	c.inwork++;
}
int main() 
{
	setlocale(LC_ALL, "Russian");
	Truba t;
	KS c;
	bool isTruba = false;
	bool isKS = false;
	while (true) 
	{
		Menu();
		switch (GetCorrectNumber(0,7))
		{
		case 1:
		{
			ifstream fin;
			fin.open("file.txt", ios::in);
			if (fin.is_open())
			{
				if (isTruba == true) 
				{
					t = ReadFileTruba(fin);
				}
				else
				{
					cout<<"Труба не создана"<<endl;
				}
				if (isKS == true) 
				{
					c = ReadFileKS(fin);
				}
				else
				{
					cout << "KC не создана" << endl;
				}
			}
			break;
		}
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
			ChangeStatus(t.repair);
			break;
		case 6:
			cout << "\t Выберите действие" << endl;
			cout << "\t 1. Запуск цеха" << endl;
			cout << "\t 2. Остановка цеха" << endl;
			switch (GetCorrectNumber(1, 2))
			{
			case 1:
				if (c.inwork < c.shop)
				{
					StartWork(c);
				}
				else
				{
					cout << "Все цеха заняты работой, выберите другой пнкт" << endl;
				}
				break;
			case 2:
				if (c.inwork > 0)
				{
					StopWork(c);
				}
				else
				{
					cout << "нет ни одного рабочего цеха, выберите другой пункт" << endl;
				}
				break;
			default:
				cout << "Произошла ошибка" << endl;
				break;
			}
		case 7:
			SaveFileTruba(t);
			SaveFileKS(c);
			isTruba = !isTruba;
			isKS = !isKS;
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "Возникла ошибка" << endl;
			break;
		}
	}
}
