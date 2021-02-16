#pragma once
#include "Iterable.h"

namespace mystl
{
	//ǰ�������
	//value -> �ڵ��ϵ�����
	template<typename value>
	class Iterator
	{
		using Iterable = Iterable<value>;

		Iterable* impl;

	public:
		//�������ĳ�ʼ��
		Iterator(Iterable* impl)
		{
			this->impl = impl;
		}

		//������������һ�ڵ����ݵ�ָ�룬���û����һ���ڵ��򷵻�nullptr
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
