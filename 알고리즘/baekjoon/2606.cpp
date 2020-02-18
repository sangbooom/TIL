#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

vector<int> graph[MAX];
bool visited[MAX];
int virus=0;

void dfs(int s){
	visited[s] = true;
	
	for(int i=0; i<graph[s].size(); i++){
		int x = graph[s][i];
		if(!visited[x]){
			visited[x] = true;
			virus++;
			dfs(x);
		}
	}
}
void bfs(int s){
	visited[s] = true;
	queue<int> q;
	q.push(s);
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		
		for(int i=0; i<graph[x].size(); i++){
			int y = graph[x][i];
			if(!visited[y]){
				visited[y] = true;
				virus++;
				q.push(y);
			}
		}
	}
}

int main(){
	int v,e;
	cin >> v >> e;
	for(int i=1; i<=e; i++){
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}
	memset(visited,false,sizeof(visited));
	//bfs(1);
	dfs(1);
	cout << virus;
	
	return 0;
}
