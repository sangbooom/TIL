## 비동기 처리

자바스크립트의 비동기 처리란 특정 코드의 연산이 끝날때 까지 코드의 실행을 멈추지 않고 다음 코드를 먼저 실행하는 자바스크립트의 특성을 의미한다.

## 비동기 방식이란?

비동기 방식은 웹페이지를 리로드하지 않고 데이터를 불러오는 방식이며 Ajax를 통해서 서버에 요청을 한 후 멈추어 있는 것이 아니라 그 프로그램은 계속 돌아간다는 의미를 내포하고 있다.

### 비동기 방식의 장점

페이지 리로드의 경우 전체 리소스를 다시 불러와야하는데 이미지, 스크립트 , 기타 코드등을 모두 재요청할 경우 불필요한 리소스 낭비가 발생하게 되지만 비동기식 방식을 이용할 경우 **필요한 부분만 불러와 사용할 수 있으므로 매우 큰 장점이 있다.**

## 비동기 처리의 첫번째 사례, AJAX

AJAX란, JavaScript의 라이브러리중 하나이며 Asynchronous Javascript And Xml(비동기식 자바스크립트와 xml)의 약자이다. 브라우저가 가지고있는 XMLHttpRequest 객체를 이용해서 전체 페이지를 새로 고치지 않고도 페이지의 일부만을 위한 데이터를 로드하는 기법 이며 **JavaScript를 사용한 비동기 통신, 클라이언트와 서버간에 XML 데이터를 주고받는 기술**이다.

즉, 쉽게 말하자면 **자바스크립트를 통해서 서버에 데이터를 요청하는 것**이다.

```jsx
function getData() {
	var tableData;
	$.get('https://domain.com/products/1', function(response) {
		tableData = response;
	});
	return tableData;
}

console.log(getData());// undefined
```

$.get()로 데이터를 요청하고 받아올 때까지 기다려주지 않고 다음 코드인 return tableData;를 실행했기 때문입니다. 따라서, getData()의 결과 값은 초기 값을 설정하지 않은 tableData의 값 undefined를 출력합니다.

## AJAX로 할 수 있는 것

AJAX라는 네트워크 기술을 이용하여 **클라이언트에서 서버로 데이터를 요청**하고 그에 대한 **결과를 돌려받을 수 있다.**

### 클라이언트란?

서버에서 정보를 가져와서 사용자에게 보여줄 수 있고 **사용자와 상호작용할 수 있는 소프트웨어**를 일컫는다.Ex) 웹브라우저, 핸드폰 어플리케이션 등...

### 서버란?

네트워크 상에서 접근할 수 있는 프로그램으로서 **어떤 자료들에 대한 관리나 접근을 제어해주는 프로그램**을 말한다. 서버는 일반적으로 사용자가 직접적으로 사용하지 않는다.

## AJAX를 사용하는 이유

단순하게 WEB화면에서 무언가 부르거나 데이터를 조회하고 싶을 경우, 페이지 전체를 새로고침하지 않기 위해 사용한다고 볼 수 있다.

기본적으로 HTTP 프로토콜은 클라이언트쪽에서 Request를 보내고 서버쪽에서 Response를 받으면 이어졌던 연결이 끊기게 되어있다. 그래서 화면의 내용을 갱신하기 위해서는 다시 request를 하고 response를 하며 페이지 전체를 갱신하게 된다. 하지만 이렇게 할 경우, 엄청난 자원낭비와 시간낭비를 초래하고 말 것이다.

AJAX는 HTML 페이지 전체가 아닌 일부분만 갱신할 수 있도록 XMLHttpRequest객체를 통해 서버에 request한다. 이 경우, **JSON이나 XML형태로 필요한 데이터만 받아 갱신하기 때문에 그만큼의 자원과 시간을 아낄 수 있다.**

## AJAX의 장단점

### 1. AJAX의 장점

- 웹페이지의 속도향상
- 서버의 처리가 완료될 때까지 기다리지 않고 처리가 가능하다.
- 서버에서 Data만 전송하면 되므로 전체적인 코딩의 양이 줄어든다.
- 기존 웹에서는 불가능했던 다양한 UI를 가능하게 해준다. ( Flickr의 경우, 사진의 제목이나 태그를 페이지의 리로드 없이 수정할 수 있다.)

