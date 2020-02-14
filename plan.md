
**Project Components**
* Hardware Device
  1. Program Microcontroller
  2. ESP integration
  3. Small speaker
  4. Screen (touch?)
  5. Heart beat sensor
  6. buttons/potentiometer
  7. casing
* Software (Arduino IDE)
  1. Read raw data from Hardware
  2. Send raw data to Application
  3. Receive input from Application
  4. Send response to Hardware
* Application
  1. Develop basic application
  2. Receive raw data
  3. Store data (Data management)
  4. Based on data and user input make health care recommendation
  5. Condition management based on aggregated data and health care research
* Cloud (AWS IoT)
  1. AWS IoT core
  2. Try to connect AWS IoT free services(not yet decided)
* Security
  * Application Security
    1. Access Control
    2. Data Security
  * Cloud Security
    1. Configure device certification
    2. AWS IoT defender(1month free)

**Timeline**
* Checkpoint I (2/20)
  * Hardware
    1. Interface microcontroller with bluetooth
    2. Screen working
    3. Basic application
    4. One button
  * Software
    1. Startup screen with few options
  * Application
    1. Basic Application
    2. Health care recommendations decisions
    3. Condition management decisions
  * Cloud
    1. Setting up AWS IoT for this project
    2. Research the AWS IoT services
  * Security

* Checkpoint II (3/24)
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

* Final (4/23)
  * Hardware
    1. Bluetooth, microcontroller, screen, battery, speaker on PCB
  * Software
    1. Software for internet connectivity and heartbeat monitor works
  * Application
    1. Condition management based on aggregated data
    2. Fix bugs
  * Cloud
    1. Connect to free AWS IoT services
  * Security
    1. Access Control
    2. Data Security
    3. Setting AWS IoT device defender

**Interfaces between the components**
The components should be integrated with each other through the microcontroller. The heartbeat sensor will feed directly into this, and any applications will obviously sit within memory on the device. The cloud component should interface over wifi using the ESP chip. Any information acquired from the cloud should be stored over micro-SD or EEPROM (not decided yet).

**Security Considerations**
1. Incorporate Security at the Design Phase
Security is very important in IoT devices as they are often involved in a lot of our very personal lives. We are building a watch that will interact with a person and monitor their personal health information. Keeping personal health information private is at the forefront of our minds as we design the application and storage of this device. Confidentiality is the most important. The application will have Access Control and require a username and password to log in and review any health information. We will make sure that we are using up-to-date operating systems and attempt to use parts that have encryption built-in if possible. Luckily the failure of the device would not cause any real risk, so availability is not a concern as much as confidentiality. The  integrity of the data is important in order to give the most accurate advice, but risks to that are moderate, nonetheless something to keep in mind.
2. Advance Security Updates and Vulnerability Management
The scope of this project is over the course of a few months leading up to a final demo, due to this security updates are not something that we will need to worry about for the future. If this were to be a real application in the field we should absolutely make sure we have a way to securely update the hardware and application, but due to the scope of the project at this time it is not something we need to consider.
3. Build on Proven Security Practices
We have read over the NIST Framework and will consider the suggestions in our project as well as the basic cybersecurity practices. That being said we don’t need to be using the information sharing platforms as ours is a smaller personal tool and not a large IoT device.
4. Prioritize Security Measures According to Potential Impact
The consequences of a security failure are a loss of personal health information, which is not a high level security threat. Because of that we do not need something as in-depth as red teaming.
5. Promote Transparency across IoT
Transparency is of vital importance when it comes to security and users understanding their risks when providing and personal information.We will provide information on what we are doing with the data they provide and how we are securing their data.
6. Connect Carefully and Deliberately
We will be careful to ensure that our device only connects to what we want it connected to. It is not vital that our device is continually connected so looking at if we can have it only connected a portion of the time in order to help increase our security practices.

**Group Assignments**
* Sam
  Application
  Application Security
* Eric
  Hardware
  Software
* Aki
  Cloud
  Cloud Security
