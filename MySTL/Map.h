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

			delete[] str;
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
		using Iterator = Iterator<Node>;
		using uint = unsigned int;

		//加载因子
		static const double loadFactor;
		//容量
		int size = 11;
		//当前键值对总数
		int count = 0;
		//内部链表指针
		List** list = nullptr;

		//TODO:待实现
		//扩容函数
		void expand()
		{
		}
	public:
		//默认构造函数
		Map()
		{
			this->list = new List * [this->size];
			for (int i = 0; i < this->size; i++)
			{
				this->list[i] = new List();
			}
		}

		//指定初始大小的构造函数
		//大小最小可为11，若不满足该条件则强制执行
		Map(int size)
		{
			if (size >= 11)
			{
				this->size = size;
			}
			else
			{
				this->size = 11;
			}

			this->list = new List * [this->size];
			for (int i = 0; i < this->size; i++)
			{
				this->list[i] = new List();
			}
		}

		//释放资源
		~Map()
		{
			this->clear();
			for (int i = 0; i < this->size; i++)
			{
				delete this->list[i];
			}
			delete[] this->list;
		}

		//将一对键值放入哈希表，
		//若键已存在将会覆盖值，并返回false
		//否则正常添加返回true
		bool put(key k, value v)
		{
			uint hashCode = Hash::getHashCode(k);
			int pos = hashCode % this->size;
			Node tag{ k,v };
			if (this->list[pos]->getCount() == 0)
			{
				//无哈希冲突
				this->list[pos]->addFirst(tag);
				this->count++;
				return true;
			}
			else
			{
				//存在哈希冲突
				Iterator* itor = this->list[pos]->getIterator();
				Node* node;
				while ((node = itor->next()) != nullptr)
				{
					if (node->key == k)
					{
						//存在该键，直接覆盖
						node->value = v;
						return false;
					}
				}
				//不存在改键，新增
				this->list[pos]->addFirst(tag);
				this->count++;
				return true;
			}
		}

		//根据键获取值
		//若键存在返回true
		//否则返回false
		bool get(key k, value* v)
		{
			uint hashCode = Hash::getHashCode(k);
			int pos = hashCode % this->size;
			if (this->list[pos]->getCount() == 0)
			{
				v = nullptr;
				return false;
			}
			else
			{
				Iterator* itor = this->list[pos]->getIterator();
				Node* node;
				while ((node = itor->next()) != nullptr)
				{
					if (node->key == k)
					{
						*v = node->value;
						return true;
					}
				}
				v = nullptr;
				return false;
			}
		}

		//是否已存在该键
		bool containsKey(key key)
		{
			uint hashCode = Hash::getHashCode(key);
			int pos = hashCode % this->size;
			if (this->list[pos]->getCount() == 0)
			{
				return false;
			}
			else
			{
				Iterator* itor = this->list[pos]->getIterator();
				Node* node;
				while ((node = itor->next()) != nullptr)
				{
					if (node->key == key)
					{
						return true;
					}
				}
				return false;
			}
		}

		//根据键删除键值对
		//若键存在返回true
		//否则返回false
		bool remove(key k)
		{
			uint hashCode = Hash::getHashCode(k);
			int pos = hashCode % this->size;
			if (this->list[pos]->getCount() == 0)
			{
				return false;
			}
			else
			{
				Iterator* itor = this->list[pos]->getIterator();
				Node* node;
				int i = 0;
				while ((node = itor->next()) != nullptr)
				{
					if (node->key == k)
					{
						this->list[pos]->remove(i);
						this->count--;
						return true;
					}
					i++;
				}
				return false;
			}
		}

		//清空所有键值对
		void clear()
		{
			for (int i = 0; i < this->size; i++)
			{
				this->list[i]->clear();
			}
			this->count = 0;
		}

		//获取当前键值对个数
		int getCount()
		{
			return this->count;
		}

		//获取当前容量上限
		int getSize()
		{
			return this->size;
		}
	};

	template<typename key, typename value>
	const double Map<key, value>::loadFactor = 0.75f;
};
