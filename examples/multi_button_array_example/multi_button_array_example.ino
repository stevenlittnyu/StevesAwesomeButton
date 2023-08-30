#include <StevesAwesomeButton.h>

// the first argument is pin number, 
// the second is the number which the event callback receives, 
// the third is either INPUT or INPUT_PULLUP (this one is optional and is INPUT by default)
StevesAwesomeButton button1(2, 0, INPUT_PULLUP);
StevesAwesomeButton button2(3, 1, INPUT_PULLUP);
StevesAwesomeButton button3(4, 2, INPUT_PULLUP);
StevesAwesomeButton button4(5, 3, INPUT_PULLUP);

StevesAwesomeButton* buttons[4] = { &button1, &button2, &button3, &button4 };

void setup() {
  Serial.begin(9600);

  for(int i=0; i<4; i++)
  {
    buttons[i]->pressHandler(onButtonPress);
    buttons[i]->releaseHandler(onButtonRelease);    
  }
}

void loop() {
  for(int i=0; i<4; i++)
  {
    buttons[i]->process();
  }
}

void onButtonPress(int _buttonNum)
{
  Serial.print("button ");
  Serial.print(_buttonNum);
  Serial.println(" pressed");  
}

void onButtonRelease(int _buttonNum)
{
  Serial.print("button ");
  Serial.print(_buttonNum);
  Serial.println(" released");  
}
