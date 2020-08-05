#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> n(3);
	while(1){
		cin >> n[0] >> n[1] >> n[2];
		if(n[0]==0 && n[1]==0 && n[2]==0){
			break;
		}
		sort(n.begin(),n.end());
		if( n[0]*n[0] + n[1]*n[1] == n[2]*n[2]){
			cout << "right" << "\n";
		} else {
			cout << "wrong" << "\n";
		}
	}
	return 0;
}
