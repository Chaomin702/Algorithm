#pragma once
#include <iostream>
template <typename T>
void List<T>::init()
{
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer;
	header->pred = NULL;
	trailer->pred = header;
	trailer->succ = NULL;
	_size = 0;
}

template <typename T>
ListNodePosi(T) List<T>::first()const
{ return header->succ; }

template <typename T>
ListNodePosi(T) List<T>::last()const
{ return trailer->pred; }

template <typename T>
ListNodePosi(T) List<T>::operator[](int r)const
{
	ListNodePosi(T) p = first();
	while (0 < r--)
		p = p->succ;
	return p;
}

template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const&e)
{
	_size++; return header->insertAsSucc(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertAsLast(T const&e)
{
	_size++; return trailer->insertAsPred(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertBefore(ListNodePosi(T) p,T const&e)
{
	_size++; return p->insertAsPred(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertAfter(ListNodePosi(T) p, T const&e)
{
	_size++; return p->insertAsSucc(e);
}

template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n)
{
	init();
	for (int i = 0; i < n; i++)
	{
		insertAsLast(p->data);
		p = p->succ;
	}
}

template <typename T>
T List<T>::remove(ListNodePosi(T) p)
{
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
}

template <typename T>
List<T>::~List()
{
	clear();
	delete header;
	delete trailer;
}

template <typename T>
int List<T>::clear()
{
	int oldSize = _size;
	while (0 < _size)
		remove(header->succ);
	return oldSize;
}
template <typename T>
void List<T>::mergeSort(ListNodePosi(T) &p, int n){
	if (n < 2)return;
	int m = n / 2;
	ListNodePosi(T) q = p;;
	for (int i = 0; i<m; i++)
		q = q->succ;
	mergeSort(p, m);
	mergeSort(q, n - m);
	merge(p, m, *this, q, n - m);
}
template <typename T>
void List<T>::merge(ListNodePosi(T) &p, int n, List<T> &L, ListNodePosi(T) &q, int m){
	ListNodePosi(T) pp = p->pred;
	while (m > 0){
		if (n>0 && p->data < q->data){
			p = p->succ;
			n--;
		}else{
			q = q->succ;
			L.insertBefore(p, L.remove(q->pred));
			m--;
		}
	}
	p = pp->succ;
}