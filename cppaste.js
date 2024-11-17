// Remove all 'copy', 'cut', and 'paste' event listeners
document.addEventListener('copy', (e) => e.stopImmediatePropagation(), true);
document.addEventListener('cut', (e) => e.stopImmediatePropagation(), true);
document.addEventListener('paste', (e) => e.stopImmediatePropagation(), true);

// Remove 'oncopy', 'oncut', and 'onpaste' attributes if they exist
document.body.setAttribute('oncopy', '');
document.body.setAttribute('oncut', '');
document.body.setAttribute('onpaste', '');

// Override the 'addEventListener' method to prevent adding these events again
const originalAddEventListener = document.addEventListener;
document.addEventListener = function(type, listener, options) {
  if (['copy', 'cut', 'paste'].includes(type)) {
    return;
  }
  return originalAddEventListener.call(document, type, listener, options);
};
