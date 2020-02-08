#include <iostream>
using namespace std;

bool IsAmstrong(int number){
	int one,two,thr;
	one = number / 100;
	two = (number % 100)/10;
	thr = (number % 100)%10;
	if(number == one*one*one + two*two*two + thr*thr*thr){
		return true;
	}else{
		return false;
	}
}
int main(){
	int n;
	cin >> n;
	if(IsAmstrong(n)){
		cout << "true";
	}else{
		cout << "false";
	}
	return 0;
}
