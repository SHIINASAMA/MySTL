#pragma once
namespace mystl
{
	//�ɿ����ӿ�
	class Cloneable
	{
	public:
		//�ú������ڷ���ʵ���ĸ���
		virtual void* clone() = 0;
	};
}
