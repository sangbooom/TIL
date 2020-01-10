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

	int N, i, n;
	cin >> N;

	vector<int> v;

	for (i = 1; i <= N; i++) {
		cin >> n;
		v.push_back(n);
	}

	if (next_permutation(v.begin(), v.end()) == true) {
		for (i = 0; i < N; i++) {
			cout << v[i] << ' ';
		}
	}
	else {
		cout << "-1";
	}

	return 0;
}
