// Js code
window.addEventListener("load",function(){
    var txtLeft = document.querySelector(".txtLeft");
    var btn = txtLeft.querySelector(".btn");
    var name = txtLeft.querySelector("#name");
    var mobile = txtLeft.querySelector("#mobile");
    var email = txtLeft.querySelector("#email");
    var tbody = document.querySelector("#summaryTable tbody");
    var search = document.querySelector("#search");
    var nameColumn = document.querySelector("#nameColumn");
    var nameArray = [{ _name : "Admin", _mobile : "9999999999", _search: "admin@xyzcompany.com" }];
  
    btn.onclick = function(){
      var tr = document.createElement("tr");
      tr.innerHTML = "<td>"+name.value+"</td>" + "<td>"+mobile.value+"</td>" + "<td>"+email.value+"</td>";
  
      tbody.appendChild(tr);
      nameArray.push({ _name : name.value, _mobile : mobile.value, _search: search.value});
      console.log(nameArray);
    }
  
    search.addEventListener("keydown",function(){
      console.log(search.value)
      // if(search.value === ){
  
      // }
    })
  
    nameColumn.onclick = function(){
      nameArray = nameArray.sort();
      for(var i=0; i<tbody.childElementCount; i++){
        tbody.children[0].remove();
      }
      console.log(nameArray)
      for(var i=0; i<nameArray.length; i++){
        var tr = document.createElement("tr");
        tr.innerHTML = "<td>"+nameArray[i]._name+"</td>" + "<td>"+nameArray[i]._mobile+"</td>" + "<td>"+nameArray[i]._email+"</td>";
        console.log(nameArray[i]._name);
        tbody.appendChild(tr);
        tr.innerHTML = "";
      }
    }
  });