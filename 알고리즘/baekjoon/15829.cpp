#include <bits/stdc++.h>
using namespace std;
const int MOD = 1234567891;
int main(){
	int L;
	unsigned long long sum = 0;
	unsigned long long r = 1;
	string s;
	
	cin >> L;
	cin >> s;
	
	for(int i=0; i<s.size(); i++){
		sum += r *(s[i] - 96);
		r = (r * 31) % MOD;
		while(sum >= MOD){
			sum %= MOD;
		}
	}
	
	cout << sum;
	
	return 0;
}
