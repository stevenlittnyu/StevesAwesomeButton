#include <StevesAwesomeButton.h>

// the first argument is pin number, 
// the second is the number which the event callback receives, 
// the third is either INPUT or INPUT_PULLUP (this one is optional and is INPUT by default)
StevesAwesomeButton button1(2, 0, INPUT_PULLUP);
StevesAwesomeButton button2(3, 1, INPUT_PULLUP);
StevesAwesomeButton button3(4, 2, INPUT_PULLUP);
StevesAwesomeButton button4(5, 3, INPUT_PULLUP);

void setup() 
{
  Serial.begin(9600);

  button1.pressHandler(onButtonPress);
  button1.releaseHandler(onButtonRelease);

  button2.pressHandler(onButtonPress);
  button2.releaseHandler(onButtonRelease);

  button3.pressHandler(onButtonPress);
  button3.releaseHandler(onButtonRelease);

  button4.pressHandler(onButtonPress);
  button4.releaseHandler(onButtonRelease);
}

void loop() 
{
  button1.process();
  button2.process();
  button3.process();
  button4.process();
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