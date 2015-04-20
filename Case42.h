#pragma once
#include "BigInt.h"
class Case42
{
public:
	Case42();
	static unsigned __int64 run(BigInt T, bool &found);
	static unsigned __int64 run(BigInt T, bool &found, vector<BigInt> &log);
	~Case42();
};

