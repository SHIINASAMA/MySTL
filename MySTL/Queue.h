#pragma once
#include "LinkedList.h"

namespace mystl
{
	template<typename type>
	class Queue : LinkedList<type>
	{
	public:
		//��һ��Ԫ�ط������ĩβ
		void put(type data)
		{
		}

		//���ض��е�һ��Ԫ��
		void peek(int index)
		{
		}
	};
}
