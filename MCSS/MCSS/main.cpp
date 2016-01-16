#include <iostream>
#include <algorithm>
using namespace std;
int MaxSubsequenceSumForce(const int A[], int N){
	int maxSum = 0, thisSum = 0;
	for (int i = 0; i < N; i++){
		thisSum = 0;
		for (int j = i; j < N; j++){
			thisSum += A[j];
			if (thisSum >maxSum)
				maxSum = thisSum;
		}
	}
	return maxSum;
}
int MaxSubsequenceSumDP1(const int A[], int N){
	int f = 0, maxSum = 0;
	for (int i = 0; i < N; i++){
		f += A[i];
		if (f < 0)
			f = 0;
		if (maxSum < f)
			maxSum = f;
	}
	return maxSum;
}

int MaxSubSumDC(const int A[], int l, int h){
	if (h - l < 1){
		if (A[l]< 0)
			return 0;
		else
			return A[l];
	}
	int centre = (l + h) / 2;
	int leftMax = MaxSubSumDC(A, l, centre);
	int rightMax = MaxSubSumDC(A, centre + 1, h);
	int centreLeftMax = 0, centreLeftSum = 0;
	for (int i = centre; i>=l; i--){
		centreLeftSum += A[i];
		if (centreLeftSum > centreLeftMax){
			centreLeftMax = centreLeftSum;
		}
	}
	int centreRightMax = 0, centreRightSum = 0;
	for (int i = centre + 1; i <= h; i++){
		centreRightSum += A[i];
		if (centreRightSum > centreRightMax)
			centreRightMax = centreRightSum;
	}
	int centreMax = centreLeftMax + centreRightMax;
	return max(max(leftMax, rightMax), centreMax);
}
int MaxSubsequenceSumDC(const int A[], int N){
	return MaxSubSumDC(A, 0, N - 1);
}
int main(void){
	const int A[] = { -2, 11, -4, 13, -5, -2 };
	cout << MaxSubsequenceSumForce(A, 6) << endl;
	cout << MaxSubsequenceSumDP1(A, 6) << endl;
	cout << MaxSubsequenceSumDC(A, 6) << endl;
	return 0;
}

