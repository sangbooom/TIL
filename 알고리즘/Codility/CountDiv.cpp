// O(B-A)
int solution(int A, int B, int K) {
    int count = 0;
    for(int i=A; i<=B; i++){
        if(i%K==0){
            count++;
        }
    }
    return count;
}

//O((B-A)/K)
int solution(int A, int B, int K) {
    int count = 0;
    for(int i=A; i<=B; i++){
        if(i%K==0){
            count++;
            i=i+K-1;
        }
    }
    return count;
}

//O(1)
int solution(int A, int B, int K) {
    int max_num = B/K;
    int min_num = A/K;
    if(A%K==0) max_num++;
    return max_num - min_num;
}