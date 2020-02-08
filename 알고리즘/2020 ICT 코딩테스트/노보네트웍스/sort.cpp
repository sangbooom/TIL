#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// arr = [4,2,1,5,3]
//sort 내장함수 사용금지 
void sort(vector<int> arr){
	for(int i=0; i<arr.size()-1; i++){
		int tmp = i;
		for(int j=i+1; j<arr.size(); j++){
			if(arr[tmp] >= arr[j]){
				tmp = j;
			}
		}
		swap(arr[i],arr[tmp]);
	}
	for(int i=0; i<arr.size(); i++){
		cout<< arr[i] << " ";
	}
}
int main(){
	vector<int> arr;
	arr.push_back(4);
	arr.push_back(2);
	arr.push_back(1);
	arr.push_back(5);
	arr.push_back(3);
	sort(arr);
	return 0;
}
