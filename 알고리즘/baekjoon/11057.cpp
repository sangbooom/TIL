#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int sum = 0;
	int dp[10000][10];
	cin >> n;
	for(int i=0; i<10; i++){
		dp[1][i] = 1;
	}
	for(int k=2; k<=n; k++){
		for(int i=0; i<10; i++){
			for(int j=i; j<10; j++){
				dp[k][i] += dp[k-1][j];
			}
			dp[k][i] %= 10007;
		}
	}
	for(int i=0; i<10; i++){
		sum += dp[n][i];
	}
	cout << sum % 10007;
	return 0;
}
