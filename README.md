# SweepingCapSense Library for Arduino
This library implements and expands upon [DZL's](http://dzlsevilgeniuslair.blogspot.se) version of *Swept Frequency Capacitive Sensing* as described in the Disney Research project known as *Touché*. It expands upon it by implementing multiple timers simultaneously which presumably allows for more sensors to be used as well. This library must also credit [Mads Hobye](http://hobye.dk) and his [instructable](http://www.instructables.com/id/Touche-for-Arduino-Advanced-touch-sensing/?ALLSTEPS) on implementing DZL's technique. 

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

# SweepingCap.h
The **SweepingCap** class handles the *Swept Frequency* aspect. It does so by using the hardware timers on the Arduino to generate a waveform at frequencies from 1.5K to 3k.  


