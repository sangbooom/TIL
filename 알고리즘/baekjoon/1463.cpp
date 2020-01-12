/******************************
Author : 박상범
Language : C++
Problem : https://www.acmicpc.net/problem/1463
동적프로그래밍 모르겠음 ㄹㅇ어려움 
******************************/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int X;
	int dp[1000001] = { 0, };
	cin >> X;

	dp[1] = 0;
	for (int n = 2; n <= X; n++) {
		dp[n] = dp[n - 1] + 1;
		if (n % 3 == 0){
			dp[n] = min(dp[n], dp[n / 3] + 1);
		}
		else if (n % 2 == 0) {
			dp[n] = min(dp[n], dp[n / 2] + 1);
		}
	}
	cout << dp[X];
	return 0;
}
