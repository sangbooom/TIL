#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    vector<char> upper{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    vector<char> lower{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int i=0; i<s.length(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            for(int j=0; j<upper.size(); j++){
                if(s[i] == upper[j]){
                    answer += upper[(j+n) % upper.size()];
                    break;
                }
            }
        } 
        else if(s[i] >= 'a' && s[i] <= 'z'){
            for(int j=0; j<lower.size(); j++){
                if(s[i] == lower[j]){
                    answer += lower[(j+n) % lower.size()];
                    break;
                }
            }
        }
        else{
            answer += s[i];
        }
    }
    return answer;
}