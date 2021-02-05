#include <bits/stdc++.h>
using namespace std;

// 시간초과 

//int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n;
//	int dp[501];
//	cin >> n;
//	for(int i=1; i<=n; i++){
//		dp[i] = i;
//	}
//	for(int i=n; i>0; i--){
//		dp[i-1] *= dp[i];
//	}
//	int count = 0;
//	while(dp[1] % 10 == 0){
//		if(dp[1] % 10 == 0){
//			dp[1] /= 10;
//			count++;
//		}
//	}
//	cout << count;
//	return 0;
//} 

int N, res;
void fact(){
	res = 0;
	for (int i = 2; i <= N; i++) {
		int tmp = i;
		while (tmp % 5 ==0) {
			res++;	
			tmp /= 5;
		}
	}
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	cin >> N;
	fact();
	cout << res;
}
