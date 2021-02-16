#include "../MySTL/Map.h"
#include <stdio.h>

using namespace mystl;

int main()
{
	LinkedList<int>* list = new LinkedList<int>;
	list->addFirst(100);
	list->addFirst(101);
	list->addFirst(102);
	auto itor = list->getIterator();
	int* a;
	while ((a = itor->next()) != nullptr)
	{
		printf("a = %d\n", *a);
	}
	return 0;
}