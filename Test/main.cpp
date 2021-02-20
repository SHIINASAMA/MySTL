#include "../MySTL/Huffman.h"
#include "../MySTL/Map.h"
#include <stdio.h>

using namespace mystl;

int main()
{
	HuffmanTreeNode<double> node[8];
	node[0].weight = 19;
	node[0].data = 0;
	node[1].weight = 21;
	node[1].data = 1;
	node[2].weight = 2;
	node[2].data = 2;
	node[3].weight = 3;
	node[3].data = 3;
	node[4].weight = 6;
	node[4].data = 4;
	node[5].weight = 7;
	node[5].data = 5;
	node[6].weight = 10;
	node[6].data = 6;
	node[7].weight = 32;
	node[7].data = 7;
	Stack<HuffmanTreeNode<double>>* stack = new Stack< HuffmanTreeNode<double>>;
	for (int i = 0; i < 8; i++)
	{
		stack->push(node[i]);
	}

	Map<double, Bin*>* map = Huffman<double>::calculate(stack);
	Bin* b1;
	for (int i = 0; i < 8; i++)
	{
		map->get(node[i].data, &b1);
		printf("%d\t -> %s\n", node[i].weight, b1->toString());
		delete b1;
	}
	delete map;

	return 0;
}