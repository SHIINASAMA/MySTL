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
		type data{ 0 };
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
		//只有add、remove和clear方法会影响到最后一个节点
		Node* last = root;
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
					//不是当前的最后一个节点
					Node* tail = prepos->next;
					tag->next = tail;
					prepos->next = tag;
				}
				else
				{
					//当前的最后一个节点
					prepos->next = tag;
					last = tag;
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
			last->next = tag;
			last = tag;
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
		bool __remove(int index)
		{
			//确保删除区间正确
			if (count > index && index >= 0)
			{
				//将删除的点的前一个点
				Node* prepos = root;
				//将要删除的点
				Node* tofree = nullptr;
				for (int i = 0; i < index; i++)
				{
					prepos = prepos->next;
				}

				tofree = prepos->next;
				if (tofree->next != nullptr)
				{
					//删除的不是最后一个节点
					Node* tail = tofree->next;
					prepos->next = tail;
				}
				else
				{
					//删除的是最后一个节点
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

		//清空所有元素
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
