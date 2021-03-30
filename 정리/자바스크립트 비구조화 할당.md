# 비구조화 할당
비구조화 할당은 객체와 배열의 값을 새로운 변수에 간단하게 대입시켜주는 문법이다.

'구조 분해'라고 부르기도 한다.

## 객체

```js
let person = {a: "철수", b: "유리", c: "맹구", d:"짱구"};
let {a, d} = person;
console.log(a); // 철수
console.log(d); // 짱구
``` 
- 위의 예제는 객체를 분해하여 a와 d 변수에 할당하는 예제입니다.

 
```js
let person = {a: "철수", b: "유리", c: "맹구", d:"짱구"};
let {a: x, b: y} = person;

console.log(x); // 철수
console.log(y); // 유리
``` 
- 객체를 분해하는 또 다른 예시   
   이대로 객체의 속성명과는 전혀 다른 이름의 변수에 할당할 수 있습니다.

 
```js
let person = {a: "철수", b: "유리", c: "맹구", d:"짱구"};
let {a:newA=1, n:newN=2} = person;

console.log(newA); // 철수
console.log(newN); // 2
```
- 기존 객체의 프로퍼티를 가져와서 새로운 변수명으로 할당하는 예제   
중괄호 안에서 정의된 값은 기본값에 해당됩니다   
만약 해당 값이 undefined로 값이 할당되지 않았다면 기본값을 할당하겠다는 의미입니다   
    
따라서 기존에 n은 존재하지 않는 객체 속성이기 때문에 2라는 값으로 새로 할당됩니다.   
   
## 배열
비구조화 할당은 배열에도 적용이 가능합니다.
```js
let personArray = ["철수", "유리", "맹구", "짱구"];
let [x, y, ...rest] = personArray;

console.log(x); // 철수
console.log(y); // 유리
console.log(rest); // Array(2) ["맹구", "짱구"] 
```
... 지시자를 활용하면 분해하고 남은 나머지 변수들을 따로 배열로 담을 수 있습니다.

 
```js
let [x=5, y=2] = [1];
console.log(x); // 1
console.log(y); // 2
```
첫번째 배열값을 분해했을 때, 분해한 값이 undefined라면 할당된 기본값을 대신 사용한다는 의미의 코드.

첫번째 기본값은 1로 할당되고 그에 매칭되는 변수는 x입니다.

 
```js
function getArray() {
    return [1, 2, 3, 4, 5];
}
[a, , , , e] = getArray();
console.log(a); // 1
console.log(e); // 5
```
함수에서 반환된 배열을 비구조화 할당하는 예제.

무시하고 싶은 배열 공간만큼 콤마를 사이에 두고 원하는 배열 요소만 가져올 수 있습니다.
