#include <bits/stdc++.h>
using namespace std;

int k,n;
int lope[10001];
	
int binarySearch(int max_num){
	long long left = 1;
	int right = max_num;
	int sum;
	int max_len = 0;
	while(left <= right){
		sum = 0;
		long long mid_num = (left + right) / 2;
		
		for(int i=0; i<k; i++){
			sum += lope[i] / mid_num;
		}
		if(sum < n){
			right = mid_num - 1;	
		} else {
			if(max_len < mid_num) max_len = mid_num;
			left = mid_num + 1;
		}
	}
	return max_len;
}

int main(){
	int max_num = 0;
	cin >> k >> n;
	
	for(int i=0; i<k; i++){
		cin >> lope[i];
		max_num = max(max_num, lope[i]);
	}
	
	cout << binarySearch(max_num);
	
	return 0;
}
