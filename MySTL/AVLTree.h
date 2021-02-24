#pragma once
#include "Kits.h"
#include "Cloneable.h"

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
	class AVLTree : Cloneable
	{
	protected:
		using Node = AVLTreeNode<key, value>;
		int count = 0;
		Node* root = nullptr;

		//右旋 - 自己变左孩子的右孩子
		Node* LL(Node* node)
		{
			Node* left = node->left;
			//判断是否存在左孩子的右孩子
			if (left->right != nullptr)
			{
				//存在则接到根节点的左孩子
				node->left = left->right;
				node->left->parent = node;
			}
			else
			{
				//不存在直接设置nullptr
				node->left = nullptr;
			}

			//判断根节点是否有父节点
			Node* parent = node->parent;
			if (parent != nullptr)
			{
				//存在则新根节点要继承原根节点的父亲
				left->parent = parent;

				//新根节点是父亲的左节点
				if (parent->key > left->key)
				{
					parent->left = left;
				}
				//新根节点是父亲的右节点
				else
				{
					parent->right = left;
				}
			}
			else
			{
				//不存在直接设置nullptr
				left->parent = nullptr;
			}

			left->right = node;
			node->parent = left;

			return left;
		}

		//左旋 - 自己变右孩子的左孩子
		Node* RR(Node* node)
		{
			Node* right = node->right;
			//判断是否存在右孩子的左孩子
			if (right->left != nullptr)
			{
				//存在则接到根节点的右孩子
				node->right = right->left;
				node->right->parent = node;
			}
			else
			{
				//不存在直接设置nullptr
				node->right = nullptr;
			}

			//判断根节点是否有父节点
			Node* parent = node->parent;
			if (parent != nullptr)
			{
				//存在则新节点要继承原根节点的父亲
				right->parent = parent;

				//新节点是父亲的左节点
				if (parent->key > right->key)
				{
					parent->left = right;
				}
				//新节点是父亲的右节点
				else
				{
					parent->right = right;
				}
			}
			else
			{
				//不存在直接设置nullptr
				right->parent = nullptr;
			}

			right->left = node;
			node->parent = right;

			return right;
		}

		//先左旋后右旋
		Node* RL(Node* node)
		{
			RR(node->left);
			return LL(node);
		}

		//先右旋后左旋
		Node* LR(Node* node)
		{
			LL(node->right);
			return RR(node);
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
			balance(tag);
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

		bool __get(Node* node, key k, value* v)
		{
			if (node->key < k)
			{
				return __get(node->right, k, v);
			}
			else if (node->key > k)
			{
				return __get(node->left, k, v);
			}
			else
			{
				*v = node->value;
				return true;
			}
			return false;
		}

		void __clear(Node* node)
		{
			if (node == nullptr)
			{
				return;
			}

			if (node->left != nullptr)
			{
				__clear(node->left);
			}

			if (node->right != nullptr)
			{
				__clear(node->right);
			}

			delete node;
		}

		Node* __clone(Node* src, Node* obj, Node* pre)
		{
			if (src == nullptr)
			{
				return nullptr;
			}
			else
			{
				Node* tag = new Node;
				tag->key = src->key;
				tag->value = src->value;
				if (pre != nullptr)
				{
					tag->parent = pre;
					if (pre->key > tag->key)
					{
						pre->left = tag;
					}
					else
					{
						pre->right = tag;
					}
				}
				obj = tag;

				if (src->left != nullptr)
				{
					__clone(src->left, obj->left, obj);
				}

				if (src->right != nullptr)
				{
					__clone(src->right, obj->right, obj);
				}

				return obj;
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
				return getHeight(0, node->left) - getHeight(0, node->right);
			}
		}

		void balance(Node* node)
		{
			if (node != nullptr)
			{
				int factor = getBalanceFactor(node);
				if (factor > 1 && getBalanceFactor(node->left) > 0)//LL --
				{
					node = LL(node);
				}
				else if (factor > 1 && getBalanceFactor(node->left) <= 0)//RL --
				{
					node = RL(node);
				}
				else if (factor < -1 && getBalanceFactor(node->right) <= 0)//RR --
				{
					node = RR(node);
				}
				else if (factor < -1 && getBalanceFactor(node->right) > 0)//LR --
				{
					node = LR(node);
				}

				if (node->parent == nullptr)
				{
					this->root = node;
				}

				balance(node->parent);
			}
			else
			{
				return;
			}
		}

	public:
		AVLTree()
		{
		}

		//添加键值对
		//键已存在时覆盖并返回true
		//键不存在时返回false
		bool put(key k, value v)
		{
			if (__insert(k, v))
			{
				this->count++;
				return true;
			}
			else
			{
				return false;
			}
		}

		//根据键查询值
		//键存在返回true
		//键不存在反之
		bool get(key k, value* v)
		{
			__get(this->root, k, v);
		}

		//根据键删除键值对
		//键存在删除并返回true
		//键不存在反之
		bool remove(key k)
		{
			if (__remove(k))
			{
				this->count--;
				return true;
			}
			else
			{
				return false;
			}
		}

		//清除所有键值对
		void clear()
		{
			__clear(this->root);
			this->root = nullptr;
			this->count = 0;
		}

		//获取元素个数
		int getCount()
		{
			return this->count;
		}

		//获取实例副本
		void* clone()
		{
			AVLTree<key, value>* tree = new AVLTree<key, value>;
			tree->root = __clone(this->root, tree->root, nullptr);
			tree->count = this->count;
			return tree;
		}
	};
};