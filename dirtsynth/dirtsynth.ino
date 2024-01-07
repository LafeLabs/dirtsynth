/*  Example playing a sinewave at a set frequency,
    using Mozzi sonification library.

DIRT SYNTH IS JUST SINE WAVE WITH FREQUENCY BASED ON AN ANALOG VOLTAGE ON THE CIRCUIT BOARD

    Demonstrates the use of Oscil to play a wavetable.

    Circuit: Audio output on digital pin 9 on a Uno or similar, or
    DAC/A14 on Teensy 3.1, or
    check the README or http://sensorium.github.io/Mozzi/

    Mozzi documentation/API
    https://sensorium.github.io/Mozzi/doc/html/index.html

    Mozzi help/discussion/announcements:
    https://groups.google.com/forum/#!forum/mozzi-users

    Tim Barrass 2012, CC by-nc-sa.
*/

int knob = 0;
int voltage = 0;
#include <Adafruit_NeoPixel.h>

#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <tables/sin2048_int8.h> // sine table for oscillator

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);

// use #define for CONTROL_RATE, not a constant
#define CONTROL_RATE 64 // Hz, powers of 2 are most reliable


void setup(){
  startMozzi(CONTROL_RATE); // :)
  aSin.setFreq(2600); // set the frequency 2600 HZ! HACK THE PLANET!
    pinMode(9,OUTPUT); 

}


void updateControl(){
  // put changing controls in here
}


AudioOutput_t updateAudio(){
  return MonoOutput::from8Bit(aSin.next()); // return an int signal centred around 0
}


void loop(){
  
  voltage = analogRead(A0);
  aSin.setFreq(440 + 3*voltage);  
  audioHook(); // required here
  
}
