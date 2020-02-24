#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int number;
int k;
int a[1001];

void primeNumberSieve() { 
    for(int i=2;i<=number;i++) {
        a[i] = i;
    }
    for(int i=2;i<=number;i++) {
        if(a[i]==0) {
        	continue;	
		} 

        for(int j=i;j<=number; j+=i) {
            if(a[j]==0){
            	continue;
			}
			a[j] = 0;
            v.push_back(j);
        }
    }
}

int main() {
	cin >> number >> k; 
    primeNumberSieve();
    cout << v[k-1];
    return 0;
}
