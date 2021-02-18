#include "../MySTL/Huffman.h"
#include <stdio.h>

using namespace mystl;

int main()
{
	int nums1[] = { 99,29,38,56,33,12,7 };
	int nums2[] = { 99,29,38,56,33,12,7 };

	sort(nums1, 7, SortMode::ASC);
	sort(nums2, 7, SortMode::DESC);
	return 0;
}