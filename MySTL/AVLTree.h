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
		}

		//����
		Node* rightRotate(Node* node)
		{
		}

		//LL
		//����һ��
		void LL(Node* node)
		{
		}

		//RR
		//����һ��
		void RR(Node* node)
		{
		}

		//LR
		//����������������ͬ�ڵ㣩
		void LR(Node* node)
		{
		}

		//RL
		//����������������ͬ�ڵ㣩
		void RL(Node* node)
		{
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
		//��Ӽ�ֵ��
		//���Ѵ���ʱ���ǣ�������false
		//��������ʱ�½��ڵ㲢����true
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