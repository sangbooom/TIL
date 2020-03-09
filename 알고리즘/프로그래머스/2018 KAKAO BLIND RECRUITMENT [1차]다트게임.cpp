#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int cnt = -1;
    vector<int> n;
    vector<int> num;
    for(int i=0; i<dartResult.length(); i++){
        if(dartResult[i] >= 48 && dartResult[i] <= 57){
            if(dartResult[i] == 49 && dartResult[i+1] == 48){
                num.push_back(10);
                continue;
            }
            num.push_back(dartResult[i]-48);
            continue;
        }
        
        if(dartResult[i] == 'S'){
            ++cnt;
            n.push_back(pow(num[cnt],1));
        }
        if(dartResult[i] == 'D'){
            ++cnt;
            n.push_back(pow(num[cnt],2));
        }
        if(dartResult[i] == 'T'){
            ++cnt;
            n.push_back(pow(num[cnt],3));
        }
        if(dartResult[i] == '*'){
            n[cnt] *= 2;
            if(cnt > 0){
                n[cnt-1] *= 2;
            }
        }
        if(dartResult[i] == '#'){
            n[cnt] *= -1;
        }
    }
    for(int i=0; i<3; i++){
        answer += n[i];
    }
    return answer;
}