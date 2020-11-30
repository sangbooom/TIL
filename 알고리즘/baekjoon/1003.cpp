#include <bits/stdc++.h>
using namespace std;

long long fibo[41] = {0,1,};
long long fibonacci(long long t){
	if(t == 0 || t == 1) {
		return fibo[t];	
	} else if(fibo[t] == 0) {
		fibo[t] = fibonacci(t-1)+ fibonacci(t-2);
	}
	return fibo[t];
}

int main(){
	int n,k;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> k;
		if(k==0){
			cout << "1 0\n";
		} else {
			fibonacci(k);
			cout << fibonacci(k-1) << " " << fibonacci(k) << "\n";
		}
	}
	return 0;
}
