#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int count=0;
	int stack_count=0;
	int max_s=0;
	vector<int> store;
	string s;
	cin >> n >> s;
	
	for(int i=0; i<s.size(); i++){
		if(s[i] == '('){
			store.push_back(1);
		} else if(s[i] == ')'){
			if(store.size() == 0){
				count += stack_count;
				max_s = max(count, max_s);
				count = 0;
				stack_count = 0;
				continue;
			} 
			stack_count += 2;
			store.pop_back();
		}
	}
	cout << max(stack_count, max_s);
	return 0;
}


