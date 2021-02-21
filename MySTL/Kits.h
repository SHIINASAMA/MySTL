#pragma once

namespace mystl
{
	//交换变量
	template<typename type>
	extern void swab(type* A, type* B)
	{
		type temp = *A;
		*A = *B;
		*B = temp;
	}

	//比较大小
	//返回0则表示相等
	//返回正数表示前者大
	//负数反之
	template<typename type>
	extern int compare(type A, type B)
	{
		return A - B;
	}

	//正序排序递归
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

	//反序排序递归
	template<typename type>
	extern void descSort(type nums[], int left, int right)
	{
		if (left > right)
		{
			return;
		}

		int i = left;
		int j = right;
		type base = nums[left];//基准值
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

	//排序模式
	enum class SortMode
	{
		//正序
		ASC = 0,
		//反序
		DESC = 1
	};

	//快速排序
	template<typename type>
	extern void sort(type objs[], int count, SortMode mode)
	{
		if (mode == SortMode::ASC)
			ascSort<type>(objs, 0, count - 1);
		else
			descSort<type>(objs, 0, count - 1);
	}

	//二进制枚举
	enum class Code
	{
		Zero = 0,
		One = 1
	};

	//返回两者最大值
	template<typename type>
	extern type max(type A, type B)
	{
		return A >= B ? A : B;
	}
};
