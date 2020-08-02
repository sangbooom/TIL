#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while(cin>> s){
		int flag = true;
		if(s == "0"){
			return 0;
		}
		for(int i=0; i<s.length()/2; i++){
			if(s[i] != s[s.length()-1-i]){
				cout << "no" << "\n";
				flag = false;
				break;
			}
		}
		if(flag){
			cout << "yes" << "\n";	
		}
	}
	return 0;
}
