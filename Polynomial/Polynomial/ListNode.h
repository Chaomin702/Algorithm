#pragma once
typedef int Rank;
#define ListNodePosi(T) ListNode<T>*
//ListNode节点类，引自邓俊辉老师《数据结构 C++》
template <typename T>
class ListNode
{
public:
	T data;
	ListNodePosi(T) pred;
	ListNodePosi(T) succ;

	ListNode(){}
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
		:data(e), pred(p), succ(s){}

	ListNodePosi(T)	insertAsPred(T const&e);
	ListNodePosi(T) insertAsSucc(T const&e);
};
#include "ListNode_implementation.h"