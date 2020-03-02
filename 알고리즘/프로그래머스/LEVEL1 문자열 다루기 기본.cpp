#include <string>
#include <vector>
//#include <cctype>
using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.length() != 4 && s.length() != 6){
        return false;
    } 
    for(int i=0; i<s.length(); i++){
      //if(!isdigit(s[i]))
        if(s[i] > '9'){
           return false;  
        }
    } 
    return answer;
}