
#include <SoftwareSerial.h>
#include "DFRobot_ST7687S_Latch.h"
#include <IRremote.h>   // Referring to the IRRemote function library, the header file 
                        //has defined PIN 3 as the signal output, so it can only connect 
                        //to PIN 3. If change, please change it in the header file                                              
IRsend irsend;
        
// Setup for screen
#ifdef __AVR__
uint8_t pin_cs = 3, pin_rs = 5, pin_wr = 6, pin_lck = 10;
#else
uint8_t pin_cs = D3, pin_rs = D5, pin_wr = D6, pin_lck = D10;
#endif

DFRobot_ST7687S_Latch screen(pin_cs, pin_rs, pin_wr, pin_lck);
bool panic = false;

SoftwareSerial Eblue(12, 4); // RX, TX
IRsend mySender;

int menu_state = 0;

void start()
{
  screen.fillScreen(DISPLAY_BLACK);
  delay(200);
  screen.drawCircle(0, 0, 63, DISPLAY_WHITE);
  screen.setTextColor(DISPLAY_WHITE);
  screen.setTextSize(2);
  screen.setCursor(10, 56);
  screen.print("Watch");
  delay(250);
  screen.print(" 2.0");
  delay(500);
  screen.fillCircle(0, 0, 62, DISPLAY_BLACK);
}

void menu(int option){
  int x[] = {-22, -22, 22, 22};
  int y[] = {-20, 20, -20, 20};
  
  for (int i=0; i<4; i++)
  {
    if (option == i)
      screen.drawCircle(x[i], y[i], 15, DISPLAY_GREEN);
    else
      screen.drawCircle(x[i], y[i], 15, DISPLAY_NAVY);
  }
  
//  screen.drawCircle(-22, -20, 15, DISPLAY_GREEN);
//  screen.drawCircle(-22, 20, 15, DISPLAY_WHITE);
//  screen.drawCircle(22, -20, 15, DISPLAY_WHITE);
//  screen.drawCircle(22, 20, 15, DISPLAY_WHITE);
  screen.setCursor(53, 15);
  screen.setTextSize(1);
  screen.print("Menu");
  
}


void setup() {
  // put your setup code here, to run once:
  Eblue.begin(9600);
  Eblue.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  
  screen.begin();

  start();

  menu_state = 0;
  menu(menu_state);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A2, INPUT);

  pinMode(A3, OUTPUT);
  
  pinMode(A5, INPUT);

  digitalWrite(A0, HIGH);
  digitalWrite(A3, HIGH);
  
}

int button()
{
  unsigned long time_button = millis();
  if (analogRead(A2) > 1000)
  {
    delay(180);
    if (analogRead(A2) > 1000)
    {
      return 3;
    }
    return 0;
  }
  else if (analogRead(A5) > 1000)
  {
    delay(180);
    if (analogRead(A5) > 1000)
    {
      return 4;
    }
    return 1;
  }

  
  return 2;
}


