#include <ADCTouch.h>
int ref0;    //reference values to remove offset
int smoothedValue;
void setup()
{
  // No pins to setup, pins can still be used regularly, although it will affect readings
  Serial.begin(9600);
  ref0 = ADCTouch.read(A0, 500);    //create reference values to offset
}

void loop()
{
  int value0 = ADCTouch.read(A0);   //no second parameter
  value0 -= ref0;       //remove offset
  
  smoothedValue = smooth(value0, .85, smoothedValue);
  Serial.println(smoothedValue);
}

int smooth(int data, float filterVal, float smoothedVal) {
  if (filterVal > 1) {     // check to make sure param's are within range
    filterVal = .99;
  }
  else if (filterVal <= 0) {
    filterVal = 0;
  }
  smoothedVal = (data * (1 - filterVal)) + (smoothedVal  *  filterVal);
  return (int)smoothedVal;
}

