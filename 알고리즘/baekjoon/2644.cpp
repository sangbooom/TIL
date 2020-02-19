#include <iostream>
#include <vector>
#define MAX 101
bool visited[MAX];
using namespace std;
vector<int> graph[MAX];
int n,s,e;
int dist[MAX]={0,};

void dfs(int start){
	visited[start] = true;
	for(int i=0; i<graph[start].size(); i++){
		int y = graph[start][i];
		if(!visited[y]){
			visited[y] = true;
			dist[y] = dist[start] + 1;
			dfs(y);
		}
	}
}

int main(void){
	cin >> n;
	cin >> s >> e;
	for(int i=0; i<s; i++){
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);	
	}
	dfs(s);
	if(dist[e]==0){
		dist[e] = -1;
	} 
	cout << dist[e];
}
