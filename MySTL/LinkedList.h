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

		Node* root = nullptr;
		int count = 0;

	public:
#pragma region ������ɾ���
		//��ָ��λ�����Ԫ��
		void add(int index, type data)
		{
			if (count - 1 >= index && index >= 0)
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
				if (nullptr != pos->next->next)
				{
					Node* tail = pos->next->next;
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
			if (count - 1 >= index && index >= 0)
			{
				//��λ�ڵ�
				Node* pos = root;
				for (int i = 0; i < index; i++)
				{
					pos = pos->next;
				}

				return pos->data;
			}
		}

		//�޸�ָ��λ�õ�Ԫ��
		void set(int index, type data)
		{
			if (count - 1 >= index && index >= 0)
			{
				//��λ�ڵ�
				Node* pos = root;
				for (int i = 0; i < index; i++)
				{
					pos = pos->next;
				}

				pos->data = data;
			}
		}

		//ɾ��ָ��λ�õ�Ԫ��
		void remove(int index)
		{
			if (count - 1 >= index && index >= 0)
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
					tag->next = tail;
				}
				else
				{
					delete pos->next;
					pos->next = nullptr;
				}

				count--;
			}
		}
#pragma endregion
	};
};
