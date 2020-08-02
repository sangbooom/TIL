#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	int maxValue=0;
	int flag = true;
	cin >> n;
	vector<int> s(n);
	vector<string> answer;
	vector<int> store(1,0);
	for(int i=0; i<n; i++){
		cin >> s[i];
		if(i == 0){
			for(int j=0; j<s[i]-maxValue; j++){
				answer.push_back("+");
			}
			store.push_back(s[i]);
			answer.push_back("-");	
		} else {
			maxValue = *max_element(store.begin(), store.end());
			if( s[i-1] < s[i]){
				for(int j=0; j<s[i]-maxValue; j++){
					answer.push_back("+");
				}
				store.push_back(s[i]);
				answer.push_back("-");	
			} else if( s[i-1] > s[i]){
				if( s[i-1]-1 == s[i]){	
					store.push_back(s[i]);	
					answer.push_back("-");
					continue;
				}
				for(int j=s[i-1]-1; j>s[i]; j--){
					flag = true;
					for(int k=0; k<store.size(); k++){
						if(store[k] == j){
							flag= false;
							break;
						}
					}
					if(flag){
						cout << "NO";
						return 0;
					}
				}
				store.push_back(s[i]);
				answer.push_back("-");
			}
		}
	}
	for(int i=0; i<answer.size(); i++){
		cout << answer[i] << "\n";
	}
	
	return 0;
}