### 2. AJAX의 단점

- 히스토리 관리가 되지 않는다.
- 페이지 이동없는 통신으로 인한 보안상의 문제가 있다.
- 연속으로 데이터를 요청하면 서버 부하가 증가할 수 있다.
- XMLHttpRequest를 통해 통신하는 경우, 사용자에게 아무런 진행 정보가 주어지지 않는다. (요청이 완료되지 않았는데 사용자가 페이지를 떠나거나 오작동할 우려가 발생하게 된다.)
- AJAX를 쓸 수 없는 브라우저에 대한 문제 이슈가 있다.
- HTTP 클라이언트의 기능이 한정되어 있다.
- 지원하는 Charset이 한정되어 있다.
- Script로 작성되므로 디버깅이 용이하지 않다.
- 동일-출처 정책으로 인하여 다른 도메인과는 통신이 불가능하다. (Cross-Domain문제)

## 비동기 처리의 두번째 사례, setTimeOut()

또 다른 비동기 처리 사례는 setTimeout()이 있다.

 setTimeout()은 Web API의 한 종류다. 코드를 바로 실행하지 않고 지정한 시간만큼 기다렸다가 로직을 실행한다.

```jsx
// #1
console.log('Hello');
// #2
setTimeout(function() {
	console.log('Bye');
}, 3000);
// #3
console.log('Hello Again');
```

## 콜백함수로 비동기 처리 방식의 문제점 해결하기

```jsx
function getData(callbackFunc) {
	$.get('https://domain.com/products/1', function(response) {
		callbackFunc(response); // 서버에서 받은 데이터 response를 callbackFunc() 함수에 넘겨줌
	});
}

getData(function(tableData) {
	console.log(tableData); // $.get()의 response 값이 tableData에 전달됨
});
```

이렇게 콜백 함수를 사용하면 특정 로직이 끝났을 때 원하는 동작을 실행시킬 수 있습니다.

## 콜백 지옥 (Callback hell)

콜백 지옥은 비동기 처리 로직을 위해 콜백 함수를 연속해서 사용할 때 발생하는 문제입니다. 아마 아래와 같은 코드를 본 적이 있을 겁니다.

```jsx
$.get('url', function(response) {
	parseValue(response, function(id) {
		auth(id, function(result) {
			display(result, function(text) {
				console.log(text);
			});
		});
	});
});
```

웹 서비스를 개발하다 보면 서버에서 데이터를 받아와 화면에 표시하기까지 인코딩, 사용자 인증 등을 처리해야 하는 경우가 있습니다. 

만약 이 모든 과정을 비동기로 처리해야 한다고 하면 위와 같이 콜백 안에 콜백을 계속 무는 형식으로 코딩을 하게 됩니다. 이러한 코드 구조는 가독성도 떨어지고 로직을 변경하기도 어렵습니다. 

이와 같은 코드 구조를 콜백 지옥이라고 합니다.

## 콜백 지옥을 해결하는 방법

일반적으로 콜백 지옥을 해결하는 방법에는 Promise나 Async를 사용하는 방법이 있습니다. 만약 코딩 패턴으로만 콜백 지옥을 해결하려면 아래와 같이 각 콜백 함수를 분리해주면 됩니다.

```jsx
function parseValueDone(id) {
	auth(id, authDone);
}
function authDone(result) {
	display(result, displayDone);
}
function displayDone(text) {
	console.log(text);
}
$.get('url', function(response) {
	parseValue(response, parseValueDone);
});
```

위 코드는 앞의 콜백 지옥 예시를 개선한 코드다.

위와 같은 코딩 패턴으로도 콜백 지옥을 해결할 수 있지만 Promise나 Async를 이용하면 더 편하게 구현할 수 있습니다.

