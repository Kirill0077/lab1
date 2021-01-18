#include "Gts.h"
#include "utils.h"
int Gts::Get_indexKS(int id) const
{
    return index_KS.find(id)->second;
}

int Gts::Get_IdKS(int index) const
{
	for (auto iter = index_KS.begin(); iter != index_KS.end(); iter++) {
		if (iter->second == index)
			return iter->first;
	}
	return 0;
}

void Gts::Add_KS(const unordered_map<int, Class_KS>& map, int id)
{
    
	intp.insert(map.find(id)->first);
	index_KS.insert({ id, intp.size() - 1 });
	cout << "KS добавила ID: " << index_KS.find(id)->first << " Index: " << index_KS.find(id)->second << endl;
	is_change = true;

}

void Gts::Add_Truba(const unordered_map<int, Class_Truba>& map, int id)
{
	outp.insert(map.find(id)->first);
	index_Truba.insert({ id, outp.size() - 1 });
	cout << "Truba добавила ID: " << index_Truba.find(id)->first << " Index: " << index_Truba.find(id)->second << endl;
	is_change = true;
}


void Gts::Connect_outp( unordered_map<int, Class_Truba>& Map_Truba, unordered_map<int, Class_KS>& Map_KS)
{
	cout << "Введите KS: " << endl;
	int Start_KS = GetCorrectNumber("Введите начальную КС: ", 0, Class_KS::getMaxID());
	int id_Truba = GetCorrectNumber("Введите Id трубы, которой хотите соединить: ", 0, Class_Truba::getMaxID());
	int Finish_KS = GetCorrectNumber("Введите конечную КС: ", 0, Class_KS::getMaxID());
	Map_Truba.find(id_Truba)->second.setStart(Start_KS);
	Map_Truba.find(id_Truba)->second.setFinish(Finish_KS);
	cout << "KS: " << Start_KS << " была связана с КС: " << Finish_KS << " с трубой id: " << id_Truba << endl;
	is_change = true;
}

void Gts::Create_MatrixSmej(unordered_map<int, Class_Truba>& Map_Truba, unordered_map<int, Class_KS>& Map_KS)
{
	int n = intp.size();
	if (is_change) {
		NewIndex();
		Matrix_Smej.clear();
		Matrix_Smej.resize(n);
		for (int i = 0; i < n; i++) {
			Matrix_Smej[i].resize(n);
			is_change = false;
		}
	}
	for (auto itr = Map_Truba.begin(); itr != Map_Truba.end(); itr++) {
		if (itr->second.getStart() != -1) {
			Matrix_Smej[Get_indexKS(itr->second.getStart())][Get_indexKS(itr->second.getFinish())] = 1;
		}
	}
}

void Gts::Delete_intp(int id, unordered_map<int , Class_Truba>& Map_Truba)
{
	is_change = true;
	intp.erase(id);
	index_KS.erase(id);

	for (auto i = Map_Truba.begin(); i != Map_Truba.end(); i++) {
		if (i->second.getStart() == id || i->second.getFinish() == id) {
																																					/*	delete_vertices(iter->first);*/
			Map_Truba.erase(i->first);
			break;
		}
	}
}

void Gts::Delete_outp(int id)
{
	is_change = true;
																																					/*Vertices.erase(Vertices.find(id));*/
	outp.erase(id);
	index_Truba.erase(id);
}

void Gts::TopologicalSort(int index, vector<int>& color, bool& cycl, vector<int>& Sorted)
{
	if (color[index] == 2)
		return;
	if (cycl)
		return;
	if (color[index] == 1) {
		cycl = true;
		return;
	}
	color[index] = 1;
	for (int i = 0; i < intp.size(); i++) {
		if (Matrix_Smej[index][i] == 1) 
		{
			int AdjIntp = i;
			TopologicalSort(AdjIntp, color, cycl, Sorted);
			if (cycl)
				return;
		}

	}
	color[index] = 2;
	Sorted.push_back(Get_IdKS(index));
}

void Gts::TopSort()
{
	vector<int> color;
	color.resize(intp.size());
	vector<int> SortedVector;
	bool cycl = false;
	for (int i = 0; i < intp.size(); i++) {
		TopologicalSort(i, color, cycl, SortedVector);
	}
	if (cycl) {
		cout << "есть цикл" << endl;
	}
	else {
		reverse(SortedVector.begin(), SortedVector.end());
		cout << " Топологическая сортировка" << endl;
		for (int i = 0; i < SortedVector.size(); i++) {
			cout << SortedVector[i] << " ";
		}
		cout << endl;
	}
}

void Gts::NewIndex()
{
	int i = 0;
	for (auto iter = index_KS.begin(); iter != index_KS.end(); iter++) {
		iter->second = i;
		++i;
	}
	i = 0;
	for (auto iter = index_Truba.begin(); iter != index_Truba.end(); iter++) {
		iter->second = i;
	}
}
