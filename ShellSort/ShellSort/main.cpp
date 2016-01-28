#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int> &A){
	for (int gap = A.size() / 2; gap > 0; gap = gap / 2){
		for (int k = gap + 1; k < A.size(); k++){
			for (int j = k - gap; j >= 0; j = j - gap){
				if (A[j + gap]<A[j]){
					swap(A[j + gap], A[j]);
				}else{ 
					break;
				}
			}
		}
	}
}

int main(void){
	vector<int> A = { 6, 5, 4, 3, 2, 1, 0 };
	shellSort(A);
	return 0;
}