#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,tmp;
	cin >> n;
	vector<int> A;
	vector<int> len(n,0);
	
	for(int i=0; i<n; i++){
		cin >> tmp;
		A.push_back(tmp);
		len[i] = tmp;
	}
	
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(A[j] < A[i] && len[j]+A[i] > len[i]){
				len[i] = len[j] + A[i];
			}
		}
	}
	
	int max_len = *max_element(len.begin(),len.end());
	cout << max_len;
	
	return 0;
}
