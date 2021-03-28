function solution(A) {
    A.sort((a,b) => b-a);
    if(A[0] < 0){
        return A[0] * A[1] * A[2];
    } else {
        if(A[0] * A[1] < A[A.length-1] * A[A.length-2]){
            return A[A.length-1] * A[A.length-2] * A[0];
        } else {
            if(A[1] * A[2] < A[A.length-1] * A[A.length-2]){
                return A[A.length-1] * A[A.length-2] * A[0];
            }
            return A[0] * A[1] * A[2];
        }
    }
}