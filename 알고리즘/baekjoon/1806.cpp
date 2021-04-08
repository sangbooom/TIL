#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int main(){ ios::sync_with_stdio(0); cin.tie(0);
	int N,S;
	int cnt = 0;
	int low = 0; 
	int high = 0;
	
	cin >> N >> S;
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	int sum = arr[0];
	int result = 987654321;
	//투 포인터 알고리즘 적용 
	while (low <= high && high < N)
	{
		if (sum < S){
			sum += arr[++high];
		} else if (sum == S) {
			result = min(result, (high - low + 1));
			sum += arr[++high];
		} else if (sum > S) {
			result = min(result, (high - low + 1));
			sum -= arr[low++];
		}
	}
	if (result == 987654321){
		cout << 0 << "\n";
	} else {
		cout << result << "\n";
	}
	return 0;
}
