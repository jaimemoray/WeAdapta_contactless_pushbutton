
// ESP32 WROOM Dev
#include <driver/touch_pad.h>

const int touchPin=4;

void setup() {
  Serial.begin(115200);
  delay(1000);
  // put your setup code here, to run once:

}

void loop() {
  Serial.println(touchRead(touchPin));
  delay(1000);

}
