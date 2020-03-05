#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int solution(int n)
{
    int answer = 0;
    int temp = n/10;
    int len= (int)(log10(n)+1);
    answer += n%10;
    for(int i=0; i<len; i++){
        answer += temp %10;
        temp = temp / 10;
    }
    return answer;
}