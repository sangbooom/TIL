#include <bits/stdc++.h>
using namespace std;

int fact(int num){
	int sum = 1;
	for(int i=num; i>0; i--){
		sum *= i;
	}
	return sum;
}
int main(){
	int n,k;
	cin >> n >> k;
	cout << fact(n) / (fact(k) * fact(n-k));
	return 0;
}
