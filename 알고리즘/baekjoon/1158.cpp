#include <bits/stdc++.h>
using namespace std;
int main(){
	int N,K;
	int count = 1;
	int sum = 0;
	bool flag = true;
	cin >> N >> K;
	vector<int> arr(N+1);
	vector<int> answer;
	
	for(int i=1; i<=N; i++){
		arr[i] = i;
	}
	
	while(1){
		for(int i=1; i<=N; i++){
			if(sum == N){
				flag = false;
				break;
			}
			if(arr[i] == 0){
				continue;
			}
			if(count == K){
				answer.push_back(arr[i]);
				arr[i] = 0;
				count = 0;
				sum++;
			}
			count++;
		}
		if(!flag) break;
	}
	
	cout<< "<";
	for(int i=0; i<N; i++){
		if(i == N-1) cout << answer[i];
		else cout << answer[i] << ", ";
	}
	cout<< ">";
	
	return 0;
}
