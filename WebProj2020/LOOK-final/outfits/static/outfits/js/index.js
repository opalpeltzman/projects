


    var lightbox = $("#deleteModal").modal("hide"), overlays, myimgid;
    document.getElementById("confirmdelete").onclick = function(){

    }



document.getElementById("addOutfits").onclick =function(){
    window.location.href = "createLook"; 
}



$(document).ready(function(){
    $.getJSON("../static/outfits/data/items.json",function(data){
        $.each(data,function(key,value){
            var link = `<div class="img_container" class='${value.imgid}'>
            <button><img class="dynamic_image" onclick="showoverlay(${value.imgid})" src='${value.img}' id='${value.imgid}'></button>
            <section class="overlay" onclick="showoverlay2(${value.imgid})">
                <button id="Edit" type="button"
                    class="btn btn-outline-secondary items tops "onclick="editlook()">Edit</button>
                <button id="delete" type="button"
                    class="btn btn-outline-secondary items tops" onclick="deletelook(${value.imgid})">Delete</button>
            </section>
            </div>`;
            $("#hanger").append(link);
        });
    });

    overlays = document.getElementsByClassName("overlay");
});

function editlook(){
    window.location.href = "createLook"; 
}

    function deletelook(id){
        lightbox.modal("show")
        document.getElementById("confirmdelete").onclick = function(){
            lightbox.modal("hide")
        }
    }

    function showoverlay(id){
        if(overlays[id - 1].style.display == "none")
            overlays[id- 1].style.display = "block";
        else    
            overlays[id - 1].style.display = "none"
    }

    function showoverlay2(id){
        if(overlays[id - 1].style.display == "none")
            overlays[id- 1].style.display = "block";
        else    
            overlays[id - 1].style.display = "none"
    }
