#include <Arduino.h>

#define BTN_PIN 2 // D4

unsigned long int lastDebounceTime = 0; 
unsigned long int debounceDelay = 150; 
bool lastBtnState = 1; 
bool btnState; 
bool trigBtnState;

int i = 0; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  pinMode(BTN_PIN, INPUT_PULLUP);
}

void loop() {
  btnState = digitalRead(BTN_PIN); 
  if (btnState != lastBtnState) {
    lastDebounceTime = millis();
    trigBtnState = !btnState;
  }
  if (millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis(); 
    if (!btnState && trigBtnState) {
      Serial.print("button pressed ");
      Serial.println(i);
      i += 1;
      trigBtnState = btnState;
    }
  }
  lastBtnState = btnState;
}
