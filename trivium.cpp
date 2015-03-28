// trivium.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#define N 42
#define random(x) (rand()%x)
#define binary(x) ((iv[(x-1)/32] >> ((x-1)%32)) & 1)
#define replace(x, y) iv[(x-1)/32] &= ~(1 << ( (x-1)%32 )); iv[(x-1)/32] |= (y << ( (x-1)%32 ))

char w[] = { 1, 2, 4, 6, 8, 9, 11, 13, 14 };

void print(unsigned int *iv){
	char res[43];
	unsigned int s0 = iv[0], s1 = iv[1];
	for (int i = 0; i < 32; i++){
		res[i] = (s0 & 1) ? '1' : '0';
		s0 >>= 1;
	}
	for (int i = 0; i < 10; i++){
		res[32 + i] = (s1 & 1) ? '1' : '0';
		s1 >>= 1;
	}
	res[42] = '\0';
	for (int i = 41; i >= 0; i--){
		printf("%c", res[i]);
	}
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand((int)time(0));
	const int scale = N / 32 + (((N % 32) != 0) ? 1 : 0);
	unsigned int iv[scale], _iv[scale];
	memset(iv, 0, sizeof(unsigned int)* scale);
	for (int i = 0; i < scale; i++){
		int high = random(65536), low = random(65536);
		iv[i] = (high << 16) | low;
	}
	iv[scale - 1] &= (1 << (N % 32)) - 1;
	print(iv);

	memcpy(_iv, iv, sizeof(unsigned int)* scale);
	for (unsigned int i = 0; i < UINT_MAX; i++){
		char t0 = (binary(3 * w[0]) + binary(3 * w[2] - 1) & binary(3 * w[2] - 2) + binary(3 * w[4])) & 1,
			t1 = (binary(3 * w[3]) + binary(3 * w[5] - 1) & binary(3 * w[5] - 2) + binary(3 * w[7])) & 1,
			t2 = (binary(3 * w[6]) + binary(3 * w[8] - 1) & binary(3 * w[8] - 2) + binary(3 * w[1])) & 1;
		for (int j = scale - 1; j > 0; j--){
			iv[j] <<= 1;
			iv[j] |= (iv[j - 1] >> 31);
		}
		iv[0] <<= 1;
		iv[0] |= t2;
		replace(3 * w[2] + 1, t0);
		replace(3 * w[5] + 1, t1);

		iv[scale - 1] &= (1 << (N % 32)) - 1;
		print(iv);
		/*
		print(iv);
		print(_iv);
		printf("iv[1]:%u, iv[0]:%u, _iv[1]:%u, _iv[0]:%u, memcmp(_iv, iv, 42):%d\n", iv[1], iv[0], _iv[1], _iv[0], memcmp(_iv, iv, 42));
		if ((iv[0] == _iv[0]) && (iv[1] == _iv[1])){
		printf("iv = _iv\n");
		}
		system("pause");
		*/
		int k = 0;
		for (; k < scale; k++){
			if (iv[k] != _iv[k]){
				break;
			}
		}
		if (k == scale){
			printf("%d\n", i);
			system("pause");
			return 0;
		}
	}
	printf("Not found\n");
	system("pause");
	return 0;
}