#include <bits/stdc++.h>
using namespace std;
int main(){
	int H,M;
	int time = 45;
	cin >> H >> M;
	if(M < time){
		time -= M;
		H -= 1;
		if( H < 0){
			H = 23;
		}
		M = 60 - time;
	} else {
		M -= time;
	}
	cout << H % 24 <<" "<< M;
	
	return 0;
}
