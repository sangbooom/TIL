#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	int a = 6;
	int room = 1;
	int count = 1;
	while(1){
		if( N <= room ){
			cout << count;
			return 0;	
		}
		room += a;
		a += 6;
		count++;
	}
	return 0;
}
