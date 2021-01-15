//Ex10-클릭한 컬럼을 기준으로 레코드 정렬하기 #1
window.addEventListener("load", function () {
  var notices = [
    {
      id: 1,
      title: "공부를 열심히 하자",
      regDate: "2021-02-05",
      writerId: "samgboom",
      hit: 2,
    },
    {
      id: 2,
      title: "자바스크립트란..",
      regDate: "2021-02-02",
      writerId: "samgboom",
      hit: 0,
    },
    {
      id: 3,
      title: "기본기가 튼튼해야...",
      regDate: "2021-02-01",
      writerId: "samgboom",
      hit: 1,
    },
    {
      id: 4,
      title: "자바스크립트는 어렵다",
      regDate: "2021-01-25",
      writerId: "samgboom",
      hit: 0,
    },
  ];

  var section = document.querySelector("#section10");

  var noticeList = section.querySelector(".notice-list");
  var titldTd = section.querySelector(".title");
  var tbodyNode = noticeList.querySelector("tbody");

  var bindData = function () {
    var template = section.querySelector("template");

    for (var i = 0; i < notices.length; i++) {
      var cloneNode = document.importNode(template.content, true);
      var tds = cloneNode.querySelectorAll("td");
      tds[0].textContent = notices[i].id;

      var aNode = tds[1].children[0];
      aNode.href = notices[i].id;
      aNode.textContent = notices[i].title;

      tds[2].textContent = notices[i].regDate;
      tds[3].textContent = notices[i].writerId;
      tds[4].textContent = notices[i].hit;

      tbodyNode.appendChild(cloneNode);
    }
  };

  var titleSorted = false;
  bindData();

  titldTd.onclick = function () {
    tbodyNode.innerHTML = "";

    if (!titleSorted) {
      notices.sort(function (a, b) {
        titleSorted = true;
        if (a.title < b.title) {
          return -1;
        } else if (a.title > b.title) {
          return 1;
        } else {
          return 0;
        }
      });
    } else {
      notices.reverse();
    }
    bindData();
  };
});

//Ex9-다중 노드선택 방법과 일괄삭제, 노드의 자리바꾸기
window.addEventListener("load", function () {
  var section = document.querySelector("#section9");

  var noticeList = section.querySelector(".notice-list");
  var tbody = noticeList.querySelector("tbody");
  var allCheckbox = section.querySelector(".overall-checkbox");
  var delButton = section.querySelector(".del-button");
  var swapButton = section.querySelector(".swap-button");

  allCheckbox.onchange = function () {
    var inputs = tbody.querySelectorAll("input[type='checkbox']");
    for (var i = 0; i < inputs.length; i++) {
      inputs[i].checked = allCheckbox.checked;
    }
  };

  delButton.onclick = function () {
    var inputs = tbody.querySelectorAll("input[type='checkbox']:checked");
    for (var i = 0; i < inputs.length; i++) {
      inputs[i].parentElement.parentElement.remove();
    }
  };

  swapButton.onclick = function () {
    var inputs = tbody.querySelectorAll("input[type='checkbox']:checked");

    if (inputs.length != 2) {
      alert("엘리먼트는 2개를 선택해야만 합니다");
      return;
    }

    var trs = [];
    for (var i = 0; i < inputs.length; i++) {
      trs.push(inputs[i].parentElement.parentElement);
    }

    var cloneNode = trs[0].cloneNode(true);
    console.log(trs[1]);
    trs[1].replaceWith(cloneNode);
    console.log(trs[1]);
    trs[0].replaceWith(trs[1]);
  };
});

//Ex8-노드 삽입과 바꾸기
window.addEventListener("load", function () {
  var section = document.querySelector("#section8");

  var noticeList = section.querySelector(".notice-list");
  var tbodyNode = noticeList.querySelector("tbody");
  var upButton = section.querySelector(".up-button");
  var downButton = section.querySelector(".down-button");

  var currentNode = tbodyNode.firstElementChild; //.children[0];

  downButton.onclick = function () {
    var nextNode = currentNode.nextElementSibling;

    if (nextNode == null) {
      alert("더 이상 이동할 수 없습니다.");
      return;
    }

    tbodyNode.removeChild(nextNode);
    tbodyNode.insertBefore(nextNode, currentNode);
  };

  upButton.onclick = function () {
    var previousNode = currentNode.previousElementSibling;

    if (previousNode == null) {
      alert("더 이상 이동할 수 없습니다.");
      return;
    }

    // tbodyNode.removeChild(currentNode);
    // tbodyNode.insertBefore(currentNode, previousNode);
    currentNode.insertAdjacentElement("afterend", previousNode);
  };
});

