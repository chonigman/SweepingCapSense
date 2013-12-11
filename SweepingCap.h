/* SweepingCap.h Library for Sweeping Frequency Capacitance Touch Sensing
   Created by Colin Honigman. November 2013
   Based Illutron's take on Disney style capacitive touch sensing, using
   only passive components. 
   Released into the public domain.
*/

#ifndef SweepingCap_h
#define SweepingCap_h

#include "Arduino.h"

#define SET(x,y) (x |=(1<<y))				//-Bit set/clear macros
#define CLR(x,y) (x &= (~(1<<y)))       	// |
#define CHK(x,y) (x & (1<<y))           	// |
#define TOG(x,y) (x^=(1<<y))            	//-+


class SweepingCap
{
	public:
        SweepingCap(unsigned char howManyFrequencies);
		SweepingCap(int whichTimer, unsigned char howManyFrequencies);

        void            setup();
		void            sweep(int freq);
        unsigned char   getNumFrequencies();
	private:
        
		int             timer;
        bool            allTimers;
        unsigned char   numFrequencies;
		
	
};

#endif