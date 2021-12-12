var enableWrite1 = 0;
var enableWrite2 = 0;
var enableWrite3 = 0;

var counter1 = 0;
var counter2 = 0;
var counter3 = 0;

var endFlag1 = 0;
var endFlag2 = 0;
var endFlag3 = 0;

var title1 = document.querySelector("#table_button-1").innerHTML;
var title2 = document.querySelector("#table_button-2").innerHTML;
var title3 = document.querySelector("#table_button-3").innerHTML;

var text1 = document.querySelector("#table_disabled-1").innerHTML;
var text2 = document.querySelector("#table_disabled-2").innerHTML;
var text3 = document.querySelector("#table_disabled-3").innerHTML;


document.querySelector("#table_button-1").innerHTML = "^";
document.querySelector("#table_button-2").innerHTML = "^";
document.querySelector("#table_button-3").innerHTML = "^";

document.querySelector("#table_disabled-1").innerHTML = "";
document.querySelector("#table_disabled-2").innerHTML = "";
document.querySelector("#table_disabled-3").innerHTML = "";

var writeAnimation = window.setInterval(writeStatus, 15);

document.querySelector("#table_button-1").addEventListener("click", () => {
  document.querySelector("#table_button-1").classList.toggle("active_menu");
  enableWrite1 = enableWrite1 ^ 0x1
  counter1 = 0;
  if (enableWrite1 == 1) {
    document.querySelector("#table_button-1").innerHTML = title1;
    writeAnimation = window.setInterval(writeStatus, 15);
  };
  if (enableWrite1 == 0) {
    document.querySelector("#table_button-1").innerHTML = "^";
    document.querySelector("#table_disabled-1").innerHTML = "";
    document.querySelector("#table_link-1").classList.remove("link_active");
    endFlag1 = 0
  };
});


document.querySelector("#table_button-2").addEventListener("click", () => {
  document.querySelector("#table_button-2").classList.toggle("active_menu");
  enableWrite2 = enableWrite2 ^ 0x1;
  counter2 = 0;
  if (enableWrite2 == 1) {
    document.querySelector("#table_button-2").innerHTML = title2;
    writeAnimation = window.setInterval(writeStatus, 15);
  };
  if (enableWrite2 == 0) {
    document.querySelector("#table_button-2").innerHTML = "^";
    document.querySelector("#table_disabled-2").innerHTML = "";
    document.querySelector("#table_link-2").classList.remove("link_active");
    endFlag2 = 0
  };
});


document.querySelector("#table_button-3").addEventListener("click", () => {
  document.querySelector("#table_button-3").classList.toggle("active_menu");
  enableWrite3 = enableWrite3 ^ 0x1;
  counter3 = 0;
  if (enableWrite3 == 1) {
    document.querySelector("#table_button-3").innerHTML = title3;
    writeAnimation = window.setInterval(writeStatus, 15);
  };
  if (enableWrite3 == 0) {
    document.querySelector("#table_button-3").innerHTML = "^";
    document.querySelector("#table_disabled-3").innerHTML = "";
    document.querySelector("#table_link-3").classList.remove("link_active");
    endFlag3 = 0
  };
});

function writeStatus(){

  if (enableWrite1 == 1) writeIn(1, counter1);
  if (enableWrite2 == 1) writeIn(2, counter2);
  if (enableWrite3 == 1) writeIn(3, counter3);
  if (endFlag1 == 1 && endFlag2 == 1 && endFlag3 == 1) clearInterval(writeAnimation);
}

function writeIn (input, i){
  let stringBuffer = "";
  if(i > 512) return;
  switch (input) {
      case 1  : if (i == 0) document.querySelector("#table_disabled-1").innerHTML = "";
                stringBuffer = document.querySelector("#table_disabled-1").innerHTML;
                if (text1[i] == undefined) {
                  endFlag1 = 1;
                  document.querySelector("#table_link-1").classList.add("link_active");
                  break;
                };
                document.querySelector("#table_disabled-1").innerHTML = stringBuffer + text1[i];
                counter1++;
                break;
      case 2  : if (i == 0) document.querySelector("#table_disabled-2").innerHTML = "";
                stringBuffer = document.querySelector("#table_disabled-2").innerHTML;
                if (text2[i] == undefined) {
                  endFlag2 = 1;
                  document.querySelector("#table_link-2").classList.add("link_active");
                  break;
                };
                document.querySelector("#table_disabled-2").innerHTML = stringBuffer + text2[i];
                counter2++;
                break;
      case 3  : if (i == 0) document.querySelector("#table_disabled-3").innerHTML = "";
                stringBuffer = document.querySelector("#table_disabled-3").innerHTML;
                if (text3[i] == undefined) {
                  endFlag3 = 1;
                  document.querySelector("#table_link-3").classList.add("link_active");
                  break;
                };
                document.querySelector("#table_disabled-3").innerHTML = stringBuffer + text3[i];
                counter3++;
                break;
  };

}
