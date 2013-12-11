# SweepingCapSense Library for Arduino
This library implements and expands upon [DZL's](http://dzlsevilgeniuslair.blogspot.se) version of *Swept Frequency Capacitive Sensing* as described in the Disney Research project known as *Touché*. It expands upon it by implementing multiple timers simultaneously which presumably allows for more sensors to be used as well. This library must also credit [Mads Hobye](http://hobye.dk) and his [instructable](http://www.instructables.com/id/Touche-for-Arduino-Advanced-touch-sensing/?ALLSTEPS) on implementing DZL's technique. 

## Installation
Git Cone or Download and place SweepingCapSense folder inside your Arduino/libraries folder. If you don't have an libraries folder create one (make sure it is lowercase) and place inside.

## Required Components

**Resistors:** 10k, 1M, and 3.3k
**Capcitors:** 100pf, 10nf (.01uf)
**Diode:** 1N4148
**Inductor/Coil:** 10mH
**Object:** Plant, Water Bottle, pretty much any conductive object

## Circuit Diagram

[Circuit Diagram](http://www.instructables.com/file/FR73R4DH2MYISBD) using an Arduino Uno (I believe)

The send pin you use depends which Arduino and which timer you use. 

## Notes
This library was developed with an Arduino Mega and so allows for the use of all four **16 bit** timers. It should also be noted that when making changers to the hardware timers it effects all pins connected to that timer. 

# Basic Usage
This library is made up of two classes **SweepingCap** and **Touch**. To use you must import SweepingCap.h and Touch.h into your Arduino sketch.

## SweepingCap.h
The **SweepingCap** class handles the *Swept Frequency* aspect of *Swept Frequency Capacitive Sensing*. It does so by using the hardware timers on the Arduino to generate a waveform at frequencies from 1.5Khz to 3.5Mhz. The class itself is fairly simple, the bulk of the code being several bit-shifting functions that handle the waveform generation on the timers. 

When instantiating you call **SweepingCap()**, which sets up all 4 timers of the Arduino Mega, or **SweepingCap(int )** to set up only one timer at a time. When doing the latter please note that the 16 bit timers on the Mega are 1, 3, 4, and 5. I purposefully  made it work with the specific timer number as a reinforcement of the  knowledge that those timers are the 16 bit timers available. 

In setup you simply call **.setup()** on your SweepingCap object. Inside the main loop you will need a for loop which acts as the frequency sweep, and you pass in the iterator to the **.sweep(int freq)** function, where all the bit shifting takes place. 




