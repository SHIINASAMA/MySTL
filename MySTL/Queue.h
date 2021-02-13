#pragma once
#include "LinkedList.h"

namespace mystl
{
	template<typename type>
	class Queue : LinkedList<type>
	{
	protected:
		bool hasLimit = false;
		int limit = 0;

	public:
		//hasLimit用于设置队列元素是否有个数上限，默认为否
		Queue(bool hasLimit = false)
		{
			this->hasLimit = hasLimit;
		}

		//设置队列元素上限
		//该函数在构造函数设置有上限时生效
		//设置成功返回true，
		//设置失败返回false
		bool setLimit(int limit)
		{
			if (limit <= 0 || count > limit)
			{
				return false;
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
			addLast(data);
		}

		//将一个元素放入队列末尾，
		//该函数适用于存在上限时，
		//添加成功返回true，添加失败返回false
		bool offer(type data)
		{
			if (!hasLimit)
			{
				if (count < limit)
				{
					addLast(data);
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
			if (count == 0)
			{
				return false;
			}
			get(0, data);
		}

		//获取并删除队列的第一个元素
		//如果队列为空则返回false，
		//成功返回true
		bool take()
		{
			if (count == 0)
			{
				return false;
			}
			get(0, data);
			remove(0);
			return true;
		}

		//清空队列
		void clear()
		{
			LinkedList<type>::clear();
		}
	};
}
