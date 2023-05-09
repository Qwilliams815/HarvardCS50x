### WebAccessibilityChromeExt

#### Video Demo: https://youtu.be/PoLH6ATrkCc

# Description -

A Chrome extension compilation of 6 togglable popup widgets, each with their own unique ability to read/manipulate the current webpage DOM.

# Purpose -

Created as a final project for the Harvard CS50x course, and to assist with a variety of visual and auditory disabilities.

# The Widgets -

Here is a list of all the widgets, along with a short description:

- **Dictionary**: Upon double clicking a word, uses the dictionary API from https://dictionaryapi.dev/ to display a small tooltip containing the word itself, definition, and hyperlink to a more in depth definition.
- **Screen Reader**: Utilizes SpeechSynthesis of JavaScript's built in Web Speech API to read any block of text selected by the user. This widget also includes 3 different reading speed options.
- **Page Structure**: Launches a modal that displays a concise structure of the headers and their corresponding articles in accordian fashion. Complete with anchor tag links to quickly navigate to any particular section.
- **Text Size**: Uses the chrome.tabs.setZoom() method to quickly adjust page magnification based on the selection from 1 of 3 magnification options((S) Small, (M) Medium, (L) Large).
- **Line Height**: Scrapes all text from a webpage and manipulates the (you guessed it) line-height style of each element.
- **Word Spacing**: Uses the same gathered text as line Height to manipulate the word-spacing style of each element.

**NOTE:** This extensions also allows you to save all of your widget configurations across multiple tabs by storing your saved preferences in Chrome's local storage.

# The Files -

- Popup (popup.js, popup.html, popup_styles.css): These 3 files handle the logic, layout, and styling of the popup window launched when you click the extension icon. Popup.js is responsible for handling widget activation and sending messages to the content script to follow through on widget functionality, as well as writing widget activation status to local storage.

- Content (content_script.js, content_styles.css): These are file that get injected into a web page when it becomes active. Content.js handles all the widget logic when it receives the OK from popup.js. This involves adding event listeners to text, creating a showdow host element for the dictionary and page structure shadowDOM modals, and various API calls. Content_script.js is also responsible for reading and activating widget activation status from local storage. This is important because we want our preferences to run on the page before activating the popup.

- Background (background.js, manifest.json): Background.js is responsible for grabbing the current tabs ID and sending it to the content script so that loading preferences from storage can be achieved successfully. Manifest.json is a collection of settings the tell chrome what my extension does, what it needs permission for, and what files need to be linked to make my extension work properly.

- Assets (image_assets, icon_assets): Various images and icons for buttons, widgets, and other aesthetic purposes.

# What I Learned -

- More practice with event loop priority in regards to promises and asynchronous JavaScript when dealing with updating Chrome's local storage.
- Working with Shadow DOM's to apply distinct styling to injected elements (Page structure modal, dictionary tooltip). **Side note**: (at the time of writing this) a dialog element cannot serve as a shadow host. If you need to inject a modal into a webpage while ignoreing the page's provided styling, you will need to wrap the dialog element in a div -> attach the shadow root to that -> and create/append a dialog element to that div.
- Familiarized myself with some of the Web Content Accessibility Guidelines (WCAG) as inspiration for this project.