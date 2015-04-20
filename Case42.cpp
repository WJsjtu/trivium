#include "stdafx.h"
#include "Case42.h"


Case42::Case42()
{

}

unsigned __int64 Case42::run(BigInt T, bool &found){
	BigInt S = T;
	char w[] = { 1, 2, 4, 6, 8, 9, 11, 13, 14 };
	if (T.size() != 42){
		return false;
	}
	for (unsigned __int64 i = 0; i < 18446744073709551615; i++){
		char t0 = (T.getBit(3 * w[0]) + (T.getBit(3 * w[2] - 1) & T.getBit(3 * w[2] - 2)) + T.getBit(3 * w[4])) & 1;
		char t1 = (T.getBit(3 * w[3]) + (T.getBit(3 * w[5] - 1) & T.getBit(3 * w[5] - 2)) + T.getBit(3 * w[7])) & 1;
		char t2 = (T.getBit(3 * w[6]) + (T.getBit(3 * w[8] - 1) & T.getBit(3 * w[8] - 2)) + T.getBit(3 * w[1])) & 1;
		T.shift();
		T.setBit(1, t2);
		T.setBit(3 * w[2] + 1, t0);
		T.setBit(3 * w[5] + 1, t1);
		if (T == S){
			found = true;
			return i;
		}
	}
	found = false;
	return 0;
}

unsigned __int64 Case42::run(BigInt T, bool &found, vector<BigInt> &log){
	BigInt S = T;
	char w[] = { 1, 2, 4, 6, 8, 9, 11, 13, 14 };
	if (T.size() != 42){
		return false;
	}
	//for (unsigned __int64 i = 0; i < 18446744073709551615; i++){
	for (unsigned __int64 i = 0; i < 100; i++){
		char t0 = (T.getBit(3 * w[0]) + T.getBit(3 * w[2]) + (T.getBit(3 * w[2] - 1) & T.getBit(3 * w[2] - 2)) + T.getBit(3 * w[4])) & 1;
		char t1 = (T.getBit(3 * w[3]) + T.getBit(3 * w[5]) + (T.getBit(3 * w[5] - 1) & T.getBit(3 * w[5] - 2)) + T.getBit(3 * w[7])) & 1;
		char t2 = (T.getBit(3 * w[6]) + T.getBit(3 * w[8]) + (T.getBit(3 * w[8] - 1) & T.getBit(3 * w[8] - 2)) + T.getBit(3 * w[1])) & 1;
		T.shift();
		T.setBit(1, t2);
		T.setBit(3 * w[2] + 1, t0);
		T.setBit(3 * w[5] + 1, t1);
		log.push_back(T);
		if (T == S){
			found = true;
			return i;
		}
	}
	found = false;
	return 0;
}


Case42::~Case42()
{
}
