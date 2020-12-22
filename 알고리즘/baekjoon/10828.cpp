#include <bits/stdc++.h>
using namespace std;
int main(){ cin.tie(0);cout.tie(0); ios_base::sync_with_stdio(0);
	int n,num;
	string mode;
	vector<int> k;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> mode;
		if(mode == "push"){
			cin >> num;
			k.push_back(num);
		}
		if(mode == "top"){
			if(k.size() < 1){
				cout << "-1\n";
			} else {
				cout << k[k.size()-1] << "\n";	
			}
		}
		if(mode == "size"){
			cout << k.size() << "\n";
		}
		if(mode == "empty"){
			if(k.empty()){
				cout << "1\n";	
			} else {
				cout << "0\n";
			}
		}
		if(mode == "pop"){
			if(k.size() > 0) {
				cout << k[k.size()-1] << "\n";
				k.pop_back();
			} else {
				cout << "-1\n";
			}
		}
	}
	return 0;
}

