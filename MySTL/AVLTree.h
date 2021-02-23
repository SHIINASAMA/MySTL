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
		Node* parent = nullptr;
		Node* left = nullptr;
		Node* right = nullptr;
	};

	//AVL树
	template<typename key, typename value>
	class AVLTree
	{
	protected:
	public:
		using Node = AVLTreeNode<key, value>;
		int count = 0;
		Node* root = nullptr;

		//右旋
		Node* LL(Node* node)
		{
			Node* left = node->left;

			node->left = left->right;
			left->right = nullptr;
			if (node->left != nullptr)
			{
				node->left->parent = node;
			}

			left->right = node;
			left->parent = node->parent;
			node->parent = left;

			return left;
		}

		//左旋
		Node* RR(Node* node)
		{
			Node* right = node->right;

			node->right = right->left;
			right->left = nullptr;
			if (node->right != nullptr)
			{
				node->right->parent = node;
			}

			right->left = node;
			right->parent = node->parent;
			node->parent = right;

			return right;
		}

		//先右旋后左旋
		Node* RL(Node* node)
		{
			LL(node->right);
			return RR(node);
		}

		//先左旋后右旋
		Node* LR(Node* node)
		{
			RR(node->left);
			return LL(node);
		}

		//获取节点高度
		int getHeight(int height, Node* node)
		{
			if (node == nullptr)
			{
				return height;
			}
			else
			{
				return max<int>(getHeight(height + 1, node->left), getHeight(height + 1, node->right));
			}
		}

		//插入节点
		//若键不存在则新建并返回true
		//若键存在则返回false
		bool __insert(key k, value v)
		{
			if (root == nullptr)
			{
				root = new Node;
				root->key = k;
				root->value = v;
				return true;
			}

			Node* p = root;
			Node* pp = nullptr;

			while (p != nullptr)
			{
				pp = p;
				if (p->key > k)
				{
					p = p->left;
				}
				else if (p->key == k)
				{
					return false;
				}
				else
				{
					p = p->right;
				}
			}

			Node* tag = new Node{ k,v };
			tag->parent = pp;
			if (pp->key > k)
			{
				pp->left = tag;
			}
			else
			{
				pp->right = tag;
			}
			return true;
		}

		//删除节点
		//若键存在则删除并true
		//若键不存在则返回false
		bool __remove(key k)
		{
			Node* p = root;
			Node* pp = nullptr;

			while (p != nullptr && p->key != k)
			{
				pp = p;
				if (p->key > k)
				{
					p = p->left;
				}
				else
				{
					p = p->right;
				}
			}

			//查无此人
			if (p == nullptr)
			{
				return false;
			}

			//无其他节点
			if (p->left == p->right)
			{
				if (p != root)
				{
					if (pp->key > k)
					{
						pp->left = nullptr;
					}
					else
					{
						pp->right = nullptr;
					}
					delete p;
				}
				else
				{
					delete root;
					root = nullptr;
				}
			}
			//左右均有节点
			else if (p->left != nullptr && p->right != nullptr)
			{
				if (p->left->right != nullptr)
				{
					Node* left = p->left;
					Node* tag = left->right;
					tag->right = p->right;
					left->right = nullptr;
					if (p != root)
					{
						if (pp->key > k)
						{
							pp->left = tag;
						}
						else
						{
							pp->right = tag;
						}
						tag->left = left;
						delete p;
					}
					else
					{
						delete root;
						root = tag;
					}
				}
				else if (p->right->left != nullptr)
				{
					Node* right = p->right;
					Node* tag = right->left;
					tag->left = p->left;
					right->left = nullptr;
					if (p != root)
					{
						if (pp->key > k)
						{
							pp->left = tag;
						}
						else
						{
							pp->right = tag;
						}
						tag->right = right;
						delete p;
					}
					else
					{
						delete root;
						root = tag;
					}
				}
				else
				{
					Node* left = p->left;
					if (p != root)
					{
						if (pp->key > k)
						{
							pp->left = left;
						}
						else
						{
							pp->right = left;
						}
						delete p;
					}
					else
					{
						delete root;
						root = left;
					}
				}
			}
			//只有左边有节点
			else if (p->left != nullptr)
			{
				Node* left = p->left;
				if (p != root)
				{
					if (pp->key > k)
					{
						pp->left = left;
					}
					else
					{
						pp->right = left;
					}
					delete p;
				}
				else
				{
					delete root;
					root = left;
				}
			}
			//只有右边有节点
			else if (p->right != nullptr)
			{
				Node* right = p->right;
				if (p != root)
				{
					if (pp->key > k)
					{
						pp->left = right;
					}
					else
					{
						pp->right = right;
					}
					delete p;
				}
				else
				{
					delete root;
					root = right;
				}
			}

			return true;
		}

		void balance(Node* node)
		{
		}

	public:
		//添加键值对
		//键已存在时覆盖并返回true
		//键不存在时返回false
		bool put(key k, value v)
		{
			return __insert(k, v);
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
			return __remove(k);
		}
	};
};