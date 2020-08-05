#include <bits/stdc++.h>
using namespace std;

int isSqr[1000001];

int main() {
	long long _min, _max;
	cin >> _min >> _max;

	for (long long i = 2; i * i <= _max; i++){
		long long start = _min / (i * i);
		if (start * i * i != _min) start++;
		for (long long j = start; i * i * j <= _max; j++) {
			isSqr[i * i * j - _min] = 1;
		}
	}
	int count = 0;
	for (int i = 0; i < _max - _min + 1; i++) {
		if (!isSqr[i]) count++;
	}
	cout << count;

	return 0;
}
