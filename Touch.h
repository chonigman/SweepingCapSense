/*
  Touch.h - Library for Touch Sensing Data
  Created by Colin Honigman. November 2013
  Released into the public domain.
*/

#ifndef Touch_h
#define Touch_h

#include "Arduino.h"

class Touch 
{
  public:
    Touch(unsigned char pin);
    Touch(unsigned char pin, unsigned char frequencies);
    unsigned char   getTopPoint();
    void            setTopPoint(unsigned char tp);
    uint16_t        getTopValue();
    void            setTopValue(uint16_t tv);
    uint16_t        interpolate();
    void            setResults(uint16_t i, float v);
    uint16_t        getResults(uint16_t i);
    void            reset();
    unsigned char   getNumFrequencies();
    unsigned char   getPin();
    uint16_t        readPin();
    uint16_t        getValue();
    
  private:
    unsigned char   mPin;
    unsigned char   topPoint;
    uint16_t        topValue;
    uint16_t        interpolatedValue;
    uint16_t        results[180];
    unsigned char   numFrequencies;
    uint16_t        value;
    
  
};

#endif