또한, 콜백 함수는 다른 코드의 인자로 넘겨줌으로써 제어권 또한 위임한 함수이다.**즉, 콜백 함수 호출 시점의 권한이 개발자에게 있는 것이 아니라제어권을 넘겨받은 코드에게 있다는 것이다.** 좀 추상적인 의미로, 우리는 수동적으로 자세로 해당 콜백 함수의 호출을 지켜볼 수 밖에 없다.

다행히도 ES6에서 도입된 `Promise` 덕분에 이러한 비동기 프로그래밍의 난관을 해결해주었다.

# Promise

프로미스는 **자바스크립트 비동기 처리에 사용되는 객체**이다. 

미래에 어떤 종류의 결과가 반환됨을 promise (약속) 해주는 객체 이다!!

Promise 객체는 비동기 작업이 맞이할 미래의 완료 또는 실패와 그 결과 값을 나타냅니다.

> 출저 - MDN

## Point of Promise

흔히 프로미스의 장점으로는 콜백 함수를 통한 비동기 처리시 발생하는 **콜백 지옥**을 해결하는 것으로만 초점이 맞추어져있는데, 그보다 중요한 2가지 포인트가 있다.

- return value를 이용할 수 있다는 점
- error handling이 동기식 코드와 유사하게 쓰일 수 있다는 점

이 2가지가 프로미스의 핵심이라고 한다.

기존 비동기 세상(콜백 함수를 통한 비동기 처리)에서는 `return`값은 아무런 의미를 갖지 않는다.왜냐하면 해당 함수 실행문 안에서 또 다른 함수가 실행되고 또 다른 함수가 실행되는 방식이기 때문이다. 그래서 `return`된 값으로 우리가 뭘 다룰 틈도 없이, 비동기 처리가 이루어진다.

하지만 Promise를 이용할 경우, `return`값 가지고 있는 프로미스 객체가 우리 손에 쥐어지기 때문에동기코드와 마찬가지로, 그 값을 변수에 할당하거나, 다양한 메소드를 사용하는 것과 같이 자유로운 추가 작업이 가능하게 되었다.

또 기존 비동기 세상(콜백 함수를 통한 비동기 처리)에서는 모든 콜백함수에서 각각 에러 핸들링을 해줘야했다.하지만 마찬가지로 Promise를 이용할 경우 `then`, `catch`등을 통해 에러에 대한 대처가 훨씬 간결해졌고, 이는 동기 방식의 `try{} catch{}` 구문과 흐름이 매우 유사하다.

**결론적으로, Promise의 포인트는비동기 흐름을 동기적 흐름과 유사하게 만들어주었다는 것에 초점이 있다고 이해했다.**

## async/await

```jsx
async function 함수명() {
  await 비동기_처리_메서드_명();
}
```

## async

먼저 비동기 함수를 async function으로 만들기 위하여 function()앞에 async keyword를 추가합니다.

async function()은 await 키워드가 비동기 코드를 호출할 수 있게 해주는 함수 입니다.

`async` 함수를 실행하게 되면 무조건 `Promise` 객체가 반환된다.`async` 함수 내에서 `return`은 반환된 `Promise` 객체의 결과(resolve)값이다.

```jsx
async function name() {
  return "chan"; // async function 내부의 return값은 Promise 객체의 결과값을 반환한다.
}

const foo = name(); // 변수 foo에 프로미스 객체가 할당된다.
console.log(foo); // Promise {<fulfilled>: "chan"}
```

## await

`await` 키워드는 반드시 `async`함수 안에서만 사용할 수 있고,일반 함수에서 사용하면 SyntaxError를 발생시킨다.

`await` 키워드는 Promise 객체를 생성하는 함수 앞에 놓을 수 있고,자바스크립트가`await` 키워드를 만나게 되면 해당 함수가 Promise 상태가 이행될 때까지 기다렸다가,이행이 완료되면 그 결과 값을 반환하고 다음 코드를 실행한다.

```jsx
const promise = function () {
  return new Promise((resolve, reject) => {
    setTimeout(() => resolve("Done!!"), 2000);
  });
};
async function foo() {
  const result = await promise(); // 프라미스가 이행될 때까지 기다렸다가,
  console.log(result); // 완료 되면 하단의 코드가 이어서 실행됨
}

foo();
```
