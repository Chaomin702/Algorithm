#include "list.h"
#include <iostream>

class Poly{
public:
	typedef std::pair<int, int> factorAndExp;
	ListNodePosi(factorAndExp) addTerm(factorAndExp e);
	Poly() :polynomial(List<factorAndExp>()){}
	Poly add(const Poly &m, const Poly &n){
		Poly p;
		return p;
	}
private:
	List<factorAndExp> polynomial;

};