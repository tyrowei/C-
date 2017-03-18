#include "sort_algorithm.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#define MAX_RAND_CNT	50000	//随机数个数

int main()
{
	fstream rand_file;	//随机数放入文件
	rand_file.open("rand_file.txt", ios_base::in | ios_base::out);

	int number = 0;
	srand((unsigned)time(NULL));	//srand()用来设置rand()产生随机数时的随机数种子
	if (rand_file)
	{
		for (int i = 0; i < MAX_RAND_CNT; i++)
		{
			number = rand() % MAX_RAND_CNT;
			rand_file << number << " ";
			if ((i + 1) % 10 == 0)
			{
				rand_file << "\n";
			}
		}
	}

	rand_file.seekg(0, fstream::beg);	//重定位标记到文件头

	vector<int> int_arr;
	string word;
	while (rand_file >> word)
	{
		int_arr.push_back(atoi(word.c_str()));
	}
	rand_file.close();

	if (int_arr.empty())
	{
		cout << "null file!" << endl;
		return 0;
	}

	BubbleSort(int_arr);

	SelectSort(int_arr);
	
	InsertSort(int_arr);
	
	QuickSort(int_arr);
	
	ShellSort(int_arr);
	
	MergeSort(int_arr);
	
	HeapSort(int_arr);


	ofstream result_file;
	result_file.open("result.txt", ios_base::out);
	if (result_file)
	{
		vector<int>::iterator itr = int_arr.begin();
		int i = 0;
		while (itr != int_arr.end())
		{
			i++;
			result_file << *itr++ << " ";
			if (i % 10 == 0)
			{
				result_file << "\n";
			}
		}
	}
	result_file.close();
	cout << "End Sort~!" << endl;
	return 0;
}
