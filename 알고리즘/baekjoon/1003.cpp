#include <iostream>
using namespace std;
long long fibo[41] = {0,1,};
long long fibonacci(long long t){
	if(t==0 || t==1){
		return fibo[t];
	} else if(fibo[t] == 0) {
		return fibo[t] = fibonacci(t-2) + fibonacci(t-1);
	}
	return fibo[t];
}
int main() {
	int n,k;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> k;
		if(k==0){
			cout << "1 0\n"; 
		} else {
			fibonacci(k);
			cout << fibo[k-1] << " " << fibo[k] << "\n";	
		}
	}
	return 0;
}
