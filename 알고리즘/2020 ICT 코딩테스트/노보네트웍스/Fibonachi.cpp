#include <iostream>
using namespace std;
//Àç±Í·ÎÇ®±â
int sum = 0;
int Fibonachi(int number){
	if(number == 0 || number == 1){
		return true;
	}
	return Fibonachi(number-1) + Fibonachi(number-2);
}
int main(){
	int n;
	cin >> n;
	cout << Fibonachi(n);
	return 0;
}


