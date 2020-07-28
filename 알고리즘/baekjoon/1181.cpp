#include <bits/stdc++.h>
using namespace std;

int N;

bool cmp(string a, string b){
  if(a.length() == b.length()){
       return a<b;
  }
  return a.length()<b.length();
}

int main(){
	cin >> N;
	string s;
	vector<string> word; 
	for(int i=0; i<N; i++){
		cin >> s;
		word.push_back(s);
	}
	
	sort(word.begin(),word.end(),cmp);
	
	for(int i=0; i<N; i++){
		cout << word[i] << "\n";
	}
		
	return 0;
}
