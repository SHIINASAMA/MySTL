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
			Node* left = node->left;
			Node* right = node->right;
			node->right = right->left;
			right->left = node;

			left->height = max<int>(getHeight(left->left, left->right)) + 1;
			right->height = max<int>(getHeight(right->left, right->right)) + 1;

			return right;
		}

		//右旋
		Node* rightRotate(Node* node)
		{
			Node* left = node->left;
			Node* right = node->right;
			node->left = left->right;
			left->right = node;

			left->height = max<int>(getHeight(left->left, left->right)) + 1;
			right->height = max<int>(getHeight(right->left, right->right)) + 1;

			return left;
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
		Node* reBalance(Node* node)
		{
			//根据计算的平衡因子判断当前的纠正模式
			int factor = getBalanceFactor(node);

			//LL
			if (factor > 1 && getBalanceFactor(node->left) > 0)
			{
				return rightRotate(node);
			}
			//LR
			else if (factor > 1 && getBalanceFactor(node->left) <= 0)
			{
				node->left = leftRotate(node->left);
				return rightRotate(node);
			}
			//RR
			else if (factor < -1 && getBalanceFactor(node->right) <= 0)
			{
				return leftRotate(node);
			}
			//LR
			else if (factor < -1 && getBalanceFactor(node->right) > 0)
			{
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}
			//无需操作
			else
			{
				return node;
			}
		}

		bool insert(Node* node, key k, value v)
		{
			//节点为空添加并返回true
			if (node == nullptr)
			{
				Node* tag = new Node;
				tag->key = k;
				tag->value = v;

				*node = tag;
			}
			//节点不为空覆盖并返回false
			else if (node->key == k)
			{
				node->value = v;
				return false;
			}
			else
			{
				if (node->value < v)
				{
					return insert(node->right, k, v);
				}
				else
				{
					return insert(node->left, k, v);
				}
			}

			reBalance(node);
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