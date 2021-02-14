#pragma once
#include "LinkedList.h"
#include <string.h>

namespace mystl
{
	template<typename key>
	class Hash
	{
	public:
		using uint = unsigned int;
		using byte = char;

		//计算哈希值
		static uint getHashCode(key key)
		{
			uint res = 0;
			//键长度
			int size = sizeof(key);
			//对齐后的数组长度
			int len = size / 4;
			if (size % 4 != 0)
			{
				len++;
			}

			byte* str = new byte[len * 4];
			memset(str, 0, len * 4);
			memcpy(str, &key, size);
			uint temp;
			for (int i = len; i > 0; i--)
			{
				memcpy(&temp, (str + i * 4), 4);
				res += temp;
			}

			delete str;
			return res;
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
	class Map
	{
	};
};
