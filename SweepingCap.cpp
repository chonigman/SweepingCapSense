/* SweepingCap.cpp Library for Sweeping Frequency Capacitance Touch Sensing
 Based on DZL's Arduino port of the Touche project.
 Library Created by Colin Honigman. November 2013
 Released into the public domain.
 */

#include "Arduino.h"
#include "SweepingCap.h"

#define SET(x,y) (x |=(1<<y))				//-Bit set/clear macros
#define CLR(x,y) (x &= (~(1<<y)))       	// |
#define CHK(x,y) (x & (1<<y))           	// |
#define TOG(x,y) (x^=(1<<y))            	//-+

SweepingCap::SweepingCap(unsigned char howManyFrequencies)
{
    timer = 0;
    allTimers = true;
    numFrequencies = howManyFrequencies;
}

SweepingCap::SweepingCap(int whichTimer, unsigned char howManyFrequencies)
{
    timer = whichTimer;
    allTimers = false;
    numFrequencies = howManyFrequencies;
}

void SweepingCap::setup()
{
    if( allTimers )
    {
        TCCR1A=0b10000010;        //-Set up frequency generator
        TCCR1B=0b00011001;        //-+
        ICR1=110;
        OCR1A=55;
        pinMode(11, OUTPUT);
        pinMode(12, OUTPUT);
        
        TCCR3A=0b10000010;        //-Set up frequency generator
        TCCR3B=0b00011001;        //-+
        ICR3=110;
        OCR3A=55;
        pinMode(2, OUTPUT);
        pinMode(3, OUTPUT);
        pinMode(5, OUTPUT);
        
        TCCR4A=0b10000010;        //-Set up frequency generator
        TCCR4B=0b00011001;        //-+
        ICR4=110;
        OCR4A=55;
        pinMode(6, OUTPUT);
        
        TCCR5A=0b10000010;        //-Set up frequency generator
  		TCCR5B=0b00011001;        //-+
  		ICR5=110;
  		OCR5A=55;
  		pinMode(46, OUTPUT);
        
        
    }
    else {
        if(timer == 1)
        {
            TCCR1A=0b10000010;        //-Set up frequency generator
            TCCR1B=0b00011001;        //-+
            ICR1=110;
            OCR1A=55;
            pinMode(11, OUTPUT);
            pinMode(12, OUTPUT);
        }
        else if(timer == 3)
        {
            TCCR3A=0b10000010;        //-Set up frequency generator
            TCCR3B=0b00011001;        //-+
            ICR3=110;
            OCR3A=55;
            pinMode(2, OUTPUT);
            pinMode(3, OUTPUT);
            pinMode(5, OUTPUT);
        }
        else if(timer == 4)
        {
            TCCR4A=0b10000010;        //-Set up frequency generator
            TCCR4B=0b00011001;        //-+
            ICR4=110;
            OCR4A=55;
            pinMode(6, OUTPUT);
        }
        else if(timer == 5)
        {
            TCCR5A=0b10000010;        //-Set up frequency generator
            TCCR5B=0b00011001;        //-+
            ICR5=110;
            OCR5A=55;
            pinMode(46, OUTPUT);
        }
    }
}

void SweepingCap::sweep(int freq)
{
    if( allTimers )
    {
        CLR(TCCR1B, 0);
        TCNT1 = 0;
        ICR1 = freq;
        OCR1A = freq/2;
        SET(TCCR1B, 0);
        
        CLR(TCCR3B, 0);
        TCNT3 = 0;
        ICR3 = freq;
        OCR3A = freq/2;
        SET(TCCR3B, 0);
        
        CLR(TCCR4B, 0);
        TCNT4 = 0;
        ICR4 = freq;
        OCR4A = freq/2;
        SET(TCCR4B, 0);
        
        CLR(TCCR5B, 0);
        TCNT5 = 0;
        ICR5 = freq;
        OCR5A = freq/2;
        SET(TCCR5B, 0);
    }
    else {
        if(timer == 1)
        {
            CLR(TCCR1B, 0);
            TCNT1 = 0;
            ICR1 = freq;
            OCR1A = freq/2;
            SET(TCCR1B, 0);
        }
        else if(timer == 3)
        {
            CLR(TCCR3B, 0);
            TCNT3 = 0;
            ICR3 = freq;
            OCR3A = freq/2;
            SET(TCCR3B, 0);
        }
        else if(timer == 4)
        {
            CLR(TCCR4B, 0);
            TCNT4 = 0;
            ICR4 = freq;
            OCR4A = freq/2;
            SET(TCCR4B, 0);				
        }
        else if(timer == 5)
        {
            CLR(TCCR5B, 0);
            TCNT5 = 0;
            ICR5 = freq;
            OCR5A = freq/2;
            SET(TCCR5B, 0);				
        }
    }
	
	delayMicroseconds(1);
	
}

unsigned char SweepingCap::getNumFrequencies()
{
    return numFrequencies;
}
