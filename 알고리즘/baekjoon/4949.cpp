#include <bits/stdc++.h>
using namespace std;
bool solution(string s)
{
	vector<char> store;
	for(int i=0; i<s.size(); i++){
		if(s[i] == '('){
			store.push_back('(');
		} else if(s[i] == ')'){
			if(store.empty()){
				return false;
			} else if(store.back() == '('){
				store.pop_back();
			} else return false;
		} else if (s[i] == '['){
			store.push_back('[');
		} else if(s[i] == ']'){
			if(store.empty()){
				return false;
			} else if(store.back() == '['){
				store.pop_back();
			} else return false;
		} else continue;
	}
	if(store.empty()){
		return true;
	} else {
		return false;
	}
}
int main(){
	string s;
	while(1){
		getline(cin, s, '.');
		if(s.size() == 1) break;
		cout << (solution(s) ? "yes" : "no") << "\n";
	}
	return 0;
}
