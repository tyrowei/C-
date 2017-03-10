#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int CheckTextSimilarity(const char* NewText, const char* LastText)
{
	if (NewText == NULL || LastText == NULL)
	{
		cout << "need string!" << endl;
		return -1;
	}
	
	int iLastLength = strlen(LastText);
	int iNewLength = strlen(NewText);

	if (0 == iLastLength || 0 == iNewLength)
	{
		cout << "length error!" << endl;
		return -2;
	}

	vector<vector<int> > len;
	len.resize(iLastLength + 1);
	for (int i = 0; i <= iLastLength; ++i)
	{
		len[i].resize(iNewLength + 1, 0);
	}

	for (int i = 1; i <= iLastLength; ++i)
	{
		for (int j = 1; j <= iNewLength; ++j)
		{
			if (LastText[i-1] == NewText[j-1])
			{
				len[i][j] = len[i-1][j-1] + 1;
			}
			else if (len[i-1][j] > len[i][j-1])
			{
				len[i][j] = len[i-1][j];
			}
			else
			{
				len[i][j] = len[i][j-1];
			}
		}
	}

	int iLcsLength = len[iLastLength][iNewLength];
	int iSimilar = iLcsLength * 100 / iLastLength;
	cout << "LastLength = " << iLastLength << endl;
	cout << "LcsLength  = " << iLcsLength << endl;
	cout << "SimilarVal = " << iSimilar << endl;
	if (iSimilar >= 90)	//相似度超过90%
	{
		cout << "have same string!" << endl;
	}

	for (int i = 0; i <= iLastLength; ++i)
	{
		for (int j = 0; j <= iNewLength; ++j)
		{
			cout << len[i][j] << " "; 
		}
		cout << endl;
	}
	
	return 0;
}

int main()
{
	char A[] = "aabcdababce";	//abcdace
	char B[] = "12abcabcdace";	//bcedkce
	
	CheckTextSimilarity(A, B);
	
	return 0;
}
