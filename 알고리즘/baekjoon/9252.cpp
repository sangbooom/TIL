#include <bits/stdc++.h>
using namespace std;

int lcs[1001][1001];
string a,b,sum;

int main(){ cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	cin >> a >> b;
	for(int i=1; i<=a.size(); i++){
		for(int j=1; j<=b.size(); j++){
			if(a[i-1] == b[j-1]){
				lcs[i][j] += lcs[i-1][j-1] + 1;
			} else {
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}
	
	cout << lcs[a.size()][b.size()] << "\n";
	
	int n = a.size();
	int m = b.size();
	
	while(lcs[n][m]){
		if(lcs[n-1][m]+1 == lcs[n][m] && lcs[n][m-1]+1 == lcs[n][m]){
			sum += a[n-1];
			n--;
			m--;
		} else if(lcs[n-1][m]+1 == lcs[n][m-1] && lcs[n][m-1] == lcs[n][m]){
			m--;
		} else if(lcs[n-1][m] == lcs[n][m]){
			n--;
		}
	}
	
	reverse(sum.begin(), sum.end());
	cout << sum;
	
	return 0;
}
