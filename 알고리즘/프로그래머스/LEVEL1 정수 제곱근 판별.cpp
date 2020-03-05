#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    if(n == pow((long long)sqrt(n),2)){
        answer = pow(sqrt(n)+1,2);
    } else {
        return -1;
    }
    
    return answer;
}