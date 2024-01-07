 # DIRT SYNTH

![](https://raw.githubusercontent.com/LafeLabs/dirtsynth/main/images/dirtsynth.png)

PUT A FEW MICROFARADS CAPACITOR IN SERIES WITH PIN 9 FROM YOUR ARDUINO INTO AN AUDIO JACK! 

THIS WILL MAKE SURE WE DON'T DRIVE DC DOWN THAT LINE!

YOU CAN RUN THE ARDUINO OFF A 5 VOLT SOLAR PANEL VIA USB!

SMEAR GREASE AND DIRT ON THE CIRCUIT BOARD AND CREATE MODES OF OSCILLATION!

THIS IS FULL STACK DIRT MAGIC!

WE ARE DIRT LOOKING AT ITSELF!


YOU WILL NEED TO INSTALL THE MOZZI LIBRARY ON YOUR ARDUINO!

ARDUINO CODE IS AS FOLLOWS:


```

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
```

REPLICATE THIS PAGE WITH THE QRCODES BELOW:

![](https://raw.githubusercontent.com/LafeLabs/dirtsynth/main/images/qrcode.png)
![](https://raw.githubusercontent.com/LafeLabs/dirtsynth/main/images/qrcode-page.png)