//Ex7 : 노드 복제와 템플릿 태그
window.addEventListener("load", function () {
  var notices = [
    {
      id: 5,
      title: "열심히 공부하자",
      regDate: "2021-01-15",
      writerId: "samgboom",
      hit: 0,
    },
    {
      id: 6,
      title: "복제해봐",
      regDate: "2021-01-15",
      writerId: "samgboom",
      hit: 17,
    },
  ];

  var section = document.querySelector("#section7");

  var noticeList = section.querySelector(".notice-list");
  var tbodyNode = noticeList.querySelector("tbody");
  var cloneButton = section.querySelector(".clone-button");
  var templateButton = section.querySelector(".template-button");

  cloneButton.onclick = function () {
    var trNode = noticeList.querySelector("tbody tr");
    var cloneNode = trNode.cloneNode(true);
    var tds = cloneNode.querySelectorAll("td");

    tds[0].textContent = notices[0].id;
    tds[1].innerHTML = '<a href="1">' + notices[0].title + "</a>";
    tds[2].textContent = notices[0].regDate;
    tds[3].textContent = notices[0].writerId;
    tds[4].textContent = notices[0].hit;

    tbodyNode.appendChild(cloneNode);
  };

  templateButton.onclick = function () {
    var template = section.querySelector("template");
    var cloneNode = document.importNode(template.content, true);
    var tds = cloneNode.querySelectorAll("td");

    for (var i = 0; i < notices.length; i++) {
      tds[0].textContent = notices[i].id;
      tds[1].innerHTML = '<a href="">' + notices[i].title + "</a>";
      tds[2].textContent = notices[i].regDate;
      tds[3].textContent = notices[i].writerId;
      tds[4].textContent = notices[i].hit;

      tbodyNode.appendChild(cloneNode);
    }
  };
});

//Ex6 : 메뉴추가(createTextNode, Element)
window.addEventListener("load", function () {
  var section = document.querySelector("#section6");

  var titleInput = section.querySelector(".title-input");
  var menuListUl = section.querySelector(".menu-list");
  var addButton = section.querySelector(".add-button");
  var delButton = section.querySelector(".del-button");

  addButton.onclick = function () {
    var title = titleInput.value;

    // menuListUl.innerHTML += '<li><a href="">' + title + '</a></li>';

    var html = '<a href="">' + title + "</a>";
    var liNode = document.createElement("li");
    liNode.innerHTML = html;
    menuListUl.appendChild(liNode);

    // var txtNode = document.createTextNode(title);
    // var aNode = document.createElement("a");
    // aNode.href="";
    // aNode.appendChild(txtNode);
    // var liNode = document.createElement("li");
    // liNode.appendChild(aNode);

    // menuListUl.appendChild(liNode);
  };

  delButton.onclick = function () {
    // menuListUl.removeChild(menuListUl.children[0]);

    var liNode = menuListUl.children[0];
    liNode.remove();
  };
});

//Ex5 : 엘리먼트 노드의 속성& CSS 속성 변경
window.addEventListener("load", function () {
  var section = document.querySelector("#section5");
  var srcInput = section.querySelector(".src-input");
  var imgSelect = section.querySelector(".img-select");
  var changeButton = section.querySelector(".change-button");
  var img = section.querySelector(".img");
  var colorInput = section.querySelector(".color-input");

  changeButton.onclick = function () {
    img.src = "Images/" + srcInput.value;
    img.style["border-color"] = colorInput.value;
  };
});

//Ex4 : childNodes를 이용한 노드 선택
window.addEventListener("load", function () {
  var section4 = document.querySelector("#section4");
  var box = section4.querySelector(".box");

  var input1 = box.children[0]; // childNodes[0] 로 할때는 <div class="box"><input /><input /></div> 처럼 html을 일자로 둬야함. whitespace가 있어서
  var input2 = box.children[1];

  input1.value = "hello";
  input2.value = "okay";
});

//Ex3 : Selectors API Level1
window.addEventListener("load", function () {
  var section3 = document.getElementById("section3");
  var x = section3.querySelector("input[name='x']");
  var txtY = section3.querySelector(".txt-y");
  var btnAdd = section3.querySelector(".btn-add");
  var txtSum = section3.querySelector(".txt-sum");

  btnAdd.addEventListener("click", function () {
    txtSum.value = parseInt(x.value) + parseInt(txtY.value);
  });
});

//Ex2 : 엘리먼트 선택방법 개선하기
window.addEventListener("load", function () {
  var section2 = document.getElementById("section2");
  var txtX = section2.getElementsByClassName("txt-x")[0];
  var txtY = section2.getElementsByClassName("txt-y")[0];
  var btnAdd = section2.getElementsByClassName("btn-add")[0];
  var txtSum = section2.getElementsByClassName("txt-sum")[0];

  /*
      var inputs = section2.getElementsByTagName("input");
      var txtX = inputs[0];
      var txtY = inputs[1];
      var btnAdd = inputs[2];
      var txtSum = inputs[3];
      */

  btnAdd.onclick = function () {
    txtSum.value = parseInt(txtX.value) + parseInt(txtY.value);
  };
});

//Ex1 : 계산기 프로그램
window.addEventListener("load", function () {
  var txtX = document.getElementById("txt-x");
  var txtY = document.getElementById("txt-y");
  var btnAdd = document.getElementById("btn-add");
  var txtSum = document.getElementById("txt-sum");

  // btnAdd.addEventListener("click", function(){
  //     txtSum.value = parseInt(txtX.value) + parseInt(txtY.value);
  // })
  btnAdd.onclick = function () {
    txtSum.value = parseInt(txtX.value) + parseInt(txtY.value);
  };
});
