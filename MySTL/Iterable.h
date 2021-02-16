#pragma once

namespace mystl
{
	//�ɵ����ӿ�
	//node	-> �����ýڵ�
	//value -> �ڵ��ϵ�����
	template<typename node, typename value>
	class Iterable
	{
	public:
		//��ȡ��һ���ڵ�ĵ����������û����һ���ڵ���Ӧ�÷���nullptr
		virtual Iterable* getNext() = 0;

		//��ȡ��ǰ�ڵ������ݵ�ָ�룬���û����һ���ڵ���Ӧ�÷���nullptr
		virtual value* getValue() = 0;
	};
};