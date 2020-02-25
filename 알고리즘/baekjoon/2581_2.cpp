#include <iostream>
using namespace std;
int main(){
	int M,N;
	int sum=0; 
	int low = 10001;
	bool flag;
	
	cin >> M >> N;
	
	for(int i=M; i<N; i++){
		for(int j=2; j<i; j++){
			if(i%j == 0){
				flag = true;
			}
		}
		if(!flag && i!=1){
			sum += i;
			if(low>i){
				low = i;
			}	
		}
		flag = false;
	}
	if(low == 10001){
		cout << "-1";
	} else {
		cout << sum << "\n" << low;
	}
	
	return 0;
}
