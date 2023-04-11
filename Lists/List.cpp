#include <iostream>
#include <math.h>
#include "List.h"
#include "el_List.h"

using namespace std;

List::List()
{
	Head = NULL;
	Tail = NULL;
}

List::~List()
{
	while (Head)
	{
		Tail = Head->next;
		delete Head;
		Head = Tail;
	}
}

void List::Add(int num)
{
	el_List* cur = new el_List(num);

	if (!Head)
	{
		Head = cur;
		Tail = cur;
	}
	else
	{
		el_List* curForSearch = Head;
		bool isEnded = false;

		while (!isEnded)
		{
			if (!curForSearch)
			{
				cur->last = Tail;
				Tail->next = cur;
				Tail = cur;

				isEnded = true;
			}
			else if (curForSearch->data >= num)
			{
				cur->last = curForSearch->last;
				cur->next = curForSearch;
				curForSearch->last = cur;

				if (cur->last != NULL)
				{
					cur->last->next = cur;
				}
				else
				{
					Head = cur;
				}

				isEnded = true;
			}
			else
			{
				curForSearch = curForSearch->next;
			}
		}
	}
}

void List::Print()
{
	el_List* cur = Head;
	if (cur)
	{
		while (cur)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
	}
	else
	{
		cout << "List is empty";
	}
	cout << endl;
}

void List::Delete(int num)
{
	el_List* cur = Head;

	while (cur)
	{
		if (cur->data == num)
		{
			while (cur && (cur->data == num))
			{
				el_List* sec_cur = cur;
				if (cur->next) 
				{
					cur->next->last = cur->last; 
				}
				else
				{
					Tail = cur->last;
				}
				if (cur->last) 
				{ 
					cur->last->next = cur->next; 
				}
				else
				{
					Head = cur->next;
				}

				cur = cur->next;
				delete sec_cur;
			}
		}
		else
		{
			cur = cur->next;
		}
	}
}

int List::Find(int num)
{
	int elNum = 1;
	el_List* cur = Head;

	if (Head)
	{
		if (Head->data == num)
		{
			return elNum;
		}
		else
		{
			while (cur)
			{
				elNum++;
				cur = cur->next;

				if ((cur) && (cur->data == num))
				{
					return elNum;
				}
			}
		}
	}
	
	return 0;
}

int List::NumCount(int num)
{
	int countOfNum = 0;
	int stepsToNum = Find(num);
	el_List* cur = Head;

	if (stepsToNum != 0)
	{
		for (int i = 1; i < stepsToNum; i++)
		{
			cur = cur->next;
		}

		while (cur)
		{
			if (cur->data != num)
			{
				return countOfNum;
			}
			cur = cur->next;
			countOfNum++;
		}
		return countOfNum;
	}
	return 0;
}

el_List* List::Skip(el_List* cur)
{
	if (cur)
	{
		int num = cur->data;
		bool isEnded = false;

		while (!isEnded)
		{
			cur = cur->next;
			if ((!cur) || (cur->data != num))
			{
				isEnded = true;
			}
		}

		return cur;
	}
}

void List::Combination(List* list)
{
	el_List* cur = list->Head;
	int num, numCount1, numCount2;

	while (cur)
	{
		num = cur->data;
		numCount1 = NumCount(cur->data);
		numCount2 = list->NumCount(cur->data);

		if (numCount2 > numCount1)
		{
			for (int i = 0; i < (numCount2 - numCount1); i++)
			{
				Add(num);
			}
		}

		cur = cur->next;
	}
}

void List::Intersection(List* list)
{
	el_List* cur = list->Head;
	int num, numCount1, numCount2;

	while (cur)
	{
		num = cur->data;
		numCount1 = NumCount(cur->data);
		numCount2 = list->NumCount(cur->data);

		if (numCount1 > numCount2)
		{
			Delete(num);
			for (int i = 0; i < numCount2; i++)
			{
				Add(num);
			}
		}

		cur = cur->next;
	}

	cur = Head;
	while (cur)
	{
		num = cur->data;
		if (list->Find(num) == 0)
		{
			if (cur->last)
			{
				cur = cur->last;
			}
			else
			{
				cur = Skip(cur);
			}

			Delete(num);
		}
		else
		{
			cur = cur->next;
		}
	}
}

void List::Difference(List* list)
{
	if (this != list)
	{
		el_List* cur = list->Head;
		int num, numCount1, numCount2;

		while (cur)
		{
			num = cur->data;
			numCount1 = NumCount(cur->data);
			numCount2 = list->NumCount(cur->data);

			if (numCount1 != 0)
			{
				Delete(num);
				if (numCount1 > numCount2)
				{
					cur = Skip(cur);
					for (int i = 0; i < (numCount1 - numCount2); i++)
					{
						Add(num);
					}
				}
				else
				{
					cur = cur->next;
				}
			}
			else
			{
				cur = cur->next;
			}
		}
	}
	else
	{
		this->~List();
		Head = NULL;
		Tail = NULL;
	}
}

void List::Power()
{
	el_List* cur = Head;
	int power = 0;

	if (Head)
	{
		while (cur)
		{
			power++;
			cur = cur->next;
		}
	}

	cout << "power: " << power << endl;
}