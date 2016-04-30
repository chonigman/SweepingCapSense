# SweepingCapSense Library for Arduino
This library implements and expands upon [DZL's](http://dzlsevilgeniuslair.blogspot.se) version of *Swept Frequency Capacitive Sensing* as described in the Disney Research project known as *Touché*. It expands upon it by implementing multiple timers simultaneously which presumably allows for more sensors to be used as well. This library must also credit [Mads Hobye](http://hobye.dk) and his [instructable](http://www.instructables.com/id/Touche-for-Arduino-Advanced-touch-sensing/?ALLSTEPS) on implementing DZL's technique.

*Note:* Only for Arduino Mega and Uno (atmega328 boards) (other boards coming soon).

## Installation
Git Clone or Download and place SweepingCapSense folder inside your Arduino/libraries folder. If you don't have a libraries folder create one (make sure it is lowercase) and place this library inside inside.

## Required Components

* **Resistors:** 10k, 1M, and 3.3k
* **Capcitors:** 100pf, 10nf (.01uf)
* **Diode:** 1N4148
* **Inductor/Coil:** 10mH
* **Object:** Foil,Plant, Water Bottle, pretty much any conductive object

## Circuit Diagram

[Circuit Diagram](http://www.instructables.com/file/FR73R4DH2MYISBD)

The send pin you use depends which Arduino and which timer you use. 

## Notes
This library was developed with an Arduino Mega and so allows for the use of all four **16 bit** timers. It should also be noted that when making changers to the hardware timers it effects all pins connected to that timer. 

# Basic Usage
This library is made up of two classes **SweepingCap** and **Touch**. To use you must import SweepingCap.h and Touch.h into your Arduino sketch.

## SweepingCap.h
The **SweepingCap** class handles the *Swept Frequency* aspect of *Swept Frequency Capacitive Sensing*. It does so by using the hardware timers on the Arduino to generate a waveform at frequencies from 1.5Khz to 3.5Mhz. The class itself is fairly simple, the bulk of the code being several bit-shifting functions that handle the waveform generation on the timers. 

When instantiating you call **SweepingCap(unsigned char )**, which sets up all 4 timers of the Arduino Mega and sets the number of frequencies to sweep (200 max), or **SweepingCap(int , unsigned char )** to set up only one timer and the number of frequencies. When doing the latter please note that the 16 bit timers on the Mega are 1, 3, 4, and 5. I purposefully  made it work with the specific timer number as a reinforcement of the knowledge that those timers are the 16 bit timers available. Other Arduino Boards will be added in the future.

In the setup you simply call **.setup()** on your SweepingCap object. Inside the main loop you will need a for loop which acts as the frequency sweep. You can use method **.getNumFrequencies** to setup the for loop and pass in the iterator to the **.sweep(int freq)** function, where all the bit shifting takes place. 

### Notes on Timers
Timer 1 uses Digi Pin 11 but also controls Pin 12. 
Timer 3 uses Digi Pin 5 but also controls Pin 2 and 3.
Timer 4 uses Digi Pin 6 but also controls Pin 7 and 8.
Timer 5 uses Digi Pin 46 but also controls Pin 45 and 44.

### Methods
* **SweepingCap(unsigned char howManyFrequencies)**
> Constructor - turns on all 4 16bit timers and sets the number of frequencies to be swept.
* **SweepingCap(int whichTimer, unsigned char howManyFrequencies)**
> Constructor (overloaded) - turns on one timer and sets frequencies to be swept.
* **setup()**
> Setup method, does all the actual setup for the timer pins to be used as waveform generators. 
* **sweep(int freq)**
> Main method, uses bit shifting methods to change the frequency on the waveform. 
* **getNumFrequencies()**
> Returns number of frequencies, to be used when setting up the iterator for sweeping. Max frequencies is 200.

## Touch.h

Class acts as a container for touch data. Instantiate **Touch** class by setting the Analog Pin you want to use. 
*Touch* touch(0); // sets read pin to Analog Pin 0. 

### Methods

* **readPin()**
> Performs an *analogRead()* on pin set by constructor. Stores value into private variable and returns the value as a 16 bit integer when called.

* **getValue()**
> Returns value stored when **readPin()** is called. uni16_t

* **setResults(uint16_t i, uint16_t v)**
> Set result value in results array, position and value

* **getResults(uint16_t i)**
> Get result at i position

* **setTopPoint( unsigned char tp )**
> Set Resonant Peak frequency

* **setTopValue(unit16_t tv)**
> Set Top Value of resonant peak

* **getTopPoint()**
> Returns stored top point

* **getTopValue()**
> Returns stored top value

* **interpolate()**
> Returns an interpolated top value

* **reset()**
> Reset *topPoint* and *topValue* 

* **getPin()**
> Return pin number




