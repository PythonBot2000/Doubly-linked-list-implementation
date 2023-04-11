#pragma once
#include "el_List.h"
class List
{
private:
	el_List* Head;
	el_List* Tail;
	el_List* Skip(el_List* cur);
	int NumCount(int num);
public:
	List();
	~List();
	void Add(int num);
	void Delete(int num);
	int Find(int num);
	void Print();

	void Combination(List* list);
	void Intersection(List* list);
	void Difference(List* list);
	void Power();
};

