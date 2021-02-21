#pragma once
#include "Kits.h"

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
		int height = 0;
		Node* left = nullptr;
		Node* right = nullptr;
	};

	//AVL��
	template<typename key, typename value>
	class AVLTree
	{
	protected:
		using Node = AVLTreeNode<key, value>;
		int count = 0;
		Node* root = nullptr;

		//����
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

		//����
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

		//��ȡ�߶�
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

		//��ȡƽ������
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

		//��ƽ��
		Node* reBalance(Node* node)
		{
			//���ݼ����ƽ�������жϵ�ǰ�ľ���ģʽ
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
			//�������
			else
			{
				return node;
			}
		}

		bool insert(Node* node, key k, value v)
		{
			//�ڵ�Ϊ����Ӳ�����true
			if (node == nullptr)
			{
				Node* tag = new Node;
				tag->key = k;
				tag->value = v;

				*node = tag;
			}
			//�ڵ㲻Ϊ�ո��ǲ�����false
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
		//��Ӽ�ֵ��
		//���Ѵ���ʱ���ǣ�������false
		//��������ʱ�½��ڵ㲢����true
		bool put(key k, value v)
		{
		}

		//���ݼ���ѯֵ
		//�����ڷ���true
		//�������ڷ�֮
		bool get(key k, value* v)
		{
		}

		//���ݼ�ɾ����ֵ��
		//������ɾ��������true
		//�������ڷ�֮
		bool remove(key k)
		{
		}
	};
};