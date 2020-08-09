#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	int k;
	cin >> N;
	int arr[10001] ={0};
	for(int i=0; i<N; i++){
		cin >> k;
		arr[k]++;
	}
	for(int i=1; i<=10000; i++){
		for(int j=1; j<=arr[i];j++){
			cout << i << "\n";
		}
	}
	
	return 0;
}
