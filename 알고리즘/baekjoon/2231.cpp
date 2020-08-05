#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	int sum;
	int temp;
	cin >> N;
	int len = log10(N)+1;
	int minValue = N - (len*9);
	for(int i = minValue; i<=N; i++){
		sum = 0;
		temp = i;
		for(int j=0; j<len; j++){
			sum += temp % 10;
			temp /= 10;
		}
		if(sum + i == N){
			cout << i;
			return 0;
		}
	}
	cout << "0";
	return 0;
}
