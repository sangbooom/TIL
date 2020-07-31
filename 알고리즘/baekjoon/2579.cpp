#include <bits/stdc++.h>
using namespace std;
int main(){
	int dp[301] ={0};
	int n;
	cin >> n;
	int w[n];
	
	for(int i=0; i<n; i++){
		cin >> w[i+1];
	}
	
	dp[1] = w[1];
	dp[2] = w[1] + w[2];
	dp[3] = max( w[2] + w[3], w[1] + w[3]);
	for(int i=4; i<=n; i++){
		dp[i] = max(dp[i-3] + w[i-1] + w[i], 
		            dp[i-2] + w[i]);	
	}
	cout << dp[n];	
	return 0;
} 
