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
		type data;
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
		//ֻ��add��remove��clear������Ӱ�쵽�����ڶ����ڵ�
		Node* penultimate = root;
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
					Node* tail = prepos->next;
					tag->next = tail;
					prepos->next = tag;
					if (index == count - 1)
					{
						penultimate = prepos->next;
					}
				}
				else
				{
					prepos->next = tag;
					penultimate = prepos;
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
			if (count != 0)
			{
				penultimate = penultimate->next;
			}
			penultimate->next = tag;
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
		bool remove(int index)
		{
			//ȷ��ɾ��������ȷ
			if (count > index && index >= 0)
			{
				Node* preprepos = root;
				//��ɾ���ĵ��ǰһ����
				Node* prepos = root;
				//��Ҫɾ���ĵ�
				Node* tofree = nullptr;
				for (int i = 0; i < index; i++)
				{
					preprepos = prepos;
					prepos = prepos->next;
				}

				tofree = prepos->next;
				if (prepos->next->next != nullptr)
				{
					Node* tail = prepos->next->next;
					prepos->next = tail;
					if (tail->next == nullptr)
					{
						penultimate = prepos;
					}
				}
				else
				{
					prepos->next = nullptr;
					penultimate = preprepos;
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
				Node* pos = root->next;
				Node* next;

				for (int i = 0; i < count; i++)
				{
					next = pos->next;
					delete pos;
					pos = next;
				}

				root->next = nullptr;
				penultimate = root;
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
