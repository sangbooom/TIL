// Ex9 - 마우스 이벤트 객체: 박스의 옵셋 영역 좌표 이용하기
window.addEventListener("load", function () {
  var section = document.querySelector("#section9");
  var container = section.querySelector(".container");
  var box = section.querySelector(".box");
  var status = section.querySelector(".status");
  var offset = { x: 0, y: 0 };
  var dragging = false;
  var current = null;
  var left = container.offsetLeft;
  var top = container.offsetTop;
  console.log(left, top);

  document.onmousedown = function (e) {
    if (e.target.classList.contains("box")) {
      dragging = true;
      current = e.target;
      offset.x = e.offsetX;
      offset.y = e.offsetY;
    }
  };
  document.onmousemove = function (e) {
    if (!dragging) return;

    var x = e.pageX - offset.x - left;
    var y = e.pageY - offset.y - top;

    current.style.left = x + "px";
    current.style.top = y + "px";

    status.innerHTML = "(x, y) : " + x + " , " + y;
  };
  document.onmouseup = function (e) {
    dragging = false;
  };
});

// Ex8 - 마우스 이벤트 객체: 여러개 박스 드래그 방식으로 옮기기
window.addEventListener("load", function () {
  var section = document.querySelector("#section8");
  var container = section.querySelector(".container");
  var box = section.querySelector(".box");
  var offset = { x: 0, y: 0 };
  var dragging = false;
  var current = null;

  container.onmousedown = function (e) {
    if (e.target.classList.contains("box")) {
      dragging = true;
      current = e.target;
      offset.x = e.offsetX;
      offset.y = e.offsetY;
    }
  };
  container.onmousemove = function (e) {
    if (!dragging) return;

    current.style.left = e.pageX - offset.x + "px";
    current.style.top = e.pageY - offset.y + "px";
  };
  container.onmouseup = function (e) {
    dragging = false;
  };
  // box.onmousedown = function(e){
  //   offset.x = e.offsetX;
  //   offset.y = e.offsetY;
  // }
});

// Ex7 - 마우스 이벤트 객체: 드래그 방식으로 박스 옮기기
window.addEventListener("load", function () {
  var section = document.querySelector("#section7");
  var container = section.querySelector(".container");
  var box = section.querySelector(".box");
  var offset = { x: 0, y: 0 };
  var dragging = false;
  container.onmousedown = function (e) {
    if (e.target === box) {
      dragging = true;
    }
  };
  container.onmousemove = function (e) {
    if (!dragging) return;

    box.style.left = e.pageX - offset.x + "px";
    box.style.top = e.pageY - offset.y + "px";
  };
  container.onmouseup = function (e) {
    dragging = false;
  };

  box.onmousedown = function (e) {
    offset.x = e.offsetX;
    offset.y = e.offsetY;
  };
});

// Ex6 - 마우스 이벤트 객체: 마우스 좌표
window.addEventListener("load", function () {
  var section = document.querySelector("#section6");
  var container = section.querySelector(".container");
  var box = section.querySelector(".box");

  container.onclick = function (e) {
    console.log(e.x, e.y);
    console.log("clientX:", e.clientX, "clientY:", e.clientY);
    console.log("pageX:", e.pageX, "pageY:", e.pageY);
    console.log("offsetX:", e.offsetX, "offsetY:", e.offsetY);

    box.style.position = "absolute";
    box.style.left = e.x + "px";
    box.style.top = e.y + "px";
  };
});

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
