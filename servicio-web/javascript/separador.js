var wordsInput;
var charInput;
var lengthFilter;
var methodFilter;
var keyPress;
var wordsOutput;

var charLength = 0;
var compareFlags = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
var charFilter = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
var spChar = 0;

var bufferWord = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
var bufferStr = "";

var offset = 0;

var htmlOutput;
var noInput;


document.querySelector("#form_input-5").addEventListener("click", () => {
                    screen_in();
                    setTimeout(doSomething, 1000);
                    setTimeout(screen_out, 2000);
                  });

function doSomething(){
  wordsInput    = document.querySelector('#form_input-1').value;
  charInput     = document.querySelector('#form_input-2').value;
  lengthFilter  = document.querySelector('#form_input-3').value;
  methodFilter  = document.querySelector('#form_input-4').value;
  if(!!! wordsInput){
      document.querySelector("#form_output-1").innerHTML = "Debe ingresar palabras para que puedan ser filtradas";
      return
    };
  if(!!! charInput){
      document.querySelector("#form_output-1").innerHTML = "Debe ingresar un filtro por letras en el campo inferior izquierdo";
      return
    };

  wordsInput = wordsInput + "\n";
  offset = 0;
  document.querySelector("#form_output-1").innerHTML = "";
  prepareChar();
  compareWords();
  return;
}


function prepareChar(){
      charLength = 0;
      charFilter = ["", "", "", "", "", "", "", "", "", "", "", "",];
      for (let i = 0; i < 24; i++) {
        if(charInput[i] != '\s' && charInput[i] != undefined && charInput[i] != ' '){
          charFilter[charLength] = String.fromCharCode(charInput.charCodeAt(i) & 0xDF);
          charLength++;
        };
      };
      charFilter[charLength] = '\0'
      // console.log(charInput);
      return;
}

function compareWords(){
      let wordLength = 0;
      let lenghtFlag = 0;
      let charFilterFlag = 0;
      let writeFlag = 0;
      while(offset < 8192){
          wordLength = strlen(wordsInput, offset);
          wordLength = wordLength - spChar;
          lenghtFlag= filterByLength(wordLength);
          storeBufferString(wordsInput, offset, wordLength);
          charFilterFlag = filterByInput();
          offset = offset + wordLength + spChar + 1;
          writeFlag = lenghtFlag & charFilterFlag;
          if (writeFlag) {
              htmlOutput = document.querySelector("#form_output-1").textContent + bufferStr + '\n';
              document.querySelector("#form_output-1").textContent = htmlOutput;
          };
        };
        htmlOutput = document.querySelector("#form_output-1").textContent;
        if(htmlOutput == "") document.querySelector("#form_output-1").textContent = "No hay resultados\nPruebe modificando los parámetros de búsqueda";
      return;
}

function strlen (string_input, offset){
    let length = 0;
    let status = 1;
    spChar = 0;
    while (status) {
        if (string_input[offset + length + spChar] == ' ' | string_input[offset + length + spChar] == '\n' | string_input[offset + length + spChar] == '' | string_input[offset + length + spChar] == '\0') status = 0;
        if (string_input[length + offset + spChar] == 'á' && string_input[length + offset + spChar] == 'Á' &&
            string_input[length + offset + spChar] == 'é' && string_input[length + offset + spChar] == 'É' &&
            string_input[length + offset + spChar] == 'í' && string_input[length + offset + spChar] == 'Í' &&
            string_input[length + offset + spChar] == 'ó' && string_input[length + offset + spChar] == 'Ó' &&
            string_input[length + offset + spChar] == 'ú' && string_input[length + offset + spChar] == 'U') spChar++;
        if ((length + offset + spChar) > 8192) status = 0;
        if (status == 1) length++;
    };
    return length;
}

function filterByLength (length){
  let filter = 0;
  // console.log("filter mode: " + methodFilter + " l1: " + length + " l2: " + lengthFilter);
  switch(methodFilter){
      case '1'  : filter = 1;
                break;
      case '2'  : if (length < lengthFilter) filter = 1;
                break;
      case '3'  : if (length == lengthFilter) filter = 1;
                break;
      case '4'  : if (length > lengthFilter) filter = 1;
                break;
      case '5'  : if (length <= lengthFilter) filter = 1;
                break;
      case '6'  : if (length >= lengthFilter) filter = 1;
                break;
      case '7'  : if (length != lengthFilter) filter = 1;
                break;
  };
  return filter;
}

function storeBufferString(text, offset, length){
  bufferWord = ['', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', ''];
  for (let i = 0; i < length; i++) {
    bufferWord[i] = text[offset + i];
  };
  bufferWord.join("+");
  // bufferWord[offset + length] = '\0';
  return;
}

function filterByInput(){
  bufferStr = bufferWord.join("");

  let str_length = strlen(bufferWord, 0);
  str_length = str_length - spChar;
  let flagAddition = 0;
  let a = '';
  compareFlags = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
  for (var i = 0; i < str_length; i++) {
      for (let j = 0; j < charLength; j++) {
        // a = String.fromCharCode(bufferWord.charCodeAt(i) & 0xDF);
        a = String.fromCharCode(bufferStr.charCodeAt(i) & 0xDF);
        switch(a){
            case 'Á'  :  a = 'A';
                          break;
            case 'É'  :  a = 'E';
                          break;
            case 'Í'  :  a = 'I';
                           break;
            case 'Ó'  :  a = 'O';
                           break;
            case 'Ú'  :  a = 'U';
                         break;
        };
        if(a == charFilter[j]){
            compareFlags[j] = compareFlags[j]  | 0x1;
            j = 200;
          };
      };
  };
  for (var i = 0; i < charLength; i++) {
    flagAddition = flagAddition + compareFlags[i];
  };
  if (flagAddition != charLength) return 0;
  return 1;
}

function screen_in(){
    document.querySelector(".wait_overlay").classList.toggle("wait_overlay-show");
    document.querySelector(".wait_main").classList.toggle("wait_frame-show");
    document.querySelector(".article_main").classList.toggle("article_blur");
    operationToggle = 1;
    return;
}

function screen_out(){
    document.querySelector(".wait_overlay").classList.toggle("wait_overlay-show");
    document.querySelector(".wait_main").classList.toggle("wait_frame-show");
    document.querySelector(".article_main").classList.toggle("article_blur");
    operationToggle = 0;
    return;
}
