#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <queue>

#define MAX_SIZE 25
using namespace std;
int n;
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
int groups[MAX_SIZE*MAX_SIZE];
int group_id;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int bfs(int x, int y){
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

int main(){
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%1d",&map[i][j]);
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == 1 && visited[i][j] == false){
				group_id++;
				bfs(i,j);
			}
		}
	}
	
	sort(groups + 1, groups + group_id + 1);
	printf("%d\n",group_id);
	
	for(int i=1; i<=group_id; i++){
		printf("%d\n",groups[i]);
	}
	
	return 0;
}
