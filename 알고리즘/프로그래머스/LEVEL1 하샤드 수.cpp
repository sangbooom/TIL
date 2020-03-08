#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool solution(int x) {
    bool answer = true;
    int len = log10(x);
    int num1=0;
    if(x >= 1 && x <= 10000){
        int num2 = x;
        for(int i=0; i<=len; i++){
            num1 += num2 % 10;
            num2 /= 10;
        }
        if(x % num1 == 0){
            return true;
        } else{
            return false;
        }
    }
    return false;
}
////////////////////////////// 더 줄여보자
#include <string>
#include <vector>
using namespace std;

bool solution(int x) {
    int num1=0;
    int num2 = x;
        while(num2 > 0){
            num1 += num2 % 10;
            num2 /= 10;
        }
        return x%num1 == 0 ? true : false; 
    return false;
}