#include "sort_algorithm.h"

int main()
{
	cout << "Input some numbers: ";
	vector<int> arr;
	int num;
	while (cin >> num)
	{
		arr.push_back(num);
	}
	cout << endl;

	BubbleSort(arr);
	SelectSort(arr);
	InsertSort(arr);
	QuickSort(arr);
	ShellSort(arr);
	MergeSort(arr);
	HeapSort(arr);

	cout << "Result numbers: ";
	vector<int>::iterator itr = arr.begin();
	while (itr != arr.end())
	{
		cout << *itr++ << " ";
	}
	cout << endl;
	return 0;
}
