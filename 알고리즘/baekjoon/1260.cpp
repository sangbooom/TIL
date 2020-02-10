#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 1001
using namespace std;

vector<int> graph[MAX];
bool visited[MAX];
int N,M,V;

void dfs(int V){
	cout << V << " ";
	visited[V] = true;
	
	for(int i=0; i< graph[V].size(); i++){
		int x = graph[V][i];
		if(!visited[x]){
			dfs(x);
		}
	}
}

void bfs(int V){
	queue<int> q;
	q.push(V);
	visited[V] = true;
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";
		
		for(int i=0; i<graph[x].size(); i++){
			int y = graph[x][i];
			if(!visited[y]){
				visited[y] = true;
				q.push(y);
			}
		}
	}
}

int main(){
	
	cin >> N >> M >> V;
	for(int i=0; i<M; i++){
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}
	for(int i=1; i<=N; i++){
		sort(graph[i].begin(),graph[i].end());
	}
	dfs(V);
	cout << "\n";
	memset(visited,false,sizeof(visited));
	bfs(V);
  
	return 0;
}
