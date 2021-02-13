#pragma once

namespace mystl
{
	//����ڵ�
	template<typename type>
	class LinkedListNode
	{
	public:
		type data;
		LinkedListNode* next;
	};

	//�洢�͹�������
	template<typename type>
	class LinkedList
	{
	protected:
		using Node = LinkedListNode<type>;

		Node* root = new Node;
		//ֻ��add��remove��clear������Ӱ�쵽�����ڶ����ڵ�
		Node* penultimate = nullptr;
		int count = 0;

	public:
		//���캯��
		LinkedList()
		{
		}

		//�������� - �ͷ���Դ
		~LinkedList()
		{
			clear();
			delete root;
		}

		//��ָ��λ�����Ԫ��
		void add(int index, type data)
		{
			if (count >= index && index >= 0)
			{
				Node* penultimate = nullptr;
				//Ҫ����Ľڵ�
				Node* tag = new Node;
				tag->data = data;

				//������ĵ��ǰһ����
				Node* prepos = root;
				for (int i = 0; i < index; i++)
				{
					prepos = prepos->next;
				}

				if (nullptr != prepos->next)
				{
					Node* tail = prepos->next;
					tag->next = tail;
					prepos->next = tag;
					penultimate = prepos;
				}
				else
				{
					tag->next = prepos->next;
					prepos->next = tag;
					penultimate = tag;
				}

				if (count - 2 < index)
				{
					this->penultimate = penultimate;
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
			Node* tag = new tag;
			tag->data = data;

			penultimate = penultimate->next;
			penultimate->next = tag;
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
				Node* penultimate = nullptr;
				Node* preprepos = nullptr;
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
				if (nullptr != tofree->next)
				{
					Node* tail = tofree->next;
					prepos->next = tail;
				}
				delete tofree;

				if (count == 1)
				{
					penultimate = nullptr;
				}
				else if (count - 1 > index)
				{
					penultimate = prepos;
				}
				else if (count - 1 == index)
				{
					penultimate = preprepos;
				}

				if (count - 2 < index)
				{
					this->penultimate = penultimate;
				}

				count--;
				return true;
			}
			else
			{
				return false;
			}
		}

		//�������Ԫ��
		virtual void clear()
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
				penultimate = nullptr;
				count = 0;
			}
		}
	};
};
