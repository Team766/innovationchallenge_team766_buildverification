#include <Adafruit_LSM6DSO32.h>
#define BUZZER 8
 
Adafruit_LSM6DSO32 dso32;
void setup(void) {
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens
 
  Serial.println("Adafruit LSM6DSO32 test!");
 
  if (!dso32.begin_I2C()) {
    while (1) {
      delay(10);
     Serial.println("Accelermeter not found, check connections")
    }
  }
 
  Serial.println("LSM6DSO32 Found!");
  pinMode(BUZZER, OUTPUT);
  dso32.setAccelRange(LSM6DSO32_ACCEL_RANGE_8_G);
  dso32.setGyroRange(LSM6DS_GYRO_RANGE_250_DPS );
  dso32.setAccelDataRate(LSM6DS_RATE_52_HZ);
  dso32.setGyroDataRate(LSM6DS_RATE_52_HZ);
}
 
void loop() {
 
  //  /* Get a new normalized sensor event */
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  dso32.getEvent(&accel, &gyro, &temp);
 
  Serial.print("\t\tTemperature ");
  Serial.print(temp.temperature);
  Serial.println(" deg C");
 
  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("\t\tAccel X: ");
  Serial.print(accel.acceleration.x);
  Serial.print(" \tY: ");
  Serial.print(accel.acceleration.y);
  Serial.print(" \tZ: ");
  Serial.print(accel.acceleration.z);
  Serial.println(" m/s^2 ");
  /* Display the results (rotation is measured in rad/s) */
  Serial.print("\t\tGyro X: ");
  Serial.print(gyro.gyro.x);
  Serial.print(" \tY: ");
  Serial.print(gyro.gyro.y);
  Serial.print(" \tZ: ");
  Serial.print(gyro.gyro.z);
  Serial.println(" radians/s ");
  Serial.println();
  tone(BUZZER, 250, 200);
  delay(100);
}
