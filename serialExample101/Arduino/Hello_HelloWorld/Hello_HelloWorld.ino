char serialInput;
void setup() {
  //start serial communication at 9600baud (pulses per second)
  Serial.begin(9600);
}
void loop() {
  //check if there's anything in Serial RX
  if (Serial.available() > 0) {
    //read one byte
    serialInput = Serial.read();
    //print byte back
    //Serial.println(serialInput);
    if (serialInput == 'a') {
      Serial.println("hello");
      //turn on built-in LED
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
  }
}
