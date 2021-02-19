## this 
- 일반 함수는 함수를 선언할 때 this에 바인딩할 객체가 정적으로 결정되는 것이 아니고, 함수를 호출할 때 함수가 어떻게 호출되었는지에 따라 this에 바인딩할 객체가 동적으로 결정된다고 하였다.

화살표 함수는 함수를 선언할 때 this에 바인딩할 객체가 정적으로 결정된다. 동적으로 결정되는 일반 함수와는 달리 **화살표 함수의 this는 언제나 상위 스코프의 this를 가리킨다.** 이를 **Lexical this**라 한다.

## 클로저
- 클로저는 **자신이 생성될 떄의 환경(Lexical environment)을 기억하는 함수**이다.   
즉, 외부함수가 이미 반환되었어도 외부함수 내의 변수는 이를 필요로 하는 내부함수가 하나 이상 존재하는 경우 계속 유지된다.   
이때 내부함수가 외부함수에 있는 변수의 복사본이 아니라 실제 변수에 접근한다는 것에 주의 해야한다.

```js
function getClosure(){
    var text = "hello"
    return () => {
        return text;
    }
}

var clousure = getClosure();
console.log(closure());
```

## 클로저는 언제 유용하게 쓰이는가?
### 상태 유지
- 클로저가 가장 유용하게 사용되는 상황은 **현재 상태를 기억하고 변경된 최신 상태를 유지하는 것**이다. 

자바스크립트 클로저 개념을 이용해 구현한 useState는 다음과 같다.
```js
const useState = (initialState) => { 
    let value = initialState;
    const getter = () => value 
    // 클로저 
    const setter = next => (value = next) 
    // 클로저 

    return [getter, setter] 
} 

const [state, setState] = useState(0)
```

## useState()에서 모든 상태값을 관리하면 안될까?
- 안된다. 함수는 상태를 저장하지 않는다. 바로 이게 **클로저가 필요한 이유**이다.