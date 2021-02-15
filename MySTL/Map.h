#pragma once
#include "LinkedList.h"
#include <string.h>

namespace mystl
{
	//哈希计算
	template<typename key>
	class Hash
	{
	public:
		using uint = unsigned int;
		using byte = char;

		//计算哈希值
		static uint getHashCode(key key, int size)
		{
			uint res = 0;
			//对齐后的数组长度
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
		//计算哈希值
		static uint getHashCode(key key)
		{
			return getHashCode(key, sizeof(key));
		}
	};

	//哈希节点
	template<typename key, typename value>
	class HashNode
	{
	public:
		key key;
		value value;
	};

	//哈希表
	template<typename key, typename value>
	class Map
	{
	protected:
		using Hash = Hash<key>;
		using Node = HashNode<key, value>;
		using List = LinkedList<Node>;
		using uint = unsigned int;

		//加载因子
		static const double loadFactor;
		//容量
		int size = 11;
		//当前键值对总数
		int count = 0;
		//内部链表指针
		List* list = nullptr;

		//扩容函数
		void expand()
		{
		}
	public:
		//默认构造函数
		Map()
		{
		}

		//指定初始大小的构造函数
		//大小最小可为11，若不满足该条件则强制执行
		Map(int size)
		{
		}

		//释放资源
		~Map()
		{
		}

		//将一对键值放入哈希表，
		//若键已存在将会覆盖值，并返回false
		//否则正常添加返回true
		bool put(key k, value v)
		{
		}

		//根据键获取值
		//若键存在返回true
		//否则返回false
		bool get(key k, value* v)
		{
		}

		//是否已存在该键
		bool containsKey(key key)
		{
		}

		//根据键删除键值对
		//若键存在返回true
		//否则返回false
		bool remove(key k)
		{
		}

		//清空所有键值对
		void clear()
		{
		}

		//获取当前键值对个数
		int getCount()
		{
		}

		//获取当前容量上限
		int getSize()
		{
		}
	};
	template<typename key, typename value>
	const double Map<key, value>::loadFactor = 0.75f;
};
