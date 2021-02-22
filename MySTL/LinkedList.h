#pragma once
#include "Iterator.h"
#include "Cloneable.h"

namespace mystl
{
	//����ڵ�
	template<typename type>
	class LinkedListNode : public Iterable<type>
	{
	public:
		type data{ 0 };
		LinkedListNode* next = nullptr;

		//ʵ�ֵ������ӿ�
	public:
		Iterable<type>* getNext()
		{
			return next;
		}

		type* getValue()
		{
			return &data;
		}
	};

	//�洢�͹�������
	template<typename type>
	class LinkedList : public Cloneable
	{
	protected:
		using Node = LinkedListNode<type>;

		Node* root = new Node;
		//ֻ��add��remove��clear������Ӱ�쵽���һ���ڵ�
		Node* last = root;
		int count = 0;

	public:
		//���캯��
		LinkedList()
		{
		}

		//�������� - �ͷ���Դ
		virtual ~LinkedList()
		{
			clear();
			delete root;
		}

		//��ָ��λ�����Ԫ��
		void add(int index, type data)
		{
			if (count >= index && index >= 0)//index ���� [0,count]
			{
				//Ҫ����Ľڵ�
				Node* tag = new Node;
				tag->data = data;

				//������ĵ��ǰһ����
				Node* prepos = root;
				for (int i = 0; i < index; i++)
				{
					prepos = prepos->next;
				}

				if (prepos->next != nullptr)
				{
					//���ǵ�ǰ�����һ���ڵ�
					Node* tail = prepos->next;
					tag->next = tail;
					prepos->next = tag;
				}
				else
				{
					//��ǰ�����һ���ڵ�
					prepos->next = tag;
					last = tag;
				}

				count++;
			}
		}

		//�ڸ��ڵ����Ԫ��
		void addFirst(type data)
		{
			add(0, data);
		}

		//��ĩβ���Ԫ��
		void addLast(type data)
		{
			Node* tag = new Node;
			tag->data = data;
			last->next = tag;
			last = tag;
			count++;
		}

		//����ָ��λ�õ�Ԫ�أ�
		//��ȡ�ɹ�����true��ʧ���򷵻�false
		bool get(int index, type* data)
		{
			if (count > index && index >= 0)
			{
				//��λ�ڵ�
				Node* pos = root;
				for (int i = 0; i < index + 1; i++)
				{
					pos = pos->next;
				}

				*data = pos->data;
				return true;
			}
			else
			{
				return false;
			}
		}

		//�޸�ָ��λ�õ�Ԫ��
		void set(int index, type data)
		{
			if (count > index && index >= 0)
			{
				//��λ�ڵ�
				Node* pos = root;
				for (int i = 0; i < index + 1; i++)
				{
					pos = pos->next;
				}

				pos->data = data;
			}
		}

		//ɾ��ָ��λ�õ�Ԫ��
		//��ȡ�ɹ�����true��ʧ���򷵻�false
		bool __remove(int index)
		{
			//ȷ��ɾ��������ȷ
			if (count > index && index >= 0)
			{
				//��ɾ���ĵ��ǰһ����
				Node* prepos = root;
				//��Ҫɾ���ĵ�
				Node* tofree = nullptr;
				for (int i = 0; i < index; i++)
				{
					prepos = prepos->next;
				}

				tofree = prepos->next;
				if (tofree->next != nullptr)
				{
					//ɾ���Ĳ������һ���ڵ�
					Node* tail = tofree->next;
					prepos->next = tail;
				}
				else
				{
					//ɾ���������һ���ڵ�
					prepos->next = nullptr;
					last = prepos;
				}

				delete tofree;
				count--;
				return true;
			}
			else
			{
				return false;
			}
		}

		//�������Ԫ��
		void clear()
		{
			if (0 != count)
			{
				Node* tofree = root->next;
				Node* next = nullptr;

				do
				{
					next = tofree->next;
					delete tofree;
					tofree = next;
				} while (next != nullptr);

				root->next = nullptr;
				last = root;
				count = 0;
			}
		}

		//���ر���Ԫ�ظ���
		int getCount()
		{
			return count;
		}

		//��ȡ���������
		Iterator<type>* getIterator()
		{
			return new Iterator(root);
		}

		//����ʵ������
		void* clone()
		{
			LinkedList<type>* list = new  LinkedList<type>;
			Iterator<type>* itor = this->getIterator();
			type* v;
			while ((v = itor->next()) != nullptr)
			{
				list->addLast(*v);
			}
			delete itor;
			return list;
		}
	};
};
