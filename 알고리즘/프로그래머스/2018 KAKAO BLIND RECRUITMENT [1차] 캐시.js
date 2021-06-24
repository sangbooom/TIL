function solution(cacheSize, cities) {
    let answer = 0;
    const cache = [];
    let cacheCount = 0;
    const citiesLen = cities.length;
    let continueFlag = false;
    while(cities.length != 0){
        continueFlag = false;
        let target = cities.shift();
        for(let i=0; i<cache.length; i++){
            if(cache[i].city.toLowerCase() == target.toLowerCase()){
                answer += 1;
                continueFlag = true;
            }
        }
        if(continueFlag){
            continue;
        }
        if(cacheSize == cache.length && cacheSize > 0){
            let minIndex = Math.min(...cache.map(v => v.index))
            for(let i=0; i<cache.length; i++){
                if(cache[i].index === minIndex){
                    let targetIndex = cache.findIndex(v => v.index === cache[i].index);
                    cache.splice(targetIndex,1,{city: target, index: cacheCount++});
                    answer += 5;
                }
            }
        } else {
            cache.push({city: target, index: cacheCount++});
            answer += 5;
        }
    }
    return answer;
}