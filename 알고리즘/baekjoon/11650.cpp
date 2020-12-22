#include <bits/stdc++.h>
using namespace std;
int main(){
	int N,x,y;
	vector<pair<int,int>> xy;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> x >> y;
		xy.push_back(make_pair(x,y));
	}
	sort(xy.begin(),xy.end());
	for(int i=0; i<xy.size(); i++){
		cout << xy[i].first << " " << xy[i].second << "\n";
	}
	
	return 0;
}
