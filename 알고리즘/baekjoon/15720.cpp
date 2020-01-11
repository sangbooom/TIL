/******************************
Author : 박상범
Language : C++
Problem : https://www.acmicpc.net/problem/15720
******************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> a;
	vector<int> b;
	vector<int> c;

	int n1, n2, n3;
	int sum = 0;
	int sale_sum = 0;

	cin >> n1 >> n2 >> n3;

	for (int i = 0; i < n1; i++) {
		int bugger;
		cin >> bugger;
		a.push_back(bugger);
		sum += bugger;
	}
	sort(a.begin(), a.end(), greater<int>());

	for (int i = 0; i < n2; i++) {
		int side;
		cin >> side;
		b.push_back(side);
		sum += side;
	}
	sort(b.begin(), b.end(), greater<int>());

	for (int i = 0; i < n3; i++) {
		int beverage;
		cin >> beverage;
		c.push_back(beverage);
		sum += beverage;
	}
	sort(c.begin(), c.end(), greater<int>());

	cout << sum<<"\n";

	int abc = min(n1, min(n2, n3));
	
	for (int i = 0; i < abc; i++) {
		sale_sum += a[i] * 0.9;
		sale_sum += b[i] * 0.9;
		sale_sum += c[i] * 0.9;
	}
	for (int i = abc; i < a.size(); i++) {
		sale_sum += a[i];
	}
	for (int i = abc; i < b.size(); i++) {
		sale_sum += b[i];
	}
	for (int i = abc; i < c.size(); i++) {
		sale_sum += c[i];
	}

	cout << sale_sum;


	return 0;
}
