#include <bits/stdc++.h>
using namespace std;
int main(){
	int N,M;
	vector<string> b1,c1;
	cin >> N >> M;
	string a,b;
	for(int i=0; i<N; i++){
		cin >> a;
		b1.push_back(a);
	}
	sort(b1.begin(),b1.end());
	for(int i=0; i<M; i++){
		cin >> b;
		if(binary_search(b1.begin(),b1.end(),b)){
			c1.push_back(b);
		}
	}
	sort(c1.begin(),c1.end());
	cout << c1.size() << "\n";
	for(int i=0; i<c1.size(); i++){
		cout << c1[i] << "\n";
	}
	return 0;
}
