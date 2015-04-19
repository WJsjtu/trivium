// trivium.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "Case42.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	fstream file("..\\trivium\\result.txt", ios::in);
	if (!file){
		cout << "File open error!\n";
		return - 1;
	}
	string line = "";
	while (std::getline(file, line)){
		if (line.size() < 41 * 2 + 2){
			continue;
		}
		string serial = "";
		for (int i = 0; i < 42; i++){
			serial += line[i * 2];
		}
		string _result = line.substr(41 * 2 + 2);
		int result = atoi(_result.c_str());

		bool found = false;
		//vector<unsigned int> test = {0,0};
		//unsigned __int64 cycle = Case42::run(BigInt(test, 42 % 32), found);
		unsigned __int64 cycle = Case42::run(BigInt(serial), found);
		if (found) {
			cout << serial << " expect:" << result << ",\tresult: ";
			printf("%I64u\n", cycle);
		}
		else {
			cout << "not found" << endl;
		}
	}

	system("pause");
	return 0;
}