#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>::size_type size_type;

void Swap(vector<int> &arr, int index_1, int index_2)
{
	int tmp = arr[index_1];
	arr[index_1] = arr[index_2];
	arr[index_2] = tmp;
}

int BubbleSort(vector<int> &arr)
{
	size_type length = arr.size();
	if (length < 2)
	{
		return 0;
	}

	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				Swap(arr, j, j+1);
			}
		}
	}
	return 0;
}

int InsertSort(vector<int> &arr)
{
	int length = arr.size();
	if (length < 2)
	{
		return 0;
	}

	int current_val = 0;
	for (int i = 1; i < length; ++i)
	{
		current_val = arr[i];
		int j = i;
		for (; j > 0 && current_val < arr[j - 1]; --j)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = current_val;
	}
}

int SelectSort(vector<int> &arr)
{
	int length = arr.size();
	if (length < 2)
	{
		return 0;
	}

	int current_pos = 0;
	for (int i = 0; i < length - 1; ++i)
	{
		current_pos = i;
		for (int j = i + 1; j < length; ++j)
		{
			if (arr[current_pos] > arr[j])
			{
				current_pos = j;
			}
		}
		if (i != current_pos)
		{
			Swap(arr, i, current_pos);
		}
	}
}

//冒泡+二分+递归
int QuickSort(vector<int> &arr, int left, int right)
{
	if (left >= right)
	{
		return 0;
	}
	
	int key = arr[left];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (j > i && arr[j] >= key)
			--j;
		arr[i] = arr[j];

		while (i < j && arr[i] <= key)
			++i;
		arr[j] = arr[i];
	}
	arr[i] = key;
	QuickSort(arr, left, i);
	QuickSort(arr, i + 1, right);
	return 0;
}

int QuickSort(vector<int> &arr)
{
	int length = arr.size();
	if (length < 2)
	{
		return 0;
	}

	QuickSort(arr, 0, length - 1);
	return 0;
}

/*	希尔排序
**	增量式的插入排序，每趟排序的增量逐渐减小
*/
int ShellSort(vector<int> &arr)
{
	int length = arr.size();
	if (length < 2)
	{
		return 0;
	}

	for (int interval = length / 2; interval >= 1; interval /= 2)
	{
		for (int i = interval; i < length; ++i)
		{
			int current_val = arr[i];
			int j = i;
			for (; j >= interval && arr[j] < arr[j-interval]; j -= interval)
			{
				arr[j] = arr[j - interval];
			}
			if (j != i)
			{
				arr[j] = current_val;
			}
		}
	}
}

/*归并排序*/
int MergeArr(vector<int> &arr, vector<int> &tmparr, int left_beg, int middle, int right_end)
{
	int left_end = middle;
	int right_beg = middle + 1;
	int tmppos = left_beg;
	int copy_len = right_end - left_beg + 1;

	while (left_beg <= left_end && right_beg <= right_end)
	{
		if (arr[left_beg] <= arr[right_beg])
		{
			tmparr[tmppos++] = arr[left_beg++];
		}
		else
		{
			tmparr[tmppos++] = arr[right_beg++];
		}
	}
	while (left_beg <= left_end)
	{
		tmparr[tmppos++] = arr[left_beg++];
	}
	while (right_beg <= right_end)
	{
		tmparr[tmppos++] = arr[right_beg++];
	}
	
	for (int i = 0; i < copy_len; ++i, --right_end)
	{
		arr[right_end] = tmparr[right_end];
	}
	return 0;
}

int MergeSort(vector<int> &arr, vector<int> &tmparr, int left, int right)
{
	if (left >= right)
	{
		return 0;
	}
	int middle = (left + right) / 2;
	MergeSort(arr, tmparr, left, middle);
	MergeSort(arr, tmparr, middle + 1, right);
	MergeArr(arr, tmparr, left, middle, right);
}

int MergeSort(vector<int> &arr)
{
	int length = arr.size();
	if (length < 2)
	{
		return 0;
	}
	vector<int> tmparr(length);
	MergeSort(arr, tmparr, 0, length - 1);
}
/***end 归并***/

/**堆排序**/
/* arr[beg]以这个节点为根的子树，BuildMaxHeap后变成大堆*/
int BuildMaxHeap(vector<int> &arr, int beg, int end)
{
	int child = 2 * beg + 1;
	int tmp;
	for (tmp = arr[beg]; child < end; beg = child)
	{
		child = 2 * beg + 1;
		if (child < end - 1 && arr[child] < arr[child+1])
		{
			++child;
		}
		if (tmp < arr[child])
		{
			arr[beg] = arr[child];
		}
		else
		{
			break;
		}
	}
	arr[beg] = tmp;
	return 0;
}

int HeapSort(vector<int> &arr)
{
	int length = arr.size();
	for (int i = length / 2; i >= 0; --i)
	{
		BuildMaxHeap(arr, i, length);
	}
	
	for (int i = length - 1; i >= 0; --i)
	{
		Swap(arr, 0, i);
		BuildMaxHeap(arr, 0, i);
	}
	return 0;
}
/***end 堆排序***/

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

	//BubbleSort(arr);
	//SelectSort(arr);
	//InsertSort(arr);
	//QuickSort(arr);
	//ShellSort(arr);
	//MergeSort(arr);
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
