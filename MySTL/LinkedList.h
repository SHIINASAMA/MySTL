#pragma once
#include "Iterator.h"
#include "Cloneable.h"

namespace mystl
{
	//链表节点
	template<typename type>
	class LinkedListNode : public Iterable<type>
	{
	public:
		type data;
		LinkedListNode* next = nullptr;

		//实现迭代器接口
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

	//存储和管理链表
	template<typename type>
	class LinkedList : public Cloneable
	{
	protected:
		using Node = LinkedListNode<type>;

		Node* root = new Node;
		//只有add、remove和clear方法会影响到倒数第二个节点
		Node* penultimate = root;
		int count = 0;

	public:
		//构造函数
		LinkedList()
		{
		}

		//析构函数 - 释放资源
		virtual ~LinkedList()
		{
			clear();
			delete root;
		}

		//在指定位置添加元素
		void add(int index, type data)
		{
			if (count >= index && index >= 0)//index 属于 [0,count]
			{
				//要插入的节点
				Node* tag = new Node;
				tag->data = data;

				//将插入的点的前一个点
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

		//在根节点添加元素
		void addFirst(type data)
		{
			add(0, data);
		}

		//在末尾添加元素
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
				Node* preprepos = root;
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
				penultimate = root;
				count = 0;
			}
		}

		//返回表内元素个数
		int getCount()
		{
			return count;
		}

		//获取链表迭代器
		Iterator<type>* getIterator()
		{
			return new Iterator(root);
		}

		//返回实例副本
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
