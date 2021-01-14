/******************************
Author : 박상범
Language : C++
Problem : http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=523&sca=3010
******************************/

#include <iostream>
using namespace std;

unsigned long long int Babilonia(unsigned long long int input, double x) {
	for (int i = 0; i < 100000; i++) {
		x = (x + (input / x)) / 2;
	}
	return x;
}

int main() {
	int N;
	cin >> N;
	cout << Babilonia(N, 2) << endl;
	return 0;
}
