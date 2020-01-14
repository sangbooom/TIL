/******************************
Author : 박상범
Language : C++
Problem : https://www.acmicpc.net/problem/2845
******************************/

#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m; 
	int asd[11] = { 0, };
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> asd[i];
	}
	for (int i = 0; i < n; i++) {
		cout << asd[i] - (n * m) << " ";
	}

	return 0;
}
