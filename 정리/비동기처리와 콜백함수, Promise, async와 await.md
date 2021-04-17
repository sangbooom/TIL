## 콜백함수가 왜 필요하나?
콜백함수가 함수의 인자로 전달되는 함수이며, 전달받은 함수내에서 실행된다는 것은 알겠습니다.

그렇다면 왜 콜백함수를 사용하는 것일까?


```js
function getData() {
    var tableData;
    $.get('https://domain.com/products/1', function (response) {
        tableData = response;
    });
    return tableData;
}
 
console.log(getData()); // undefined
```

위와 같은 ajax 코드가 있다고 생각해 봅시다. 

getData 함수는 $.get 메소들를 통하여 'https://domain.com/products/1' 에서 데이터를 수신해 옵니다.

수신한 데이터를 2번째 줄에서 정의한 tableData 변수에 할당하고, tableData 를 리턴합니다.

코드의 9번째 줄에서 getData 함수를 실행하면 'https://domain.com/products/1' 를 통해 받아온 데이터가 콘솔에 찍힐것이라 예상되지만, 콘솔에는 undefined 가 찍힙니다.



이는 $.get 메소드는 비동기적 메소드이기 때문에 발생하는 문제입니다.

코드가 실행되다 $.get 메소드를 만나면 $.get 메소드를 다른 프로그램에 위임하고 다음코드인 tableData 를 리턴해 버립니다. 즉, tableData 에는 아무런 값도 할당되지 않은 채로 함수가 끝나버리므로 콘솔창에는 undefined 가 찍히는 것입니다.



이러한 문제를 콜백함수를 통해 해결할 수 있습니다.

```js
function getData(callbackFunc) {
    $.get('https://domain.com/products/1', function (response) {
        callbackFunc(response); // 서버에서 받은 데이터 response를 callbackFunc() 함수에 넘겨줌
    });
}
 
getData(function (tableData) {
    console.log(tableData); // $.get()의 response 값이 tableData에 전달됨
});
```

위의 코드에서는 getDate 함수를 정의 할 때 파라메터로 callback 함수를 주었습니다.

그리고 파라메터로 지정된 콜백함수는 $.get 메소드 안에서 실행 되었습니다.

$.get 메소드는 서버에서 받은 데이터를 콜백함수의 인자로 넘겨줍니다.



7번째 줄에서 getData 를 실행할 때 인자로 익명함수를 주었는데, 그 익명함수는 전달받은 인자를 콘솔에 표시하는 함수입니다.

(콜백함수를 실행단계에서 정의)



콜백함수를 통해 $.get 메소드의 비동기적 처리로 인한 문제를 해결할 수 있게 되었습니다.



즉, 콜백함수를 사용하기 이전의 코드는 데이터가 준비되지 않은 상태에서 함수가 끝나기 때문에 원하는 대로 동작하지 못하지만, 콜백함수를 사용하면 필요한 데이터가 다 준비된 시점에서만 원하는 동작을 수행하도록 할 수 있습니다. 
