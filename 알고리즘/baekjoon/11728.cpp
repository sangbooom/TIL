#include <bits/stdc++.h>
using namespace std;
int A[1000001], B[1000001], C[1000001];
int main(){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N,M;
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> A[i];
	}
	for(int i=0; i<M; i++){
		cin >> B[i];
	}
	int A_index = 0;
	int B_index = 0;
	for(int i=0; i<N+M; i++){
		if(A_index == N) C[i] = B[B_index++];
		else if(B_index == M) C[i] = A[A_index++];
		else if(A[A_index] < B[B_index]) C[i] = A[A_index++];
		else C[i] = B[B_index++];  
	}
	
	for(int i=0; i<N+M; i++){
		cout << C[i] << " ";
	}
	
	return 0;
}
