#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,tmp;
	cin >> n;
	vector<int> A;
	vector<int> len(n,1);
	vector<int> len_r(n,0);
	
	for(int i=0; i<n; i++){
		cin >> tmp;
		A.push_back(tmp); 
	}
	
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(A[j] < A[i] && len[j]+1 > len[i]){
				len[i] = len[j] + 1;
			}
		}
	}
	
	for(int i=n-2; i>=0; i--){
		for(int j=n-1; j>i; j--){
			if(A[i] > A[j] && len_r[j]+1 > len_r[i]){
				len_r[i] = len_r[j] + 1;
			}
		}
	}
	
//	for(int i=0; i<n; i++){
//		cout << len[i] << " ";
//	}
//	cout << "\n";
//	for(int i=0; i<n; i++){
//		cout << len_r[i] << " ";
//	}
	
	int answer = 0;
	int sum = 0;
	for(int i=0; i<n; i++){
		sum = len[i] + len_r[i];
		answer = max(answer,sum);
	}
	cout << answer;
		
	return 0;
}
