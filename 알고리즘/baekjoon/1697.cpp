#include <bits/stdc++.h>
using namespace std;
int dist[100002];
int N,K;
int main(){
	cin >> N >> K;
	fill(dist, dist+100001, -1);
	dist[N] = 0;
	queue<int> Q;
	Q.push(N);
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		for(int dir=0; dir<3; dir++){
			int nx;
			if(dir==0) nx = cur-1;
			if(dir==1) nx = cur+1;
			if(dir==2) nx = cur*2;
			if(dist[nx] >= 0) continue;
			if(nx < 0 || nx > 100000) continue;
			if(nx == K){
				cout << dist[cur] + 1;
				return 0;
			}
			dist[nx] = dist[cur] + 1;
			Q.push(nx);
		}
	}
	return 0;
}
