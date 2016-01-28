#include <iostream>
#include <vector>
#include <list>
using namespace std;
void insertSort1(vector<int> &A){
	if (A.size() < 2)
		return;
	for (int i = 1; i < A.size(); i++){
		for (int j = i - 1; j >= 0; j--){
			if (A[j]>A[j + 1]){
				swap(A[j], A[j + 1]);
			}else{
				break;
			}
		}
	}
}

int main(){
	vector<int> A = { 7, 6, 5, 4, 3, 2, 1 };
	insertSort1(A);
	return 0;
}