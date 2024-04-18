let button = document.getElementById("btn");
let button_left = document.getElementById("btn_arrow_left");
let button_right = document.getElementById("btn_arrow_right");
let counter = 0;
let http_response;

function move_step(j){
    let from = http_response[j].from.y * 4 + http_response[j].from.x;
    let to = http_response[j].to.y * 4 + http_response[j].to.x;
    let tempo = document.getElementById(`${from}`).value

    document.getElementById(`${from}`).value = document.getElementById(`${to}`).value;
    document.getElementById(`${to}`).value = tempo;
}

button.addEventListener("click", function ssanina() {
    let arr = [];

    for (let i = 0; i < 15; i++) {
        let tmp = document.getElementById(`${i}`).value;
        arr.push(tmp);
    }

    let http_request = new XMLHttpRequest();

    http_request.onreadystatechange = function() {
        if (this.readyState === 4 && this.status === 200) {
            http_response = JSON.parse(this.responseText);
        }
    }
    http_request.open("GET", "http://localhost:8080/?array=" + arr, true);
    http_request.send();

    button_right.hidden = false;
});

button_right.addEventListener("click", function (){
    move_step(counter);

    counter++;

    button_left.hidden = false;
    if (counter >= http_response.length) {
        button_right.hidden = true;
    }
})

button_left.addEventListener("click", function (){
    counter--;

    move_step(counter);

    button_right.hidden = false;
    if (counter === 0) {
        button_left.hidden = true;
    }
})
