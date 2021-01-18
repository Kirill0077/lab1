#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <string>
#include < fstream >
#include "Class_Truba.h"
#include "Class_KS.h"
#include "utils.h"
#include "Gts.h"
using namespace std;


template<class T, typename T_param>
using Filter = bool(*)(const T& obj, T_param param);

template<class T, typename T_param>
vector<int> FindObjectsByFilter(const unordered_map<int, T>& m, Filter<T, T_param> f, T_param param) 
{
	vector <int> res;
	for (auto& obj : m)
	{
		if (f(obj.second, param))
			res.push_back(obj.first);
	}
	return res;
}
void Menu2(string line1, string line2)
{
	cout << "++++++++++++++++++++++\n" 
		<< " 1. " << line1 << "\n"
		<< " 2. " << line2 << "\n"
		<< " 0. Назад" << "\n"
		<< "+++++++++++++++++++++++" << endl;
}
template <class T>
bool check_id(const T& s, unsigned int param)
{
	return s.getid() == param;
}

bool check_repair(const Class_Truba& t, bool param)
{
	return t.getrepair() == param;
}

bool check_name(const Class_KS& s, string param)
{
	return s.getname() == param;
}

bool check_pointBywork(const Class_KS& s, double param)
{
	double point_inwork = 1.0 - s.get_inworks() / (double)s.getshops();
	return (abs(point_inwork - param / 100.0) < 0.0001);
}
template<class T>
void Delete_Truba_and_KS(unordered_map <int, T>& m)
{
	unsigned int id = GetCorrectNumber("Введите ID: ", 0, 10000);
	int n = 0;
	bool is_finded = false;
	if (m.count(id) == 1) m.erase(id);
	else cout << "Такого ID не существует" << endl;
}


void EditingTruba(unordered_map<int, Class_Truba>& m)
{
	int answer;
	while (true)
	{
		Menu2("все найденные", "указать, какие именно");
		answer = GetCorrectNumber("Выберите (0-2): ", 0, 2);
		if (answer == 1)
		{
			for (int i = 1; i <= m.size(); i++)
			{
				m[i].ChangeStatus();
			}
		}
		else if (answer == 2) 
		{
			int begin_slice = GetCorrectNumber("Type start index the slice: ", 0, Class_Truba::getMaxID());
			int end_slice = GetCorrectNumber("Type end index of the slice: ", begin_slice, Class_Truba::getMaxID());
			int n = 0;
			for (auto& t : m) 
			{
				if (t.second.getid() >= begin_slice && t.second.getid() <= end_slice) 
				{
					t.second.ChangeStatus();
				}
				n++;
			}
		}
		else
		{
			break;
		}
	}
}

template<typename T>
bool deleted(unordered_map<int, T>& Map, int id) {
	return Map.erase(id);
}

void Menu()
{
	cout << "+++++++++++++++++++++++++++++++++++++++++++\n"
		<< " 1. Создать трубы и КС" << "\n"
		<< " 2. Удалить трубы и КС" << "\n"
		<< " 3. Редактировать трубы и КС" << "\n"
	    << " 4. Показ всех объектов" << "\n"
		<< " 5. Поиск труб по заданному фильтру" << "\n"
		<< " 6. Поиск КС по заданному фильтру" << "\n"
		<< " 7. Пакетное редактирование труб" << "\n"
		<< " 8. Сохранить в файл" << "\n"
		<< " 9. Загрузить из файла" << "\n"
		<< " 10. Добавление Трубы в ГТС" << "\n"
		<< " 11. Добавить КС в ГТС" << "\n"
		<< " 12. Соединение станций" << "\n"
		<< " 13. Удаление вершин" << "\n"
		<< " 14. Удаление краёв труб" << "\n"
		<< " 15. Топологическая сортировка" << "\n"
		<< " 16. Чистка консоли" << "\n"
		<< " 0. Выход" << "\n"
		<< "+++++++++++++++++++++++++++++++++++++++++++" << endl;
}




