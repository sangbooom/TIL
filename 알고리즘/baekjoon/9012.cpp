#include <bits/stdc++.h>
using namespace std;
bool solution(string s)
{
    int count = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '('){
            ++count;
        } else if(s[i] == ')'){
            --count;
        }
        if(count < 0) return false;
    }
    if(count != 0){
        return false;
    }
    
    return true;
}
int main(){
	int T;
	string s;
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> s;
		cout << (solution(s) ? "YES" : "NO" )<< "\n";
	}
	return 0;
}
