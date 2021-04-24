# script 태그
일반적으로 `<script>`는 html의 <head>요소 안에 작성합니다.  
`<script>`를 <head>에 작성하면 css 등 외부로부터 불러오는 리소스 파일을 한 군데에서 관리할 수 있는 장점이 있습니다.
```html
<!doctype html>
<html>
  <title>title</title>
  <link href="stylesheet.css" rel="stylesheet" type="text/css">
  <script scr="script.js"></script>
  <body>
    ...
  </body>
</html>
```
**하지만 위의 방식은 브라우저가 html 렌더링에 영향을 줍니다.**   
  
브라우저는 HTML 마크업을 파싱하여 DOM 트리를 구성하고 페이지를 렌더링합니다.      
HTML을 파싱하는 동안 브라우저는 `<script>`를 만날 때 마다 파싱을 중지하고 스크립트를 로드하고 실행하게 됩니다.    
이 과정에서 외부 스크립트를 로드하는 네트워크 왕복 시간, 자바스크립트를 실행하는 시간만큼 렌더링이 지연됩니다.     
```html
<!doctype html>
<html>
  <title>title</title>
  <style>
    /* css */
  </style>
  <script type="text/javascript">
    /* inline js */
  </script>  
  <body>
    ...
  </body>
</html>
```
위 같이 작성하면, 외부스크립트를 로드하는 요청이 없어져서 빠르게 렌더링을 할 수 있습니다.    
하지만 스크립트를 실행하는 동안 `<body>`의 내용은 사용자에게 보이지 않습니다.    
스크립트의 내용이 길어질수록 렌더링은 점점 늦어지게 됩니다.   

스크립트가 렌더링을 막는 것을 방지하기 위해 최근 웹에서는 일반적으로 아래와 같이 스크립트를 `<body>`의 맨 아래에 삽입합니다.    
```html
<!doctype html>
<html>
  <title>title</title>
  <link href="stylesheet.css" rel="stylesheet" type="text/css">
  <body>
    ...
    <script scr="script.js"></script>
  </body>
</html>
```
위와 같이 작성하면 body의 내용이 렌더링 된 이후에 script를 만나 로드하고 실행하기 때문에 위의 코드보다 렌더링 타이밍이 더 빨라지게 됩니다.   
스크립트가 DOM을 조작하는 내용을 포함하고 있다면, 스크립트가 렌더링 된 DOM에 접근할 수 있음으로 아래 위치에 작성하는 것이 좋습니다.   

# async
async 속성을 가진 스크립트는 `<script>, <script defer>`와 마찬가지로 브라우저가 해당 요소를 만났을 때 외부 스크립트 다운로드를 시작합니다.    
defer와 마찬가지로 다운로드 중에 HTML 파싱을 막지 않지만 다운로드가 완료되면 즉시 실행하고 실행하는 동안 브라우저는 HTML 파싱을 멈춥니다.    
async속성의 스크립트에는 DOM을 조작하지 않으며 앞뒤에 로드되고 실행될 스크립트와 의존성이 없는 코드만 포함하는 것이 좋습니다.  
async속성 역시 일부 브라우저에서 지원하지 않음으로 주의해야합니다.   

```html
script ASYNC src="aphid.js"></script>
<script src="bmovie.js></script>
<script src="seaserpent.js"></script>
<img src="deejay.gif">
<img src="elope.gif">
```
```
aphid.js        ====xxx
bmovie.js       =====  xx
seaserpent.js   =====    xx
deejay.gif      =====
elope.gif       =====
DOM Interactive            *
image render               *
```
> 여기서 ==는 다운로드하는 작업을 의미하고, xx는 스크립트 파싱과 실행을 의미한다.    
> DOM interactive는 브라우저가 HTML 구문 분석을 완효한 후에 실행된다.

aphid가 async였지만, 다운로드가 먼저 되었기 때문에 다른 스크립트 실행을 차단하고 먼저 실행되었다.   
다시말해, **async는 다운로드 된 뒤에 모든 동기 스크립트 실행을 차단해 버린다.**

# defer
`<script>`는 다운로드와 실행이 순차적으로 진행되는 것과 달리 defer 속성을 가진 스크립트는 브라우저가 `<script defer>`를 만났을 때 다운로드를 시작하지만,
html 파싱을 막지 않고 `</html>`을 만났을 때 실행됩니다. (DOMContentLoaded 이벤트 이전에 실행됩니다)  
스크립트를 `<body>`태그의 맨 마지막 줄에 작성하는 것과 같이 스크립트가 DOM을 조작하는 내용을 포함하는 것이 좋습니다.   
하지만 일부 브라우저에서는 defer속성을 지원하지 않음으로 주의해야합니다.   

```html
<script DEFER src="aphid.js"></script>
<script src="bmovie.js></script>
<script src="seaserpent.js"></script>
<img src="deejay.gif">
<img src="elope.gif">
```
```html
aphid.js        ====     xxx
bmovie.js       =====xx
seaserpent.js   =====  xx
deejay.gif      =====
elope.gif       =====
DOM Interactive          *
image render             *
```
> 여기서 ==는 다운로드하는 작업을 의미하고, xx는 스크립트 파싱과 실행을 의미한다.    
> DOM interactive는 브라우저가 HTML 구문 분석을 완효한 후에 실행된다.
> 
defer는 DOM이 상호작용이 가능해지는 시점에 실행된다.   
**defer는 다운로드가 먼저 되었음에도 다른 동기 스크립트가 실행된 이후에 실행**된 것을 볼 수 있다.

<br/>
<br/>

# defer를 더 선호해야하는 이유
defer는 항상 async와 동시에, 또는 그 이후에 스크립트 실행을 발생시킨다.   
아마도 스크립트 중에서도 덜 중요한 것들을 defer나 async로 만들 것이다.   
따라서 기본 렌더링 시간 외에 실행 될 수 있도록 defer로 하는 것이 좋다.   
defer는 동기 스크립트를 차단할 수 없지만, async는 스크립트 다운로드에 따라 차단할 수도 있다.   
동기 스크립트는 일반적으로 페이지에서 중요한 내용을 담고 있으므로, 다른 작업이 방해하지 않도록 defer를 쓰는 것이 좋다.  
<br/>

## 결론

![image](https://user-images.githubusercontent.com/43921054/115960352-da634080-a54b-11eb-9ae3-63bdf91754b6.png)   

> 출처 : https://kimlog.me/js/2019-10-05-script/   

### 참고
- https://yceffort.kr/2020/10/defer-than-async
- https://ko.javascript.info/script-async-defer
- https://kimlog.me/js/2019-10-05-script/
