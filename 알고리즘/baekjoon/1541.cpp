#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	string cpy;
	int flag = 0;
	int sum = 0;
	
	cin >> s;
	
	for(int i=0; i<=s.length(); i++){
		if(s[i]>=48 && s[i]<=57){
			cpy += s[i];
			continue;
		} else {
			if(flag){
				sum -= stoi(cpy);	
			} else {
				sum += stoi(cpy);
			}
		}
		if(s[i] == '-' || flag){
			if(!flag){
				flag++;
			}
		}
		cpy = "";
	}
	cout << sum;
	return 0;
}
