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
		//���캯��
		Queue()
		{
		}

		//���ö���Ԫ������
		//����Ϊ0����Ϊ������,
		//���óɹ�����true��
		//����ʧ�ܷ���false
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

		//��һ��Ԫ�ط������ĩβ��
		//�ú���������û�����޴���ʱ
		void put(type data)
		{
			if (hasLimit)
			{
				return;
			}
			addLast(data);
		}

		//��һ��Ԫ�ط������ĩβ��
		//�ú��������ڴ�������ʱ��
		//��ӳɹ�����true�����ʧ�ܷ���false
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

		//��ȡ���е�һ��Ԫ�أ�
		//�������Ϊ���򷵻�false��
		//�ɹ�����true
		bool peek(type* data)
		{
			if (__super::count == 0)
			{
				return false;
			}
			get(0, data);
		}

		//��ȡ��ɾ�����еĵ�һ��Ԫ��
		//�������Ϊ���򷵻�false��
		//�ɹ�����true
		bool take(type* data)
		{
			if (__super::count == 0)
			{
				return false;
			}
			__super::get(0, data);
			__super::remove(0);
			return true;
		}

		//��ն���
		void clear()
		{
			LinkedList<type>::clear();
		}
	};
}
