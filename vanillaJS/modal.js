window.addEventListener("load",function(){
    var openBtn = document.querySelector(".open");
    var container = document.querySelector(".container");
    var closeBtn = document.querySelector(".close");
    var overlay = document.querySelector(".overlay");

    openBtn.onclick = function(){
        container.classList.toggle("visibility-hidden");
    }

    closeBtn.onclick = function(){
        container.classList.toggle("visibility-hidden");
    }

    overlay.onclick = function(){
        container.classList.toggle("visibility-hidden");
    }
})