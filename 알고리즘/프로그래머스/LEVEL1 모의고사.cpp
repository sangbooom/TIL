#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> they(3);
    int num1[] = {1,2,3,4,5};
    int num2[] = {2,1,2,3,2,4,2,5};
    int num3[] = {3,3,1,1,2,2,4,4,5,5};
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == num1[i % 5]){
            they[0]++;
        }
        if(answers[i] == num2[i % 8]){
            they[1]++;
        }
        if(answers[i] == num3[i % 10]){
            they[2]++;
        }
    }
    int max_answer = *max_element(they.begin(),they.end());
    for(int i=0; i<3; i++){
        if(they[i] == max_answer){
            answer.push_back(i+1);
        }
    }
    return answer;
}
