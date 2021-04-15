// 삼각달팽이

function solution(n) {
    const answer = Array(n).fill(0).map((_, i) => Array(i+1).fill(0));
    let x = -1;
    let y = 0;
    let num = 1;
    for(let i=0; i<n; i++){
        for(let j=n-i; j>=1; j--){
            if(i % 3 == 0){
                answer[++x][y] = num++;
            } else if(i % 3 == 1){
                answer[x][++y] = num++;
            } else if(i % 3 == 2){
                answer[--x][--y] = num++;
            }
        }
    }
    return answer.flat();
}

// 이진변환 반복하기

function solution(s) {
    const result = Array(2).fill(0);
    let answer = s
    let s_del0 = s.replace(/0/gi,"")
    while(answer != "1"){
        s_del0 = answer.replace(/0/gi,"");
        result[1] += (answer.length - s_del0.length);
        answer = s_del0;
        answer = answer.length.toString(2);
        result[0]++;
    }
    
    return result;
}

// 코드챌린지

Array(a.length).fill(a).map((t,i) => {
    t = a.substr(i+1,a.length);
    t += a.substr(0,i+1);
    return t; 
})

for
