#include "Gts.h"
#include "utils.h"
int Gts::Get_indexKS(int id) const
{
    return index_KS.find(id)->second;
}

void Gts::Add_KS(const unordered_map<int, Class_KS>& map, int id)
{
    
	outp.insert(map.find(id)->first);
	index_KS.insert({ id, outp.size() - 1 });
	cout << "KS added ID: " << index_KS.find(id)->first << " Index: " << index_KS.find(id)->second << endl;
	is_change = true;

}

void Gts::Add_Truba(const unordered_map<int, Class_Truba>& map, int id)
{
	intp.insert(map.find(id)->first);
	index_Truba.insert({ id, intp.size() - 1 });
	cout << "Truba added ID: " << index_Truba.find(id)->first << " Index: " << index_Truba.find(id)->second << endl;
	is_change = true;
}


void Gts::Connect_outp( unordered_map<int, Class_Truba>& Map_Truba, unordered_map<int, Class_KS>& Map_KS)
{
	cout << "Enter KS: " << endl;
	int Start_KS = GetCorrectNumber("Enter start KS", 0, Class_KS::getMaxID());
	int id_Truba = GetCorrectNumber("Enter Truba: ", 0, Class_Truba::getMaxID());
	int Finish_KS = GetCorrectNumber("Enter final KS: ", 0, Class_KS::getMaxID());
	Map_Truba.find(id_Truba)->second.setStart(Start_KS);
	Map_Truba.find(id_Truba)->second.setFinish(Finish_KS);
	cout << "KS: " << Start_KS << " was connected with KS: " << Finish_KS << "by Truba with id: " << id_Truba << endl;
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
