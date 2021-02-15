#pragma once
#include "LinkedList.h"
#include <string.h>

namespace mystl
{
	//��ϣ����
	template<typename key>
	class Hash
	{
	public:
		using uint = unsigned int;
		using byte = char;

		//�����ϣֵ
		static uint getHashCode(key key, int size)
		{
			uint res = 0;
			//���������鳤��
			int len = size / 4;
			if (size % 4 != 0)
			{
				len++;
			}

			byte* str = new byte[len * 4];
			//memset(str, 0, len * 4);
			memcpy(str, &key, size);
			uint temp = 0;
			for (int i = 0; i < len; i++)
			{
				memcpy(&temp, (str + i * 4), 4);
				res += temp;
			}

			delete str;
			return res;
		}
		//�����ϣֵ
		static uint getHashCode(key key)
		{
			return getHashCode(key, sizeof(key));
		}
	};

	//��ϣ�ڵ�
	template<typename key, typename value>
	class HashNode
	{
	public:
		key key;
		value value;
	};

	//��ϣ��
	template<typename key, typename value>
	class Map
	{
	protected:
		using Hash = Hash<key>;
		using Node = HashNode<key, value>;
		using List = LinkedList<Node>;
		using uint = unsigned int;

		//��������
		static const double loadFactor;
		//����
		int size = 11;
		//��ǰ��ֵ������
		int count = 0;
		//�ڲ�����ָ��
		List* list = nullptr;

		//���ݺ���
		void expand()
		{
		}
	public:
		//Ĭ�Ϲ��캯��
		Map()
		{
		}

		//ָ����ʼ��С�Ĺ��캯��
		//��С��С��Ϊ11�����������������ǿ��ִ��
		Map(int size)
		{
		}

		//�ͷ���Դ
		~Map()
		{
		}

		//��һ�Լ�ֵ�����ϣ��
		//�����Ѵ��ڽ��Ḳ��ֵ��������false
		//����������ӷ���true
		bool put(key k, value v)
		{
		}

		//���ݼ���ȡֵ
		//�������ڷ���true
		//���򷵻�false
		bool get(key k, value* v)
		{
		}

		//�Ƿ��Ѵ��ڸü�
		bool containsKey(key key)
		{
		}

		//���ݼ�ɾ����ֵ��
		//�������ڷ���true
		//���򷵻�false
		bool remove(key k)
		{
		}

		//������м�ֵ��
		void clear()
		{
		}

		//��ȡ��ǰ��ֵ�Ը���
		int getCount()
		{
		}

		//��ȡ��ǰ��������
		int getSize()
		{
		}
	};
	template<typename key, typename value>
	const double Map<key, value>::loadFactor = 0.75f;
};
