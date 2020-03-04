#include <vector>
#include <queue>
using namespace std;
 
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int currentWeight = 0;
    queue<int> count;
    queue<int> cross;
    
    while(1) {
        int size = cross.size();
        for (int i = 0; i < size; i++){
            int length = cross.front();
            cross.pop();
            if (length <= 1) {
                currentWeight -= count.front();
                count.pop();
                continue;
            }
            cross.push(length - 1);
        }
        if (truck_weights.size() > 0 && currentWeight + truck_weights[0] <= weight) {
            count.push(truck_weights[0]);
            currentWeight += truck_weights[0];
            cross.push(bridge_length);
            truck_weights.erase(truck_weights.begin());
        }
        answer++;
        if (truck_weights.size() == 0 && count.size() == 0)
            break;
    }
    return answer;
}