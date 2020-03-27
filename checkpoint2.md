**Ideal Deliverables:**
* Hardware
  1. Bluetooth, microcontroller, screen/battery all working on PCB
  2. Buttons all integrated
* Software
  1. Extension on menu options/applications
* Application
  1. Receive raw data
  2. Store data
  3. Respond to Hardware with health care recommendations
* Cloud
  1. Connecting smartwatch and AWS IoT
  2. Setting the IoT core
* Security
  1. Setting the device certification

**What changes were necessary in the project?**
* Hardware
  1. Heartbeat sensor was unable to pick up heart rate and got hot to the touch so we decide to scrap it
* Software
  1. N/A
* Application
  1. The user can force a “panic mode” which will then provide the same options
* Cloud
  1. N/A
* Security
  1. N/A

**Where we fell behind**
* Hardware
  1. Heart beat sensor broke, wifi chip has no USB-Serial converter RIP
* Software
  1. N/A
* Application
  1. The web application is very basic
  2. Because the heart rate sensor doesn’t work must now store whenever panic mode is activated: have yet to work on this
* Cloud
  1. Wifi-module(ESP8285) should be connected with AWS IoT as soon as possible.
  2. After connection is built, IoT core should be made setting up soon.
* Security
  1. N/A

**What we will do to catch up**
* Hardware
  1. Buttons, Shell
* Software
  1. Starting run-time ecosystem
* Application
  1. The web application will be pretty simple overall. I will work on this once I am done with storage.
  2. Communicate with the cloud to get storage working
  3. Determine what not having a heart rate sensor means for the rest of the project
* Cloud
  1. Already, the items are here, then try to make a connection.
* Security
  1. N/A
