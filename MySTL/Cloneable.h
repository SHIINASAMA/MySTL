#pragma once
namespace mystl
{
	//可拷贝接口
	class Cloneable
	{
	public:
		//该函数用于返回实例的副本
		virtual void* clone() = 0;
	};
}
