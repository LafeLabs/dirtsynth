/*  Example playing a sinewave at a set frequency,
    using Mozzi sonification library.

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

//int button1pin = 2;
//int button2pin = 3;
//boolean button1 = false;
//boolean button2 = false;
//boolean synthon = true;

void setup(){
  startMozzi(CONTROL_RATE); // :)
  aSin.setFreq(2600); // set the frequency
//  pinMode(button1pin,INPUT_PULLUP); 
 // pinMode(button2pin,INPUT_PULLUP); 
    pinMode(9,OUTPUT); 

}


void updateControl(){
  // put changing controls in here
}


AudioOutput_t updateAudio(){
  return MonoOutput::from8Bit(aSin.next()); // return an int signal centred around 0
}


void loop(){
  
//  button1 = !digitalRead(button1pin);  
 // button2 = !digitalRead(button2pin); 
  knob = analogRead(A2);
//  voltage = analogRead(A1);
    aSin.setFreq(440 + 3*knob);

/*
  if(button1 && synthon == false){
    synthon = true;
    startMozzi();
  }
  
  if(button2 && synthon == false){
    synthon = true;
    startMozzi();  
  }
  if(button1){
    aSin.setFreq(220 + knob);
  }
  if(button2){
    aSin.setFreq(220 + knob + voltage);
  }
  
  if(!button1 && synthon){
    stopMozzi();
    synthon = false;
  }
  */
  
  audioHook(); // required here
  
  
}
