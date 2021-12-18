var slide_position = 1;

main(0)

var timerAnimations = window.setInterval(main, 5000);

document.querySelector("#slider_button-left").addEventListener("click", () => {
        main(0);
        clearInterval(timerAnimations);
        timerAnimations = window.setInterval(main, 5000);
});

document.querySelector("#slider_button-right").addEventListener("click", () => {
        main(1);
        clearInterval(timerAnimations);
        timerAnimations = window.setInterval(main, 5000);
});

function main(input){
  switch(input){
    case 0  : if(slide_position == 0) {
                slide_position = 3;
                  } else {
               slide_position--;
                  };
              sliderLeft(slide_position);
              break;
    default  : if(slide_position == 3) {
              slide_position = 0;
                 } else {
              slide_position++;
                 };
              sliderRight(slide_position);
              break;
  };
  changeText(slide_position);
  console.log(slide_position);
  return
}


function sliderLeft(position){
  switch (position) {
                case 0  : document.querySelector("#slider_image_1").style.right="";
                          document.querySelector("#slider_image_1").style.left="0%";
                          document.querySelector("#slider_image_1").style.width="100%";
                          document.querySelector("#slider_image_2").style.left="";
                          document.querySelector("#slider_image_2").style.right="0%";
                          document.querySelector("#slider_image_2").style.width="0%";
                          break;
                case 1  : document.querySelector("#slider_image_2").style.right="";
                          document.querySelector("#slider_image_2").style.left="0%";
                          document.querySelector("#slider_image_2").style.width="100%";
                          document.querySelector("#slider_image_3").style.left="";
                          document.querySelector("#slider_image_3").style.right="0%";
                          document.querySelector("#slider_image_3").style.width="0%";
                          break;
                case 2  : document.querySelector("#slider_image_3").style.right="";
                          document.querySelector("#slider_image_3").style.left="0%";
                          document.querySelector("#slider_image_3").style.width="100%";
                          document.querySelector("#slider_image_4").style.left="";
                          document.querySelector("#slider_image_4").style.right="0%";
                          document.querySelector("#slider_image_4").style.width="0%";
                          break;
                case 3  : document.querySelector("#slider_image_4").style.right="";
                          document.querySelector("#slider_image_4").style.left="0%";
                          document.querySelector("#slider_image_4").style.width="100%";
                          document.querySelector("#slider_image_1").style.left="";
                          document.querySelector("#slider_image_1").style.right="0%";
                          document.querySelector("#slider_image_1").style.width="0%";
                          break;
};
    return;
}

function sliderRight(position){
  switch (position) {
                case 0  : document.querySelector("#slider_image_1").style.left="";
                          document.querySelector("#slider_image_1").style.right="0%";
                          document.querySelector("#slider_image_1").style.width="100%";
                          document.querySelector("#slider_image_4").style.right="";
                          document.querySelector("#slider_image_4").style.left="0%";
                          document.querySelector("#slider_image_4").style.width="0%";
                          break;
                case 1  : document.querySelector("#slider_image_2").style.left="";
                          document.querySelector("#slider_image_2").style.right="0%";
                          document.querySelector("#slider_image_2").style.width="100%";
                          document.querySelector("#slider_image_1").style.right="";
                          document.querySelector("#slider_image_1").style.left="0%";
                          document.querySelector("#slider_image_1").style.width="0%";
                          break;
                case 2  : document.querySelector("#slider_image_3").style.left="";
                          document.querySelector("#slider_image_3").style.right="0%";
                          document.querySelector("#slider_image_3").style.width="100%";
                          document.querySelector("#slider_image_2").style.right="";
                          document.querySelector("#slider_image_2").style.left="0%";
                          document.querySelector("#slider_image_2").style.width="0%";
                          break;
                case 3  : document.querySelector("#slider_image_4").style.left="";
                          document.querySelector("#slider_image_4").style.right="0%";
                          document.querySelector("#slider_image_4").style.width="100%";
                          document.querySelector("#slider_image_3").style.right="";
                          document.querySelector("#slider_image_3").style.left="0%";
                          document.querySelector("#slider_image_3").style.width="0%";
                          break;
};
      return;
  }

function changeText(input){
  let stringInput;
  switch (input) {
    case 0  : stringInput = "Separación de palabras";
              break;
    case 1  : stringInput = "Múltiples filtros";
              break;
    case 2  : stringInput = "Exportar a un archivo";
              break;
    case 3  : stringInput = "Modularidad";
              break;
  };
  document.querySelector("#slider_text-bottom").textContent = stringInput;
  return;
}
