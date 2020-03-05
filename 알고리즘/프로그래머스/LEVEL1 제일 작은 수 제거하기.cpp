#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    if(arr.size() == 1){
        arr.clear();
        arr.push_back(-1);
        return arr;
    }
    int mini = *min_element(arr.begin(),arr.end());
    for(int i=0; i<arr.size(); i++){
        if(mini == arr[i]){
            arr.erase(arr.begin() + i);
        }
    }
    vector<int> answer(arr);
    return answer;
}