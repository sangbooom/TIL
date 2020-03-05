#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    int x;
    for(int i=0; i<s.length(); i++){
        if(s[i] != ' '){
            if((i+x) % 2 == 0){
                if(s[i] >= 97 && s[i] <= 122){
                    answer += (s[i] - 32);
                    continue;
                }
                answer += s[i];
            } else{
                if(s[i] >= 65 && s[i] <= 90){
                    answer += (s[i] + 32); 
                    continue;
                }
                answer += s[i];
            } 
        } else {
            x = 0;
            if(i % 2 == 0){
                x = 1;
            }
            answer += ' ';   
        }
    }
    return answer;
}