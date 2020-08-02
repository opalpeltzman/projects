

var golfElement = document.getElementById("golftab");


var lightbox1 = $("#myModal").modal("hide");


document.getElementById("tops").onclick = function(){ 
  lightbox1.modal("show");
  golfElement.style.fontWeight = 900;
  golfElement.style.color = "#0d0909";
}

document.getElementById("save").onclick = function(){ lightbox1.modal("hide");}

document.getElementById("saveTlook").onclick = function(){
    // window.open('stylist','_self');
    window.location.href = "profile"; 
    document.getElementById("changeOutfit").src= "{% static 'outfits/images/o6.jpg' %}";
}

