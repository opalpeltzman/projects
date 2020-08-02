
function calculate(firstName, lastName){
    var sum = firstName.length * lastName.length;

    return sum;
}

debugger;
var fullName = prompt("plaese enter yout full name", "Opal Peltzman");
    var firstName = fullName.split(' ')[0];
    var lastName = fullName.substring(firstName.length).trim();

var article = "";
var numOfArticles = calculate(firstName, lastName);
for(var i = 0; i < numOfArticles; i++){
    article += "<article></article>"
}
var main = document.getElementById("lay2Main");
main.innerHTML = article;


var input1 = document.createElement("button");
var input2 = document.createElement("button");
var nav = document.getElementById("navThirdPg");
nav.appendChild(input1);
nav.appendChild(input2);
input1.className = "button1";
input2.className = "button2";

var allArticles = document.getElementsByTagName("article");
input1.onclick = function(){
    for(var j = 0; j < firstName.length; j++){
        allArticles[j].style.backgroundColor = "gray";
    }
}

input2.onclick = function(){
    for(var j = 0; j < firstName.length; j++){
        allArticles[j].style.backgroundColor = "#fefefe";
    }
}

var count = 0;
allArticles[0].onmouseover = function(){
    count++;
    if(count == 1){
        var firstLetter = firstName[0];
        var p = "<p></p>";
        allArticles[0].innerHTML = p;
        document.getElementsByTagName("p")[0].innerText = firstLetter;
    }
}