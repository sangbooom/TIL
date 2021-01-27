#include <bits/stdc++.h>
using namespace std;

int main(){
	string n;
	int height = 0;
	cin >> n;
	
	for(int i=n.size()-1; i>=1; i--){
		if(n[i] == n[i-1]){
			height += 5;
		} else {
			height += 10;
		}
	}
	cout << height+10;
	return 0;
}
