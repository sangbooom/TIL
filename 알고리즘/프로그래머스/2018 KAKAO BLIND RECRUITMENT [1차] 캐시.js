function solution(cacheSize, cities) {
    let answer = 0;
    const cache = [];
    let cacheCount = 0;
    const citiesLen = cities.length;
    let continueFlag = false;
    while(cities.length != 0){
        continueFlag = false;
        let target = cities.shift();
        if(cacheSize == 0){
            answer += 5;
            continue;
        }
        for(let i=0; i<cache.length; i++){
            if(cache[i].toLowerCase() == target.toLowerCase()){
                cache.splice(i,1);
                cache.push(target);
                answer += 1;
                continueFlag = true;
                break;
            }
        }
        if(continueFlag){
            continue;
        }
        if(cacheSize == cache.length && cacheSize != 0){
            cache.shift();
            cache.push(target);
            answer += 5;
        } else {
            cache.push(target);
            answer += 5;
        }
    }
    return answer;
}