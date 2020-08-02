#include <bits/stdc++.h>
using namespace std;
int main(){
	int M,N;
	cin >> M >> N;
	int prime[N+1] = {1,1,0};
	
	for(int i=2; i<=N; i++){
		if(prime[i]){
			continue;
		}
		prime[i] = 0;
		for(int j=i*2; j<=N; j+=i){
			prime[j] = 1;
		}
	} 
	
	for(int i=M; i<=N; i++){
		if(!prime[i]){
			cout << i << "\n";
		}
	}
	return 0;
}
