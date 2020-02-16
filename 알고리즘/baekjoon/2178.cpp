#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_SIZE 101
using namespace std;
int N,M;
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
bool visited[MAX_SIZE][MAX_SIZE];
int map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];

void bfs(int x, int y){
	queue< pair<int,int> > q;
	q.push(make_pair(x,y));
	
	visited[x][y] = true;
	dist[0][0] = 1;
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(0<=nx && nx < N && 0<=ny && ny < M){
				if(map[nx][ny] == 1 && visited[nx][ny] == false){
					visited[nx][ny] = true;
					dist[nx][ny] = dist[0][0] + 1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}

int main(void){
	cin >> N >> M;
	for(int i=0; i<N;i++){
		for(int j=0; j<M; j++){
			scanf("%1d",&map[i][j]);
		}
	}
	bfs(0,0);
	printf("%d",dist[N-1][M-1]);
	return 0;
}
