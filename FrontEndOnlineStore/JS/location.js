$.extend({
    redirectPost: function(location, lat,long)
    {
       var globaljson;
        $.post(location,
        {
          'lat' : lat,
          'long': long
        },
        function(data,status){
          console.log(JSON.stringify(data));
          //  globaljson = JSON.stringify(data);
        }, 'json');

        // console.log(globaljson)
        // localStorage.setItem("storejson", form);
        //
        // $('<form action="storelist.html" id="storejson" method="POST"></form>').appendTo('body').submit();


    }
});



var x = document.getElementById("demo");
function getLocation() {
    if (navigator.geolocation) {
        navigator.geolocation.getCurrentPosition(showPosition);
    } else {
        x.innerHTML = "Geolocation is not supported by this browser.";
    }
}
function showPosition(position) {
    var lat = position.coords.latitude;
    var long = position.coords.longitude;
    $.redirectPost("https://onlinegrocerystore.herokuapp.com/searchedlocation/",lat,long)
}
