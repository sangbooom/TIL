#include <bits/stdc++.h>
using namespace std;
int main(){
	int remainder[42] = {0};
	int n;
	int count = 0;
	
	for(int i=0; i<10; i++){
		cin >> n;
		if(!remainder[n%42]++){
			count++;
		}
	}
	cout << count;
	
	return 0;
}
