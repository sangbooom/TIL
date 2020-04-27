#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a, string b){
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    for(auto n : numbers){
        temp.push_back(to_string(n));
    }
    sort(temp.begin(),temp.end(),cmp);
    if(temp[0] == "0") return "0";
    for(auto n : temp){
        answer += n;
    }
    return answer;
}
