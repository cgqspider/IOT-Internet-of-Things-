# Introduction
This is code snippet which can be used with any IOT based controller to send the email to any device. It uses the SMTP protocol to send to send the email.

# How to use?
This project has 2 major files <br>
1. Esp8266_Gmail_Sender.ino  <br>
2. Gsender.h <br>
Fill the SSID AND PASSWORD in .ino file to which the wifi is to be connected and Insie Gsender.h pass the Email and password with base64 converted data.<br>

Inside Setup function there is if code :<br>
if(gsender->Subject(subject)->Send("aadityamonu67@gmail.com", "Setup test")) if(gsender->Subject(subject)->Send("Email@gmail.com", "Here is message")) <br>

Just replace the email and message inside the send() function and run the code. mail will be sent<br>
<p>Hope you enjoyed</p>

