#include "../MySTL/AVLTree.h"
#include <stdio.h>

using namespace mystl;

int main()
{
	AVLTree<int, int>* tree = new AVLTree<int, int>;
	tree->put(10, 0);
	tree->put(90, 0);
	tree->put(89, 0);
	tree->put(20, 0);
	tree->put(30, 1);
	tree->put(2, 0);
	tree->put(4, 0);
	tree->put(3, 0);
	tree->put(1, 0);

	AVLTree<int, int>* newtree = (AVLTree<int, int>*)tree->clone();
	return 0;
}