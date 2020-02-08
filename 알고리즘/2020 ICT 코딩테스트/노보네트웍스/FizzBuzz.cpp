#include <iostream>
using namespace std;

void FizzBuzz(int number){
	for(int i=1; i<=number; i++){
		if(i % 3 == 0 && i % 5 == 0){
			cout << "FizzBuzz" << "\n";
			continue;
		}
		else if(i % 3 == 0){
			cout << "Fizz" << "\n";
			continue;
		}
		else if(i % 5 == 0){
			cout << "Buzz" << "\n";
			continue;
		}
		cout << i << "\n";
	}
}
int main(){
	int n;
	cin >> n;
	FizzBuzz(n);	
	return 0;
}
