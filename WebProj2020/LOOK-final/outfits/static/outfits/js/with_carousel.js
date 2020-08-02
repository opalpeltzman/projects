


$(function () {
  $('.multiple-items').slick({
      useTransform:true,
      infinite: true,
      dots: false,
      slidesToScroll: 3,
      centerMode: false, 
      variableWidth: true,
      swipe: true,
      swipeToSlide: true,
      nextArrow: '<span class="next_arrow"><span class="right_arrow"></span></span>',
      prevArrow: '<span class="prev_arrow"><span class="left_arrow"></span></span>',
  });
})

 
// save look button takes to myOutfits
document.forms["myForm"]["submit"].onclick = function(){
  window.location.href = "index.html";
}

//light box options between tops and pants
var golfElement = document.getElementById("golftab");


var lightbox1 = $("#myModal").modal("hide");


document.getElementById("tops").onclick = function(){ 
  lightbox1.modal("show");
  golfElement.style.fontWeight = 900;
  golfElement.style.color = "#0d0909";
}

document.getElementById("save").onclick = function(){ lightbox1.modal("hide");}







  