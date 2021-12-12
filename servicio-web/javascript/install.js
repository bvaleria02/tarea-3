var active = 1;
var timerAnimations = window.setInterval(changeSlide, 5000);

refreshSize();


document.querySelector("#button-1").addEventListener("click", () => {
  if (active == 1) window.location.href = "#article-1";
  active = 1;
  refreshSize();
});

document.querySelector("#button-2").addEventListener("click", () => {
  if (active == 2) window.location.href = "#article-2";
  active = 2;
  refreshSize();
});

document.querySelector("#button-3").addEventListener("click", () => {
  if (active == 3) window.location.href = "#article-3";
  active = 3;
  refreshSize();
});

document.querySelector("#button-4").addEventListener("click", () => {
  if (active == 4) window.location.href = "#article-4";
  active = 4;
  refreshSize();
});

document.querySelector("#button-5").addEventListener("click", () => {
  if (active == 5) window.location.href = "#article-5";
  active = 5;
  refreshSize();
});

document.querySelector("#button-6").addEventListener("click", () => {
  if (active == 6) window.location.href = "#article-6"; 
  active = 6;
  refreshSize();
});

function refreshSize () {
  clearInterval(timerAnimations);
  timerAnimations = window.setInterval(changeSlide, 5000);
  console.log(active);
  let stringInput;
  shrinkAll();
  switch(active){
    case 1  : document.querySelector("#button-1").style.width="35%";
              stringInput = document.querySelector("#text-d-1").textContent;
              document.querySelector("#text-1").textContent = stringInput;
              document.querySelector("#img-top-1").style.opacity="100%";
              break;
    case 2  : document.querySelector("#button-2").style.width="35%";
              stringInput = document.querySelector("#text-d-2").textContent;
              document.querySelector("#text-1").textContent = stringInput;
              document.querySelector("#img-top-2").style.opacity="100%";
              break;
    case 3  : document.querySelector("#button-3").style.width="35%";
              stringInput = document.querySelector("#text-d-3").textContent;
              document.querySelector("#text-1").textContent = stringInput;
              document.querySelector("#img-top-3").style.opacity="100%";
              break;
    case 4  : document.querySelector("#button-4").style.width="35%";
              stringInput = document.querySelector("#text-d-4").textContent;
              document.querySelector("#text-1").textContent = stringInput;
              document.querySelector("#img-top-4").style.opacity="100%";
              break;
    case 5  : document.querySelector("#button-5").style.width="35%";
              stringInput = document.querySelector("#text-d-5").textContent;
              document.querySelector("#text-1").textContent = stringInput;
              document.querySelector("#img-top-5").style.opacity="100%";
              break;
    case 6  : document.querySelector("#button-6").style.width="35%";
              stringInput = document.querySelector("#text-d-6").textContent;
              document.querySelector("#text-1").textContent = stringInput;
              document.querySelector("#img-top-6").style.opacity="100%";
              break;
  };
  return;
}

function shrinkAll () {
  document.querySelector("#button-1").style.width="13%";
  document.querySelector("#button-2").style.width="13%";
  document.querySelector("#button-3").style.width="13%";
  document.querySelector("#button-4").style.width="13%";
  document.querySelector("#button-5").style.width="13%";
  document.querySelector("#button-6").style.width="13%";

  document.querySelector("#img-top-1").style.opacity="0%";
  document.querySelector("#img-top-2").style.opacity="0%";
  document.querySelector("#img-top-3").style.opacity="0%";
  document.querySelector("#img-top-4").style.opacity="0%";
  document.querySelector("#img-top-5").style.opacity="0%";
  document.querySelector("#img-top-6").style.opacity="0%";
  return;
}

function changeSlide (){
  active++;
  if(active == 7) active = 1;
  refreshSize();
  return;
}
