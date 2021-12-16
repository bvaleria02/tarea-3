var mode = 0;
var counter = 0;

resize_init(0);
var writeAnimation = window.setInterval(animationCounter, 20);

document.querySelector("#bg-2").addEventListener("click", () => {
  document.querySelector("#bg-2").style.width="20%";
});

document.querySelector("#bg-3").addEventListener("click", () => {
  document.querySelector("#bg-3").style.width="20%";
});

document.querySelector("#bg-1").addEventListener("click", () => {
  if (mode == 1) mode = mode ^ 0x1;
  counter = 0;
  resize_init(mode);
});

document.querySelector("#bg-4").addEventListener("click", () => {
  if (mode == 0) mode = mode ^ 0x1;
  counter = 0;
  resize_init(mode);
});

document.querySelector("article").addEventListener("click", () => {
  mode = mode ^ 0x1;
  counter = 0;
  resize_init(mode);
});

function resize_init (input) {
  switch(input){
    case 0  : document.querySelector("#bg-1").style.width="10%";
              document.querySelector("#bg-2").style.width="5%";
              document.querySelector("#bg-3").style.width="5%";
              document.querySelector("#bg-4").style.width="80%";
              break;
    case 1  : document.querySelector("#bg-1").style.width="80%";
              document.querySelector("#bg-2").style.width="5%";
              document.querySelector("#bg-3").style.width="5%";
              document.querySelector("#bg-4").style.width="10%";
              break;
  };
  textAnimation(input);
  return;
}

function textAnimation (input){
  switch(input){
    case 0  : document.querySelector(".contact-frame").classList.remove("contact-frame-active");
              document.querySelector(".about-frame").classList.add("about-frame-active");
              break;
    case 1  : document.querySelector(".contact-frame").classList.add("contact-frame-active");
              document.querySelector(".about-frame").classList.remove("about-frame-active");
              break;
  };
  return 0;
}

function animationCounter () {
  counter++;
  if (counter > 20) reloadAnimation(mode);
  console.log(counter);
  return counter;
}

function reloadAnimation (input){
  switch(input){
    case 0  : if (counter == 120) ;

              if (counter == 16) document.querySelector("#table-6-2").style.height = "40rem";
              if (counter == 24) document.querySelector("#table-5-2").style.height = "40rem";
              if (counter == 32) document.querySelector("#table-4-2").style.height = "40rem";
              if (counter == 40) document.querySelector("#table-3-2").style.height = "40rem";
              if (counter == 48) document.querySelector("#table-2-2").style.height = "40rem";
              if (counter == 56) document.querySelector("#table-1-2").style.height = "40rem";

              if (counter == 128) document.querySelector("#table-1-1").style.height = "3rem";
              if (counter == 136) document.querySelector("#table-2-1").style.height = "3rem";
              if (counter == 144) document.querySelector("#table-3-1").style.height = "3rem";
              if (counter == 152) document.querySelector("#table-4-1").style.height = "3rem";
              if (counter == 160) document.querySelector("#table-5-1").style.height = "3rem";
              if (counter == 168) document.querySelector("#table-6-1").style.height = "3rem";
              if (counter == 176) document.querySelector("#about-bottom-text").style.opacity = "100%";
              break;
    case 1  :
              if (counter == 16) document.querySelector("#table-6-1").style.height = "40rem";
              if (counter == 24) document.querySelector("#table-5-1").style.height = "40rem";
              if (counter == 32) document.querySelector("#table-4-1").style.height = "40rem";
              if (counter == 40) document.querySelector("#table-3-1").style.height = "40rem";
              if (counter == 48) document.querySelector("#table-2-1").style.height = "40rem";
              if (counter == 56) document.querySelector("#table-1-1").style.height = "40rem";
              if (counter == 64) document.querySelector("#about-bottom-text").style.opacity = "0%";

              if (counter == 128) document.querySelector("#table-1-2").style.height = "3rem";
              if (counter == 136) document.querySelector("#table-2-2").style.height = "3rem";
              if (counter == 144) document.querySelector("#table-3-2").style.height = "3rem";
              if (counter == 152) document.querySelector("#table-4-2").style.height = "3rem";
              if (counter == 160) document.querySelector("#table-5-2").style.height = "3rem";
              if (counter == 168) document.querySelector("#table-6-2").style.height = "3rem";
              break;
  };
  return;
}
