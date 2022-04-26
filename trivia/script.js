
const wrong_answer_1 = document.querySelector('.wrong_1');
const wrong_answer_2 = document.querySelector('.wrong_2');
const correct_answer = document.querySelector('.correct');
const popup_text = document.querySelector('.popup_text');

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

