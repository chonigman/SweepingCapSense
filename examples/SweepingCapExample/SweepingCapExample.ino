#include <SweepingCap.h>
#include <Touch.h>

//SweepingCap Object
//set the timer and number of frequencies to sweep
//timer 1 on mega controls DigitalPin 11 - but also affects Pin12
SweepingCap cap(1, 120); 

//Touch Object
Touch touch(0); //set the analog pin for reading

void setup()
{
  Serial.begin(9600);
  cap.setup();
  
}

void loop()
{
  touch.reset();
  for(int i = 0; i < cap.getNumFrequencies(); i++)
  {
    touch.readPin();
    cap.sweep(i);
    delayMicroseconds(1);
    
    touch.setResults(i, touch.getResults(i)*0.5+(float)(touch.getValue()*0.5));
    
    if(touch.getTopValue() < touch.getResults(i))
    {
      touch.setTopValue(touch.getResults(i));
      touch.setTopPoint(i);  
    }
  }     
    Serial.print( touch.getTopPoint() );
    Serial.print( "\t" );
    Serial.print( touch.interpolate() );
    Serial.println();
}
