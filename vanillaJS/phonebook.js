window.addEventListener("load",function(){
    var txtLeft = document.querySelector(".txtLeft");
    var addBtn = txtLeft.querySelector(".btn");
    var name = txtLeft.querySelector("#name");
    var mobile = txtLeft.querySelector("#mobile");
    var email = txtLeft.querySelector("#email");
    var tbody = document.querySelector("#summaryTable tbody");
    var search = document.querySelector("#search");
    var nameColumn = document.querySelector("#nameColumn");
    var noResult = document.querySelector("#noResult");
    var nameArray = [{ _name : "Admin", _mobile : "9999999999", _email: "admin@xyzcompany.com" }];
    var nameArrayToggle = false;

    addBtn.onclick = function(){
      var tr = document.createElement("tr");
      tr.innerHTML = "<td>"+name.value+"</td>" + "<td>"+mobile.value+"</td>" + "<td>"+email.value+"</td>";
  
      tbody.appendChild(tr);
      nameArray.push({ _name : name.value, _mobile : mobile.value, _email: email.value});
      console.log(nameArray);
    }
  
    search.addEventListener("keyup",function(){ // keydown으로하면 동기화? 가 안되는데 keyup으로하니까 동기화가 된다. 이 점 유의하고 기억하자.
      var names =  nameArray.filter(array => array._name.indexOf(search.value) === 0)
      
      if(names.length === 0){
          noResult.classList.remove("dn");
      } else {
        if(!noResult.classList.contains("dn")){
          noResult.classList.add("dn");
        }
      }

      var childElementCount = tbody.childElementCount;

      for(var j=0; j<childElementCount; j++){
        tbody.children[0].remove();
      }
      for(var i=0; i<names.length; i++){
        var tr = document.createElement("tr");
        tr.innerHTML = "<td>" + names[i]._name + "</td>" + "<td>" + names[i]._mobile + "</td>" + "<td>" + names[i]._email + "</td>";
        tbody.appendChild(tr);
      }
    })
  
    nameColumn.onclick = function(){
      nameArrayToggle = !nameArrayToggle;
      nameArray = nameArray.sort(function(a, b) {
        if (a._name < b._name) {
          return -1;
        }
        if (a._name > b._name) {
          return 1;
        }
        // 이름이 같을 경우
        return 0;
      });

      if(!nameArrayToggle) nameArray.reverse();

      var childElementCount = tbody.childElementCount;
      for(var j=0; j<childElementCount; j++){
        tbody.children[0].remove();
      }

      for(var i=0; i<nameArray.length; i++){
        var tr = document.createElement("tr");
        tr.innerHTML = "<td>" + nameArray[i]._name + "</td>" + "<td>" + nameArray[i]._mobile + "</td>" + "<td>" + nameArray[i]._email + "</td>";
        tbody.appendChild(tr);
      }
    }
  });