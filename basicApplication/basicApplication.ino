void setup() {
  // put your setup code here, to run once:
  // no sensor so put a constant value rn
  int normalHeartrate = 67;
  int heartrate = 66;
  bool panic = false;
  //  user input of what they want to do to calm down 
  int choice = 1;
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
      break;
  }
}

//show breathing exercise
//do until panic = false

void breathing(){
    //for 27 seconds
    //breathe in for 5 breathe out for 4  
}

void mindful(){
    //each gets 20 seconds
    //5 things you see
    //4 things you can touch
    //3 things you hear
    //2 things you smell
    //1 thing you tast
}

void focus(){
    //1 minute of this
    //focus on the normal heartrate that is being displayed
    //if possible haptics
}

void loop() {
  // put your main code here, to run repeatedly:
  if(heartrate > (normalHeartrate + 15)){
    panic = true;
    promptChoice(choice);
  }
  else{
    panic = false;
  }
  delay(1000);
}
