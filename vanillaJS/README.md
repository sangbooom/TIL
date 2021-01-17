# 👨‍💻practice1. 이미지캐러셀 구현
![image_carousel](https://user-images.githubusercontent.com/43921054/104838646-b1556300-58ff-11eb-8614-dfb18a472a61.gif)
___
# 👨‍💻practice2. 연락처 구현
![pd](https://user-images.githubusercontent.com/43921054/104838652-be725200-58ff-11eb-9e65-d431053b1165.gif)
___
# 👨‍💻practice3. 모달창 구현
![image](https://user-images.githubusercontent.com/43921054/104845972-8416ae00-591b-11eb-854f-aa310dba54e0.png)
## 📝잊지말자
모달창의 밖 회색 부분을 클릭했을 때 자연스럽게 닫혀야 한다고 생각한다. 바로 이 역할을 Overlay 가 해결한다.
만약 Overlay 를 따로 잡지않고 Container 에서 처리하려고 했다면 bubbling 과 capturing 때문에 고통을 맛보게 된다.


![image](https://1ilsang.dev/static/63e4cb5ded96d445eff804dbfec66131/4b190/event-flow.jpg)

> 출처 : [Javascript-Info](https://javascript.info/bubbling-and-capturing)

그러므로 Overlay 라는 컴포넌트와 Contents 컴포넌트를 **형제로 두어** Event flow 에 영향을 가지 않도록 해야한다.
