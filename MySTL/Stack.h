#pragma once
#include "LinkedList.h"

namespace mystl
{
	template<typename type>
	class Stack : LinkedList<type>
	{
	public:
		//���캯��
		Stack()
		{
		}

		//��ȡ��ջ����Ԫ��
		//�ɹ�����true
		//ʧ�ܷ���false
		bool peek(type* data)
		{
			return __super::get(0, data);
		}

		//��ȡ��ɾ����ջ����Ԫ�أ�������
		//�ɹ�����true
		//ʧ�ܷ���false
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

		//��Ԫ��ѹ���ջ
		void push(type data)
		{
			__super::addFirst(data);
		}

		//�����ջ��Ԫ��
		void clear()
		{
			__super::claer();
		}

		//��ȡ��ջ��Ԫ�ظ���
		int getCount()
		{
			return __super::count;
		}
	};
};
