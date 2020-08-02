#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	int location;
	int max = 0;
	int count = 0;
	bool flag = true;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> k >> location;
		
		vector<int> priorities(k);
		for(int j=0; j<k; j++){
			cin >> priorities[j];	
		}
		flag = true;
		count = 0;
		while(1){
			for(int i=0; i<k; i++){
				max = *max_element(priorities.begin(), priorities.end());
				if(max == priorities[i]){
					count++;
					priorities[i] = 0;
					
					if(location == i){
						cout << count << "\n";
						flag = false;
						break;
					}
				}
			}
			if(!flag) break;
		}	
		priorities.assign(k,0);
	}
	return 0;
}