int main() 
{
	setlocale(LC_ALL, "Russian");
	unordered_map <int, Class_Truba> Truba;
	unordered_map <int, Class_KS> KS;
	vector <int> EditedTrubs;
	while (true)
	{
		Menu();
		int i = GetCorrectNumber("Выберите от 0 до 10: ", 0, 10);
		cout << '\n';
		switch (i)
		{
		case 1:
		{
			while (true)
			{
				Menu2("Труба", "КС");
				int choice = GetCorrectNumber("Выберите от 0 до 2: ", 0, 2);
				if (choice == 1)
				{
					Class_Truba trub;
					cin >> trub;
					Truba.emplace(trub.getid(), trub);
				}
				else if (choice == 2)
				{
					Class_KS ks;
					cin >> ks;
					KS.emplace(ks.getid(), ks);
				}
				else if (choice == 0)
				{
					break;
				}
				else
				{
					cout << "Ошибка: выберите от 0 до 2" << endl;
				}
			}
			break;
		}
		case 2:
		{
			while (true)
			{
				Menu2("Труба", "КС");
				int choice1 = GetCorrectNumber("Выберите от 0 до 2: ", 0, 2);
				if (choice1 == 1)
				{
					if (Truba.size() != 0)
					{
						Delete_Truba_and_KS(Truba);
					}
					else
					{
						cout << "Вы еще не создавали трубы" << endl;
					}
				}
				else if (choice1 == 2) 
				{
					if (KS.size() != 0)
					{
						Delete_Truba_and_KS(KS);
					}
					else
					{
						cout << "Вы еще не создавали КС" << endl;
					}
				}
				else if (choice1 == 0)
				{
					cout << '\n';
					break;
				}
				else
				{
					cout << "Ошибка: выберите от 0 до 2" << endl;
				}
			}
			break;
		}
		case 3:
		{
			while (true)
			{
				Menu2("Труба", "КС");
				int choice = GetCorrectNumber("Выберите от 0 до 2: ", 0, 2);
				if (choice == 1) 
				{
					int ID = GetCorrectNumber("Введите ID:", 1u, Truba.size());
					if (Truba.size() != 0)
					{
						if (Truba.count(ID))
							Truba[ID].ChangeStatus();
						else cout << " Такого ID не существует " << endl;
					}
					else
					{
						cout << "Вы еще не создавали трубы" << endl;
					}
				}
				else if (choice == 2)
				{
					int ID = GetCorrectNumber("Введите ID:", 1u, KS.size());
					if (KS.size() != 0)
					{
						KS[ID].edit_KS();
					}
					else
					{
						cout << "Вы еще не создавали КС" << endl;
					}
				}
				else if (choice == 0)
				{
					cout << '\n';
					break;
				}
				else
				{
					cout << "Ошибка, выберите от 0 до 2" << endl;
				}
			}
			break;
		}
		case 4: 
		{
			if (Truba.size() != 0)
			{
				for (auto& t : Truba)
				{
					cout << t.second << endl;
				}
			}
			else
			{
				cout << "Вы еще не создавали трубы" << endl;
			}
			if (KS.size() != 0)
			{
				for (auto& s : KS)
				{
					cout << s.second << endl;
				}
			}
			else
			{
				cout << "Вы еще не создавали КС" << endl;
			}
			break;
		}
		case 5: 
		{
			while (true) {
				Menu2("Поиск по ID", "Поиск по статусу в ремонте ");
				int choice5 = GetCorrectNumber("Выберите от 0 до 2: ", 0, 2);
				if (choice5 == 1) {
					unsigned int Id_Find;
					Id_Find = GetCorrectNumber("Введите ID: ", 0u, 10000u);
					if (Truba.count(Id_Find))
						for (int i : FindObjectsByFilter(Truba, check_id, Id_Find)) 
						{
							cout << Truba[i] << endl;
						}
					else
					{
						cout << " Такого ID не существует " << endl;
					}
					
				}
				else if (choice5 == 2)
				{
					bool ChangeStatus_find;
					ChangeStatus_find = GetCorrectNumber("В ремонте? [да-1/нет-0]: ", false, true);
					for (int i : FindObjectsByFilter(Truba, check_repair, ChangeStatus_find))
					{
						cout << Truba[i] << endl;
					}
				}
				else if (choice5 == 0) 
				{
					break;
				}
				else 
				{
					cout << "Ошибка: выберите от 0 до 2" << endl;
				}
			}
			break;
		}
		case 6:
		{
			while (true)
			{
				Menu2("Поиск по имени", "Поиск по проценту незадействованных цехов");
				int choice6 = GetCorrectNumber("Выберите от 0 до 2: ", 0, 2);
				if (choice6 == 1) {
					string Name_Find;
					Class_KS ks;
					cout << "Введите имя КС: ";
					cin.get();
					getline(cin, Name_Find);
					int n = 0;
					for (int i : FindObjectsByFilter(KS, check_name, Name_Find))
					{
						cout << KS[i] << endl;
						n++;
					}
					if (n==0)
					{
						cout << " Такого имени КС не существует " << endl;
					}
				}
				else if (choice6 == 2) {
					double Point_Find;
					int n = 0;
					Point_Find = GetCorrectNumber("Введите значение в процентах (0-100%) [если процент не целый, введите две цифры после запятой] : ", 0.0, 100.0);
					for (int i : FindObjectsByFilter(KS, check_pointBywork, Point_Find))
					{
						cout << KS[i] << endl;
						n++;
					}
					if (n == 0) 
						cout << "Такого процента не существует" << endl;
				}
				else if (choice6 == 0) {
					break;
				}
				else {
					cout << "Ошибка: выберите от 0 до 2 " << endl;
				}
			}
			break;
		}
		case 7:
		{
			if (Truba.size() != 0)
			{
				EditingTruba(Truba);
			}
			else
			{
				cout << "Вы еще не создавали трубы" << endl;
			}
			break;
		}
		case 8:
		{
			ofstream fout;
			string filename;
			cout << "Введите название файла: ";
			cin.ignore();
			getline(cin, filename);
			fout.open(filename, ios::out);
			if (fout.is_open())
			{
				fout << Truba.size() << endl;
				fout << KS.size() << endl;
				for (auto& t1 : Truba)
					fout << t1.second;
				for (auto s : KS)
					fout << s.second;
				fout.close();
			}
			else cout << "Файл не открывается" << endl;
			break;
		}
		case 9:
		{
			Truba.clear();
			KS.clear();
			ifstream fin;
			string filename;
			cout << "Введите название файла: ";
			cin.ignore();
			getline(cin, filename);
			fin.open(filename, ios::in);
		if (fin.is_open())
			{
				int Numb_Truba;
				int Numd_KS;
				fin >> Numb_Truba;
				fin >> Numd_KS;
				while (Numb_Truba--) 
				{
					Class_Truba t;
					fin >> t;
					Truba.emplace(t.getid(), t);
				}
				while (Numd_KS--) 
				{
					Class_KS s;
					fin >> s;
					KS.emplace(s.getid(), s);
				}
				fin.close();
			}
			else cout << "Файл не открывается" << endl;
			break;
		}
		case 10:
		{
			Gts.Add_Truba(Truba, GetCorrectNumber("Введите ID трубы:", 0, Class_Truba::getMaxID()));
			break;
		}
		case 11:
		{
			Gts.Add_KS(KS, GetCorrectNumber("Введите ID КС: ", 0, Class_KS::getMaxID()));
			break;
		}
		case 12:
		{
			Gts.Connect_outp(Truba, KS);
			break;
		}
	
		case 15:
		{
		
		}
		case 16:
		{
			system("cls");
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			cout << "Ошибка: введите значение 0 до 10" << endl;
		}
		}
	}

	return 0;
}
