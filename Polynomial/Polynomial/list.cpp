#include "list.h"
struct Node{
	ElementType Element;
	Position pre;
	Position next;
};
List EmptyList(){
	Position Header,Trailer;
	Header = (Position)malloc(sizeof(struct Node));
	Trailer = (Position)malloc(sizeof(struct Node));
	if (Header == NULL || Trailer==NULL)
		exit(0);
	Header->pre = NULL;
	Header->next = Trailer;
	Trailer->next = NULL;
	Trailer->pre = Header;
	return Header;
}
List MakeEmpty(List L){
	while (L != NULL){
		L->Element = 0;
		L = L->next;
	}
	return L;
}
int IsEmpty(List L){
	return (L->next == NULL);
}
int IsLast(Position P, List L){
	return (P->next == NULL);
}
Position Find(ElementType X, List L){
	Position P = L->next;
	while (P != NULL && P->Element != X)
		P = P->next;
	return P;
}
void Delete(ElementType X, List L){
	Position P = Find(X, L);
	if (P != NULL){
		P->pre->next = P->next;
		P->next->pre = P->pre;
		free(P);
	}
}void Insert(ElementType X, List L, Position P){
	Position TmpCell;
	TmpCell = (Position)malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		exit(0);
	TmpCell->Element = X;
	P->pre->next = TmpCell;
	TmpCell->pre = P->pre;
	P->pre = TmpCell;
	TmpCell->next = P;
}
void DeleteList(List L){
	Position P, Tmp;
	P = L->next;
	L->next = 0;
	while (P != NULL){
		Tmp = P->next;
		free(P);
		P = Tmp;
	}
}
Position Header(List L){
	return L;
}
Position First(List L){
	return L->next;
}