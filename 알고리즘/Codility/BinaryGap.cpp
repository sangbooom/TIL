string s = ;

void tenConvertTwo(int num) {
    if (num == 0  num == 1) { 
        s += to_string(num); 
        return; 
    } 
    tenConvertTwo(num2); 
    s += to_string(num % 2); 
}

int solution(int N) {
    int answer = 0; 
    int value = 0;
    bool flag = false;
    tenConvertTwo(N);
    for(int i=0; is.size(); i++){
        if(flag){
            if(s[i] == '0'){
                value++;
            } else {
                answer = max(value,answer);
                value = 0;
                flag = false;
            }
        }
        if(s[i] == '1'){
            flag = true;
        }
    }
    return answer;
}
