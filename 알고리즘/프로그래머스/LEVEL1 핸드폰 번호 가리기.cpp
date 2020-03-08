#include <string>
#include <vector>
using namespace std;

string solution(string phone_number) {
    string answer = "";
    //메모리 초과
    /*
    for(int i=0; i<=phone_number.size()-5; i++){
        answer += '*';
    }
    for(int i=phone_number.size()-4; i<=phone_number.size()-1; i++){
        answer += phone_number[i];
    }
    */
    vector<string> p_n(phone_number.size()-4,"*");
    for(int i=0; i<phone_number.size()-4; i++){
        answer += p_n[i]; 
    }
    for(int i=phone_number.size()-4; i<=phone_number.size()-1; i++){
        answer += phone_number[i];
    }
    return answer;
}