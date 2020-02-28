#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer(3);
    
    int num1 = 1;
    int num2[8] = {2,1,2,3,2,4,2,5};
    int num3[10] = {3,3,1,1,2,2,4,4,5,5};
    int n = 0;
    int k = 0;
    
    for(int i=0; i<answers.size(); i++){
        if(num1 % 6 == 0){
            num1 = 1;
        }
        else if(answers[i] == num1){
            answer[0]++;
        }
        num1++;
        if(n % 8 == 0){
            n = 0;
        }
        else if(answers[i] == num2[n]){
            answer[1]++;
        }
        n++;
        if(k % 10 == 0){
            k = 0;
        }
        else if(answers[i] == num2[k]){
            answer[2]++;
        }
        k++;
    }
    
    int max_answer = *max_element(answer.begin(),answer.end());
    int cnt = 3;
    for(int i=0; i<answer.size(); i++){
        if(answer[i] == max_answer){
            answer[i] = i+1;
            cnt--;
        }
    }
    for(int i=0; i<cnt; i++){
        answer.pop_back();
    }
    return answer;
}