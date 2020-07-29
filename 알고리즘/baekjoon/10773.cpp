#include <bits/stdc++.h>
using namespace std;
int main(){
	int k,a;
	int sum=0;
	cin >> k;
	vector<int> n;
	for(int i=0; i<k; i++){
		cin >> a;
		if(a != 0){
			n.push_back(a);	
		} else {
			n.pop_back();
		}
	}
	for(int i=0; i<n.size(); i++){
		sum += n[i];
	}
	cout << sum;
	return 0;
}
