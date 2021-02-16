#pragma once
#include "Iterable.h"

namespace mystl
{
	//前向迭代器
	//value -> 节点上的数据
	template<typename value>
	class Iterator
	{
		using Iterable = Iterable<value>;

		Iterable* impl;

	public:
		//迭代器的初始化
		Iterator(Iterable* impl)
		{
			this->impl = impl;
		}

		//迭代并返回下一节点数据的指针，如果没有下一个节点则返回nullptr
		value* next()
		{
			this->impl = this->impl->getNext();
			if (this->impl != nullptr)
			{
				return this->impl->getValue();
			}
			else
			{
				return nullptr;
			}
		}
	};
};
