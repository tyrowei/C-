#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

/*
** 单词转换程序
** 将文件2中的在文件1中出现了的单词，转换为相对应的单词
*/

using namespace std;

int OutputWordTransformResult(ifstream &rule_file, ifstream &trans_file);
int BuildRuleMap(ifstream &rule_file, map<string, string> &rule_map);
string WordTransformResult(const map<string, string> &rule_map, string word);

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Only need to enter two filenames, one for rule, one for transform!" << endl;
		return -1;
	}

	ifstream rule_file;
	ifstream trans_file;
	rule_file.open(argv[1]);
	trans_file.open(argv[2]);

	if (!rule_file || !trans_file)
	{
		cout << "Open file failed!" << endl;
		return -1;
	}

	int ret = OutputWordTransformResult(rule_file, trans_file);
	if (ret != 0)
	{
		cout << "OutputWordTransformResult error occurred! Ret: " << ret << endl;
		return -1;
	}

	return 0;
}

int OutputWordTransformResult(ifstream &rule_file, ifstream &trans_file)
{
	//规则存入map
	map<string, string> rule_map;
	int ret = BuildRuleMap(rule_file, rule_map);

	if (ret != 0)
	{
		cout << "" << endl;
		return -1;
	}

	if (rule_map.size() == 0)
	{
		cout << "Don't have rule!" << endl;
		return -2;
	}

	//开始转换
	string trans_line;
	while (getline(trans_file, trans_line))
	{
		if (trans_line.size() > 0)
		{
			istringstream str_line(trans_line);
			string word;
			while (str_line >> word)
			{
				cout << WordTransformResult(rule_map, word) << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "line size: " << trans_line.size() << endl;
		}
	}

	return 0;
}

int BuildRuleMap(ifstream &rule_file, map<string, string> &rule_map)
{
	string map_key;
	string map_val;

	while (rule_file >> map_key && getline(rule_file, map_val))
	{
		if (map_val.size() < 1)
		{
			cout << "The rule key " << map_key << " don't have value!!!" << endl;
			continue;
		}
		rule_map[map_key] = map_val;
	}

	return 0;
}

string WordTransformResult(const map<string, string> &rule_map, string word)
{
	auto itr = rule_map.find(word);
	if (itr != rule_map.end())
	{
		return itr->second;
	}

	return word;
}