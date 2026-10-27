#include <Arduino.h>
#include "USB.h"
#include "USBHIDKeyboard.h"
#include "USBHIDConsumerControl.h"
#include <PinButton.h>
#include <RotaryEncoder.h>


USBHIDKeyboard Keyboard;
USBHIDConsumerControl ConsumerControl;

/*
Pines a los que están conectados los componentes:
Teclas:
(Conecté al G1 y después G3 saltándome el G2 por error, pero qué más da)
1-G1
2-G3
3-G4
4-G5
5-G6
6-G7
7-G8
8-G9
9-G10
Encoder:
EN1-G14
EN2-G15
*/

//Teclas
PinButton teclas[] = {1, 3, 4, 5, 6, 7, 8, 9, 10}; 
RotaryEncoder encoder(14, 15, RotaryEncoder::LatchMode::TWO03); 
int numTeclas;
int pos = 0;

void setup() {
  USB.begin();
  Keyboard.begin();
  numTeclas = (sizeof(teclas) / sizeof(teclas[0])); //Variable numTeclas almacena el número de teclas que hay según cuántos pines se hayan puesto en el array teclas. Así esto valdrá para otros macro pads con más o menos teclas.
}

void loop()
{
  //Leer encoder
  encoder.tick();

  int newPos = encoder.getPosition();
  if (pos != newPos) {
    cambiarVol((int)(encoder.getDirection()));
    pos = newPos;
  }

  //Leer teclas
  for (int i=0; i<numTeclas; i++){
    teclas[i].update();
    if (teclas[i].isSingleClick()){
      pulsaTecla(i);
    }
    if (teclas[i].isLongClick()){
      pulsaTeclaLargo(i);
    }
  }
}

void cambiarVol(int dir){
  if (dir == 1){ // Subir volumen == 1, bajar volumen == -1
    ConsumerControl.press(CONSUMER_CONTROL_VOLUME_INCREMENT);
    delay(30);
  }else{
    ConsumerControl.press(CONSUMER_CONTROL_VOLUME_DECREMENT);
    delay(30);
  }
  ConsumerControl.release();
  delay(30);
}

void pulsaTecla(int t){
  int teclaPulsada=t+1;
  Keyboard.press(KEY_LEFT_GUI);
  delay(20);
  Keyboard.print(teclaPulsada);
  delay(20);
  Keyboard.releaseAll();
  delay(20);
}

void pulsaTeclaLargo(int t){
  //Pulsar tecla windows
  Keyboard.press(KEY_LEFT_SHIFT);
  delay(20);
  pulsaTecla(t);
}
