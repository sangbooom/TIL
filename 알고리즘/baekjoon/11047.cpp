#include <iostream>
using namespace std;
int N[10];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> N[i];
	int count = 0;
	for (int i = n-1; i>=0; i--) {
		if (k == 0) break;
		count = count + k / N[i];
		k = k % N[i];
	}
	cout << count << endl;
}


//#include <bits/stdc++.h>
//using namespace std;
//int main(){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	int n,k,coin;
//	int val = 0;
//	int cnt = 0;
//	vector<int> v;
//	cin >> n >> k;
//	for(int i=0; i<n; i++){
//		cin >> coin;
//		v.push_back(coin);
//	}
//	for(int i=0; i<n; i++){
//		if(v[i] > k){
//			val = i-1;
//			break;	
//		}
//	}
//	while(k > 0){
//		k -= v[val];
//		cnt++;
//		while(k <= v[val]){
//			val--;
//		}
//	}
//	cout << cnt;
//	return 0;
//}
