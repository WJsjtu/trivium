#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class BigInt
{

private:
	int bitLen;
	unsigned int mask;
	vector<unsigned int> data;
	
public:
	BigInt(vector<unsigned int> data,int maskLen);
	BigInt(string binary);
	string toString();
	char getBit(int pos);
	bool setBit(int pos, char bit);
	BigInt& shift();
	int size();
	bool operator == (const BigInt &);
	~BigInt();


	friend inline ostream &operator << (ostream& os, BigInt& T){
		os << T.toString();
		return os;
	}
};

