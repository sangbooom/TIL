#include <bits/stdc++.h>
using namespace std;

queue<string> q;

int main()
{
	int N;
	int count;
    string s;
    cin >> N;
	int k = N+1;
    while(getline(cin,s) && k--){
		if(s.find("push") != string::npos){
			count = 0;
			istringstream ss(s);
			string stringBuffer;
			
			while (getline(ss, stringBuffer, ' ')){
				if(count){
					q.push(stringBuffer);
					break;
				}
			    count++;
			}		
		}
		if(s=="front"){
			if(q.empty()){
				cout << "-1" << "\n";
				continue;
			}
			cout << q.front() << "\n";
		} else if(s=="back"){
			if(q.empty()){
				cout << "-1" << "\n";
				continue;
			}
			cout << q.back() << "\n";
		} else if(s=="size"){
			cout << q.size() << "\n";
		} else if(s=="empty"){
			cout << (q.empty() ? "1" : "0") << "\n";
		} else if(s=="pop"){
			if(q.empty()){
				cout << "-1" << "\n";
				continue;
			}
			cout << q.front() << "\n";
			q.pop();
		}
		if(!k) break;
	}
    return 0;
}
