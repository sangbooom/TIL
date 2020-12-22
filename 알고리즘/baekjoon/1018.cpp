#include <bits/stdc++.h>
using namespace std;

int N,M;
char board[50][50] = {0,};
string WB[8] = {"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW"};
				
string BW[8] = {"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB",
				"BWBWBWBW",
				"WBWBWBWB"};

int solution(int w,int h){
	int count_WB = 0;
	int count_BW = 0;
	int a=0;
	int b=0;
	for(int i=w; i<w+8; i++){
		for(int j=h; j<h+8; j++){
			if(board[i][j] != WB[a][b]){
				count_WB++; 
			}
			if(board[i][j] != BW[a][b]){
				count_BW++;
			}
			b++;
		}
		a++;
		b=0;
	}
	
	return min(count_WB,count_BW);
}

int main(){
	int check_count = 0;
	int min_count = 99999;	  
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> board[i][j];
		}
	}
	
	for(int i=0; i<=N-8; i++){
		for(int j=0; j<=M-8; j++){
			check_count = solution(i,j);
			if(check_count < min_count){
				min_count = check_count;
			}
		}
	}
	
	cout << min_count;
	
	return 0;
}
