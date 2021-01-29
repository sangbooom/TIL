#include <bits/stdc++.h>

int solution(vector<int> &A) {
    unsigned long len = A.size() + 1;
    unsigned long total = (len * (len + 1)) / 2;
    unsigned long sum = 0;
    for(int i=0; i<A.size(); i++){
        sum += A[i];
    }
    unsigned long res = total - sum;
    return (int)res;
}