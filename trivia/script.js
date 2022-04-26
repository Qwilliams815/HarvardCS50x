// function correct_answer() {
//     const correct_text = document.querySelector('.correct');
//     correct_text.style.backgroundColor = 'green';
//     console.log("hello world");
// };

// function wrong_answer() {
//     const wrong_text = document.querySelector('.wrong');
//     wrong_text.style.backgroundColor = 'red';
// }
const correct_text = document.querySelector('.correct_popup');
const wrong_text = document.querySelector('.incorrect_popup');
let text_status = false;

const wrong_answer_1 = document.querySelector('.wrong_1');
const wrong_answer_2 = document.querySelector('.wrong_2');
const correct_answer = document.querySelector('.correct');

wrong_answer_1.addEventListener('click', function() {
    wrong_answer_1.style.backgroundColor = 'red';

})

wrong_answer_2.addEventListener('click', function() {
    wrong_answer_2.style.backgroundColor = 'red';
})

correct_answer.addEventListener('click', function() {
    correct_answer.style.backgroundColor = 'green';
})

