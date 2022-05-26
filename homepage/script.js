const modal = document.querySelector(".modal-wrapper");
const bodyWrapper = document.querySelector("wrapper");
const modalXBtn = document.querySelector(".x-btn");
const signInBtn = document.querySelector(".profile-btn");
let profileName = document.querySelector(".profile-btn");
const modalSubmitBtn = document.querySelector(".submit");
const usernameInput = document.querySelector("#username");
const passwordInput = document.querySelector("#password");

if (localStorage.getItem("ProfileName")) {
    profileName.innerHTML = localStorage.getItem("ProfileName");
};

signInBtn.addEventListener("click", (e) => {
    modal.classList.add("modal-active");
    bodyWrapper.classList.add("blur-effect");
    console.log(profileName.innerHTML);
});

modalXBtn.addEventListener("click", (e) => {
    if (localStorage.getItem("ProfileName")) {
        profileName.innerHTML = localStorage.getItem("ProfileName");
    } else {
        profileName.innerHTML = "Sign in";
    }
    modal.classList.remove("modal-active");
    bodyWrapper.classList.remove('blur-effect');
});

modalSubmitBtn.addEventListener("click", (e) => {
    profileName.innerHTML = document.getElementById("username").value;
    localStorage.setItem("ProfileName", profileName.innerHTML);

    if (usernameInput.value.trim().length != 0 && passwordInput.value.trim().length != 0) {
        modal.classList.remove("modal-active");
        bodyWrapper.classList.remove('blur-effect');
    }
});


