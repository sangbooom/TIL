#include <bits/stdc++.h>
using namespace std;

int main(){
	int T,n;
	int d[2][100001];
	int a[2][100001];
	cin >> T;
	
	for(int i=0; i<T; i++){
		cin >> n;
		for(int j=0; j<2; j++){
			for(int k=0; k<n; k++){
				cin >> d[j][k];
			}
		}
		a[0][0] = a[1][0] = 0;
		a[0][1] = d[0][0]; 
		a[1][1] = d[1][0];
		
		for(int i=2; i<=n; i++){
			a[0][i] = max(a[1][i-2],a[1][i-1]) + d[0][i-1];
			a[1][i] = max(a[0][i-2],a[0][i-1]) + d[1][i-1];
		}
		cout << max(a[0][n],a[1][n]) << "\n";
	}
	return 0;
}

//		for(int i=0; i<2; i++){
//			for(int j=0; j<n; j++){
//				cout << d[i][j] <<" ";		
//			}
//			cout<< "\n";
//		}

