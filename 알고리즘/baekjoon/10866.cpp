#include <bits/stdc++.h>
using namespace std;

deque<string> dq;

int main(){
	int N;
	int count;
    string s;
    cin >> N;
	int k = N+1;
    while(getline(cin,s) && k--){
		if(s.find("push_back") != string::npos){
			count = 0;
			istringstream ss(s);
			string stringBuffer;
			
			while (getline(ss, stringBuffer, ' ')){
				if(count){
					dq.push_back(stringBuffer);
					break;
				}
			    count++;
			}		
		} else if(s.find("push_front") != string::npos){
			count = 0;
			istringstream ss(s);
			string stringBuffer;
			
			while (getline(ss, stringBuffer, ' ')){
				if(count){
					dq.push_front(stringBuffer);
					break;
				}
			    count++;
			}
		}
		if(s=="front"){
			if(dq.empty()){
				cout << "-1" << "\n";
				continue;
			}
			cout << dq.front() << "\n";
		} else if(s=="back"){
			if(dq.empty()){
				cout << "-1" << "\n";
				continue;
			}
			cout << dq.back() << "\n";
		} else if(s=="size"){
			cout << dq.size() << "\n";
		} else if(s=="empty"){
			cout << (dq.empty() ? "1" : "0") << "\n";
		} else if(s=="pop_front"){
			if(dq.empty()){
				cout << "-1" << "\n";
				continue;
			}
			cout << dq.front() << "\n";
			dq.pop_front();
		} else if(s=="pop_back"){
			if(dq.empty()){
				cout << "-1" << "\n";
				continue;
			}
			cout << dq.back() << "\n";
			dq.pop_back();
		}
		if(!k) break;
	}
    return 0;
}
