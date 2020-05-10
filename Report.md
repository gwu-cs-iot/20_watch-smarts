**An overview of the design of the system**
* Hardware
  1. Two buttons, circular screen, IR blaster, bluetooth module, pro trinket, strap
* Software
  1. Reads and writes data to the application based on the hardware. Receives and sends requests to hardware to respond accordingly to the application.
* Application
  1. Watch application designed to help a person calm down during a panic attack. The user can respond to the watch and choose one of three options. Based on the option picked the watch will guide the user through the appropriate exercise. The three exercises are a guided breathing, mindfulness, and forced focus exercise.
   2. Web application that also has the three exercises so the user can use that if they wish.
* Cloud
  1. Wi-Fi chip(ESP8285), AWS IoT core(IoT platform), AWS Lambda(Program), AWS Simple Stroage Service.
  
* Security
  1. No data from the application is stored for either watch or web so there is no security needed for data management for either application.
  2. When we use cloud service, the connection between Wi-FI chip and AWS IoT core is on the SSL. The data uploaded to the storage service is encrypted.


**What changes were necessary in the project**
* Hardware
  1. Wifi needed to be changed to bluetooth because of FTDI header and pin layout
Heartbeat sensor was broken, couldn’t get shipment in time. This screen also takes a large number of pins on the pro trinket, which makes I2C communication with other devices difficult.
* Software
  1. No changes.
* Application
  1. Not able to receive raw data since we were unable to get the heart rate sensor to work, switched to using the buttons on the watch as indicators instead.
  2. There is a website that goes with it, but it just has the basic exercises and does not contain any health recommendations or management tools.
* Cloud
  1. ESP8285 can not be set in the smartwatch, then we have to check the AWS IoT separately.
* Security
  1. Because ESP 8285 could not set in the smartwatch, real data transaction is not there. Then, we have to use a not real data for connection.

**What you were not able to accomplish**
* Hardware
  1. Wifi chip changed to bluetooth, heartbeat sensor
* Software
  1. Nothing WE ACCOMPLISHED EVERYTHING
* Application
  1. Not able to get the heart rate sensor working so we had to use a different method to detect panic attacks.
  2. Did not get the actual data stored on the cloud. Because of this the health management and health care recommendations couldn’t happen without the data necessary.
* Cloud
  1.Write a code for downloading the data from AWS IoT to WiFi chip.
* Security
  * Application Security
  1. Because we did not store the data there is no access control or data security necessary for the application.
  * Cloud Security
  1. Try to use a non AWS default setting security service.



**Who did what**
* Sam
  1. Attempted to get the heart rate sensor to work, the code is still there, but is commented out since the sensor does not work.
  2. Created the application for the watch in Arduino.
  3. Created the website to go along with the application.
* Eric
  1. Built watch
  2. Wrote software for watch
  3. Bluetooth code
* Aki
  1. Make a SSL connection between WiFi-chip and Amazon AWS IoT
  2. Write a code for storing the data from WiFi chip to AWS storage service.
