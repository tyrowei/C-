#ifndef BINARYSEARCHTREE_H__
#define BINARYSEARCHTREE_H__

/**
** 二叉查找树的插入
** 类似于查找，只是当到达相应的位置为空时，建立节点
** 如果有重复的，则可在节点中建立一个count来统计
**
** 删除
** 如果是叶节点，则直接删除
** 如果该节点还有子节点，则可用右子树中最小值来代替
**/

class BinarySearchTree
{
private:
	struct BSNode
	{
		int data;
		BSNode *left;
		BSNode *right;
		
		BSNode(int val, BSNode *lt, BSNode *rt) : data(val), left(lt), right(rt) { }
	};
	
public:
	BinarySearchTree();
	~BinarySearchTree();
	BinarySearchTree(const BinarySearchTree &rhs);	//right hand side
	BinarySearchTree &operator=(const BinarySearchTree &rhs);
	
	bool IsEmpty() const;
	bool Contains(const int &val) const;
	const int &FindMax() const;
	const int &FindMin() const;
	
	void Insert(const int &val);
	void Remove(const int &val);
	
	void PreorderPrintTree() const;
	void InorderPrintTree() const;
	void PostorderPrintTree() const;

private:
	Delete(BSNode *root);
	bool Contains(const int &val, BSNode *node) const;
	const int &FindMax(BSNode *node) const;
	const int &FindMin(BSNode *node) const;
	void Insert(const int &val, BSNode *node);
	void Remove(const int &val, BSNode *node);

private:	
	BSNode *m_root;	//根节点，为NULL表示是空树
};

BinarySearchTree::BinarySearchTree()
{
	m_root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
	Delete(m_root);
}

bool BinarySearchTree::IsEmpty()
{
	if (NULL == m_root)
	{
		return true;
	}

	return false;
}

bool BinarySearchTree::Contains(const int &val)
{
	return Contains(val, m_root);
}

bool BinarySearchTree::Contains(const int &val, BSNode *node)
{
	if (NULL == node)
	{
		return false;
	}
	else if (val > node->data)
	{
		return Contains(val, node->right);
	}
	else if (val < node->data)
	{
		return Contains(val, node->left);
	}
	else
	{
		return true;
	}
}

const int &BinarySearchTree::FindMax()
{
	return FindMax(m_root);
}

const int &BinarySearchTree::FindMin()
{
	return FindMin(m_root);
}

const int &BinarySearchTree::FindMax(BSNode *node)
{
	if (NULL == node)
	{
		return 0;
	}
	while (node->right != NULL)
	{
		node = node->right;
	}
	return node->data;
}

const int &BinarySearchTree::FindMin(BSNode *node)
{
	if (NULL == node)
	{
		return 0;
	}
	while (node->left != NULL)
	{
		node = node->left;
	}
	return node->data;
}

void BinarySearchTree::Insert(const int &val)
{
	Insert(m_root, val);
}

void BinarySearchTree::Remove(const int &val)
{
	Remove(m_root, val);
}

void BinarySearchTree::Insert(const int &val, BSNode *node)
{
	if (NULL == node)
	{
		node = new BSNode(val, NULL, NULL);
	}
	else if (val < node->data)
	{
		Insert(val, node->left);
	}
	else if (val > node->data)
	{
		Insert(val, node->right);
	}
	else
	{
		//相等
	}
}

#endif  /*BINARYSEARCHTREE_H__*/