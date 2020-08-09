#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	int prevSum = 0;
	int sum = 0;
	cin >> N;
	vector<int> arr(N);
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	
	for(int i=0; i<N; i++){
		if(i >= 1) prevSum += arr[i-1]; 
		sum += arr[i] + prevSum;
	}
	cout << sum;
	return 0;
}
