#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int w = 1;
	int sum = 0;
	string s;
	
	cin >> n;
	for(int j=0; j<n; j++){
		cin >> s;
		for(int i=0; i<s.length(); i++){
			if(s[i] == 'O'){
				sum += w;
				w++;
			} else {
				w = 1;
			}
		}
		cout << sum << "\n";
		sum = 0;
		w = 1;
	}
	
	return 0;
}
