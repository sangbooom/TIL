# 정규 표현식

- 참고: https://youtu.be/t3M6toIflyQ

- 연습용 사이트: https://regexr.com/5ml92   
   
<br>
   
## 문법 정리

### Groups and ranges

| Chracter | 뜻                                     |
| -------- | -------------------------------------- |
| `\|`     | 또는                                   |
| `()`     | 그룹                                   |
| `[]`     | 문자셋, 괄호안의 어떤 문자든           |
| `[^]`    | 부정 문자셋, 괄호안의 어떤 문가 아닐때 |
| `(?:)`   | 찾지만 기억하지는 않음                 |

### Quantifiers

| Chracter    | 뜻                                  |
| ----------- | ----------------------------------- |
| `?`         | 없거나 있거나 (zero or one)         |
| `*`         | 없거나 있거나 많거나 (zero or more) |
| `+`         | 하나 또는 많이 (one or more)        |
| `{n}`       | n번 반복                            |
| `{min,}`    | 최소                                |
| `{min,max}` | 최소, 그리고 최대                   |

### Boundary-type

| Chracter | 뜻               |
| -------- | ---------------- |
| `\b`     | 단어 경계        |
| `\B`     | 단어 경계가 아님 |
| `^`      | 문장의 시작      |
| `$`      | 문장의 끝        |

### Character classes

| Chracter | 뜻                           |
| -------- | ---------------------------- |
| `\`      | 특수 문자가 아닌 문자        |
| `.`      | 어떤 글자 (줄바꿈 문자 제외) |
| `\d`     | digit 숫자                   |
| `\D`     | digit 숫자 아님              |
| `\w`     | word 문자                    |
| `\W`     | word 문자 아님               |
| `\s`     | space 공백                   |
| `\S`     | space 공백 아님              |

### Expressiong Flags
![image](https://user-images.githubusercontent.com/43921054/109905597-5e364480-7ce2-11eb-8c35-81a5eeb4d1e6.png)  
**case insensitive는 대소문자 구분안함**  

<br>

# 연습
### 전화번호

![image](https://user-images.githubusercontent.com/43921054/109906018-0fd57580-7ce3-11eb-8efd-19e5df13c6ff.png)
### 이메일

![image](https://user-images.githubusercontent.com/43921054/109906198-6773e100-7ce3-11eb-87c2-a6c4b370085d.png)
### url

![image](https://user-images.githubusercontent.com/43921054/109906300-95f1bc00-7ce3-11eb-80f1-f1484515f374.png)

<br>

### 괄호 안의 문자열 추출 
![image](https://user-images.githubusercontent.com/43921054/122645809-3961c200-d157-11eb-8a2f-b8be9c401401.png)
> 괄호는 찾되 정규식에 포함안하는 기능은 없나보다. 그 후에 split으로 처리했음.

## 활용하기
![image](https://user-images.githubusercontent.com/43921054/109906495-f3860880-7ce3-11eb-935f-239a44d3170c.png)

---

![image](https://user-images.githubusercontent.com/43921054/122645862-82b21180-d157-11eb-9b61-668a12b96551.png)

# 정규식의 중요성

> 정규식이 신입공채 웹개발포지션 코딩테스트에 종종 등장한다. 그때마다 split으로 하드코딩 할 순 없으니 기능을 다 익혀두고 참고서 보면서 바로 적용할 수 있도록 하자.

