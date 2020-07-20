#include <bits/stdc++.h>
using namespace std;

int S,C;
int p[1000001];

long long binarySearch(int m){
	long long left = 1;
	int right = m;
	long long sum;
	long long max_len=0;
	while(left <= right){
		sum = 0;
		long long mid_num = (left + right) / 2;
		for(int i=0; i<S; i++){
			sum += p[i] / mid_num; 
		}
		if(sum < C){
			right = mid_num - 1;
		} else {
			if(max_len < mid_num) max_len = mid_num;
			left = mid_num + 1;
		}
	}
	long long remain = 0;
	for(int i=0; i<S; i++){
		remain += p[i];
	}
	return remain - (max_len * C);
}

int main(){
	int max_num = 0;
	cin >> S >> C;
	
	for(int i=0; i<S; i++){
		cin >> p[i];
		max_num = max(max_num, p[i]);
	}	 
	
	cout << binarySearch(max_num);
	
	return 0;
}
