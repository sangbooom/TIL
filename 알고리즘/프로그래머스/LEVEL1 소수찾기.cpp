#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<bool> prime(n+1);
    int answer = 0;
    for(int i=2; i<=n; i++){
        if(!prime[i]){
            answer++;
        } 
        for(int j=i*2; j<=n; j+=i){
            prime[j] = 1;
        }
    }
    return answer;
}