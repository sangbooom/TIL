#include <bits/stdc++.h>
using namespace std;

int N,M;
int arr[10];
int visited[10];

void backTracking(int k){
	if(k==M){
		for(int i=0; i<M; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	} else {
		for(int i=1; i<=N; i++){
			if(!visited[i]){
				arr[k] = i;
				visited[i] = 1;
				backTracking(k+1);
				visited[i] = 0;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
  	cin.tie(0);
	cin >> N >> M;
	backTracking(0);

	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//
//int arr[N];
//int main(){
//	int N,M;
//	cin >> N >> M;
//	for(int i=1; i<=N; i++){
//		arr[i] = i;
//	}
//	
//	do{
//		for(int i=1; i<N; i++){
//			
//		}
//	} while(next_permutation(arr, arr+M))
//	
//	return 0;
//}
