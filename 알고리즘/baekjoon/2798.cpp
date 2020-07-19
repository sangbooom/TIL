#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,M;
	int card[101];
	int max_sum = 0;
	
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> card[i];
	}
	for(int i=0; i<=N-3; i++){
		for(int j=i+1; j<=N-2; j++){
			for(int k=j+1; k<=N-1; k++){
				if(card[i] + card[j] + card[k] > max_sum && card[i] + card[j] + card[k] <= M){
					max_sum = card[i] + card[j] + card[k];
				}	
			}
		}	
	}
	cout << max_sum;	
	
	return 0;
}
