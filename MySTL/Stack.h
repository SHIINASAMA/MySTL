#pragma once
#include "LinkedList.h"

namespace mystl
{
	//堆栈
	template<typename type>
	class Stack : LinkedList<type>
	{
	public:
		//构造函数
		Stack()
		{
		}

		//获取堆栈顶部元素
		//成功返回true
		//失败返回false
		bool peek(type* data)
		{
			return __super::get(0, data);
		}

		//获取并删除堆栈顶部元素（弹出）
		//成功返回true
		//失败返回false
		bool pop(type* data)
		{
			if (__super::count == 0)
			{
				return false;
			}
			__super::get(0, data);
			__super::remove(0);
			return true;
		}

		//将元素压入堆栈
		void push(type data)
		{
			__super::addFirst(data);
		}

		//直接删除堆栈顶部元素
		//成功返回true
		//失败返回false
		bool remove()
		{
			if (__super::count == 0)
			{
				return false;
			}
			__super::remove(0);
			return true;
		}

		//清除堆栈内元素
		void clear()
		{
			__super::claer();
		}

		//获取堆栈中元素个数
		int getCount()
		{
			return __super::count;
		}

		//返回实例副本
		void* clone()
		{
			Stack<type>* stack = new Stack<type>;
			Iterator<type>* itor = this->getIterator();
			type* v;
			while ((v = itor->next()) != nullptr)
			{
				stack->addLast(*v);
			}
			delete itor;
			return stack;
		}
	};
};
