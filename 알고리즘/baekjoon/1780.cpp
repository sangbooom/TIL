#include <bits/stdc++.h>
using namespace std;
int paper[2187][2187];

int sum1 = 0;
int sum2 = 0;
int sum3 = 0;

void divPaper(int N, int a, int b){
	bool flag = true;
	int c = paper[a][b];
	for(int i=a; i<N+a; i++){
		for(int j=b; j<N+b; j++){
			if(c != paper[i][j]){
				flag = false;
				break;
			} 
		}
	}
	if(flag){
		if(c == -1) sum1++;
		else if(c == 0) sum2++;
		else if(c == 1) sum3++; 
	} else {
		for(int i=a; i<N+a; i+=N/3){
			for(int j=b; j<N+b; j+=N/3){
				divPaper(N/3,i,j);
			}
		}
	}
}

int main(){
	int N;	
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> paper[i][j];
		}
	}
	divPaper(N,0,0);
	cout << sum1 << "\n" << sum2 << "\n" << sum3;
	return 0;
}
