#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Ps3Controller.h>

int player = 0;
int battery = 0;

#define PCA9685_ADDRESS 0x40 // Default I2C address of PCA9685
#define SERVO_MIN_PULSE_WIDTH 110 // Minimum pulse width for the servo
#define SERVO_MAX_PULSE_WIDTH 610 // Maximum pulse width for the servo
#define SERVO_MIN_ANGLE 0 // Minimum angle for the servo
#define SERVO_MAX_ANGLE 180 // Maximum angle for the servo
#define SERVO_CHANNEL 0 // PCA9685 channel connected to the servo

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void notify() {
  if (battery != Ps3.data.status.battery) {
    battery = Ps3.data.status.battery;
    Serial.print("The controller battery is ");
    if (battery == ps3_status_battery_charging) Serial.println("charging");
    else if (battery == ps3_status_battery_full) Serial.println("FULL");
    else if (battery == ps3_status_battery_high) Serial.println("HIGH");
    else if (battery == ps3_status_battery_low) Serial.println("LOW");
    else if (battery == ps3_status_battery_dying) Serial.println("DYING");
    else if (battery == ps3_status_battery_shutdown) Serial.println("SHUTDOWN");
    else Serial.println("UNDEFINED");
  }
}

void onConnect() {
  Serial.println("Connected.");
}

void setup() {
  Serial.begin(9600);
  
  Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin("00:00:00:00:00:00"); // Enter MAC address of PS3 controller here
  
  Serial.println("Ready.");
  
  pwm.begin();
  pwm.setPWMFreq(60); // Set PWM frequency to 60 Hz
  delay(10);
}

void loop() {
  if (!Ps3.isConnected()) return;
  
  // Control servos with PS3 controller
  if (Ps3.event.button_down.right) {
    servo4(45);
  }
  if (Ps3.event.button_down.left) {
    servo4(125);
  }
  if (Ps3.event.button_down.up) {
    servo5(45);
  }
  if (Ps3.event.button_down.down) {
    servo5(125);
  }
  if (Ps3.event.button_down.start) {
    moveservo(90);
  }
  if (Ps3.event.button_down.circle) {
    moveSequence();
  }
  if (Ps3.event.button_down.square) {
    complexMoveSequence();
  }
  if (Ps3.event.button_down.triangle) {
    specialMove();
  }
}

// Servo control functions
void servo1(int angle) {
  int pulse_width = map(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
  pwm.setPWM(0, 0, pulse_width);
  Serial.print("Moving servo1 to ");
  Serial.print(angle);
  Serial.println(" degrees");
}

void servo3(int angle) {
  int pulse_width = map(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
  pwm.setPWM(2, 0, pulse_width);
  Serial.print("Moving servo3 to ");
  Serial.print(angle);
  Serial.println(" degrees");
}

void servo4(int angle) {
  int pulse_width = map(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
  pwm.setPWM(3, 0, pulse_width);
  Serial.print("Moving servo4 to ");
  Serial.print(angle);
  Serial.println(" degrees");
}

void servo5(int angle) {
  int pulse_width = map(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
  pwm.setPWM(4, 0, pulse_width);
  Serial.print("Moving servo5 to ");
  Serial.print(angle);
  Serial.println(" degrees");
}

void moveservo(int angle) {
  int pulse_width = map(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
  for (int i = 0; i < 7; i++) {
    pwm.setPWM(i, 0, pulse_width);
  }
  Serial.print("Moving all servos to ");
  Serial.print(angle);
  Serial.println(" degrees");
}

void esp(int angle) {
  int pulse_width = map(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
  pwm.setPWM(5, 0, pulse_width);
  pwm.setPWM(6, 0, pulse_width);
  Serial.print("Moving ESP servos to ");
  Serial.print(angle);
  Serial.println(" degrees");
}

void moveSequence() {
  moveservo(125);
  delay(500);
  moveservo(90);
  delay(500);
  moveservo(45);
  delay(500);
  moveservo(90);
  delay(500);
}

void complexMoveSequence() {
  for (int i = 0; i < 3; i++) {
    moveservo(45);
    delay(500);
    moveservo(90);
    delay(500);
    moveservo(125);
    delay(500);
  }
}

void specialMove() {
  servo5(45);
  delay(500);
  servo3(45);
  delay(500);
  servo1(125);
  delay(500);
  servo5(90);
  delay(500);
  servo3(90);
  delay(500);
  servo1(90);
  delay(500);
}
