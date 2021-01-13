#include <bits/stdc++.h>
using namespace std;
int main(){
	int N,M,B,ground;
	vector<int> block;
	cin >> N >> M >> B;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> ground; 
			block.push_back(ground);
		}
	}
	
	for(int i=0; i<block.size(); i++){
		cout << block[i] << " ";
	}
	
	
	return 0;
}
