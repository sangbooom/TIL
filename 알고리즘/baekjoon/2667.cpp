#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_SIZE 26
using namespace std;
int n;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int groups[1010];
int group_id;
int map[30][30];
bool visited[30][30];

void bfs(int x, int y){
	queue < pair<int,int> > q;
	q.push(make_pair(x,y));
	
	visited[x][y] = true;
	groups[group_id]++;
	
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(0<=nx && nx<n && 0<=ny && ny<n){
				if(map[nx][ny] == 1 && visited[nx][ny] == false){
					visited[nx][ny] = true;
					groups[group_id]++;
					
					q.push(make_pair(nx,ny));
				}
			}	
		}
	}
}

void dfs(int x, int y){
	visited[x][y] = true;
	groups[group_id]++;
	
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(0<=nx && nx<=n && 0<=ny && ny<=n){
			if(map[nx][ny] == 1 && visited[nx][ny] == false){
				dfs(nx,ny);
			}
		}
		
	}
}

int main(void){
	cin >> n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%1d",&map[i][j]);
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] && !visited[i][j]){
				group_id++;
				dfs(i,j);
			}
		}
	}
	

	printf("%d\n",group_id);
	sort(groups , groups + group_id);
		
	for(int i=1; i<=group_id; i++){
		printf("%d\n",groups[i]);
	}
	
	return 0;
}
