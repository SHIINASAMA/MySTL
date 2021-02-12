#include "LinkedList.h"

using namespace mystl;

int main()
{
	LinkedList<int>* list = new LinkedList<int>;
	list->add(0, 0);
	list->add(1, 1);
	list->add(2, 2);
	list->add(3, 3);
	list->add(0, -1);

	list->remove(4);

	delete list;

	return 0;
}