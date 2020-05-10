**Project Organization**
* Arduino
  1. Adafruit Pro Trinket
* BasicApplication
  * Arduino Code for the Panic Attack Application
    1. BasicApplication.ino
* Website
  * Files for the website that goes along with the project, including the html, javascript, and css pages
    * HTML
      1. Main.html
      2. Breathe.html
      3. Mindful.html
      4. Focus.html
    * JS
      1. Exercises.js
      2. Main.js
    * CSS
      1.  Main.css
    * Other
      1. BreatheImage.gif

* Cloud(AWS IoT)
  * ESP 8285
  * AWS account and preparing the AWS IoT console
  * Arduino IDE + Libraries


**How to Build and Use Our Project**

HC-05 module
Adafruit Pro trinket
Download https://github.com/gwu-iot/20_watch-smarts/blob/master/watch.ino  <- arduino file
https://www.amazon.com/gp/product/B07JCV9GF5/ref=ppx_yo_dt_b_asin_title_o07_s01?ie=UTF8&psc=1
https://www.amazon.com/gp/product/B00INWZRNC/ref=ppx_yo_dt_b_asin_title_o03_s00?ie=UTF8&psc=1
https://www.amazon.com/gp/product/B083B7FGVL/ref=ppx_yo_dt_b_asin_title_o08_s00?ie=UTF8&psc=1
https://www.amazon.com/gp/product/B07GGSM8SP/ref=ppx_yo_dt_b_asin_title_o04_s00?ie=UTF8&psc=1
Attach 1 button to A0 and A2, the other button to A3 and A5. Pressing one button with allow current to flow from A0 digital write to A2 analog read. Same with A3 and A5.

* The relevant files of Amazon AWS IoT file is here

https://github.com/gwu-iot/20_watch-smarts/tree/master/Arduino

* This folder include
- Make wifi connection and AWS connection check(not ssl)

https://github.com/gwu-iot/20_watch-smarts/blob/master/Arduino/Connection_AWS/AmazonAWSConnect/AmazonAWSConnect.ino
- Making AWS connection by MQTT

https://github.com/gwu-iot/20_watch-smarts/blob/master/Arduino/Connection_AWS/MQTT
- Secret file(need certification)

https://github.com/gwu-iot/20_watch-smarts/blob/master/Arduino/Connection_AWS/secrets.h
- Lambda function(upload to Storage service)

https://github.com/gwu-iot/20_watch-smarts/blob/master/Arduino/AWS_lambda_functions/upload_file_s3_basic.py

P.S. I will write the code for understanding more AWS IoT during summer. (Aki)