void loop() {
  // put your main code here, to run repeatedly:
  // println will send char from Eblue to device
  int clicked = button();

  main_menu:

  if (clicked == 0)
  {
    menu_state = (menu_state + 1) % 4;
    menu(menu_state);
    delay(90);
  }
  else if(clicked == 1 && menu_state == 2)
  {
    screen.fillScreen(DISPLAY_BLACK);

    int heart_state = 0;
    unsigned long time;
    time = millis();

    screen.setTextColor(DISPLAY_WHITE);
    screen.setCursor(36, 15);
    screen.setTextSize(1);
    screen.print("Heart Beat");
      
    while(true)
    {
      
      if (heart_state == 0)
      {
         screen.drawCircle(-30, 30, 10, DISPLAY_GREEN);
         screen.drawCircle(0, 30, 10, DISPLAY_NAVY);
         screen.drawCircle(30, 30, 10, DISPLAY_NAVY); 
      }
      else if (heart_state == 1)
      {
         screen.drawCircle(-30, 30, 10, DISPLAY_NAVY);
         screen.drawCircle(0, 30, 10, DISPLAY_GREEN);
         screen.drawCircle(30, 30, 10, DISPLAY_NAVY); 
      }
      else if (heart_state == 2)
      {
         screen.drawCircle(-30, 30, 10, DISPLAY_NAVY);
         screen.drawCircle(0, 30, 10, DISPLAY_NAVY);
         screen.drawCircle(30, 30, 10, DISPLAY_GREEN); 
      }

      screen.setTextColor(DISPLAY_RED);
      screen.setCursor(46, 45);
      screen.setTextSize(4);

      if (millis() - time >= 1000)
      {
         time = millis();
         screen.print(random(60, 100));
      }

      int heart_clicked = button();
      int delay_time = 70;
      
      if (heart_clicked == 0)
      {
        heart_state = (heart_state + 1) % 3;
      }
      else if (heart_clicked == 1 && heart_state == 0)
      {
        unsigned long time_pulse;
        time_pulse = millis();
        screen.fillScreen(DISPLAY_BLACK);
        
        screen.setCursor(30, 15);
        screen.setTextSize(1);
        screen.setTextColor(DISPLAY_WHITE);
        screen.print("Count breath");

        int count = 0;
        int count_in = 0;
        int count_out = 0;

        screen.setTextColor(DISPLAY_BLUE);
        screen.setCursor(50, 85);
        screen.setTextSize(2);
        screen.print(count_in);

        screen.setTextColor(DISPLAY_GREEN);
        screen.setCursor(75, 85);
        screen.setTextSize(2);
        screen.print(count_out);
        
        while (true)
        {
          if (millis() - time_pulse >= 940)
          {
            screen.setTextColor(DISPLAY_RED);
            screen.setCursor(46, 45);
            screen.setTextSize(4);
            screen.print(count);
            
            count = count + 1 % 60;
            time_pulse = millis();
          }
          int breath_clicked = button();

          if (breath_clicked == 0)
          {
              count_in ++;

              screen.setTextColor(DISPLAY_BLUE);
              screen.setCursor(50, 85);
              screen.setTextSize(2);
              screen.print(count_in);
          }
          else if (breath_clicked == 1)
          {
              count_out ++;

              screen.setTextColor(DISPLAY_GREEN);
              screen.setCursor(75, 85);
              screen.setTextSize(2);
              screen.print(count_out);
          }
          else if (breath_clicked == 4)
          {
            // clear screen, go back to heart menu
            screen.fillScreen(DISPLAY_BLACK);
            
            screen.setTextColor(DISPLAY_WHITE);
            screen.setCursor(36, 15);
            screen.setTextSize(1);
            screen.print("Heart Beat");
            break;
          }
        }  
      }
      else if (heart_clicked == 1 && heart_state == 1)
      {
        screen.fillScreen(DISPLAY_BLACK);
        
        screen.setCursor(20, 35);
        screen.setTextSize(1);
        screen.setTextColor(DISPLAY_WHITE);
        screen.print("Find 4 things to   touch, 2 to smell, 3 to hear, 1 to taste");

        while (true)
        {
          if (button() == 4)
          {
            // clear screen, go back to heart menu
            screen.fillScreen(DISPLAY_BLACK);
            
            screen.setTextColor(DISPLAY_WHITE);
            screen.setCursor(36, 15);
            screen.setTextSize(1);
            screen.print("Heart Beat");
            break;
          }       
        }
      }
      else if (heart_clicked == 1 && heart_state == 2)
      {
        // new screen with 100bpm pulse
        int bpm = 80;
        int bpm_to_milli = 750;
        unsigned long time_pulse;
        time_pulse = millis();
        screen.fillScreen(DISPLAY_BLACK);
        
        screen.setCursor(30, 15);
        screen.setTextSize(2);
        screen.setTextColor(DISPLAY_WHITE);
        screen.print(bpm);
        screen.print(" BPM");
        
        while (true)
        {
          if (millis() - time_pulse >= bpm_to_milli)
          {
            // do a quick pulse
            screen.fillCircle(0, 0, 10, DISPLAY_RED); 
            delay(20);
            screen.fillCircle(0, 0, 20, DISPLAY_RED);
            delay(20);
            screen.fillCircle(0, 0, 20, DISPLAY_BLACK);
            time_pulse = millis();
          }

          if (button() == 4)
          {
            // clear screen, go back to heart menu
            screen.fillScreen(DISPLAY_BLACK);
            
            screen.setTextColor(DISPLAY_WHITE);
            screen.setCursor(36, 15);
            screen.setTextSize(1);
            screen.print("Heart Beat");
            break;
          }
        }
      }

      else if (heart_clicked == 4)
      {
        goto main_menu;
      }
      delay(delay_time);
    }
  }

  

//  if button

//  if (Eblue.available()){
//      char from_device = Eblue.read();
//      if (from_device == 'r')
//      {
//        screen.fillScreen(DISPLAY_RED);
//        Eblue.println("changing display to red");
//      }
//      else if (from_device == 'b')
//      {
//        screen.fillScreen(DISPLAY_BLUE);
//        Eblue.println("changing display to blue");
//      }
//      else if (from_device == 'n')
//      {
//        screen.fillScreen(DISPLAY_BLACK);
//        Eblue.println("changing display to blue");
//      }
//      else if (from_device == 'g')
//      {
//        screen.fillScreen(DISPLAY_GREEN);
//        Eblue.println("changing display to blue");
//      }
//      else if (from_device == 'm')
//      {
//        screen.fillScreen(DISPLAY_MAGENTA);
//        Eblue.println("changing display to blue");
//      }
//      else if (from_device == 'o')
//      {
//        screen.fillScreen(DISPLAY_OLIVE);
//        Eblue.println("changing display to blue");
//      }
//      else if (from_device == 'l')
//      {
//        screen.fillScreen(DISPLAY_LIGHTGREY);
//        Eblue.println("changing display to blue");
//      }
//      else if (from_device == 'd')
//      {
//        screen.fillScreen(DISPLAY_DARKGREY);
//        Eblue.println("changing display to blue");
//      }
//      else if (from_device == 'N')
//      {
//        screen.fillScreen(DISPLAY_NAVY);
//        Eblue.println("changing display to blue");
//      }
//      else if (from_device == 'M')
//      {
//        screen.fillScreen(DISPLAY_MAROON);
//        Eblue.println("changing display to blue");
//      }
//      else if (from_device == 'G')
//      {
//        screen.fillScreen(DISPLAY_DARKGREEN);
//        Eblue.println("changing display to blue");
//      }
//      else if (from_device == 'p')
//      {
//        screen.fillScreen(DISPLAY_PINK);
//        Eblue.println("changing display to blue");
//      }
//      else if (from_device == 'O')
//      {
//        screen.fillScreen(DISPLAY_ORANGE);
//        Eblue.println("changing display to blue");
//      }
//      else if (from_device == 'y')
//      {
//        screen.fillScreen(DISPLAY_YELLOW);
//        Eblue.println("changing display to blue");
//      }
//  
//      
//      // Eblue.println(char(Eblue.read()));
//   }
}




// https://github.com/DFRobot/DFRobot_ST7687S
