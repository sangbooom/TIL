#include <string>
#include <vector>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if(a <= b){
        while(a!=b+1){
            answer += a;
            a++;
        }        
    } else {
        while(a!=b-1){
            answer += a;
            a--;
        }
    }
    return answer;
}