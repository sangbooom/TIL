#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	int N,M,index;
	cin >> N;
	vector<int> num(N);
	for(int i=0; i<N; i++){
		cin >> num[i];
	}
		
	sort(num.begin(),num.end());
	
	cin >> M; 
	for(int i=0; i<M; i++){
		cin >> index;
		cout << upper_bound(num.begin(),num.end(),index) - lower_bound(num.begin(),num.end(),index) << " ";
	}
	
	return 0;
}
