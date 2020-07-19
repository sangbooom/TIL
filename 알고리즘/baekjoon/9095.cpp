#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int d[11];
	cin >> n;
	int arr[n];
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		for(int j=4; j<=arr[i]; j++){
			d[j] = d[j-1] + d[j-2] + d[j-3];
		}
		cout << d[arr[i]] << "\n";
	}
	
	return 0;
}
