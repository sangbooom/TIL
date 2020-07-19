#include <iostream>
#include <algorithm>

using namespace std;
int d[1000000];

int calc(int n){
	d[1] = 0;
	for(int i=2; i<=n; i++){
		d[i] = d[i-1] + 1;
		if(i%2==0){
			d[i] = min(d[i], d[i/2] + 1);
		}
		if(i%3==0){
			d[i] = min(d[i], d[i/3] + 1);
		}
	}
	return d[n];
}

int main(){
	int n;
	cin >> n;
	
	cout << calc(n);
	
	return 0;
}
