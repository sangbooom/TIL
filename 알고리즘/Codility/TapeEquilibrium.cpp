#include <bits/stdc++.h>

// 100% O(N)
int solution(vector<int> &A) {
    int left = 0;
    int right = 0;
    int sum = 0;
    int min_value = 987654321;
    for(int i : A) sum += i;
    for(int i=0; i<A.size()-1; i++){
        left += A[i];
        right = sum - left;
        min_value = min(min_value,abs(left - right));
    }
    return min_value;
}

// 65% O(N*N)
int solution(vector<int> &A) {
    int sum1 = 0;
    int sum2 = 0;
    int min_value = 987654321;
    for(int i=0; i<A.size()-1; i++){
        for(int j=0; j<i+1; j++){
            sum1 += A[j];
        }
        for(int j=i+1; j<A.size(); j++){
            sum2 += A[j];
        }
        min_value = min(min_value,abs(sum1 - sum2));
        sum1=0;
        sum2=0;
    }
    return min_value;
}