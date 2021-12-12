var flags = [0, 0, 0, 0, 0, 0];

document.querySelector("#wow-in-1").addEventListener("click", () => {
    addChar("N");
    flags[0] = 1;
});

document.querySelector("#wow-in-2").addEventListener("click", () => {
    addChar("L");
    flags[1] = 1;
});

document.querySelector("#wow-in-3").addEventListener("click", () => {
    addChar("A");
    flags[2] = 1;
});

document.querySelector("#wow-in-4").addEventListener("click", () => {
    deleteAll();
});

document.querySelector("#wow-in-5").addEventListener("click", () => {
    addChar("B");
    flags[3] = 1;
});

document.querySelector("#wow-in-6").addEventListener("click", () => {
    addChar("O");
    flags[4] = 1;
});

document.querySelector("#wow-in-7").addEventListener("click", () => {
    addChar("C");
    flags[5] = 1;
});

document.querySelector("#wow-in-8").addEventListener("click", () => {
    enterWord();
});

function addChar (input_char){
  switch(input_char){
      case 'N'  : if (flags[0] == 1) input_char = '';
                  break;
      case 'L'  : if (flags[1] == 1) input_char = '';
                  break;
      case 'A'  : if (flags[2] == 1) input_char = '';
                  break;
      case 'B'  : if (flags[3] == 1) input_char = '';
                  break;
      case 'O'  : if (flags[4] == 1) input_char = '';
                  break;
      case 'C'  : if (flags[5] == 1) input_char = '';
                  break;
  };
  let text = document.querySelector("#wow-text").value;
  document.querySelector("#wow-text").value = text + input_char;
  return;
}

function deleteAll (){
  document.querySelector("#wow-text").value = "";
  flags = [0, 0, 0, 0, 0, 0];
  return;
}

function enterWord(){
  let text = document.querySelector("#wow-text").value;
  console.log(text);
  switch(text){
    case "BOCA"   : document.querySelector("#square-25").textContent = 'B';
                    document.querySelector("#square-26").textContent = 'O';
                    document.querySelector("#square-27").textContent = 'C';
                    document.querySelector("#square-28").textContent = 'A';

                    document.querySelector("#square-25").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-26").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-27").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-28").style.backgroundColor="#FFFFFFD0";
                    break;
    case "BALON"  : document.querySelector("#square-4").textContent = 'B';
                    document.querySelector("#square-5").textContent = 'A';
                    document.querySelector("#square-6").textContent = 'L';
                    document.querySelector("#square-7").textContent = 'O';
                    document.querySelector("#square-8").textContent = 'N';

                    document.querySelector("#square-4").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-5").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-6").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-7").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-8").style.backgroundColor="#FFFFFFD0";
                    break;
    case "BLANCO" : document.querySelector("#square-16").textContent = 'B';
                    document.querySelector("#square-17").textContent = 'L';
                    document.querySelector("#square-18").textContent = 'A';
                    document.querySelector("#square-19").textContent = 'N';
                    document.querySelector("#square-20").textContent = 'C';
                    document.querySelector("#square-21").textContent = 'O';

                    document.querySelector("#square-16").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-17").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-18").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-19").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-20").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-21").style.backgroundColor="#FFFFFFD0";
                    break;
    case "BANCO"  : document.querySelector("#square-1").textContent = 'B';
                    document.querySelector("#square-3").textContent = 'A';
                    document.querySelector("#square-8").textContent = 'N';
                    document.querySelector("#square-12").textContent = 'C';
                    document.querySelector("#square-21").textContent = 'O';

                    document.querySelector("#square-1").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-3").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-8").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-12").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-21").style.backgroundColor="#FFFFFFD0";

                    break;
    case "COLA"   : document.querySelector("#square-12").textContent = 'C';
                    document.querySelector("#square-13").textContent = 'O';
                    document.querySelector("#square-14").textContent = 'L';
                    document.querySelector("#square-15").textContent = 'A';

                    document.querySelector("#square-12").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-13").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-14").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-15").style.backgroundColor="#FFFFFFD0";
                                    break;
    case "CABO"   : document.querySelector("#square-9").textContent = 'C';
                    document.querySelector("#square-15").textContent = 'A';
                    document.querySelector("#square-22").textContent = 'B';
                    document.querySelector("#square-24").textContent = 'O';

                    document.querySelector("#square-9").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-15").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-22").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-24").style.backgroundColor="#FFFFFFD0";

                    break;
    case "BALCON" : document.querySelector("#square-4").textContent = 'B';
                    document.querySelector("#square-10").textContent = 'A';
                    document.querySelector("#square-17").textContent = 'L';
                    document.querySelector("#square-23").textContent = 'C';
                    document.querySelector("#square-26").textContent = 'O';
                    document.querySelector("#square-29").textContent = 'N';

                    document.querySelector("#square-4").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-10").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-17").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-23").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-26").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-29").style.backgroundColor="#FFFFFFD0";

                    break;
    case "CLAN"   : document.querySelector("#square-2").textContent = 'C';
                    document.querySelector("#square-6").textContent = 'L';
                    document.querySelector("#square-11").textContent = 'A';
                    document.querySelector("#square-19").textContent = 'N';

                    document.querySelector("#square-2").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-6").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-11").style.backgroundColor="#FFFFFFD0";
                    document.querySelector("#square-19").style.backgroundColor="#FFFFFFD0";

                    break;
  };
  document.querySelector("#wow-text").value = "";
  flags = [0, 0, 0, 0, 0, 0];
  return;
}
