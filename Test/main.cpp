#include "../MySTL/AVLTree.h"
#include <stdio.h>

using namespace mystl;

int main()
{
	AVLTree<int, int>* tree = new AVLTree<int, int>;
	tree->put(33, 0);
	tree->put(16, 0);
	tree->put(50, 0);
	tree->put(13, 0);
	tree->put(18, 0);
	tree->put(34, 0);
	tree->put(58, 0);
	tree->put(15, 0);
	tree->put(17, 0);
	tree->put(25, 0);
	tree->put(51, 0);
	tree->put(66, 0);
	tree->put(19, 0);
	tree->put(27, 0);
	tree->put(55, 0);

	tree->remove(13);
	tree->remove(18);
	tree->remove(55);

	return 0;
}