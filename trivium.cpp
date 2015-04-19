// trivium.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "Case42.h"

int _tmain(int argc, _TCHAR* argv[])
{
	bool found = false;
	//vector<unsigned int> test = {0,0};
	//unsigned __int64 cycle = Case42::run(BigInt(test, 42 % 32), found);
	unsigned __int64 cycle = Case42::run(BigInt("000000000000000000000100000100100000000100"), found);
	if (found) {
		printf("%I64u\n", cycle);
	}
	else {
		printf("Not found\n");
	}
	system("pause");
	return 0;
}