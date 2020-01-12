/******************************
Author : 박상범
Language : C++
Problem : https://www.acmicpc.net/problem/5585
******************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int money;
	int n;
	int count = 0;
	int arr[6] = { 500, 100, 50, 10, 5, 1 };
	cin >> money;
	n = 1000 - money;

	for (int i = 0; i < 6; i++) {
		while (1) {
			if (n - arr[i] >= 0) {
				count++;
				n = n - arr[i];
			}
			else {
				break;
			}
		}
	}
	cout << count;

	return 0;
}
