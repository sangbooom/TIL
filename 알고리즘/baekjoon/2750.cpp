#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,k;
	cin >> N;
	vector<int> v(N,0);
	for(int i=0; i<N; i++){
		cin >> v[i];
	}
	for(int i=N-1; i>0; i--){
		for(int j=i-1; j>=0; j--){
			if(v[i] < v[j]){
				int temp = v[i];
				v[i] = v[j];
				v[j] = temp; 
			}
		}
	}
	
	for(int i=0; i<N; i++){
		cout << v[i] << "\n";
	}
	
	return 0;
}
