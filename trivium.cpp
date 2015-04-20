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
	
	system("pause");
	return 0;
}

int check(){

	fstream file("..\\trivium\\result.txt", ios::in);

	if (!file){
		cout << "File open error!\n";
		return -1;
	}

	vector<pair<string, int>> source = vector<pair<string, int>>();
	string line = "";
	while (std::getline(file, line)){
		string serial = "";
		for (int i = 0; i < 42; i++){
			serial += line[i];
		}
		string _result = line.substr(43);
		int result = atoi(_result.c_str());
		source.push_back(pair<string, int>(serial, result));
	}
	file.close();


	fstream log("..\\trivium\\log.txt", ios::out);
	if (!log){
		cout << "File open error!\n";
		return -1;
	}

	vector<BigInt> record = vector<BigInt>();
	for_each(source.begin(), source.end(), [&](pair<string, int> p){

		bool logged = false;
		for (vector<BigInt>::iterator i = record.begin(); i != record.end(); i++){
			if ((*i).toString() == p.first){
				logged = true;
				break;
			}
		}
		if (!logged){
			bool found = false;

			//vector<unsigned int> test = {0,0};
			//unsigned __int64 cycle = Case42::run(BigInt(test, 42 % 32), found);

			//unsigned __int64 cycle = Case42::run(BigInt(p.first), found);
			unsigned __int64 cycle = Case42::run(BigInt(p.first), found, record);
			if (found) {

				char cycleStr[256];
				sprintf_s(cycleStr, "%I64u", cycle);

				cout << p.first << "\texpect:" << p.second << "\tresult: " << cycleStr << endl;
				log << p.first << "\texpect:" << p.second << "\tresult: " << cycleStr << endl;

			}
			else {
				cout << "not found" << endl;
				//log << "not found" << endl;
			}
		}
		else {
			cout << p.first << "\texpect:" << p.second << "\tresult: " << "logged" << endl;
			//log << p.first << "\texpect:" << p.second << "\tresult: " << "logged" << endl;
		}
	});
	log.close();
	return 0;
}

void generate(){
	fstream log("..\\trivium\\log.txt", ios::out);
	if (!log){
		cout << "File open error!\n";
		return;
	}

	for (int i1 = 0; i1 < 3; i1++)
	{
		for (int i2 = 0; i2 < 3; i2++)
		{
			for (int i3 = 0; i3 < 3; i3++)
			{
				for (int i4 = 0; i4 < 3; i4++)
				{
					for (int i5 = 0; i5 < 3; i5++)
					{
						for (int i6 = 0; i6 < 3; i6++)
						{
							for (int i7 = 0; i7 < 3; i7++)
							{
								for (int i8 = 0; i8 < 3; i8++)
								{
									for (int i9 = 0; i9 < 3; i9++)
									{
										for (int i10 = 0; i10 < 3; i10++)
										{
											for (int i11 = 0; i11 < 3; i11++)
											{
												for (int i12 = 0; i12 < 3; i12++)
												{
													for (int i13 = 0; i13 < 3; i13++)
													{
														for (int i14 = 0; i14 < 3; i14++)
														{
															int p[] = { i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14 };
															vector<unsigned int> _s = { 0, 0 };
															BigInt s = BigInt(_s, 10);
															for (int i = 0; i < 14; i++)
															{
																if (p[i] == 1) {
																	s.setBit(3 * i + 1, 1);
																}
																else if (p[i] == 2) {
																	s.setBit(3 * i + 3, 1);
																}
															}

															bool found = false;
															__int64 length = Case42::run(s, found);

															if (found) {
																cout << s << ":" << length << endl;
																log << s << ":" << length << endl;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	log.close();
}
