#include <bits/stdc++.h>
using namespace std;
int D[11] = {0,1,2,4,};
int main(){
	int n,temp;
	for(int i=4; i<=10; i++){
		D[i] = D[i-1] + D[i-2] + D[i-3]; 
	}
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> temp;
		cout << D[temp] << "\n";
	}
	return 0;
}
