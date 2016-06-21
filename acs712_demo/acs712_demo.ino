#include <ACS712.h>
ACS712 ACS;

void setup() {
  Serial.begin(9600);
  Serial.println("Start");

  uint16_t half_bit = ACS.Set_ADC(10);
  Serial.print("half_bit: ");
  Serial.println(half_bit);
  long vcc = ACS.Get_vcc_analog();
  Serial.print("vcc: ");
  Serial.println(vcc);
}
void loop() {
  double current = ACS.Get_current(A1,5);
  Serial.print("current: ");
  Serial.println(current);
  delay(100);
}
