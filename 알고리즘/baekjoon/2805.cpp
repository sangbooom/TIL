#include <bits/stdc++.h>
using namespace std;
//ÀÌºÐÅ½»ö 

int tree[1000001]={0};
int N,M;

int binarySearch(int max_num){ //20
	int left = 1;
	int right = max_num;
	long long sum;
	int max_h = 0;
	
	while(left <= right){ 
		sum = 0;
		int mid_num = (left + right) / 2; // 10
		
		for(int i=0; i<N; i++){
			if(tree[i] - mid_num < 0) continue;
			
			sum += (tree[i] - mid_num);
		}
		if(sum < M){
			right = mid_num - 1;
		} else {
			if(max_h < mid_num) max_h = mid_num;
			left = mid_num + 1;
		}
	}
	return max_h;
}
int main(){
	int max_num = -999999;
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> tree[i];
		max_num = max(max_num,tree[i]);
	}
	cout << binarySearch(max_num);
	
	return 0;
} 
