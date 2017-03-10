#ifndef INFIXTOSUFFIX_H_
#define INFIXTOSUFFIX_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef vector<int>::size_type size_type;

bool SymbolPriority(const char c1, const char c2);

//中缀表达式转换为后缀表达式
int InfixToSuffix(const string &infix_expr, string &suffix_expr)
{
	size_type infix_len = infix_expr.size();
	if (infix_len < 3)
	{
		cout << "Expression length=" << infix_len << ", invalid!!!" << endl;
		return -1;
	}
	
	vector<char> suffix_vec;	//存储结果
	vector<char> symbol_stack;	//转换过程中存储符号的栈

	//忽略表达式前面的空格
	int i = 0;
	while (infix_expr[i] == ' ' || infix_expr[i] == '\t')
	{
		++i;
	}

	for (; i < infix_len; ++i)
	{
		if (infix_expr[i] == '(')
		{
			symbol_stack.push_back(infix_expr[i]);
			suffix_expr.push_back(' ');	//每次遇到一个符号就增加一个空格
		}
		else if (infix_expr[i] == '+' ||
				 infix_expr[i] == '-' ||
				 infix_expr[i] == '*' ||
				 infix_expr[i] == '/'  )
		{
			if (symbol_stack.empty())
			{
				symbol_stack.push_back(infix_expr[i]);
			}
			else
			{
				while (!symbol_stack.empty() && symbol_stack.back() != '(' && SymbolPriority(infix_expr[i], symbol_stack.back()))
				{
					suffix_expr.push_back(symbol_stack.back());
					symbol_stack.pop_back();
				}
				symbol_stack.push_back(infix_expr[i]);
			}

			suffix_expr.push_back(' ');
		}
		else if (infix_expr[i] == ')')
		{
			while (symbol_stack.back() != '(')
			{
				suffix_expr.push_back(symbol_stack.back());
				symbol_stack.pop_back();
			}
			symbol_stack.pop_back();	//删除stack中的'('

			suffix_expr.push_back(' ');
		}
		else if (infix_expr[i] >= '0' && infix_expr[i] <= '9' || infix_expr[i] == '.')
		{
			suffix_expr.push_back(infix_expr[i]);
		}
		else
		{
			cout << "Error symbol~!!!" << endl;
		}
	}

	while (!symbol_stack.empty())
	{
		suffix_expr.push_back(symbol_stack.back());
		symbol_stack.pop_back();
	}

	vector<char>::iterator itr = suffix_vec.begin();
	while (itr != suffix_vec.end())
	{
		suffix_expr += *itr;
		++itr;
	}

	return 0;
}

//')'	  用1表示
//'+' '-' 用2表示
//'*' '/' 用3表示
//'('     用4表示 
int SymbolTransfeNum(const char c)
{
	if (c == ')')
	{
		return 1;
	}
	if (c == '+' || c == '-')
	{
		return 2;
	}
	else if (c == '*' || c == '/')
	{
		return 3;
	}
	else if (c == '(')
	{
		return 4;
	}

	return 0;
}


//当c1优先级 <= c2时，返回true
bool SymbolPriority(const char c1, const char c2)
{
	int c1_val = SymbolTransfeNum(c1);
	int c2_val = SymbolTransfeNum(c2);
	if (c1_val == 0 || c2_val == 0)
	{
		cout << "SymbolPriority parameter Error~!" << endl;
		cout << "c1 = " << c1 << ", c2 = " << c2 << endl;
		return false;
	}

	if (c1_val <= c2_val)
	{
		return true;
	}

	return false;
}

#endif /*INFIXTOSUFFIX_H_*/