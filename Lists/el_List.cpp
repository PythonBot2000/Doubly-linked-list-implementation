#include "el_List.h"
#include <iostream>

el_List::el_List(int num)
{
	data = num;
	last = NULL;
	next = NULL;
}
