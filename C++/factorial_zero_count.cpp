#include <iostream>
#include <string>

using namespace std;

/*
**	N! N的阶乘末尾0的个数
**	N! = K * 10的M次方，则末尾有M个0
**	对N!进行质因数分解：N!=2的x次方*3的y次方*5的z次方...
**	因为10=2*5，所以M与x和z有关，M=min(x,z)，
**	因为能被2整除的数出现的频率要比能被5整除的数出现的频率高，所以M=z
**
*/

int CalculateZeroCount(int number)
{
	int zero_cnt = 0;
	
	for (int i = 1; i <= number; ++i)
	{
		int j = i;
		while (0 == j % 5)
		{
			++zero_cnt;
			j /= 5;
		}
	}
	
	return zero_cnt;
}

int main()
{
	int val;
	string str;
	cout << "Begin :" << endl;
	while (cin >> val)
	{
		cout << "Value[" << val << "] has zero numbers :";  
		cout << CalculateZeroCount(val) << endl;
		cout << "continues yes/no?" << endl;
		cin >> str;
		if ("no" == str)
		{
			break;
		}
		cout << "Input a number : ";
	}
	cout << "End!" << endl;
	return 0;
}