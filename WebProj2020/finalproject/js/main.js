
var img = document.getElementById("im4");

document.getElementsByClassName("overlay")[0].style.display = "none";

img.onclick = function () {
    var overlay = document.getElementsByClassName("overlay")[0];
    if( overlay.style.display == "none")
        overlay.style.display = "block";
    else
    overlay.style.display = "none";
};

var overlay = document.getElementsByClassName("overlay")[0];
overlay.onclick = function(){ overlay.style.display = "none"};

