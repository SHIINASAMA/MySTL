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
		//hasLimit�������ö���Ԫ���Ƿ��и������ޣ�Ĭ��Ϊ��
		Queue(bool hasLimit = false)
		{
			this->hasLimit = hasLimit;
		}

		//���ö���Ԫ������
		//�ú����ڹ��캯������������ʱ��Ч
		//���óɹ�����true��
		//����ʧ�ܷ���false
		bool setLimit(int limit)
		{
			if (limit <= 0 || count > limit)
			{
				return false;
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

		//��ȡ���е�һ��Ԫ�أ�
		//�������Ϊ���򷵻�false��
		//�ɹ�����true
		bool peek(type* data)
		{
			if (count == 0)
			{
				return false;
			}
			get(0, data);
		}

		//��ȡ��ɾ�����еĵ�һ��Ԫ��
		//�������Ϊ���򷵻�false��
		//�ɹ�����true
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

		//��ն���
		void clear()
		{
			LinkedList<type>::clear();
		}
	};
}
