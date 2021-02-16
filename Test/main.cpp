#include "../MySTL/Map.h"
#include <stdio.h>

using namespace mystl;

int main()
{
	Map<int, int>* map = new Map<int, int>;
	for (int i = 0; i < 100; i++)
	{
		map->put(i, 100 - i);
	}

	int a;
	map->get(57, &a);
	return 0;
}