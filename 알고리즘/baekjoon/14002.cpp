#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,tmp;
	cin >> n;
	vector<int> A;
	vector<int> len(n,1);
	vector<int> v(n,0);
	
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
	
	for(int i=0; i<n; i++){
		cout << len[i] << " ";
	}
	
	int max_len = *max_element(len.begin(),len.end());
	cout << max_len << "\n";
	
	return 0;
}
