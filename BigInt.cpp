#include "stdafx.h"
#include "BigInt.h"
#include <algorithm>

BigInt::BigInt(string binary) : bitLen(binary.size())
{
	int scale = this->bitLen / 32 + (((this->bitLen % 32) != 0) ? 1 : 0);
	this->mask = (this->bitLen % 32) ? (1 << (this->bitLen % 32)) - 1 : ~0;

	for (int i = 0; i != 32 - (this->bitLen % 32); i++){
		binary += "0";
	}

	this->data = vector<unsigned int>();
	for (int i = 0; i != scale; i++){
		unsigned int temp = 0;
		for (int j = 0; j != 32; j++){
			temp <<= 1;
			temp |= (binary[i * 32 + 31 - j] == '1') ? 1 : 0;
		}
		this->data.push_back(temp);
	}

}

BigInt::BigInt(vector<unsigned int> source, int maskLen) : bitLen(32 * source.size() - 32 + maskLen){
	for_each(source.begin(), source.end(), [&, this](unsigned int num){
		this->data.push_back(num);
	});
	this->mask = (1 << maskLen) - 1;
	this->data[this->data.size() - 1] &= this->mask;
}

char BigInt::getBit(int pos){
	if (pos <= 0 || pos > this->bitLen){
		return -1;
	}
	return (char)((this->data[(pos - 1) / 32] >> ((pos - 1) % 32)) & 1);
}
bool BigInt::setBit(int pos, char bit){
	if (pos <= 0 || pos > this->bitLen){
		return false;
	}
	int division = (pos - 1) / 32, remainer = (pos - 1) % 32, _bit = bit;
	this->data[division] &= ~(1 << remainer);
	this->data[division] |= (_bit << remainer);
	return true;
}
BigInt& BigInt::shift(){
	char prev = 0;
	for (vector<unsigned int>::iterator i = this->data.begin(); i != this->data.end(); i++){
		char high = (char)(*i >> 31);
		*i <<= 1;
		*i |= prev;
		prev = high;
	}
	this->data[this->data.size() - 1] &= this->mask;
	return *this;
}

string BigInt::toString(){
	string res = "";
	for_each(this->data.begin(), this->data.end() - 1, [&](unsigned int num){
		for (int i = 0; i < 32; i++){
			res += (num & 1) ? '1' : '0';
			num >>= 1;
		}
	});
	int temp = this->data[this->data.size() - 1];
	for (int i = 0; i < this->bitLen % 32; i++){
		res += (temp & 1) ? '1' : '0';
		temp >>= 1;
	}
	return res;
}

int BigInt::size(){
	return this->bitLen;
}

bool BigInt::operator == (const BigInt & T){
	if (T.bitLen != this->bitLen || T.mask != this->mask){
		return false;
	}
	for (size_t i = 0; i != this->data.size(); i++){
		if (this->data[i] != T.data[i]){
			return false;
		}
	}
	return true;
}

BigInt::~BigInt()
{
}
