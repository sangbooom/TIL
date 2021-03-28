function solution(A) {
    const l_discs = [];
    const r_discs = [];
    for(let index in A){
        l_discs.push(index - A[index]);
        r_discs.push(parseInt(index,10) + A[index]);
    }
    l_discs.sort((a,b) => a-b);
    r_discs.sort((a,b) => b-a);
    return r_discs[0] - l_discs[0] - 1;
}