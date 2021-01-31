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

//그다음날 풀이

#include <bits/stdc++.h>
int cnt[1000001];
int solution(vector<int> &A) {
    // vector<int> count(A.size(),0);
    for(int i=0; i<A.size(); i++){
        if(A[i] < 0) continue;
        if(!cnt[A[i]]) cnt[A[i]]++;
    }
    
    for(int i=1; i<100001; i++){
        if(!cnt[i]){
            return i;
        }
    }
} 
