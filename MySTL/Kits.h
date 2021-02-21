#pragma once

namespace mystl
{
	//��������
	template<typename type>
	extern void swab(type* A, type* B)
	{
		type temp = *A;
		*A = *B;
		*B = temp;
	}

	//�Ƚϴ�С
	//����0���ʾ���
	//����������ʾǰ�ߴ�
	//������֮
	template<typename type>
	extern int compare(type A, type B)
	{
		return A - B;
	}

	//��������ݹ�
	template<typename type>
	extern void ascSort(type nums[], int left, int right)
	{
		if (left > right)
		{
			return;
		}

		int i = left;
		int j = right;
		type base = nums[left];
		while (i != j)
		{
			while (nums[j] >= base && i < j)
			{
				j--;
			}
			while (nums[i] <= base && i < j)
			{
				i++;
			}
			if (left < right)
			{
				swab<type>(&nums[i], &nums[j]);
			}
		}

		nums[left] = nums[i];
		nums[i] = base;

		ascSort<type>(nums, left, i - 1);
		ascSort<type>(nums, i + 1, right);
	}

	//��������ݹ�
	template<typename type>
	extern void descSort(type nums[], int left, int right)
	{
		if (left > right)
		{
			return;
		}

		int i = left;
		int j = right;
		type base = nums[left];//��׼ֵ
		while (i != j)
		{
			while (nums[j] <= base && i < j)
			{
				j--;
			}
			while (nums[i] >= base && i < j)
			{
				i++;
			}
			if (left < right)
			{
				swab<type>(&nums[i], &nums[j]);
			}
		}

		nums[left] = nums[i];
		nums[i] = base;

		descSort<type>(nums, left, i - 1);
		descSort<type>(nums, i + 1, right);
	}

	//����ģʽ
	enum class SortMode
	{
		//����
		ASC = 0,
		//����
		DESC = 1
	};

	//��������
	template<typename type>
	extern void sort(type objs[], int count, SortMode mode)
	{
		if (mode == SortMode::ASC)
			ascSort<type>(objs, 0, count - 1);
		else
			descSort<type>(objs, 0, count - 1);
	}

	//������ö��
	enum class Code
	{
		Zero = 0,
		One = 1
	};

	//�����������ֵ
	template<typename type>
	extern type max(type A, type B)
	{
		return A >= B ? A : B;
	}
};
