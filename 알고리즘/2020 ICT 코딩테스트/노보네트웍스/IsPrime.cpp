#include <iostream>
using namespace std;

bool IsPrime(int number){
	if(number == 1){
		return false;
	}
	else if(number == 2 || number == 3){
		return true;
	}
	else if(number % 2 == 0|| number % 3 == 0){
		return false;
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	if(IsPrime(n)){
		cout << "true";
	} else{
		cout << "false";
	}
} 
