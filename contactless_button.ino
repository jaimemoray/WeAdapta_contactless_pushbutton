


#include <driver/touch_pad.h>

const int touchPin = 4;
const int calibratedPin = 22;
const int outputPin = 17;
const int latchPin = 16;
const int threshold = 1;  //1 unit

int touchValue;
int calibratedValue;
bool latchMode;

void setup() {
  Serial.begin(115200);

  pinMode(calibratedPin, INPUT);
  pinMode(outputPin, OUTPUT);
  pinMode(latchPin, INPUT);
  pinMode(latchPin, INPUT);
  latchMode=false;

}

void loop() {
  // RemoteXY_Handler ();
  Serial.println(touchRead(touchPin));

  if (digitalRead(calibratedPin) == LOW) {
    calibratedValue = touchRead(touchPin);
    Serial.println("calibratedValue");
    Serial.println(calibratedValue);

    delay(200);  //debounce time
  }

    if (digitalRead(latchPin) == LOW) {
      latchMode=!latchMode;

      delay(200);  //debounce time
  }

  if (touchRead(touchPin) >= calibratedValue - threshold && touchRead(touchPin) <= calibratedValue + threshold) {

    if (latchMode==false){
      digitalWrite(outputPin, HIGH);
      delay(1000);
      digitalWrite(outputPin, LOW);
    }
    else{
      bool state=digitalRead(outputPin);
      digitalWrite(outputPin,!state);
      if (digitalRead(outputPin)==HIGH){
        Serial.println("ON");
      }
      else{
        Serial.println("OFF");
      }
      delay(1000);  //debounce time
    }
  }

  delay(200);
}
