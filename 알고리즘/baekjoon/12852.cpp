#include <bits/stdc++.h>
using namespace std;
int dp[1000001];
int before[1000001];
int main(){
	int x;
	cin >> x;
	for(int i=2; i<=x; i++){
		dp[i] = dp[i-1] + 1;
		before[i] = i-1;
		if(i%3==0 && dp[i] > dp[i/3] + 1){
			dp[i] = min(dp[i], dp[i/3] + 1);
			before[i] = i / 3;
		}
		if(i%2==0 && dp[i] > dp[i/2] + 1){
			dp[i] = min(dp[i], dp[i/2] + 1);
			before[i] = i / 2;
		}
	}
	cout << dp[x] << "\n";
	while (1) {
		cout << x << ' ';
		if(x == 1) break;
		x = before[x];
	}
	
	return 0;
}
