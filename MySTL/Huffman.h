#pragma once
#include "LinkedList.h"
#include "Kits.h"

namespace mystl
{
	//哈夫曼树节点
	template<typename type>
	class HuffmanTreeNode
	{
		using Node = HuffmanTreeNode<type>;
	public:
		int weight{ 0 };
		type data{ 0 };
		Node* left = nullptr;
		Node* right = nullptr;

		bool operator>=(const Node& node)
		{
			return this->weight >= node.weight;
		}

		bool operator<=(const Node& node)
		{
			return this->weight <= node.weight;
		}
	};

	//哈夫曼树
	template<typename type>
	class HuffmanTree
	{
		using Node = HuffmanTreeNode<type>;
		Node* root = nullptr;

	public:
		HuffmanTree()
		{
			root = new Node;
		}

		~HuffmanTree()
		{
		}

		//通过节点数组构建哈夫曼树
		void create(Node nodes[], int count)
		{
		}
	};

	//哈夫曼编码类
	template<typename type>
	class Huffman
	{
	};
};