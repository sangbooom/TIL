#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//sort함수로 조지는게 시간절약

string solution(string s) {    
    string answer = "";
    sort(s.begin(), s.end(), greater<char>());
    return s;
}

string solution(string s) {    
    string answer = "";
    for(int i=0;i<s.size()-1;i++){
        for(int j=i+1;j<s.size();j++){
            if(s[i]<s[j]){
                swap(s[i],s[j]);
            }
        }
    }
    answer = s;
    return answer;
    
}