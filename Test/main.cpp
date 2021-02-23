#include "../MySTL/AVLTree.h"
#include <stdio.h>

using namespace mystl;

int main()
{
	AVLTree<int, int>* tree = new AVLTree<int, int>;
	tree->put(1, 0);
	tree->put(2, 0);
	tree->put(3, 0);

	auto node = tree->RR(tree->root);

	return 0;
}