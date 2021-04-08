#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int sum[100001];
int main(){ cin.tie(0); ios::sync_with_stdio(0);
	int N,M,a,b;
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		cin >> arr[i];
		sum[i] = sum[i-1] + arr[i];
	}
	for(int i=1; i<=M; i++){
		cin >> a >> b;
		cout << sum[b] - sum[a-1] << "\n"; 	
	}
	return 0;
}
