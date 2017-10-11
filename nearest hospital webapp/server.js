var express = require('express');
var morgan = require('morgan');
var path = require('path');

var app = express();
app.use(morgan('combined'));

app.get('/', function(req, res) {
    res.sendFile(path.join(__dirname, 'ui', 'index.html'));

});
app.get('/ui/Logo.png', function(req, res) {
    res.sendfile(path.join(__dirname, 'ui', 'logo.png'));
});
app.get('/ui/styles.css', function(req, res) {
    res.sendFile(path.join(__dirname, 'ui', 'styles.css'));
    alert("Welcome to ElectroFaqs!");
});
app.get('/ui/microcontrollers', function(req, res) {
    res.sendFile(path.join(__dirname, 'ui', 'microcontrollers.html'));
});
var port = 8080; // Use 8080 for local development because you might already have apache running on 80
app.listen(8080, function() {
    console.log(`ElectroFaqs Website is listening on port ${port}!`);
});
var acc = document.getElementsByClassName("accordion");
var i;

for (i = 0; i < acc.length; i++) {
    acc[i].onclick = function() {
        this.classList.toggle("active");
        var panel = this.nextElementSibling;
        if (panel.style.maxHeight) {
            panel.style.maxHeight = null;
        } else {
            panel.style.maxHeight = panel.scrollHeight + "px";
        }
    }
}