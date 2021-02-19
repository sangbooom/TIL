## useState의 비동기적 속성과 batching
- 리액트에서 setState를 사용하여 상태를 업데이트할 경우, 업데이트 된 상태는 즉시 반영되지 않는다. setState는 비동기적으로 작동하기 때문에

- 즉, 리렌더링이 된 후에야 비로소 업데이트된 state가 반영된다. ( state 변경 - 리렌더링 - state 반영 )

- 리액트의 state를 업데이트하는 데있어서, 비동기적으로 작동하는 속성은 여러개의 state를 다룰 때 퍼포먼스측면에서 유리하다. 동기적으로 작동했다면 state1 업데이트 - state2 업데이트... 이런식으로 하나씩 업데이트가 될테니까

- 여러 state를 동시에 업데이트하는 경우, 리액트는 state를 batching하여 업데이트를 진행한다.    
(batching = 전달된 오브젝트들을 하나로 합치는 작업) **Batching**은 object composition 이라고도 불린다.

자바스크립트 코드로 object composition을 살펴보면 아래와 같다.
```js
const singleObject = Object.assign({},
  objectFromSetState1,
  objectFromSetState2,
  objectFromSetState3
);
```
리액트의 batching 예제

```js
const [value, setValue] = useState(0);

setValue(value + 1);
setValue(value + 1);
setValue(value + 1);

// Expected value: 3
// Result value: 1
```

이러한 특성때문에 업데이트된 state를 즉시 반영해야 할 때, 우리는 useEffect()를 사용한다.

## 함수형 업데이트
- 이러한 비동기적인 방법을 해결하기 위해서 우리는 함수형 업데이트(functional update)를 사용할 수 있다. 즉 setState에 값을 그대로 전달하는 것이 아니라 함수를 전달하는 것이다.

```js
const [value, setValue] = useState(0);

setValue(prev => prev + 1);
setValue(prev => prev + 1);
setValue(prev => prev + 1);

// Expected value: 3
// Result value: 3
```

- 함수형 업데이트는 useCallback과 함께 props로 전될된 함수를 최적화할 때도 유용하게 사용될 수 있다. 예를 들어 handleClick함수가 자식 컴포넌트에게 props를 통해서 전달 될 경우, 우리는 useCallback을 사용해서 함수를 감싼다.
```js
const handleToggle = useCallback((): void => setIsClicked(!isClicked), [isClicked]);
```
- 하지만 이 경우, useCallback과 함께 사용을 하더라도 isClicked에 대한 의존성 배열을 가지게 된다. 이 때 아예 의존성을 없게 만들고 싶다면 함수형 업데이트를 사용할 수 있다.
```js
const handleToggle = useCallback((): void => setIsClicked(prev => !prev), []);
```