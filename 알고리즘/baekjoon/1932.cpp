#include <bits/stdc++.h>
using namespace std;
int dp[501][501];
int main(){
	int n;
	int max_value = -1;
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			cin >> dp[i][j];
		}
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<=i; j++){
			if(j==0){
				dp[i][j] += dp[i-1][j];
			} else if(i==j){
				dp[i][j] += dp[i-1][j-1];
			} else {
				dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
			}
			if(i == n-1){
				max_value = max(max_value,dp[i][j]);
			}
		}
	}
	cout << max_value;
	return 0;
}
