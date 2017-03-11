#ifndef BINARYSEARCHTREE_H__
#define BINARYSEARCHTREE_H__

/*
** 二叉查找树
** 若它的左子树不为空，则左子树上所有结点的值都小于根结点的值
** 若它的右子树不为空，则右子树上所有结点的值都大于根结点的值
** 左右子树又分别是二叉查找树
*/

/**
** 二叉查找树的插入
** 类似于查找，只是当到达相应的位置为空时，建立节点
** 如果有重复的，则可在节点中建立一个count来统计或者不处理
**
** 删除
** 如果是叶节点，则直接删除
** 如果该节点还有子节点，则可用右子树中最小值或者左子树中的最大值来代替
**/

class BinarySearchTree
{
private:
	//结点结构
	struct BSNode
	{
		int data;
		BSNode *left;
		BSNode *right;

		BSNode(int val = 0, BSNode *lt = NULL, BSNode *rt = NULL) :
			data(val), left(lt), right(rt) { }
	};

public:
	BinarySearchTree();
	~BinarySearchTree();
	BinarySearchTree(const BinarySearchTree &rhs);	//right hand side
	BinarySearchTree &operator=(const BinarySearchTree &rhs);

	bool IsEmpty() const;
	bool Contains(const int &val) const { return Contains(val, m_root); }
	const int &FindMax() { return FindMax(m_root); }
	const int &FindMin() { return FindMin(m_root); }
	
	void Insert(const int &val) { Insert(m_root, val); }
	void Remove(const int &val) { Remove(m_root, val); }
	
	void PreorderPrintTree() { PreorderPrintTree(m_root); }		//前序遍历 根左右
	void InorderPrintTree() { InorderPrintTree(m_root); }		//中序遍历 左根右
	void PostorderPrintTree() { PostorderPrintTree(m_root); }	//后序遍历 左右根

private:
	//给外部接口调用的内部接口
	void Destroy(BSNode *root);
	bool Contains(const int &val, BSNode *node) const;
	const int &FindMax(BSNode *node) const;
	const int &FindMin(BSNode *node) const;
	void Insert(const int &val, BSNode *node);
	void Remove(const int &val, BSNode *node);

	void PreorderPrintTree(BSNode *node) const;
	void InorderPrintTree(BSNode *node) const;
	void PostorderPrintTree(BSNode *node) const;

private:	
	BSNode *m_root;	//根节点，为NULL表示是空树
};

BinarySearchTree::BinarySearchTree()
{
	m_root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
	Destroy(m_root);
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs)
{

}

BinarySearchTree &BinarySearchTree::operator = (const BinarySearchTree &rhs)
{

}

bool BinarySearchTree::IsEmpty() const
{
	if (NULL == m_root)
	{
		return true;
	}

	return false;
}

bool BinarySearchTree::Contains(const int &val, BSNode *node) const
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

const int &BinarySearchTree::FindMax(BSNode *node) const
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

const int &BinarySearchTree::FindMin(BSNode *node) const
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

void BinarySearchTree::Insert(const int &val, BSNode *node)
{
	if (NULL == node)
	{
		node = new BSNode(val);
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
		//相等，暂不处理
	}
}

void BinarySearchTree::Remove(const int &val, BSNode *node)
{

}

void BinarySearchTree::PreorderPrintTree(BSNode* node)
{
	if (node)
	{
		cout << node->data << " ";
		PreorderPrintTree(node->left);
		PreorderPrintTree(node->right);
	}
}

void BinarySearchTree::InorderPrintTree(BSNode* node)
{
	if (node)
	{
		PreorderPrintTree(node->left);
		cout << node->data << " ";
		PreorderPrintTree(node->right);
	}
}

void BinarySearchTree::PostorderPrintTree(BSNode* node)
{
	if (node)
	{
		PreorderPrintTree(node->left);
		PreorderPrintTree(node->right);
		cout << node->data << " ";
	}
}

void BinarySearchTree::Destroy(BSNode *root)
{
	if (root->left != NULL)
	{
		Destroy(root->left);
	}
	if (root->right != NULL)
	{
		Destroy(root->right);
	}

	delete(root);
	root = NULL;
}

#endif  /*BINARYSEARCHTREE_H__*/