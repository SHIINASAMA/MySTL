#pragma once
#include "Stack.h"
#include "Kits.h"
#include "Queue.h"
#include "Map.h"
#include <string.h>

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
	protected:
		using Node = HuffmanTreeNode<type>;
		using Stack = Stack<Node>;
		Node* root;

		//堆栈排序
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

		//生成哈夫曼树
		Node __create(Stack* stack)
		{
			Node* node1 = new Node;
			Node* node2 = new Node;
			Node* node3 = new Node;
			sort(stack);
			stack->pop(node1);
			stack->pop(node2);

			node3->left = node1;
			node3->right = node2;
			node3->weight = node1->weight + node2->weight;

			stack->push(*node3);
			if (stack->getCount() != 1)
			{
				__create(stack);
			}
			else
			{
				return *node3;
			}
		}

		//清除资源
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
		//构造函数
		HuffmanTree()
		{
		}

		//释放资源
		~HuffmanTree()
		{
			clear(this->root);
		}

		Node* create(Stack* stack)
		{
			root = create(stack);
			return root;
		}
	};

	//用于表示一串二进制
	class Bin : public Queue<Code>
	{
	public:
		//构造函数
		Bin() : Queue<Code>::Queue()
		{
		}

		//转换为字符串
		char* toString()
		{
			int len = this->getCount();
			if (len == 0)
			{
				return nullptr;
			}
			else
			{
				Code temp;
				char* buffer = new char[len + (unsigned long long)1];
				for (int i = 0; i < len; i++)
				{
					this->take(&temp);
					if (temp == Code::One)
					{
						buffer[i] = '1';
					}
					else
					{
						buffer[i] = '0';
					}
				}
				buffer[len] = '\0';
				return buffer;
			}
		}
	};

	//哈夫曼编码类
	template<typename type>
	class Huffman
	{
		using Node = HuffmanTreeNode<type>;
		using Tree = HuffmanTree<type>;
		using Queue = Queue<Node>;
		using Stack = Stack<Node>;
		using Map = Map<Node, Bin>;

		//遍历节点拿Code
		void getCode(Node* node, Queue* queue, Map* map)
		{
			if (node->left != nullptr)
			{
				Queue* temp = (Queue*)queue->clone();
				temp->put(Code::One);
				getCode(node->left, temp, map);
			}

			if (node->right != nullptr)
			{
				Queue* temp = (Queue*)queue->clone();
				temp->put(Code::Zero);
				getCode(node->right, temp, map);
			}

			if (node->left == nullptr && node->left == nullptr)
			{
				Bin* bin = new Bin;
				int len = queue->getCount();
				Code code;
				for (int i = 0; i < len; i++)
				{
					queue->take(&code);
					bin->put(code);
				}
				map->put(node, bin);
			}

			delete queue;
		}
	public:
		//根据所给频率表计算哈夫曼编码
		Map* calculate(Stack* stack)
		{
			Tree* tree = new Tree;
			Map* map = new Map;
			Node* root = tree->create(stack);
			Queue* queue = new Queue;

			getCode(root, queue, map);

			delete queue;
			delete tree;
			return map;
		}
	};
};