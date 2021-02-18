#pragma once
#include "Stack.h"
#include "Kits.h"
#include <stdio.h>

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
	protected:
		using Node = HuffmanTreeNode<type>;
		using Stack = Stack<Node>;
		Node root;

		//��ջ����
		void sort(Stack* stack)
		{
			int count = stack->getCount();
			Node* nodes = new Node[count];
			for (int i = 0; i < count; i++)
			{
				stack->pop(&nodes[i]);
			}

			::sort<Node>(nodes, count, SortMode::DESC);

			for (int i = 0; i < count; i++)
			{
				stack->push(nodes[i]);
			}

			delete[] nodes;
		}

		//���ɹ�������
		Node create(Stack* stack)
		{
			Node* node1 = new Node;
			Node* node2 = new Node;
			Node* node3 = new Node;
			stack->pop(node1);
			stack->pop(node2);

			node3->left = node1;
			node3->right = node2;
			node3->weight = node1->weight + node2->weight;

			stack->push(*node3);
			if (stack->getCount() != 1)
			{
				sort(stack);
				create(stack);
			}
			else
			{
				return *node3;
			}
		}

		//�����Դ
		void clear(Node* node)
		{
			if (node->left != nullptr)
			{
				clear(node->left);
			}
			if (node->right != nullptr)
			{
				clear(node->right);
			}
			delete node;
		}

	public:
		//���캯��
		HuffmanTree()
		{
		}

		//�ͷ���Դ
		~HuffmanTree()
		{
			clear(&this->root);
		}

		//������������
		void create(Node nodes[], int count)
		{
			::sort(nodes, count, SortMode::DESC);
			Stack* stack = new Stack;
			for (int i = 0; i < count; i++)
			{
				stack->push(nodes[i]);
			}

			this->root = create(stack);
			delete stack;
		}
	};

	//������������
	template<typename type>
	class Huffman
	{
	};
};