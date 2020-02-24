#include <iostream>
using namespace std;

int main(){
	int min=1000000;
	int max=-1000000;
	int n;
	
	cin >> n;
	int tmp[n+1];
	
	for(int i=0; i<n; i++){
		cin>> tmp[i];
		if(min > tmp[i]){
			min = tmp[i];
		}
		if(max < tmp[i]){
			max = tmp[i];
		}
	}
	cout << min<<" "<< max;
	return 0;
}
