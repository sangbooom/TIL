#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b){
	if( a.length() == b.length()){
		return a < b;
	}
	return a.length() < b.length();
}

int main(){
	int N;
	cin >> N;
	vector<string> word(N);
	for(int i=0; i<N; i++){
		cin >> word[i];
	}
	sort(word.begin(), word.end(), cmp);
	for(int i=0; i<N; i++){
		if(i >=1 && word[i] == word[i-1]){
			continue;
		}
		cout << word[i] << "\n";
	}
	
	return 0;
}
