#include <bits/stdc++.h>

//O(N) or O(N * log(N)) 
int solution(vector<int> &A) {
    int N = A.size();
    vector<int> counter(N+1);

    for (int i = 0; i < N; i++){
        if (A[i] > 0 && A[i] <= N+1){
            counter[A[i]-1] = 1;
        }
    }
    for (int i = 0; i < N+1 ; i++){
        if (!(counter[i])) return i+1;
    }
    return -1;
}
