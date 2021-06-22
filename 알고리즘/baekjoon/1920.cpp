#include <bits/stdc++.h>
using namespace std;

int main(){ cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m,tmp,target;
	bool flag = false;
	vector<int> A;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> tmp;
		A.push_back(tmp); 
	}
	sort(A.begin(),A.end());
	cin >> m;
	while(m--){
		cin >> target;
		flag = false;
		int l = 0;
		int r = A.size()-1;
		int mid;
		while(l <= r){
			mid = (l+r)/2;
			if(A[mid] < target){
				l = mid + 1;
			} else if(A[mid] > target){
				r = mid - 1;
			} else {
				cout << "1\n";
				flag = true;
				break;
			}
		}
		if(!flag) cout << "0\n";
	}	
	return 0;
}
