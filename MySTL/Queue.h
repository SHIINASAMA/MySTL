#pragma once
#include "LinkedList.h"

namespace mystl
{
	//队列
	template<typename type>
	class Queue : LinkedList<type>
	{
	protected:
		bool hasLimit = false;
		int limit = 0;

	public:
		//构造函数
		Queue()
		{
		}

		//设置队列元素上限
		//设置为0，则为无限制,
		//设置成功返回true，
		//设置失败返回false
		bool setLimit(int limit)
		{
			if (limit < 0 || this->count > limit)
			{
				return false;
			}
			else if (0 == limit)
			{
				this->hasLimit = false;
			}
			this->limit = limit;
			return true;
		}

		//将一个元素放入队列末尾，
		//该函数适用于没有上限存在时
		void put(type data)
		{
			if (hasLimit)
			{
				return;
			}
			__super::addLast(data);
		}

		//将一个元素放入队列末尾，
		//该函数适用于存在上限时，
		//添加成功返回true，添加失败返回false
		bool offer(type data)
		{
			if (hasLimit)
			{
				if (__super::count < limit)
				{
					__super::addLast(data);
					return true;
				}
			}
			return false;
		}

		//获取队列第一个元素，
		//如果队列为空则返回false，
		//成功返回true
		bool peek(type* data)
		{
			if (__super::count == 0)
			{
				return false;
			}
			get(0, data);
		}

		//获取并删除队列的第一个元素
		//如果队列为空则返回false，
		//成功返回true
		bool take(type* data)
		{
			if (__super::count == 0)
			{
				return false;
			}
			__super::get(0, data);
			__super::__remove(0);
			return true;
		}

		//直接删除队列的第一个元素
		//如果队列为空则返回false，
		//成功返回true
		bool __remove()
		{
			if (__super::count == 0)
			{
				return false;
			}
			__super::__remove(0);
			return true;
		}

		//清空队列
		void clear()
		{
			__super::clear();
		}

		//返回队列内元素个数
		int getCount()
		{
			return __super::count;
		}

		//返回实例副本
		void* clone()
		{
			Queue<type>* queue = new Queue<type>;
			Iterator<type>* itor = __super::getIterator();
			type* v;
			while ((v = itor->next()) != nullptr)
			{
				queue->addLast(*v);
			}
			delete itor;
			queue->hasLimit = this->hasLimit;
			queue->limit = this->limit;
			return queue;
		}
	};
}
