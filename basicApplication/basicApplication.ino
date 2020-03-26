/*Heartrate sensor code is included but commented out because we were
unable to get the heartrate sensor to work*/
/*as an alternative the user can activate the watch if they are having a
panic attack and get the same options as before*/
//#include <Wire.h>
//#include "MAX30105.h"
#include "DFRobot_ST7687S_Latch.h"

//MAX30105 particleSensor;

void setup() {
  // put your setup code here, to run once:
  //particleSensor.begin(Wire, I2C_SPEED_FAST);
  // no sensor so put a constant value rn
  int normalHeartrate = 67;
  int heartrate = 66;
  bool panic = false;
  //  user input of what they want to do to calm down 
  int choice = 1;
}


void panicMode(){
  //flash red to show in panic mode
  tft.fillScreen(DISPLAY_RED);
  delay(3000);
  tft.setCursor(64, 64);
  tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
  tft.setTextColor(DISPLAY_WHITE);  //set text color as white
  tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
  tft.print("click once for breathing");
  delay(5000);
  tft.setCursor(64, 64);
  tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
  tft.setTextColor(DISPLAY_WHITE);  //set text color as white
  tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
  tft.print("click twice for mindfulness");
  delay(5000);
  tft.setCursor(64, 64);
  tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
  tft.setTextColor(DISPLAY_WHITE);  //set text color as white
  tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
  tft.print("click thrice for focus");
  int choice = getChoice();
  promptChoice(choice);
}

int choice(){
  if(button.ClickNum == 1){
    return 1;
  }
  if(button.ClickNum == 2){
    return 2;
  }
  if(button.ClickNum == 3){
    return 3;
  }
}

//do they want to do breathing exercise, mindfulness, focus
void promptChoice(int choice){
  switch(choice){
    case 1:
      breathing();
      break;
     case 2:
      mindful();
      break;
     case 3:
      focus();
      break;
     default:
      //error make pick again
      panicMode();
      break;
  }
}

//show breathing exercise
void breathing(){
    //for 27 seconds
    //breathe in for 5 breathe out for 4
    for(int i = 0; i < 3; i++){
      tft.setCursor(64, 64);
      tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
      tft.setTextColor(DISPLAY_WHITE);  //set text color as white
      tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
      tft.print("in"); 
      delay(1000);
      tft.setCursor(64, 64);
      tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
      tft.setTextColor(DISPLAY_WHITE);  //set text color as white
      tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
      tft.print("2");
      delay(1000);
      tft.setCursor(64, 64);
      tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
      tft.setTextColor(DISPLAY_WHITE);  //set text color as white
      tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
      tft.print("3");
      delay(1000);
      tft.setCursor(64, 64);
      tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
      tft.setTextColor(DISPLAY_WHITE);  //set text color as white
      tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
      tft.print("4");
      delay(1000); 
      tft.setCursor(64, 64);
      tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
      tft.setTextColor(DISPLAY_WHITE);  //set text color as white
      tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
      tft.print("5");
      delay(1000);
      tft.setCursor(64, 64);
      tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
      tft.setTextColor(DISPLAY_WHITE);  //set text color as white
      tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
      tft.print("out");
      delay(1000);  
      tft.setCursor(64, 64);
      tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
      tft.setTextColor(DISPLAY_WHITE);  //set text color as white
      tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
      tft.print("2");
      delay(1000); 
      tft.setCursor(64, 64);
      tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
      tft.setTextColor(DISPLAY_WHITE);  //set text color as white
      tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
      tft.print("3");
      delay(1000);
      tft.setCursor(64, 64);
      tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
      tft.setTextColor(DISPLAY_WHITE);  //set text color as white
      tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
      tft.print("4");
      delay(1000);    
    }
}

void mindful(){
    //each gets 20 seconds
    //5 things you see
    tft.setCursor(64, 64);
    tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
    tft.setTextColor(DISPLAY_WHITE);  //set text color as white
    tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
    tft.print("Find 5 things you can see");
    delay(20000); 
    //4 things you can touch
    tft.setCursor(64, 64);
    tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
    tft.setTextColor(DISPLAY_WHITE);  //set text color as white
    tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
    tft.print("Find 4 things you can touch");
    delay(20000);
    //3 things you hear
    tft.setCursor(64, 64);
    tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
    tft.setTextColor(DISPLAY_WHITE);  //set text color as white
    tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
    tft.print("Find 3 things you can hear");
    delay(20000);
    //2 things you smell
    tft.setCursor(64, 64);
    tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
    tft.setTextColor(DISPLAY_WHITE);  //set text color as white
    tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
    tft.print("Find 2 things you can smell");
    delay(20000);
    //1 thing you taste
    tft.setCursor(64, 64);
    tft.setTextBackground(DISPLAY_BLACK);  //set text background as black
    tft.setTextColor(DISPLAY_WHITE);  //set text color as white
    tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
    tft.print("Find 1 thing you can taste");
    delay(20000);
}

void focus(){
    //1 minute of this
    //focus on the normal heartrate that is being displayed
    //normal heartrate is 60 bpm which is one beat per second
    //display a circle for every normal beat
    tft.drawCircle(0, 0, 20, DISPLAY_RED);  //draw circle
    tft.fillCircle(0, 0, 20, DISPLAY_RED);  //fill circle
    tft.fillScreen(DISPLAY_WHITE);
    delay(1000);
}

void loop() {
  /*
  // get heartrate from sensor
  heartrate = particleSensor.getIR();
  // put your main code here, to run repeatedly:
  if(heartrate > (normalHeartrate + 15)){
    panic = true;
    promptChoice(choice);
  }
  else{
    panic = false;
  }
  */
  //if button clicked for 20 seconds panic mode
  int diff = buttonclick.endtime() - buttonclick.starttime();
  if(abs(diff) >= 20 && panic == false){
    panic = true;
    panicMode();
  }
  else{
    panic = false;
  }
  delay(1000);
}
