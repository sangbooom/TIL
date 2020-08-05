#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	int a=0;
	int cnt = 0;
	cin >> N;
	if(N==4 || N==7){
		cout << "-1";
		return 0;
	}
	int k = N/5;
	while(1){
		if((N-(k*5))% 3 == 0){
			cnt = k+ ((N-(k*5))/3);
			break;
		} else {
			k--;
		}
		if(k == 0){
			cnt += N/3;
			break;
		}
	}
	cout << cnt;
	
	return 0;
}
