#pragma once

namespace mystd
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
		using Node = LinkedListNode<type>;

		Node* root = new Node;
		int count = 0;

	public:
		LinkedList()
		{
		}

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
				//Ҫ����Ľڵ�
				Node* tag = new Node;
				tag->data = data;

				//��λ�ڵ�
				Node* pos = root;
				for (int i = 0; i < index; i++)
				{
					pos = pos->next;
				}

				//�жϲ���λ��β���Ƿ��нڵ�
				if (nullptr != pos->next)
				{
					Node* tail = pos->next;
					pos->next = tag;
					tag->next = tail;
				}
				else
				{
					pos->next = tag;
				}

				count++;
			}
		}

		//����ָ��λ�õ�Ԫ��
		type get(int index)
		{
			if (count > index && index >= 0)
			{
				//��λ�ڵ�
				Node* pos = root;
				for (int i = 0; i < index + 1; i++)
				{
					pos = pos->next;
				}

				return pos->data;
			}

			return (type)(0);
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
		void remove(int index)
		{
			if (count > index && index >= 0)
			{
				//��λ�ڵ�
				Node* pos = root;
				for (int i = 0; i < index; i++)
				{
					pos = pos->next;
				}

				//�жϲ���λ��β���Ƿ��нڵ�
				if (nullptr != pos->next->next)
				{
					Node* tail = pos->next->next;
					delete pos->next;
					pos->next = tail;
				}
				else
				{
					delete pos->next;
					pos->next = nullptr;
				}

				count--;
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
			}

			count = 0;
		}
	};
};
