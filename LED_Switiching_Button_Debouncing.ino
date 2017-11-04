const int buttonPin = 2;
const int ledPin = 13;

int currentLedState = 0;
boolean buttonState = LOW;

void setup() {
 pinMode(ledPin, OUTPUT);
 pinMode(buttonState, INPUT);
}

void loop() {
  
    if(isDetectedButtonPress(buttonState) && isCurrentLedStateTurnedOff()){
      turnLedOn();
      buttonState = HIGH;
      currentLedState = 1;
    }
    else if(isDetectedButtonPress(buttonState) && isCurrentLedStateTurnedOn()){
    turnLedOff();
    buttonState = HIGH;
    currentLedState = 0;
    }
    else if(isDetectedButtonRelease(buttonState)){
    buttonState = LOW;
  }
}
boolean isDetectedButtonRelease(boolean buttonState){
  if(debounceButton(buttonState) == LOW && buttonState == HIGH){
    return true;
  }else
  return false;
}
boolean isDetectedButtonPress(boolean buttonState){
  if(debounceButton(buttonState) == HIGH && buttonState == LOW){
    return true;
  }
  else
  return false;
}

boolean isCurrentLedStateTurnedOff(){
  if(currentLedState == 0){
    return true;
  }
  else
    return false;
}
boolean isCurrentLedStateTurnedOn(){
  if(currentLedState == 1){
    return true;
  }
  else
    return false;
}
boolean debounceButton(boolean state)
{
  boolean stateNow = digitalRead(buttonPin);
  if(state != stateNow)
  {
    delay(10);
    stateNow = digitalRead(buttonPin);
  }
  return stateNow;
}
void turnLedOn(){
  digitalWrite(ledPin,HIGH);
}
void turnLedOff(){
  digitalWrite(ledPin,LOW);
}

