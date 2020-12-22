#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) a.first < b.first;
    return a.second < b.second;
}

int main(){
	int N,x,y;
	vector<pair<int,int>> xy;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> x >> y;
		xy.push_back(make_pair(x,y));
	}
	sort(xy.begin(), xy.end(), comp);
	for(int i=0; i<xy.size(); i++){
		cout << xy[i].first << " " << xy[i].second << "\n";
	}
	
	return 0;
}
