// Ex5-trigger
window.addEventListener("load", function () {
  var section = document.querySelector("#section5");
  var fileButton = section.querySelector(".file-button");
  var fileTriggerButton = section.querySelector(".file-trigger-button");

  fileTriggerButton.onclick = function () {
    var event = new MouseEvent("click", {
      view: window,
      bubbles: true,
      cancelable: true,
    });
    fileButton.dispatchEvent(event);
  };
});

// Ex4-서로 다른 기능의 여러 버튼을 가진 화면에서 이벤트를 처리하는 방법
window.addEventListener("load", function () {
  var section = document.querySelector("#section4");
  var tbody = section.querySelector("tbody");
  tbody.onclick = function (e) {
    e.preventDefault();
    if (e.target.nodeName != "A") {
      return;
    }
    if (e.target.classList.contains("sel-button")) {
      var tr = e.target.parentElement;
      for (; tr.nodeName != "TR"; tr = tr.parentElement);

      tr.style.background = "yellow";
    } else if (e.target.classList.contains("edit-button")) {
      console.log("234");
    } else if (e.target.classList.contains("del-button")) {
      console.log("345");
    }
  };
});

// Ex3-이벤트 버블링 멈추기
window.addEventListener("load", function () {
  var section = document.querySelector("#section3");

  var imgList = section.querySelector(".img-list");
  var addButton = section.querySelector(".add-button");
  var currentImg = section.querySelector(".current-img");

  imgList.onclick = function (e) {
    console.log("imgList click");
    if (e.target.nodeName != "IMG") {
      return;
    }
    currentImg.src = e.target.src;
  };

  addButton.onclick = function (e) {
    e.stopPropagation(); // 이벤트 버블링 멈추기
    var img = document.createElement("img");
    img.src = "images/img1.jpg";
    currentImg.insertAdjacentElement("afterend", img);
  };
});

//Ex2-이벤트 버블링을 이용해 사용자 이벤트 처리하기:event Bubbling
window.addEventListener("load", function () {
  var section = document.querySelector("#section2");
  var imgList = section.querySelector(".img-list");
  var currentImg = section.querySelector(".current-img");

  imgList.onclick = function (e) {
    if (e.target.nodeName != "IMG") {
      return;
    }
    currentImg.src = e.target.src;
  };
});

//연습문제 1-선택된 레코드 삭제하기:event target
window.addEventListener("load", function () {
  var section = document.querySelector("#section1-1");
  var delButtons = section.querySelectorAll(".del-button");

  var tbody = section.querySelector("tbody");
  tbody.onclick = function (e) {
    if (e.target.nodeName != "INPUT") {
      return;
    }
    e.target.parentElement.parentElement.remove();
  };

  // 안좋은코드
  //   for (var i = 0; i < delButtons.length; i++) {
  //     delButtons[i].onclick = function (e) {
  //       e.target.parentElement.parentElement.remove();
  //     };
  //   }
});

//Ex1-선택된 이미지 보여주기:event target
window.addEventListener("load", function () {
  var section = document.querySelector("#section1");
  var imgs = section.querySelectorAll(".img");
  var currentImg = section.querySelector(".current-img");

  var imgsDiv = section.querySelector("div");

  imgsDiv.onclick = function (e) {
    if (e.target.nodeName != "IMG") {
      return;
    }
    currentImg.src = e.target.src;
  };
  // 안좋은 코드, 메모리도 많이먹고 계속 바인딩함, 이럴 때 이벤트 버블링 조지는게 좋음
  //   for(var i=0; i<imgs.length; i++){
  //     currentImg.src = e.target.src;
  //   }

  //좋은코드
});
