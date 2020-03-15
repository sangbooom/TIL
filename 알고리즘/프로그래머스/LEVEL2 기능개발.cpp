#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i=0; i<progresses.size(); i++){
        if(progresses[i] + (100 - progresses[i])/speeds[i] * speeds[i] < 100){
            q.push(((100 - progresses[i])/speeds[i]) + 1);
            continue;
        }
        q.push((100 - progresses[i])/speeds[i]);
    }
    while(!q.empty()){
        int k = q.front();
        q.pop();
        int q_size = q.size();
        int cnt = 1;
        if(q_size == 0){
            answer.push_back(cnt);
            break;
        }
        for(int j=0; j<=q_size-1; j++){
            if(k >= q.front()){
                q.pop();
                cnt++;
            }
            if(k < q.front()){
                answer.push_back(cnt);
                break;
            }
        }
        if(q.size() == 0){
            answer.push_back(cnt);
            break;
        }
    }
    return answer;
}