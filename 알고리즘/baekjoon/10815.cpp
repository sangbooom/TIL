#include <bits/stdc++.h>
using namespace std;
int main(){ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int N,M,index;
	bool flag = false;
	cin >> N;
	vector<int> card(N);
	for(int i=0; i<N; i++){
		cin >> card[i];
	}
	sort(card.begin(),card.end());
	cin >> M;
	for(int i=0; i<M; i++){
		cin >> index;
		
		int left = 0;
		int right = N-1;
		
		while(left <= right){
			int mid = (left + right) / 2;
			
			if(card[mid] == index){
				flag = true;
				break;
			} else if(card[mid] < index){
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		if(flag){
			cout << "1";
		} else {
			cout << "0";
		}
		cout << " ";
		flag = false;
	}

	return 0;	
}


