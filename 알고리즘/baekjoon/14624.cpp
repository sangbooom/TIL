#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	
	if(N%2==0){
		cout << "I LOVE CBNU";
		return 0;
	} else {
		for(int i=0; i<N; i++){
			cout << "*";
		}
		cout << "\n";
		for(int j=0; j<(N+1)/2; j++){
			for(int k=j+1; k<(N+1)/2; k++){
				cout << " ";
			}
			if(j==0){
				cout << "*\n";
				continue;
			}
			cout << "*";
			for(int k=0; k<2*j-1; k++){
				cout << " ";
			}
			cout << "*\n";
		}	
	}
		
	return 0;
}
