#pragma once
#include "LinkedList.h"
#include "Kits.h"

namespace mystl
{
	//���������ڵ�
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

	//��������
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

		//ͨ���ڵ����鹹����������
		void create(Node nodes[], int count)
		{
		}
	};

	//������������
	template<typename type>
	class Huffman
	{
	};
};