#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    for(int i=0; i<heights.size(); i++){
        if(i == 0){
            answer.push_back(0);
            continue;
        }
        for(int j=1; j<=i; j++){
            if(heights[i-j] > heights[i]){
                answer.push_back(i-j+1);
                break;
            }
        }
        if(i == answer.size()){
            answer.push_back(0);
        }
    }
    return answer;
}