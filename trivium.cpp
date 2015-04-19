// trivium.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include "Case42.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	fstream file("..\\trivium\\result.txt", ios::in);

	if (!file){
		cout << "File open error!\n";
		return - 1;
	}

	vector<pair<string, int>> source = vector<pair<string, int>>();
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
		source.push_back(pair<string, int>(serial, result));
	}
	file.close();


	fstream log("..\\trivium\\log.txt", ios::out);
	if (!log){
		cout << "File open error!\n";
		return -1;
	}

	for_each(source.begin(), source.end(), [&](pair<string, int> p){
		bool found = false;

		//vector<unsigned int> test = {0,0};
		//unsigned __int64 cycle = Case42::run(BigInt(test, 42 % 32), found);

		unsigned __int64 cycle = Case42::run(BigInt(p.first), found);
		if (found) {

			char cycleStr[256];
			sprintf_s(cycleStr, "%I64u", cycle);

			cout << p.first << "\texpect:" << p.second << "\tresult: " << cycleStr << endl;
			log << p.first << "\texpect:" << p.second << "\tresult: " << cycleStr << endl;

		}
		else {
			cout << "not found" << endl;
			log << "not found" << endl;
		}
	});
	log.close();

	system("pause");
	return 0;
}