#include <bits/stdc++.h>

//O(N*M)으로 시간초과
vector<int> solution(int N, vector<int> &A) {
    vector<int> op(N,0);
    for(int i=1; i<=A.size(); i++){
        if(A[i-1] <= N && A[i-1] >= 1){
            op[A[i-1]-1]++;
        } else if(A[i-1] == N+1){
            int max_value = *max_element(op.begin(),op.end());
            for(int j=0; j<op.size(); j++){
                op[j] = max_value;
            }
        }
    }
    return op;
}


//O(N+M) 일줄 알았는데 O(N), 이유는 *max_element() 때문
#include <bits/stdc++.h>

vector<int> solution(int N, vector<int> &A) {
    int max_value = 0;
    vector<int> op(N,0);
    for(int i=1; i<=A.size(); i++){
        if(A[i-1] <= N && A[i-1] >= 1){
            if(op[A[i-1]-1] < max_value ){
                op[A[i-1]-1] = max_value;
            }
            op[A[i-1]-1]++;
        } else if(A[i-1] == N+1){
            max_value = *max_element(op.begin(),op.end());
        }
    }
    for(int j=0; j<op.size(); j++){
        if(op[j] < max_value){
            op[j] = max_value;
        }
    }
    return op;
}

//O(N+M)
#include <bits/stdc++.h>

vector<int> solution(int N, vector<int> &A) {
    int max_value = 0;
    int temp = 0;
    vector<int> op(N,0);
    for(int i=1; i<=A.size(); i++){
        if(A[i-1] <= N && A[i-1] >= 1){
            if(op[A[i-1]-1] < max_value ){
                op[A[i-1]-1] = max_value;
            }
            ++op[A[i-1]-1];
            temp = max(temp,op[A[i-1]-1]);            
        } else if(A[i-1] == N+1){
            max_value = temp;
        }
    }
    for(int j=0; j<op.size(); j++){
        if(op[j] < max_value){
            op[j] = max_value;
        }
    }
    return op;
}