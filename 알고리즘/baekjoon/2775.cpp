#include <bits/stdc++.h>
using namespace std;
int main(){
	int T,k,n; //kÃþ nÈ£ 
	int d[15][15];
	
	cin >> T;
	for(int p=0; p<T; p++){
		cin >> k >> n;
		for(int i=0; i<=k; i++){
			d[i][0] = 1;
		}
		for(int j=1; j<n; j++){
			d[0][j] = j+1;
		}
		for(int i=1; i<=k; i++){
			for(int j=1; j<n; j++){
				d[i][j] = d[i-1][j] + d[i][j-1];
			}
		}
		cout << d[k][n-1] << "\n";
	}
	
	return 0;
}
