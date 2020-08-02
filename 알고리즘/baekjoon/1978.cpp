#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	int count = 0;
	cin >> N;
	vector<int> num(101);
	for(int i=0; i<N; i++){
		cin >> num[i];
	}
	int maxValue = *max_element(num.begin(), num.end());
	int prime[N+1] = {1,1,0};
	
	for(int i=2; i<=maxValue; i++){
		if(prime[i]){
			continue;
		}
		prime[i] = 0;
		for(int j=i*2; j<=maxValue; j+=i){
			prime[j] = 1;
		}
	} 
	
	for(int i=0; i<num.size()-1; i++){
		if(!prime[num[i]]){
			count++;
		}
	}
	cout << count;
	return 0;
}
