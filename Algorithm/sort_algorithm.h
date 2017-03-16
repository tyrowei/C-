#ifndef SORT_ALGORITHM_H__
#define SORT_ALGORITHM_H__

#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;

template<typename _Tp>
static void Swap(vector<_Tp> &arr, size_t index_1, size_t index_2)
{
	_Tp tmp = arr[index_1];
	arr[index_1] = arr[index_2];
	arr[index_2] = tmp;
}

/*
** 冒泡排序
*/
template<typename _Tp>
static int BubbleSort(vector<_Tp> &arr)
{
	size_t length = arr.size();
	if (length < 2)	//容器内元素个数少于2个时，不用排序
	{
		return 0;
	}

	for (size_t i = 0; i < length - 1; ++i)
	{
		for (size_t j = 0; j < length - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr, j, j + 1);
			}
		}
	}
	return 0;
}

/*
** 插入排序
*/
template<typename _Tp>
static int InsertSort(vector<_Tp> &arr)
{
	size_t length = arr.size();
	if (length < 2)
	{
		return 0;
	}

	_Tp current_val = _Tp();
	for (size_t i = 1; i < length; ++i)
	{
		current_val = arr[i];
		size_t j = i;
		for (; j > 0 && current_val < arr[j - 1]; --j)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = current_val;
	}
}

/*
** 选择排序
*/
template<typename _Tp>
static int SelectSort(vector<_Tp> &arr)
{
	size_t length = arr.size();
	if (length < 2)
	{
		return 0;
	}

	size_t current_pos = 0;
	for (size_t i = 0; i < length - 1; ++i)
	{
		current_pos = i;
		for (size_t j = i + 1; j < length; ++j)
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

/*
** 快速排序
** 思想：冒泡+二分+递归
*/
template<typename _Tp>
static int QuickSort(vector<_Tp> &arr, size_t left, size_t right)
{
	if (left >= right)
	{
		return 0;
	}

	_Tp key = arr[left];
	size_t i = left;
	size_t j = right;
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

template<typename _Tp>
static int QuickSort(vector<_Tp> &arr)
{
	size_t length = arr.size();
	if (length < 2)
	{
		return 0;
	}

	QuickSort(arr, 0, length - 1);
	return 0;
}

/*
** 希尔排序
** 增量式的插入排序，每趟排序的增量逐渐减小
*/
template<typename _Tp>
static int ShellSort(vector<_Tp> &arr)
{
	size_t length = arr.size();
	if (length < 2)
	{
		return 0;
	}

	for (size_t interval = length / 2; interval >= 1; interval /= 2)
	{
		for (size_t i = interval; i < length; ++i)
		{
			_Tp current_val = arr[i];
			size_t j = i;
			for (; j >= interval && arr[j] < arr[j - interval]; j -= interval)
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

/*
** 归并排序
*/
template<typename _Tp>
static int MergeArr(vector<_Tp> &arr, vector<_Tp> &tmparr, size_t left_beg, size_t middle, size_t right_end)
{
	size_t left_end = middle;
	size_t right_beg = middle + 1;
	size_t tmppos = left_beg;
	size_t copy_len = right_end - left_beg + 1;

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

	for (size_t i = 0; i < copy_len; ++i, --right_end)
	{
		arr[right_end] = tmparr[right_end];
	}
	return 0;
}

template<typename _Tp>
static int MergeSort(vector<_Tp> &arr, vector<_Tp> &tmparr, size_t left, size_t right)
{
	if (left >= right)
	{
		return 0;
	}
	size_t middle = (left + right) / 2;
	MergeSort(arr, tmparr, left, middle);
	MergeSort(arr, tmparr, middle + 1, right);
	MergeArr(arr, tmparr, left, middle, right);
}

template<typename _Tp>
static int MergeSort(vector<_Tp> &arr)
{
	size_t length = arr.size();
	if (length < 2)
	{
		return 0;
	}
	vector<_Tp> tmparr(length);
	MergeSort(arr, tmparr, 0, length - 1);
}

/*
** 堆排序
** arr[beg]以这个节点为根的子树，BuildMaxHeap后变成大堆
*/
template<typename _Tp>
static int BuildMaxHeap(vector<_Tp> &arr, long beg, long end)
{
	long child = 2 * beg + 1;
	_Tp tmp;
	for (tmp = arr[beg]; child < end; beg = child)
	{
		child = 2 * beg + 1;
		if (child < end - 1 && arr[child] < arr[child + 1])
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

template<typename _Tp>
static int HeapSort(vector<_Tp> &arr)
{
	size_t length = arr.size();
	for (long i = length / 2; i >= 0; --i)
	{
		BuildMaxHeap(arr, i, length);
	}

	for (long i = length - 1; i >= 0; --i)
	{
		Swap(arr, 0, i);
		BuildMaxHeap(arr, 0, i);
	}
	return 0;
}

#endif /*SORT_ALGORITHM_H__*/