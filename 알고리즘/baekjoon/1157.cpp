#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int count[26] = {0};
	int cnt = 0;
	int max_index = 0;
	int index=0;
	cin >> s;
	for(int i=0; i<s.length(); i++){
		if(s[i] >= 65 && s[i] <= 90){
			s[i] += 32;
		}
		count[s[i] - 97]++;
	}
	for(int i=0; i<26; i++){
		if(max_index < count[i]){
			max_index = count[i];
			index = i;
		}
	}
	for(int i=0; i<26; i++){
		if(max_index == count[i]){
			cnt++;
			if(cnt >=2 ){
				cout << "?";
				return 0;
			}
		}
	}
	
	cout << (char)(index + 65);	
	
	return 0;
}
