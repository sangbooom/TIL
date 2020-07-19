#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int d[1000];
	
	cin >> n;
	d[1] = 1;
	d[2] = 3;
	for(int i=3; i<=n; i++){
		d[i] = ( d[i-1] + 2 * d[i-2] ) % 10007;
	}
	
	cout << d[n];
	
	return 0;
}
