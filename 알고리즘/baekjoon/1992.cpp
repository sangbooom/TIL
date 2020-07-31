#include <bits/stdc++.h>
using namespace std;

char data[65][65];

void divData(int N, int a, int b){
	bool flag = true;
	int c = data[a][b];
	for(int i=a; i<a+N; i++){
		for(int j=b; j<b+N; j++){
			if(c != data[i][j]){
				flag = false;
				break;
			}
		}
	}
	if(flag){
		cout << c-48;
	} else {
		cout << "(";
		for(int i=a; i<a+N; i+=N/2){
			for(int j=b; j<b+N; j+=N/2){
				divData(N/2,i,j);
			}
		}
		cout << ")";
	}
}

int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> data[i][j];
		}
	}
	divData(N,0,0);
	return 0;
}
