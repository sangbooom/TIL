## null
null에 대해서 기억해야 할 2가지 특징이 있다.   
null은 비어있거나 존재하지 않는 value를 나타낸다   
null은 할당되어야 존재할 수 있는 값이다.(기본적으로 주어질 일은 없다)   

간단한 예시를 보자. a에 null을 할당했다.
```js
let a = null
console.log(a)  // null
```
<br>

## undefined
undefined는 주로 선언된 변수지만 값 할당이 이루어지지 않았음을 나타낸다.   
예를 들면,
```js
let b
console.log(b)  // undefined
```
undefined를 직접 할당해 줄 수도 있다.
```js
let c = undefined
console.log(c)  // undefined
```
존재하지 않는 값을 찾게 되어도 undefined를 뱉는다.
```js
var d = {}
console.log(d.fake)  // undefined
```
<br>

## null과 undefined의 공통점

자바스크립트에는 6가지의 falsy value가 있다. null과 undefined 둘 다 falsy value에 속한다.

- false
- 0(zero)
- “”(빈 문자열)
- null
- undefined
- NaN(Not a Number)

또한, 자바스크립트에는 6가지의 primitive type이 있다. null과 undefined 둘 다 primitive type에 속한다.

- Boolean
- null
- undefined
- Number
- Symbol
- String

이를 제외한 나머지(object, function, array 등)는 모두 object다.   
하지만 null의 type을 체크하는 테스트를 진행해보면 아래처럼 object를 리턴한다.   
```js
let a = null
let b
console.log(typeof a)  // object
console.log(typeof b)  // undefined
```
이는 자바스크립트 초창기부터 있던 문제로, 초기 자바스크립트 구현에서 발생한 실수라고 본다.

<br>

## null과 undefined의 차이점
보다 실용적인 예시를 통해 알아보자.
```js
let logHi = (str = 'hi') => {
  console.log(str)
}
```
위 코드는 logHi라는 함수를 만든다. 이 함수는 1개의 파라미터를 받고, 기본값은 ‘hi’이다.
```js
logHi()  // hi
logHi('bye')  // bye
```
파라미터의 기본값이 있을 때, undefined는 그 값을 이용되는 반면 null은 그렇지 않다.
```js
logHi(undefined)  // hi
logHi(null)  // null
```
