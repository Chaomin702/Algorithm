#include <iostream>
#include <vector>

using namespace std;
bool isMainElement(vector<int> &v){
	int count = 1;
	int s = v.back();
	for (int i = 0; i < v.size() - 1; i++){
		if (v[i] == s)
			count++;
	}
	if (count>v.size() / 2)
		return true;
	else
		return false;
}
int findMainElement(vector<int> &v){
	if (v.empty()) return -1;
	if (v.size() == 1) return v[0];
	vector<int> u;
	for (int i = 0; i + 1 < v.size(); i = i + 2){
		if (v[i] == v[i + 1])
			u.push_back(v[i]);
	}
	int res = findMainElement(u);
	if (v.size() % 2 == 0)
		return res;
	else{
		if (res == -1){
			if (isMainElement(v))
				return v.back();
			else
				return -1;
		}
		else
			return res;
	}
}

int main(void){
	vector<int> v = { 3, 3, 4, 2, 4, 4, 2, 4, 4 };
	vector<int> u = { 3, 3, 4, 2, 4, 4, 2, 4 };
	vector<int> w = { 1, 1, 1, 1, 1 };
	cout << findMainElement(v) << endl;
	cout << findMainElement(u) << endl;
	cout << findMainElement(w) << endl;
	return 0;
}