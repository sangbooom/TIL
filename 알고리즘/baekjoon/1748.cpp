#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	int solution = 0;
	int t = 9;
	int cnt = 1;
	int subNum = 0;
	cin >> N;
	while(t+subNum < N){
		solution += (t*cnt);
		subNum += t;
		t *= 10;
		cnt++;
	}
	cout << (N - subNum) * cnt + solution;
	return 0;	
}

