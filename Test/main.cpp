#include "../MySTL/Huffman.h"
#include "../MySTL/Map.h"
#include <stdio.h>

using namespace mystl;

int main()
{
	HuffmanTreeNode<double> node[8];
	node[0].weight = 19;
	node[1].weight = 21;
	node[2].weight = 2;
	node[3].weight = 3;
	node[4].weight = 6;
	node[5].weight = 7;
	node[6].weight = 10;
	node[7].weight = 32;

	Stack<HuffmanTreeNode<double>>* stack = new Stack< HuffmanTreeNode<double>>;
	for (int i = 0; i < 8; i++)
	{
		stack->push(node[i]);
	}

	Huffman<double>* huffman = new Huffman<double>;
	Map<HuffmanTreeNode<double>, Bin>* map = huffman->calculate(stack);

	/*Bin bin;
	map->get(node[3], &bin);
	printf("%s\n", bin.toString());*/

	return 0;
}