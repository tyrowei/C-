#ifndef LINKED_LIST_H__
#define LINKED_LIST_H__

#include <iostream>
#include <cstddef>	//use std::nullptr_t

/*
** m_head节点需要存储数据
** m_tail节点为最后一个节点的下一个末端节点
*/

template<typename Tp>
class LinkedList
{
	struct Node
	{
		Tp data;
		Node *next;
		Node *prev;

		Node() : data(Tp()), next(NULL), prev(NULL) { }
	};

public:
	LinkedList();
	LinkedList(const LinkedList &rhs);
	~LinkedList();
	LinkedList &operator=(const LinkedList &rhs);

	bool IsEmpty() const;
	void MakeEmpty();
	size_t GetSize() const;

	bool Insert(const Tp &val);
	bool Remove(const Tp &val);

	Node *Begin() const
	{
		return m_head;
	}
	Node *End() const
	{
		return m_tail;
	}

private:
	Node *m_head;
	Node *m_tail;
	size_t m_length;
};

template<typename Tp>
LinkedList<Tp>::LinkedList()
{
	m_head = nullptr;
	m_tail = nullptr;
	m_length = 0;
}

template<typename Tp>
LinkedList<Tp>::LinkedList(const LinkedList &rhs)
{
	*this = rhs;
}

template<typename Tp>
LinkedList<Tp>::~LinkedList()
{
	Clear();
}

template<typename Tp>
LinkedList<Tp>& LinkedList<Tp>::operator=(const LinkedList<Tp> &rhs)
{
	if (this != &rhs)
	{
		Node *rhs_head = rhs.Begin();
		while (rhs_head != rhs.End())
		{
			Insert(*rhs_head->);
		}
	}

	return *this;
}

template<typename Tp>
bool LinkedList<Tp>::IsEmpty()
{
	if (m_head == nullptr)
	{
		return true;
	}

	return false;
}

template<typename Tp>
size_t LinkedList<Tp>::GetSize()
{
	return m_length;
}

#endif /*LINKED_LIST_H__*/