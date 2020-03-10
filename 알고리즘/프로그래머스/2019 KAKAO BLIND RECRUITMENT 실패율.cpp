#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//시간초과,, pair<double,int> 로 풀기
vector<int> solution(int N, vector<int> stages) {
    vector<int> bunsu;
    for(int i=1; i<=N; i++){
        int son = 0;
        int mom = stages.size();
        for(int j=0; j<mom; j++){
            if(i == stages[j]){
                son++;
                stages.erase(stages.begin()+j);
            }
        }
        bunsu.push_back((double)son/mom);
    }
    vector<int> answer(bunsu);
    sort(answer.begin(),answer.end());
    for(int i=0; i<N; i++){
        int k=1;
        for(int j=0; j<N; j++){
            if(answer[i] == bunsu[j]){
                answer[i] = k;
            }
            k++;
        }
    }
    return answer;
}