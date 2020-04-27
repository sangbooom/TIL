#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    int len = log10(n) +1;
    for(int i=0; i<len; i++){
        answer.push_back(n%10);
        n /= 10;
    }
    return answer;
}