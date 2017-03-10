#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "MyLog.h"

using namespace std;

int AnlysisFile(ifstream &in_file, const string &keyword);

//文件分析，提取出需要的日志信息
int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		cout << "Need filename and keyword!!!" << endl;
		return 0;
	}
	
	ifstream in_file;
	in_file.open(argv[1]);
	string keyword(argv[2]);
	
	cout << "Begin anlysis file , result will put in result.txt ~!" << endl;
	
	if (in_file)
	{
		AnlysisFile(in_file, keyword);
	}
	
	return 0;
}

int AnlysisFile(ifstream &in_file, const string &keyword)
{
	ofstream out_file;
	out_file.open("result.txt", ios::out);
	string line_str;
	size_t find_pos = 0;
	while (getline(in_file, line_str))
	{
		find_pos = line_str.find(keyword);
		if (find_pos != string::npos)
		{
			out_file << line_str << "\n";
		}
	}
	cout << "Done~!" << endl;
	LOG_INFO("Done~! last find position %d", find_pos);
	return 0;
}
