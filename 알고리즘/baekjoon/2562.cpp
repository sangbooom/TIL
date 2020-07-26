#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[9] = {0};
	int max_value = -999;
	int index = 1;
	for(int i=1; i<10; i++){
		cin >> arr[i];
	}
	for(int i=1; i<10; i++){
		if(max_value < arr[i]){
			max_value = arr[i];
		}
	}
	for(int i=1; i<10; i++){
		if(max_value == arr[i]){
			cout << max_value << "\n" << index;
			break;
		}
		index++;
	}
	return 0;
}
