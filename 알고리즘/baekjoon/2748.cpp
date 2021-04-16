#include <bits/stdc++.h>
using namespace std;
long long fibo[10001]={0,1,};
int main(){
	int n;
	cin >> n;
	for(int i=2; i<=n; i++){
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
	cout << fibo[n];	
	
	return 0;
}
