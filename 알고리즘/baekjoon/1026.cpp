#include <bits/stdc++.h>
using namespace std;
int main(){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	int solution = 0;
	cin >> N;
	int A[N]={0,};
	int B[N]={0,};
	for(int i=0; i<N; i++){
		cin >> A[i];
	}
	for(int i=0; i<N; i++){
		cin >> B[i];
	}
	sort(A,A+N);
	sort(B,B+N, greater<int>());
	for(int i=0; i<N; i++){
		solution += A[i] * B[i];
	}
	cout << solution;
	return 0;
}
