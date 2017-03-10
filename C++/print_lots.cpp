#include <iostream>
#include <list>

using namespace std;

int PrintLots(const list<int> &L, const list<int> &P)
{
	if (L.size() == 0 || P.size() == 0)
	{
		cout << "List length error~!" << endl;
		return -1;
	}
	list<int>::const_iterator itr_p = P.begin();
	
	while (itr_p != P.end())
	{
		if (*itr_p < 0)
		{
			++itr_p;
			continue;
		}
		list<int>::const_iterator itr_l = L.begin();
		int n = *itr_p;
		while (n > 0 && itr_l != L.end())
		{
			++itr_l;
			--n;
		}
		if (itr_l != L.end())
		{
			cout << "value = " << *itr_l << endl;
		}
		++itr_p;
	}
	
	return 0;
}

int main()
{
	list<int> L;
	list<int> P;
	int num1;
	int num2;
	cout << "input L : ";
	while (cin >> num1 && num1 != 0)
	{
		L.push_back(num1);
	}
	cout << "input P : ";
	while (cin >> num2 && num2 != 0)
	{
		P.push_back(num2);
	}
	PrintLots(L, P);
	return 0;
}
