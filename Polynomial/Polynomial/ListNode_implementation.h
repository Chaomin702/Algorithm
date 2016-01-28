#pragma once
#include "ListNode.h"
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const&e)
{
	ListNodePosi(T) x = new ListNode<T>(e, pred, this);
	pred->succ = x;
	pred = x;
	return x;
}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const&e)
{
	ListNodePosi(T) x = new ListNode<T>(e, this, succ);
	succ->pred = x;
	succ = x;
	return x;
}