#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> n;
    for(int i=0; i<nums.size(); i++){
        n.insert(nums[i]);
    }
    if(n.size() >= (nums.size() / 2)){
        answer = nums.size() / 2;
    } else if(n.size() < (nums.size() / 2)){
        answer = n.size();
    }
    return answer;
}