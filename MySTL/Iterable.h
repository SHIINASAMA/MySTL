#pragma once

namespace mystl
{
	//前向可迭代接口
	//value -> 节点上的数据
	template<typename value>
	class Iterable
	{
	public:
		//获取下一个节点的迭代器，如果没有下一个节点则应该返回nullptr
		virtual Iterable* getNext() = 0;

		//获取当前节点上数据的指针，如果没有下一个节点则应该返回nullptr
		virtual value* getValue() = 0;
	};
};