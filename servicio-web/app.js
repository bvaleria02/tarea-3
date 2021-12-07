var menu_status = 0;
var operationToggle = 0;

document.querySelector(".header_button_1").addEventListener("click", () => {
    if (!operationToggle)toggleMenu();
    });
document.querySelector("#lateral_back").addEventListener("click", () => {
    toggleMenu();
    });
document.querySelector("#darkness_fg").addEventListener("click", () => {
    if(menu_status) toggleMenu();
    });

function toggleMenu (){
        document.querySelector(".article_main").classList.toggle("article_blur");
        document.querySelector(".dark_visibility").classList.toggle("dark_visibility-show");
        document.querySelector(".lateral_visibility").classList.toggle("lateral_visibility-show");
        menu_status = menu_status ^ 0x1;
        };
