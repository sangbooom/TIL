#include <bits/stdc++.h>
using namespace std;
int board[101][101][101];
int dist[101][101][101];
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(){ //아직 해결 x 예제입력2가 실행안됨  
	int M,N,H;
	int day = 0;
	cin >> M >> N >> H;
	queue<tuple<int,int,int> > Q;
	for(int k=0; k<H; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				cin >> board[i][j][k];
				if(board[i][j][k] == 1){
					Q.push(make_tuple(i,j,k));
				}
				if(board[i][j][k] == 0){
					dist[i][j][k] = -1;
				}
			}
		}	
	}
	
	while(!Q.empty()){
		int x,y,z;
		tie(z,x,y) = Q.front();
		Q.pop();
		for(int dir=0; dir<6; dir++){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nz = z + dz[dir];
			if(nx<0 || nx>=M || ny<0 || ny>=N || nz<0 || nz>=H) continue;
			if(dist[nx][ny][nz] >= 0) continue;
			dist[nx][ny][nz] = dist[x][y][z] + 1;
			Q.push(make_tuple(nx,ny,nz));
		}
	}
	
	for(int k=0; k<H; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(dist[i][j][k] == -1){
					cout << "-1";
					return 0;
				}
				day = max(day, dist[i][j][k]);
			}
		}	
	}
	
	cout << day;
	return 0;
}

/*
1. 36라인 수정해야하는 부분입니다.
2. 14 ~ 19라인에서 Q에 어떤 순으로 넣었는지 정리해보세요.
3. 30라인에서 Q에 어떤 순으로 뺐는지 정리해보세요.
2번과 3번을 한번 맞는지 비교해보세요
*/
