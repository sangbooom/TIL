#include <iostream>
#include <string>
using namespace std;
int main()
{ 
	int n; 
	int num= 665;
	int count=0;
	cin >> n;
	
	while(num++){
		string s = to_string(num); //"666"
		if(s.find("666") != -1){
			count++;
		}
		if(n == count){
			cout<< num;
			break;
		}
	}
	return 0;
}
