#pragma once
#include "Class_KS.h"
#include "Class_Truba.h"
#include <unordered_set>
#include <unordered_map>
#include <vector>
class Gts
{
	unordered_map<int, int> index_Truba;
	unordered_map<int, int> index_KS;
	unordered_set<int> intp; //id ðåáåð
	unordered_set<int> outp; //id âåðøèíû
	vector<vector<int>> Matrix_Smej;
	vector<vector<int>> IncMatr;
	bool is_change;

public:
	int Get_indexKS(int) const;
	void Add_KS(const unordered_map<int, Class_KS>&, int);
	void Add_Truba(const unordered_map<int, Class_Truba>&, int);
	void Connect_outp( unordered_map<int, Class_Truba>&, unordered_map<int, Class_KS>&);
	void Create_MatrixSmej(unordered_map<int, Class_Truba>&, unordered_map<int, Class_KS>&);
	void Delete_intp(int, unordered_map<int, Class_Truba>&);
	void Delete_outp(int);
	void TopologicalSort(int, vector<int>&, bool&, vector<int>&);
	void TopSort();
	void NewIndex();
};

