
const wrong_answer_1 = document.querySelector('.wrong_1');
const wrong_answer_2 = document.querySelector('.wrong_2');
const correct_answer = document.querySelector('.correct');
const popup_text = document.querySelector('.popup_text');

const input_field = document.querySelector('.free_response_input');
const submit_btn = document.querySelector('.submit_button');

const text_answer = "brian";

wrong_answer_1.addEventListener('click', function() {
    wrong_answer_1.style.backgroundColor = 'red';
    popup_text.innerHTML = "Incorrect";
})

wrong_answer_2.addEventListener('click', function() {
    wrong_answer_2.style.backgroundColor = 'red';
    popup_text.innerHTML = "Incorrect";
})

correct_answer.addEventListener('click', function() {
    correct_answer.style.backgroundColor = 'green';
    popup_text.innerHTML = "Correct!";
})


submit_btn.addEventListener('click', function() {
    if (input_field.value.toLowerCase() == text_answer) {
        input_field.style.backgroundColor = 'green';
    } else {
        input_field.style.backgroundColor = 'red';
    }
})