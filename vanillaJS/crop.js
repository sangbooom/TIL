window.addEventListener("load", function () {
  var fileInput = document.querySelector("#fileInput");
  var dragging = false;
  var resizing = false;
  var pictures = document.querySelector("#pictures");
  var cropbox = document.querySelector(".cropbox");
  var activeBtn = document.querySelector("#activeBtn");

  fileInput.onchange = function (e) {
    console.log(e.target.files[0]);
    var file = e.target.files[0];
    var reader = new FileReader();
    reader.readAsDataURL(file);

    reader.onload = function () {
      var photoFrame = document.createElement("div");
      photoFrame.style = `background : url(${reader.result}); background-size : cover; position: absolute;`;
      photoFrame.className = "photoFrame";
      document.getElementById("pictures").appendChild(photoFrame);
    };
  };

  var lt = document.querySelector(".lt");
  var rt = document.querySelector(".rt");
  var rb = document.querySelector(".rb");
  var lb = document.querySelector(".lb");

  var offset = { x: 0, y: 0 };
  var current = null;
  var left = pictures.offsetLeft;
  var top = pictures.offsetTop;

  document.addEventListener("mousemove", function (e) {
    if(!dragging && !resizing) return;

    var x = e.pageX - offset.x - left;
    var y = e.pageY - offset.y - top;

    current.style.left = x + "px";
    current.style.top = y + "px";
  });

  document.addEventListener("mouseup", function () {
    dragging = false;
    resizing = false;
  });

  document.addEventListener("mousedown", function (e) {
    if (e.target.classList.contains("cropbox")) {
      dragging = true;
    } else if (e.target.classList.contains("selectbox")) {
      resizing = true;
    }
    current = e.target;
    offset.x = e.offsetX;
    offset.y = e.offsetY;

    // cropbox.style.left = event.pageX - event.offsetX - pictures_left + "px";
    // cropbox.style.top = event.pageY - event.offsetY - pictures_top + "px";
    // event.offsetX를 mousedown 했을때의 offsetX로 고정을 해놨어야 한다. mousedown할때 타겟과 값을 지정하고 mousemove에서 움직이도록 하자..
  });
  var selectbox = document.querySelector(".selectbox");

  activeBtn.onclick = function () {
    cropbox.classList.toggle("display-none");
  };
});
