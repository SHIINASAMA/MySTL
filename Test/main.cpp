#include "../MySTL/Map.h"
#include <stdio.h>

using namespace mystl;

int main()
{
	char hello[] = "lllll";
	char hello1[] = "lll1l";
	auto a = Hash<char[]>::getHashCode(hello, sizeof(hello));
	auto b = Hash<char[]>::getHashCode(hello1, sizeof(hello1));
	return 0;
}