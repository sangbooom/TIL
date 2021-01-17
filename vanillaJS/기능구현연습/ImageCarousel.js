// Add your javascript here
window.addEventListener("load", function () {
  var indicatorList = document.querySelector(".indicator-list");
  var cariuselImg = this.document.querySelector(".cariusel-img");

  var firstBtn = document.querySelector(".indicator-list li:first-child");
  var lastBtn = document.querySelector(".indicator-list li:last-child");
  var leftBtn = document.querySelector(".previous");
  var rightBtn = document.querySelector(".next");
  var slideInput = document.querySelector(".test");
  var timer = null;

  indicatorList.onclick = function (e) {
    if (
      e.target.classList.contains("one") ||
      e.target.classList.contains("two") ||
      e.target.classList.contains("three") ||
      e.target.classList.contains("four") ||
      e.target.classList.contains("five")
    ) {
      var prevNow = indicatorList.querySelector(".now");
      prevNow.classList.remove("now");
      e.target.classList.add("now");
      cariuselImg.src = `./assets/images/img-${e.target.value + 1}.jpg`;
    }
  };

  leftBtn.onclick = function () {
    var currentBtn = document.querySelector(".now");
    if (currentBtn) {
      currentBtn.classList.remove("now");
      var prevBtn = currentBtn.previousElementSibling;
      if (prevBtn) {
        prevBtn.classList.add("now");
        cariuselImg.src = `./assets/images/img-${prevBtn.value + 1}.jpg`;
      } else {
        lastBtn.classList.add("now");
        cariuselImg.src = `./assets/images/img-${lastBtn.value + 1}.jpg`;
      }
    } else {
      console.log("어떤 경우일까");
      firstBtn.classList.add("now");
    }
  };

  rightBtn.onclick = function () {
    var currentBtn = document.querySelector(".now");
    if (currentBtn) {
      currentBtn.classList.remove("now");
      var nextBtn = currentBtn.nextElementSibling;
      if (nextBtn) {
        nextBtn.classList.add("now");
        cariuselImg.src = `./assets/images/img-${nextBtn.value + 1}.jpg`;
      } else {
        firstBtn.classList.add("now");
        cariuselImg.src = `./assets/images/img-${firstBtn.value + 1}.jpg`;
      }
    } else {
      console.log("어떤 경우일까");
      lastBtn.classList.add("now");
    }
  };

  function slide() {
    var currentBtn = document.querySelector(".now");
    if (currentBtn) {
      currentBtn.classList.remove("now");
      var nextBtn = currentBtn.nextElementSibling;
      if (nextBtn) {
        nextBtn.classList.add("now");
        cariuselImg.src = `./assets/images/img-${nextBtn.value + 1}.jpg`;
      } else {
        firstBtn.classList.add("now");
        cariuselImg.src = `./assets/images/img-${firstBtn.value + 1}.jpg`;
      }
    } else {
      console.log("어떤 경우일까");
      lastBtn.classList.add("now");
    }
  }

  slideInput.onclick = function () {
    if (slideInput.hasAttribute("checked")) { //체크안됐을때
      slideInput.removeAttribute("checked");
      if (timer != null) {
        clearInterval(timer);
      }
    } else {
      slideInput.setAttribute("checked", ""); //체크됐을때
      timer = setInterval(slide, 2000);
    }
  };
});
