#include <iostream>
using namespace std;

int main(){
	long long t[36] = {1, };
	int n;
	cin >> n;
	
	for(int i=0; i<=n; i++){	
		for(int j=0; j<i; j++){
			t[i] += t[j] * t[i-1-j];
		}	
	}
	
	cout << t[n];
	return 0;
}
