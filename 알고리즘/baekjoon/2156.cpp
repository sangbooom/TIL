#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int w[10001]={0};
	int d[10001]={0};
	int sum = 0;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> w[i];
	}
	d[0] = w[0] = 0;
	d[1] = w[1];
	d[2] = w[1] + w[2];
	
	for(int i=3; i<=n; i++){
		d[i] = max(d[i-1], max(w[i] + d[i-2], w[i]+w[i-1]+d[i-3]));
	}
	
	cout << d[n];
	
	return 0;
}
