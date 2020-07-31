#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,string> a, pair<int,string> b){
	return a.first < b.first;
}

int main(){
	int N,age;
	string name;
	vector<pair<int,string> > n;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> age >> name;
		n.push_back(make_pair(age, name)); 
	}
	stable_sort(n.begin(), n.end(),cmp);
	for(int i=0; i<N; i++){
		cout << n[i].first << " " << n[i].second << "\n";
	}
	return 0;
}
