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

  // var rect = 0;

  document.addEventListener("mousedown", function (e) {
      // console.log(cropbox.getBoundingClientRect())
    if (e.target.classList.contains("cropbox")) {
      dragging = true;
    } else if (e.target.classList.contains("selectbox")) {
      resizing = true;
    }
    current = e.target;
    offset.x = e.offsetX;
    offset.y = e.offsetY;
    var prevX = e.offsetX;
    var prevY = e.offsetY;

    
    document.addEventListener("mousemove", mousemove);
    document.addEventListener("mouseup", mouseup);

    function mousemove(e) {
      if (dragging) {
        var x = e.pageX - offset.x - left;
        var y = e.pageY - offset.y - top;
  
        current.style.left = x + "px";
        current.style.top = y + "px";
        
      } else if (resizing) {
        var rect = cropbox.getBoundingClientRect();
        if (e.target.classList.contains("lt")) {
          cropbox.style.width = cropbox.offsetWidth - (prevX - e.offsetX) + "px";
          cropbox.style.height = cropbox.offsetHeight - (prevY - e.offsetY) + "px";
          cropbox.style.top = rect.top - (prevY - e.offsetY) + "px";
          cropbox.style.left = rect.left - (prevX - e.offsetX) + "px";
        } else if (e.target.classList.contains("rt")) {
          cropbox.style.width = cropbox.offsetWidth + (prevX - e.offsetX) + "px";
          cropbox.style.height = cropbox.offsetHeight - (prevY - e.offsetY) + "px";
          cropbox.style.top = rect.top - (prevY - e.offsetY) + "px";
        } else if (e.target.classList.contains("lb")) {
          cropbox.style.width = cropbox.offsetWidth + (prevX - e.offsetX) + "px";
          cropbox.style.height = cropbox.offsetHeight - (prevY - e.offsetY) + "px";
          cropbox.style.left = rect.left - (prevX - e.offsetX) + "px";
        } else if (e.target.classList.contains("rb")) {
          cropbox.style.width = cropbox.offsetWidth - (prevX - e.offsetX) + "px";
          cropbox.style.height = cropbox.offsetHeight - (prevY - e.offsetY) + "px";
        }
      } else {
        return;
      }

      prevX = e.offsetX;
      prevY = e.offsetY;
    }

    function mouseup() {
      document.removeEventListener("mousemove", mousemove);
      document.removeEventListener("mouseup", mouseup);
      dragging = false;
      resizing = false;
    }

    // cropbox.style.left = event.pageX - event.offsetX - pictures_left + "px";
    // cropbox.style.top = event.pageY - event.offsetY - pictures_top + "px";
    // event.offsetX를 mousedown 했을때의 offsetX로 고정을 해놨어야 한다. mousedown할때 타겟과 값을 지정하고 mousemove에서 움직이도록 하자..
  });
  var selectbox = document.querySelector(".selectbox");

  activeBtn.onclick = function () {
    cropbox.classList.toggle("display-none");
  };
});
