#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N-i-1; j++){
			cout << " ";
		}
		if(i==0 || i==N-1){
			for(int j=0; j<2*i+1; j++){
				cout << "*";
			}	
		} else {
			cout << "*";
			for(int j=0; j<2*(i-1)+1; j++){
				cout << " ";
			}
			cout << "*";
		}
		cout << "\n";
	}
	
	return 0;
}
