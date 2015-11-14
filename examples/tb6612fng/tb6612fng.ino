#include <TB6612FNG.h>

TB6612FNG motor=TB6612FNG(9,10,11,12);

void setup() {
  // put your setup code here, to run once:
  motor.Setup();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("motor en reversa");
  motor.Move(-255);
  delay(3000);
  Serial.println("motor frenado");
  motor.Brake();
  delay(3000);
  Serial.println("motor adelante");
  motor.Move(255);
  delay(3000);
  Serial.println("motor apagado");
  motor.Mode(motor.standby);
  delay(3000);
  Serial.println("motor normal");
  motor.Mode(motor.normal);
  delay(3000);
  while (1) {
    motor.Move(-225);
    delay(1500);
    motor.Move(225);
    delay(1500);
  }
}
