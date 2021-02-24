#pragma once
#include "Kits.h"
#include "Cloneable.h"

namespace mystl
{
	//AVL���ڵ�
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

	//AVL��
	template<typename key, typename value>
	class AVLTree : Cloneable
	{
	protected:
		using Node = AVLTreeNode<key, value>;
		int count = 0;
		Node* root = nullptr;

		//���� - �Լ������ӵ��Һ���
		Node* LL(Node* node)
		{
			Node* left = node->left;
			//�ж��Ƿ�������ӵ��Һ���
			if (left->right != nullptr)
			{
				//������ӵ����ڵ������
				node->left = left->right;
				node->left->parent = node;
			}
			else
			{
				//������ֱ������nullptr
				node->left = nullptr;
			}

			//�жϸ��ڵ��Ƿ��и��ڵ�
			Node* parent = node->parent;
			if (parent != nullptr)
			{
				//�������¸��ڵ�Ҫ�̳�ԭ���ڵ�ĸ���
				left->parent = parent;

				//�¸��ڵ��Ǹ��׵���ڵ�
				if (parent->key > left->key)
				{
					parent->left = left;
				}
				//�¸��ڵ��Ǹ��׵��ҽڵ�
				else
				{
					parent->right = left;
				}
			}
			else
			{
				//������ֱ������nullptr
				left->parent = nullptr;
			}

			left->right = node;
			node->parent = left;

			return left;
		}

		//���� - �Լ����Һ��ӵ�����
		Node* RR(Node* node)
		{
			Node* right = node->right;
			//�ж��Ƿ�����Һ��ӵ�����
			if (right->left != nullptr)
			{
				//������ӵ����ڵ���Һ���
				node->right = right->left;
				node->right->parent = node;
			}
			else
			{
				//������ֱ������nullptr
				node->right = nullptr;
			}

			//�жϸ��ڵ��Ƿ��и��ڵ�
			Node* parent = node->parent;
			if (parent != nullptr)
			{
				//�������½ڵ�Ҫ�̳�ԭ���ڵ�ĸ���
				right->parent = parent;

				//�½ڵ��Ǹ��׵���ڵ�
				if (parent->key > right->key)
				{
					parent->left = right;
				}
				//�½ڵ��Ǹ��׵��ҽڵ�
				else
				{
					parent->right = right;
				}
			}
			else
			{
				//������ֱ������nullptr
				right->parent = nullptr;
			}

			right->left = node;
			node->parent = right;

			return right;
		}

		//������������
		Node* RL(Node* node)
		{
			RR(node->left);
			return LL(node);
		}

		//������������
		Node* LR(Node* node)
		{
			LL(node->right);
			return RR(node);
		}

		//��ȡ�ڵ�߶�
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

		//����ڵ�
		//�������������½�������true
		//���������򷵻�false
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

		//ɾ���ڵ�
		//����������ɾ����true
		//�����������򷵻�false
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

			//���޴���
			if (p == nullptr)
			{
				return false;
			}

			//�������ڵ�
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
			//���Ҿ��нڵ�
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
			//ֻ������нڵ�
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
			//ֻ���ұ��нڵ�
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

		//��ȡƽ������
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

		//��Ӽ�ֵ��
		//���Ѵ���ʱ���ǲ�����true
		//��������ʱ����false
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

		//���ݼ���ѯֵ
		//�����ڷ���true
		//�������ڷ�֮
		bool get(key k, value* v)
		{
			__get(this->root, k, v);
		}

		//���ݼ�ɾ����ֵ��
		//������ɾ��������true
		//�������ڷ�֮
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

		//������м�ֵ��
		void clear()
		{
			__clear(this->root);
			this->root = nullptr;
			this->count = 0;
		}

		//��ȡԪ�ظ���
		int getCount()
		{
			return this->count;
		}

		//��ȡʵ������
		void* clone()
		{
			AVLTree<key, value>* tree = new AVLTree<key, value>;
			tree->root = __clone(this->root, tree->root, nullptr);
			tree->count = this->count;
			return tree;
		}
	};
};