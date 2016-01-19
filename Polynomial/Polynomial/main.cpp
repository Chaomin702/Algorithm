#include <iostream>
#include "polynomial.h"

int main(void){
	//Poly P;
	//P.addTerm(std::pair<int, int>(1, 1));
	//P.addTerm(std::pair<int, int>(2, 2));
	List<int> L;
	L.insertAsFirst(5);
	L.insertAsLast(4);
	L.insertAsLast(3);
	L.insertAsLast(2);
	L.insertAsLast(1);
	L.mergeSort(L.first(), 5);
	return 0;
}