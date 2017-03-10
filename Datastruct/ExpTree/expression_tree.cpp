#include <iostream>
#include <vector>
#include <string>
#include "infix_to_suffix.h"

using namespace std;

struct TreeNode
{
	char value;
	TreeNode *left;
	TreeNode *right;
	TreeNode(char val) : value(val), left(NULL), right(NULL) { }
};

bool CheckIsSymbol(const char ch);
void DeleteStack(vector<TreeNode*> &tree_stack);

TreeNode *BuildExpTree(const string &exp)
{
	int length = exp.size();
	if (length <= 2)
	{
		cout << "exp error~! Length = " << length << endl;
		return NULL;
	}
	vector<TreeNode*> tree_stack;
	bool err_flag = false;
	for (int i = 0; i < length; ++i)
	{
		if (exp[i] == ' ')
		{
			continue;
		}
		TreeNode *new_node = new TreeNode(exp[i]);
		if (!new_node)
		{
			cout << "new TreeNode failed!!!" << endl;
			err_flag = true;
			break;
		}
		if (CheckIsSymbol(exp[i]))
		{
			if (tree_stack.size() < 2)
			{
				cout << "exp error~! Symbol = " << exp[i] << ", i = " << i << endl;
				err_flag = true;
				break;
			}
			
			TreeNode *right_node = tree_stack.back();
			tree_stack.pop_back();
			TreeNode *left_node = tree_stack.back();
			tree_stack.pop_back();
			if (!left_node || !right_node)
			{
				cout << "tree_stack back error~!" << endl;
				err_flag = true;
				break;
			}
			
			new_node->left = left_node;
			new_node->right = right_node;
			
			tree_stack.push_back(new_node);
		}
		else
		{
			tree_stack.push_back(new_node);
		}
	}

	if (err_flag)
	{
		DeleteStack(tree_stack);
		return NULL;
	}
	
	return tree_stack.back();
}

bool CheckIsSymbol(const char ch)
{
	if (ch == '+' ||
		ch == '-' ||
		ch == '*' ||
		ch == '/'  )
	{
		return true;
	}
	
	return false;
}

void DeleteTree(TreeNode *r_node)
{
	if (r_node)
	{
		if (r_node->left == NULL && r_node->right == NULL)
		{
			delete r_node;
		}
		DeleteTree(r_node->left);
		DeleteTree(r_node->right);
	}
}

void DeleteStack(vector<TreeNode*> &tree_stack)
{
	vector<TreeNode*>::iterator itr = tree_stack.begin();
	while (itr != tree_stack.end())
	{
		if (*itr)
		{
			delete *itr;
		}
		++itr;
	}
}

void PrintTree(TreeNode *r_node)
{
	if (r_node)
	{
		if (r_node->left)
		{
			PrintTree(r_node->left);
		}
		cout << r_node->value << " ";
		if (r_node->right)
		{
			PrintTree(r_node->right);
		}
	}
}

int main()
{
	cout << "Input infix expression: ";
	string infix_expr, suffix_expr;
	cin >> infix_expr;

	int ret = InfixToSuffix(infix_expr, suffix_expr);
	if (ret != 0)
	{
		cout << "InfixToSuffix Error!" << endl;
		return -1;
	}
	cout << "Result expression : " << suffix_expr << endl;

	TreeNode *root_node = BuildExpTree(suffix_expr);
	if (!root_node)
	{
		cout << "BuildExpTree failed~!" << endl;
		return -1;
	}
	
	cout << "Tree result : ";
	PrintTree(root_node);
	cout << endl;
	DeleteTree(root_node);
	
	return 0;
}