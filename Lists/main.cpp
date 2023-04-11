#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List list;
	List list2;

	for (int i = 1; i < 15; i++) {
		list2.Add(10 - i % 8);

	}

	cout << endl << " list 1" << endl;

	list.Print();

	cout << endl << " list 2" << endl;

	list2.Print();

	for (int i = 1; i < 15; i = i + 2) {
		list.Delete( 3);
		list2.Delete(10 - i % 8);

	}

	cout << endl << " list 1" << endl;

	list.Print();

	cout << endl << " list 2" << endl;

	list2.Print();

	list2.Difference(&list2);  cout << "Combination: ";
	
	cout << endl << " list 1" << endl;

	list.Print();

	cout << endl << " list 2" << endl;

	list2.Print(); 

	return 0;
}