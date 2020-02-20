#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
bool visited[MAX];
using namespace std;
vector<int> graph[MAX];
int n,s,e;
int dist[MAX]={0,};

int main(void){
	cin >> n;
	cin >> s >> e;
	for(int i=0; i<s; i++){
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);	
	}
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0; i<graph[x].size(); i++){
			int y = graph[x][i];
			if(!visited[y]){
				visited[y] = true;
				dist[y] = dist[x] + 1;
				if(y == e){
					cout<< dist[e];
					return 0;
				}
				else if(dist[e]==0){
					dist[e] = -1;
				}
				q.push(y);
			}
		}
	} 
}
