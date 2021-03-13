#include <bits/stdc++.h>
using namespace std;
int w[100001];
int main(){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	int max_w = 0;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> w[i];
	}
	sort(w,w+N);
	for(int i=1; i<=N; i++){
		max_w = max(max_w, w[N-i]*i);
	}
	cout << max_w;
	
	return 0;
}
