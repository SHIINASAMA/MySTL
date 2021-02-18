#include "../MySTL/Huffman.h"
#include <stdio.h>

using namespace mystl;

int main()
{
	HuffmanTreeNode<int> node[8];
	node[0].weight = 19;
	node[1].weight = 21;
	node[2].weight = 2;
	node[3].weight = 3;
	node[4].weight = 6;
	node[5].weight = 7;
	node[6].weight = 10;
	node[7].weight = 32;
	HuffmanTree<int>* tree = new HuffmanTree<int>;

	Stack<HuffmanTreeNode<int>>* stack = new Stack< HuffmanTreeNode<int>>;
	for (int i = 0; i < 8; i++)
	{
		stack->push(node[i]);
	}

	tree->create(node, 8);
	return 0;
}