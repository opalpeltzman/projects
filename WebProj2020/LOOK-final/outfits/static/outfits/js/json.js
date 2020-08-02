




$(document).ready(function(){
    
    $.getJSON("../data/items.json", function(data){

        $each(data.stylist, function(){
            
        $('#allStylists').append("<div><img src=" + this.img + "></div>");   
    });
});
});