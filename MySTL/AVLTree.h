#pragma once
#include "Kits.h"

namespace mystl
{
	//AVL树节点
	template<typename key, typename value>
	class AVLTreeNode
	{
		using Node = AVLTreeNode<key, value>;
	public:
		key key{ 0 };
		value value{ 0 };
		int height = 0;
		Node* left = nullptr;
		Node* right = nullptr;
	};

	//AVL树
	template<typename key, typename value>
	class AVLTree
	{
	protected:
		using Node = AVLTreeNode<key, value>;
		int count = 0;
		Node* root = nullptr;

		//左旋
		Node* leftRotate(Node* node)
		{
		}

		//右旋
		Node* rightRotate(Node* node)
		{
		}

		//LL
		//右旋一次
		void LL(Node* node)
		{
		}

		//RR
		//左旋一次
		void RR(Node* node)
		{
		}

		//LR
		//先左旋后右旋（不同节点）
		void LR(Node* node)
		{
		}

		//RL
		//先右旋后左旋（不同节点）
		void RL(Node* node)
		{
		}

		//获取高度
		int getHeight(Node* node)
		{
			if (node == nullptr)
			{
				return 0;
			}
			else
			{
				return max<int>(getHeight(node->left), getHeight(node->right)) + 1;
			}
		}

		//获取平衡因子
		int getBalanceFactor(Node* node)
		{
			if (node == nullptr)
			{
				return 0;
			}
			else
			{
				return node->left->height - node->right->height;
			}
		}

		//再平衡
		void reBalance(Node* node)
		{
		}

		bool insert(Node* node, key k, value v)
		{
		}

		bool remove(Node* node, key k)
		{
		}

	public:
		//添加键值对
		//键已存在时覆盖，并返回false
		//键不存在时新建节点并返回true
		bool put(key k, value v)
		{
			if (this->count == 0)
			{
				this->root = new Node{ k,v };
				this->count++;
				return true;
			}
			else
			{
			}
		}

		//根据键查询值
		//键存在返回true
		//键不存在反之
		bool get(key k, value* v)
		{
		}

		//根据键删除键值对
		//键存在删除并返回true
		//键不存在反之
		bool remove(key k)
		{
		}
	};
};