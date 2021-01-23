
const el = document.querySelector(".resizers");
let isResizing = false;
el.addEventListener("mousedown",mousedown);

function mousedown(e){
  window.addEventListener("mousemove",mousemove);
  window.addEventListener("mouseup",mouseup);

  let prevX = e.clientX;
  let prevY = e.clientY;
  
  function mousemove(e){
    if(!isResizing){
      const rect = el.getBoundingClientRect();
      let newX = prevX - e.clientX;
      let newY = prevY - e.clientY; 
  
      el.style.left = rect.left - newX + "px";
      el.style.top = rect.top - newY + "px";
  
      prevX = e.clientX;
      prevY = e.clientY;
    }
  }

  function mouseup(){
    window.removeEventListener("mousemove", mousemove);
    window.removeEventListener("mouseup",mouseup);
  }
}

const resizers = document.querySelectorAll(".resizer");
let currentResizer;

for(let resizer of resizers){
  resizer.addEventListener("mousedown", mousedown);

  function mousedown(e){
    currentResizer = e.target;
    isResizing = true;

    window.addEventListener("mousemove",mousemove);
    window.addEventListener("mouseup",mouseup);

    let prevX = e.clientX;
    let prevY = e.clientY;

    function mousemove(e){
      const rect = el.getBoundingClientRect();
      let newX = prevX - e.clientX;
      let newY = prevY - e.clientY;
      if(currentResizer.classList.contains("top-left")){
        el.style.width = rect.width + newX + "px";
        el.style.height = rect.height + newY + "px";
        el.style.top = rect.top - newY + "px";
        el.style.left = rect.left - newX + "px";
      } else if(currentResizer.classList.contains("top-right")){
        el.style.width = rect.width - newX + "px";
        el.style.height = rect.height + newY + "px";
        el.style.top = rect.top - newY + "px";
      } else if(currentResizer.classList.contains("bottom-left")){
        el.style.width = rect.width + newX + "px";
        el.style.height = rect.height - newY + "px";
        el.style.left = rect.left - newX + "px";
      } else {
        el.style.width = rect.width - newX + "px";
        el.style.height = rect.height - newY + "px";
      }
      prevX = e.clientX;
      prevY = e.clientY;
    }

    function mouseup(){
      window.removeEventListener("mousemove",mousemove);
      window.removeEventListener("mouseup",mouseup);
      isResizing = false;
    }
  }
}

//그다음은 resizers를 한번 더 감싸고 크롭 영역 밖으로 나가지못하도록 최소 영역도 설정