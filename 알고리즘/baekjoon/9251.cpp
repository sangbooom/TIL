#include <bits/stdc++.h>
using namespace std;

int lcs[1001][1001];
int main(){
	string a;
	string b;
	cin >> a >> b;
//	for(int i=0; i<=a.size(); i++){
//		lcs[i][0] = 0;
//	}
//	for(int i=0; i<=b.size(); i++){
//		lcs[0][i] = 0;
//	}
	for(int i=1; i<=a.size(); i++){
		for(int j=1; j<=b.size(); j++){
			if(a[i-1] == b[j-1]){
				lcs[i][j] += lcs[i-1][j-1] + 1;
			} else {
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}
//	for(int i=1; i<=a.length(); i++){
//		for(int j=1; j<=b.length(); j++){
//			cout << lcs[i][j] << " ";
//		}
//		cout << "\n";
//	}
	cout << lcs[a.size()][b.size()];
	return 0;
}
