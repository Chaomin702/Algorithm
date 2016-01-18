#include <stdio.h>
#include "list.h"

int main(void){
	List L = EmptyList();
	Insert(1, L, First(L));
	Insert(2, L, First(L));
	Insert(3, L, First(L));
	Insert(4, L, First(L));
	Position V = Find(3, L);
	Delete(3, L);
	V = Find(3, L);
	return 0;
}