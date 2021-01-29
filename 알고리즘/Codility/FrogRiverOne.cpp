#include <bits/stdc++.h>

// O(N)
int visited[100001];
int solution(int X, vector<int> &A) {
    int count = 0;
    for(int i=0; i<A.size(); i++){
        if(A[i] <= X && !visited[A[i]]){
            visited[A[i]]++;
            count++;
        }
        if(X==count){
            return i;
        }
    }
    return -1;
}

(2, [2, 2, 2, 2, 2]) 