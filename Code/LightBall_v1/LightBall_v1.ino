
#include "Constants.h"
#include "Essentials.h"
#define DEBUGGER

void setup() {
    #ifdef DEBUGGER
    Serial.begin(9600);
    #endif
    ISR_disable();
    led_init();
    pinMode(2,OUTPUT);
    digitalWrite(2,HIGH);
}
int state=1;
void loop() {
  if (digitalRead(BTN_PIN)==HIGH&& state==1){
     Serial.print("started");
     buffer_init();
     ISR_enable();
     state=0;
  }
    buffer_update();
}
