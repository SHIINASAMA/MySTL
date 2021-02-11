#pragma once

namespace mystd
{
	//链表节点
	template<typename type>
	class LinkedListNode
	{
	public:
		type data;
		LinkedListNode* next;
	};

	//存储和管理链表
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

		//在指定位置添加元素
		void add(int index, type data)
		{
			if (count >= index && index >= 0)
			{
				//要插入的节点
				Node* tag = new Node;
				tag->data = data;

				//定位节点
				Node* pos = root;
				for (int i = 0; i < index; i++)
				{
					pos = pos->next;
				}

				//判断插入位置尾部是否还有节点
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

		//返回指定位置的元素
		type get(int index)
		{
			if (count > index && index >= 0)
			{
				//定位节点
				Node* pos = root;
				for (int i = 0; i < index + 1; i++)
				{
					pos = pos->next;
				}

				return pos->data;
			}

			return (type)(0);
		}

		//修改指定位置的元素
		void set(int index, type data)
		{
			if (count > index && index >= 0)
			{
				//定位节点
				Node* pos = root;
				for (int i = 0; i < index + 1; i++)
				{
					pos = pos->next;
				}

				pos->data = data;
			}
		}

		//删除指定位置的元素
		void remove(int index)
		{
			if (count > index && index >= 0)
			{
				//定位节点
				Node* pos = root;
				for (int i = 0; i < index; i++)
				{
					pos = pos->next;
				}

				//判断插入位置尾部是否还有节点
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

		//清空所有元素
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
