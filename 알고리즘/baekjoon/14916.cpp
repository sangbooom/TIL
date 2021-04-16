#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int cnt = 0;
	cin >> n;
	if(n==1 || n==3){
		cout << "-1";
		return 0;
	}
	
	while(1){
		if(n%2==0){
			if(n%5==0){
				cnt += n/5;
				cout << cnt;
				break;
			}
			n-=2;
			cnt++; 
		} else {
			if(n%2==0){
				cnt += n/2;
				cout << cnt;
				break;
			}
			n-=5;
			cnt++;
		}	
	}

	return 0;
}

