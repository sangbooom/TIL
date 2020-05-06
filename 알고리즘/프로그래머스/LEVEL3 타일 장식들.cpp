//dp 
//풀이 1 
#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    vector<long long> v(N+1);
    v[1] = 4;
    v[2] = 6;
    for(int i=3; i<=N; i++){
        v[i] = v[i-1] + v[i-2];
    }
    answer += v[N];
    return answer;
} 

//풀이 2
#include <string>
#include <vector>
using namespace std;

long long solution(int N) {
    long long x=1;
    long long y=1;
    for(int i=2; i<=N; i++){
        if(i%2){
            x+=y;
        } else {
            y+=x;
        }
    }
    return 2*(x+y);
} 
