/*
  Touch.cpp - Library for Plant Touch Sensing.
  Created by Colin Honigman. November 2013.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Touch.h"


Touch::Touch( unsigned char pin )
{
    mPin = pin;
    
    for( int i = 0; i < sizeof(results); i++ )
    {
    	results[i] = 0;	
    }
    topPoint = 0;
    topValue = 0;
    interpolatedValue = 0;
    
}

unsigned char Touch::getPin()
{
    return mPin;
}

uint16_t Touch::readPin()
{
    value = analogRead(mPin);
    return value;
}

uint16_t Touch::getValue()
{
    return value;
}

unsigned char Touch::getTopPoint()
{
    return topPoint;
}

void Touch::setTopPoint( unsigned char tp )
{
    topPoint = tp;
}

uint16_t Touch::getTopValue()
{
    return topValue;
}

void Touch::setTopValue( uint16_t tv )
{
    topValue = tv;
}

uint16_t Touch::interpolate()
{
  interpolatedValue = interpolatedValue * 0.5f + ((topPoint + results[topPoint]/results[topPoint+1]*results[topPoint-1]/results[topPoint]) * 10.0f) * 0.5f;
  return interpolatedValue;
}

void Touch::setResults(uint16_t i, uint16_t v)
{
	results[i] = v;
}

uint16_t Touch::getResults(uint16_t i)
{
	return results[i];	
}

void Touch::reset()
{
    topPoint = 0;
    topValue = 0;
}