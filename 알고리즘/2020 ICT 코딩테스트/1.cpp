#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int num,pos,count;
	vector <int> speed;
	count=0;
	
	cin >> num;
	for(int i=0; i<num; i++){
		int n;
		cin >> n;
		speed.push_back(n);
	}
	cin >> pos;
	for(int i=0; i<=pos-1; i++){
		if(speed[pos] < speed[i]){
			count++;
		}	
	}
	for(int i=pos+1; i<num; i++){
		if(speed[pos] > speed[i]){
			count++;
		}
	}
	cout << count;

	return 0;
}
