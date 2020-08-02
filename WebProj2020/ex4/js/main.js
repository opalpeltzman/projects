
document.getElementById("submitButten").onclick = function(){
    
    var y = validateName();
    if(y == false){
        return false;
    }
    
    y = range();
    if(y == false){
        return false;
    }    

    y = phone();
    if(y == false){
        return false;
    }

    y = validateInterests();
    if(y == false){
        return false;
    }

    y = validatePassword();
    if(y == false){
        return false;
    }

    return true;
}


function validateName() {
    var letters = '^[a-zA-Z ]*$';
    var x = document.forms["myForm"]["fullName"].value;
    var count = 0;
   for(var i =0; i < x.length; i++){
       if(x.charAt(i) == " "){
           count += 1;
       }
   }
    if (x.match(letters) && count != 0) {
      return true;
    }
    alert("please enter full name using space");
      return false;
  }

function validateInterests(){
    var x = document.forms["myForm"]["interests[]"];
    if(x[0].checked == false && x[1].checked == false && x[2].checked == false &&
        x[3].checked== false && x[4].checked == false && x[5].checked == false){
            alert("please choose at least one option :עם מי היית מרכיב את הקבינט");
    
        return false;
    }
}

  function phone(){
      var phoneNumber1 = /^\d{10}$/;
      var phoneNumber2 = /^\d{9}$/;
      var x = document.forms["myForm"]["phone"].value;
      if(x.match(phoneNumber1) || x.match(phoneNumber2)){
          return true;
      }
      alert("phone not valid");
      return false;
  }


function range(){
    var x;

    x = document.forms["myForm"]["temper"].value;

    if(x < 97){

    alert("Range input is not valid... try רק ביבי");    

    return false;
    }
    
}

function validatePassword(){
    var passRoles = '^[a-zA-Z ]*$';
    var x = document.forms["myForm"]["pass"].value; 
    if(x.match(passRoles)){
        return true;
    }

    alert("please enter only letters :איזה רב היית ממנה לשר הבריאות")
    return false;
}





