#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,s_reverse;
	cin >> s;
	
	for(int i=s.size()-1; i>=0; i--){
		s_reverse += s[i];
	}

	for(int i=0; i<s.size(); i++){
		if(s[i] != s_reverse[i]){
			cout << s.size();
			return 0;
		}
	}
	for(int i=0; i<s.size()-1; i++){
		if(s[i] != s[i+1]){
			cout << s.size() -1;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}
