$(document).ready(function () {
  $(".more-q").click(function () {
    document
      .getElementById("more-questionnaire")
      .scrollIntoView({ behavior: "smooth" });
  });
});

var exp;
var loc;
var zipcode;


$(document).ready(function () {
  $(".exp").click(function () {
    exp = $(this).text();
  });
});

$(document).ready(function () {
  $(".loc").click(function () {
    loc = $(this).text();
  });
});

$(document).ready(function () {
  $("#zipcode").click(function () {
    zipcode = $(this).val();
  });
  $(".slider__navlink").click(function () {
    zipcode = $("#zipcode").val();
  });
});

var data

$(document).ready(function () {
   $("#submit").click(function () {
    var gp = $("#growing-period").val();
    var ml = $("#maintenance-level").val();
    var space = $("#space").val();
     

    data = {"zipcode": zipcode,
            "experience-level": exp,
            "location": loc,
            "growing-period": gp,
            "maintenance-level": ml,
            "space": space};
    
  var xmlhttp = new XMLHttpRequest();
  var dest = "/json-handler"; // **backend json-handler
  xmlhttp.open("POST", dest);
  xmlhttp.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
  xmlhttp.send(JSON.stringify(data));
  console.log(zipcode);
  console.log(JSON.stringify(data));
  
  });
});
