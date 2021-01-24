#include <bits/stdc++.h>
using namespace std;

int board[502][502];
bool visit[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> board[i][j];
		}
	}
	int mx = 0; //제일 넓은 그림의 넓이
	int num = 0; //그림의 수
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++){
			if(board[i][j] == 0 || visit[i][j]) continue;
			num++;
			queue<pair<int,int> > Q;
			visit[i][j] = 1;
			Q.push({i, j});
			int area = 0; 
			while(!Q.empty()){ // 동서남북 체크 
				area++;
				pair<int, int> cur = Q.front();
				Q.pop();
				for(int dir=0; dir<4; dir++){
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if(visit[nx][ny] || board[nx][ny] != 1) continue;
					visit[nx][ny] = 1;
					Q.push({nx, ny}); 
				}
			}
			mx = max(mx, area); 
		}
	}
	cout << num << "\n" << mx;
	return 0;
}
