#pragma once

namespace mystl
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
	protected:
		using Node = LinkedListNode<type>;

		Node* root = new Node;
		//只有add、remove和clear方法会影响到倒数第二个节点
		Node* penultimate = nullptr;
		int count = 0;

	public:
		//构造函数
		LinkedList()
		{
		}

		//析构函数 - 释放资源
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
				Node* penultimate = nullptr;
				//要插入的节点
				Node* tag = new Node;
				tag->data = data;

				//将插入的点的前一个点
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

		//在根节点添加元素
		void addFirst(type data)
		{
			add(0, data);
		}

		//在末尾添加元素
		void addLast(type data)
		{
			Node* tag = new tag;
			tag->data = data;

			penultimate = penultimate->next;
			penultimate->next = tag;
		}

		//返回指定位置的元素，
		//获取成功返回true，失败则返回false
		bool get(int index, type* data)
		{
			if (count > index && index >= 0)
			{
				//定位节点
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
		//获取成功返回true，失败则返回false
		bool remove(int index)
		{
			//确保删除区间正确
			if (count > index && index >= 0)
			{
				Node* penultimate = nullptr;
				Node* preprepos = nullptr;
				//将删除的点的前一个点
				Node* prepos = root;
				//将要删除的点
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

		//清空所有元素
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
