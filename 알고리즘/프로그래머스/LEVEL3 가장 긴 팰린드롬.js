function solution(s){
    let answer = 1;
    let result = 0;
    let count_even; let count_odd; let left; let right;
    let isEven; let isOdd;
    for(let i=1; i<s.length-1; i++){
        left = i-1; right = i+1; count_odd = 1; count_even = 0;
        isEven = false; isOdd = false;
        while(left >= 0 && right <= s.length){
            if(s[left] == s[right-1]){
                count_even += 2;
            } else {
                isEven = true;
            }
            
            if(s[left--] == s[right++]){
                count_odd += 2;
            } else {
                isOdd = true;
            }
            
            if(isEven && isOdd) break;
        }
        result = (count_odd > count_even ? count_odd : count_even);
        answer = answer > result ? answer : result;
    }

    return answer;
}
