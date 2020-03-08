#include <string>
#include <vector>
using namespace std;

int solution(int num) {
    int answer = 0;
    int n=0;
    while(num != 1){
       if(num % 2 == 0){
          num /= 2;
        }
        else if(num % 2 == 1){
          num = (num*3)+1;
        }
        answer++;
        n++;
        if(n == 500){
            answer = -1;
            break;
        }
    }
    
    return answer;
}