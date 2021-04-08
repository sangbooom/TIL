#include <bits/stdc++.h>
using namespace std;
int A[100001];
int sum[100001];
int main(){ cin.tie(0); ios::sync_with_stdio(0);
	int N,M,i,j;
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> A[i];
		sum[i] = sum[i-1] + A[i];
	}
	cin >> M;
	for(int index=1; index<=M; index++){
		cin >> i >> j;
		cout << sum[j] - sum[i-1] << "\n";
	}
	
	return 0;
}
