#include <bits/stdc++.h>
using namespace std;

char chess[8][8];
char board[50][50];

int checkChess(){
	int countW = 0;
	int countB = 0;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if((i+j)%2==0 && chess[i][j]=='W' || (i+j)%2==1 && chess[i][j]=='B'){
				countW++;
			}
			if((i+j)%2==0 && chess[i][j]=='B' || (i+j)%2==1 && chess[i][j]=='W'){
				countB++;
			}
		}
	}	
	return min(countW,countB);
}

void getChessInfo(int x, int y){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			chess[i][j] = board[i+x][j+y];
		}
	}
}

int main(){
	int N,M;
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> board[i][j]; 
		}
	}
	
	int min_num = 9999999;
	for(int i=0; i<=N-8; i++){
		for(int j=0; j<=M-8; j++){
			getChessInfo(i,j);
			min_num = min(min_num, checkChess());
		}
	}
	
	cout << min_num;
	
	return 0;
}
