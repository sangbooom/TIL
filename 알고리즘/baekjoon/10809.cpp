#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int index[26];

	memset(index,-1,sizeof(int)*26);
	cin >> s;
	
	for(int i=0; i<s.length(); i++){
		if(index[s[i] - 'a'] == -1){
			index[s[i] - 'a'] = i;
		}	
	}
	for(int i=0; i<26; i++){
		cout << index[i] << " ";
	}
	return 0;
}
