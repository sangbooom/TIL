vector<int> solution(vector<int> &A, int K) {
    if(A.size() == 0)
        return A;
    
    for(int i = 0 ; i < K ; i++){
        int t = A.back();
        A.pop_back();
        A.insert(A.begin(), t);
    }
    
    return A;
}