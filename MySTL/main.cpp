#include "LinkedList.h"

using namespace mystd;

int main()
{
	LinkedList<int>* list = new LinkedList<int>;
	list->add(0, 0);
	list->add(1, 1);
	list->add(1, -1);
	//³¬³öË÷Òý·¶Î§
	list->add(4, 4);

	list->set(1, 1);
	list->set(2, 2);
	//³¬³öË÷Òý·¶Î§
	list->set(3, 3);
	list->set(4, 4);

	int i = list->get(0);
	int j = list->get(1);
	int k = list->get(2);
	//³¬³öË÷Òý·¶Î§
	int l = list->get(3);

	list->remove(0);
	list->remove(1);
	//³¬³öË÷Òý·¶Î§
	list->remove(3);

	delete list;

	return 0;
}