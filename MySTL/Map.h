#pragma once
#include "LinkedList.h"
#include <string.h>
#include <stdio.h>

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

			delete[] str;
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
	class Map : Cloneable
	{
	protected:
		using Hash = Hash<key>;
		using Node = HashNode<key, value>;
		using List = LinkedList<Node>;
		using Iterator = Iterator<Node>;
		using uint = unsigned int;

		//��������
		static const double loadFactor;
		//����
		int size = 11;
		//��ǰ��ֵ������
		int count = 0;
		//�ڲ�����ָ��
		List* list = nullptr;

		//���ݺ��� - �ɳ����Զ��ж��Ƿ���Ҫ���ݣ�����Ҫ�˹��ж�
		//���ݹ�ʽ f(size) = size * 2 + 1
		void expand()
		{
			//��ʱ�洢����
			List* temp = new List;
			int count = 0;
			for (int i = 0; i < this->size; i++)
			{
				Iterator* itor = this->list[i].getIterator();
				Node* node;
				while ((node = itor->next()) != nullptr)
				{
					temp->addFirst(*node);
					count++;
				}
				if (count == this->count)
				{
					break;
				}
				delete itor;
			}

			//�ͷ�ԭ�пռ䲢���·���ռ�
			delete[] this->list;
			this->size = this->size * 2 + 1;
			this->list = new List[this->size];

			//���¼���Hashֵ�������µ�ַ
			Iterator* itor = temp->getIterator();
			Node* node;
			uint hashCode;
			uint pos;
			while ((node = itor->next()) != nullptr)
			{
				hashCode = Hash::getHashCode(node->key);
				pos = hashCode % this->size;
				this->list[pos].addFirst(*node);
			}

			//�ͷ���ʱ����Դ
			delete itor;
			delete temp;
		}

	public:
		//Ĭ�Ϲ��캯��
		Map()
		{
			this->list = new List[this->size];
		}

		//ָ����ʼ��С�Ĺ��캯��
		//��С��С��Ϊ11�����������������ǿ��ִ��
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

			this->list = new List[this->size];
		}

		//�ͷ���Դ
		~Map()
		{
			this->clear();
			delete[] this->list;
		}

		//��һ�Լ�ֵ�����ϣ��
		//�����Ѵ��ڽ��Ḳ��ֵ��������false
		//����������ӷ���true
		bool put(key k, value v)
		{
			uint hashCode = Hash::getHashCode(k);
			int pos = hashCode % this->size;
			Node tag{ k,v };
			if (this->list[pos].getCount() == 0)
			{
				//�޹�ϣ��ͻ
				if (this->count == (int)(this->size * loadFactor - 1))
				{
					expand();
				}
				this->list[pos].addFirst(tag);
				this->count++;
				return true;
			}
			else
			{
				//���ڹ�ϣ��ͻ
				Iterator* itor = this->list[pos].getIterator();
				Node* node;
				while ((node = itor->next()) != nullptr)
				{
					if (node->key == k)
					{
						//���ڸü���ֱ�Ӹ���
						node->value = v;
						return false;
					}
				}
				delete itor;

				if (this->count == this->size * loadFactor - 1)
				{
					expand();
				}
				//�����ڸļ�������
				this->list[pos].addFirst(tag);
				this->count++;
				return true;
			}
		}

		//���ݼ���ȡֵ
		//�������ڷ���true
		//���򷵻�false
		bool get(key k, value* v)
		{
			uint hashCode = Hash::getHashCode(k);
			int pos = hashCode % this->size;
			if (this->list[pos].getCount() == 0)
			{
				v = nullptr;
				return false;
			}
			else
			{
				Iterator* itor = this->list[pos].getIterator();
				Node* node;
				while ((node = itor->next()) != nullptr)
				{
					if (node->key == k)
					{
						*v = node->value;
						delete itor;
						return true;
					}
				}
				v = nullptr;
				delete itor;
				return false;
			}
		}

		//�Ƿ��Ѵ��ڸü�
		bool containsKey(key key)
		{
			uint hashCode = Hash::getHashCode(key);
			int pos = hashCode % this->size;
			if (this->list[pos].getCount() == 0)
			{
				return false;
			}
			else
			{
				Iterator* itor = this->list[pos].getIterator();
				Node* node;
				while ((node = itor->next()) != nullptr)
				{
					if (node->key == key)
					{
						delete itor;
						return true;
					}
				}
				delete itor;
				return false;
			}
		}

		//���ݼ�ɾ����ֵ��
		//�������ڷ���true
		//���򷵻�false
		bool __remove(key k)
		{
			uint hashCode = Hash::getHashCode(k);
			int pos = hashCode % this->size;
			if (this->list[pos].getCount() == 0)
			{
				return false;
			}
			else
			{
				Iterator* itor = this->list[pos].getIterator();
				Node* node;
				int i = 0;
				while ((node = itor->next()) != nullptr)
				{
					if (node->key == k)
					{
						this->list[pos].__remove(i);
						this->count--;
						delete itor;
						return true;
					}
					i++;
				}
				delete itor;
				return false;
			}
		}

		//������м�ֵ��
		void clear()
		{
			for (int i = 0; i < this->size; i++)
			{
				this->list[i].clear();
			}
			this->count = 0;
		}

		//��ȡ��ǰ��ֵ�Ը���
		int getCount()
		{
			return this->count;
		}

		//��ȡ��ǰ��������
		int getSize()
		{
			return this->size;
		}

		//����ʵ������
		void* clone()
		{
			Map<key, value>* map = new Map<key, value>(this->size);
			map->size = this->size;
			map->count = this->count;
			for (int i = 0; i < map->size; i++)
			{
				map->list[i] = *(LinkedList<Node>*)this->list[i].clone();
			}
			return map;
		}
	};

	template<typename key, typename value>
	const double Map<key, value>::loadFactor = 0.75f;
};
