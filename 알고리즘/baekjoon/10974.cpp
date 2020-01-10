/******************************
Author : 박상범
Language : C++
Problem : https://www.acmicpc.net/problem/10974
******************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	int N,i;
	cin >> N;
	
	vector<int> v;
	
	for (i = 1; i <= N; i++) {
		v.push_back(i);
	}

	do {
		for (i = 0; i < N; i++) {
			cout << v[i] << ' ';
		}
		cout << "\n";
	} while (next_permutation(v.begin(), v.end())); //next_permutation - 다음 수열

	return 0;
}
