#include <bits/stdc++.h>
using namespace std;
int main(){
	int T,W,H,N;
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> H >> W >> N;
		if(N%H == 0){
			cout << H;
			if((N/H) < 10){
				cout << "0" << (N/H) << "\n";
			} else {
				cout << (N/H) << "\n";
			}	
		} else {
			cout << N%H;
			if((N/H)+1 < 10){
				cout << "0" << (N/H)+1 << "\n";
			} else {
				cout << (N/H)+1 << "\n";
			}
		}
	}
	return 0;
}
