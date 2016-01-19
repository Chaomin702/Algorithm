#include "list.h"
#include <iostream>

class Poly{
public:
	typedef std::pair<int, int> factorAndExp;
	ListNodePosi(factorAndExp) addTerm(factorAndExp e);
	Poly() :polynomial(List<factorAndExp>()){}
private:
	List<factorAndExp> polynomial;
};