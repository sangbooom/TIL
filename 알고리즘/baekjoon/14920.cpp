#include <iostream>
using namespace std;

int main(){
	int n;
	int k=1;
	int c[100001]={0,};
	cin >> n;
	
	c[k] = n;
	while(c[k]!=1){
		if(c[k]%2==0){
			c[k+1] = c[k]/2;
			k++;
		}
		else if(c[k]%2==1){
			c[k+1] = 3*c[k]+1;
			k++;
		}
	}
	cout << k;
	return 0;
}
