#pragma once
#include "ListNode.h"
template <typename T>
class List
{
private:
	int _size;
	ListNodePosi(T) header;
	ListNodePosi(T) trailer;
protected:
	void init();
	int clear();
	void copyNodes(ListNodePosi(T), int);
public:
	List(){ init(); }
	~List();
	
	Rank size()const { return _size; }
	bool empty()const { return _size <= 0; }
	ListNodePosi(T) operator[](int r)const;
	ListNodePosi(T) first()const;
	ListNodePosi(T) last()const;
	bool vaild(ListNodePosi(T) p)
	{
		return p && (trailer != p) && (header != p);
	}
	//ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
	//ListNodePosi(T) selectMax(){ return selectMax(header->succ, _size;); }

	ListNodePosi(T) insertAsFirst(T const&e);
	ListNodePosi(T) insertAsLast(T const&e);
	ListNodePosi(T) insertBefore(ListNodePosi(T) p, T const& e);
	ListNodePosi(T) insertAfter(ListNodePosi(T) p, T const& e);
	T remove(ListNodePosi(T) p);
	void mergeSort(ListNodePosi(T) &p, int n);
	void merge(ListNodePosi(T) &p, int n, List<T> &L, ListNodePosi(T) &q, int m);
};
#include "List_implenmentation.h"