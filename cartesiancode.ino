#include <Stepper.h>

//TB6600 - Motor 1 (X-axis)
const int stepsPerRevolution = 200;
const int clk1 = 44;
const int dir1 = 46;

//TB6600 - Motor 2 (Y-axis)

const int clk2 = 5;
const int dir2 = 6;

// for metal box
#define ir1 22
#define ir2 34
#define ir3 24
#define ir4 36

// for nonmetal box
#define irr1 28
#define irr2 26
#define irr3 30
#define irr4 32

#define PROXIMITY_SENSOR 48

// Relay control pin
const int relayPin = 50;

int LDR = 0;  // LDR variable to determine the metal ir
int LDRR = 0; // LDR variable to determine the nonmetal ir

// Motor 1 (X-axis)
Stepper myStepperr(stepsPerRevolution, clk1, dir1);
// Motor 2 (Y-axis)
Stepper myStepper2(stepsPerRevolution, clk2, dir2);

int delayTime = 1000000; // delay for smoother motion

void stopMotor(Stepper &motor)
{
  motor.step(0);
  delay(500);
}

void customMoveForward(Stepper &motor, int distanceCM)
{
  int steps = distanceCM * stepsPerRevolution * 2 / (5 * 3.14159);
  for (int i = 0; i < steps; i++)
  {
    motor.step(-21);
    delayMicroseconds(delayTime);
  }
}

void customMoveBackward(Stepper &motor, int distanceCM)
{
  int steps = distanceCM * stepsPerRevolution* 2 / (5 * 3.14159);
  for (int i = 0; i < steps; i++)
  {
    motor.step(21);
    delayMicroseconds(delayTime);
  }
}

void setup()
{

  // METALS IR
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  // NON METAL IR
  pinMode(irr1, INPUT);
  pinMode(irr2, INPUT);
  pinMode(irr3, INPUT);
  pinMode(irr4, INPUT);
  // Proximity sensor
  pinMode(PROXIMITY_SENSOR, INPUT);
  // Relay control pin
  pinMode(relayPin, OUTPUT);

  myStepperr.setSpeed(300);  // Motor 1 speed
  myStepper2.setSpeed(300); // Motor 2 speed

  Serial.begin(19200);
}

void loop()
{
  int proximityValue = digitalRead(PROXIMITY_SENSOR);

  // METAAALLLL
  int IR1value = digitalRead(ir1);
  int IR2value = digitalRead(ir2);
  int IR3value = digitalRead(ir3);
  int IR4value = digitalRead(ir4);

  // NONMETAAALLLLL
  int IRR1value = digitalRead(irr1);
  int IRR2value = digitalRead(irr2);
  int IRR3value = digitalRead(irr3);
  int IRR4value = digitalRead(irr4);

  digitalWrite(relayPin, HIGH);

  // METALL LDR VALUES
  if (IR1value == HIGH)
  {
    Serial.println("first metal box is empty");
    LDR = 1;
  }
  else if (IR2value == HIGH && IR1value == LOW)
  {
    Serial.println("second metal box is empty");
    LDR = 2;
  }
  else if (IR3value == HIGH && IR2value == LOW && IR1value == LOW)
  {
    Serial.println("third metal box is empty");
    LDR = 3;
  }
  else if (IR4value == HIGH && IR3value == LOW && IR2value == LOW && IR1value == LOW)
  {
    Serial.println("fourth metal box is empty");
    LDR = 4;
  }

  // NON METAL LDR VALUES
  if (IRR1value == HIGH)
  {
    Serial.println("first NON-metal box is empty");
    LDRR = 1;
  }
  else if (IRR2value == HIGH && IRR1value == LOW)
  {
    Serial.println("second NON-metal box is empty");
    LDRR = 2;
  }
  else if (IRR3value == HIGH && IRR2value == LOW && IRR1value == LOW)
  {
    Serial.println("third NON-metal box is empty");
    LDRR = 3;
  }
  else if (IRR4value == HIGH && IRR3value == LOW && IRR2value == LOW && IRR1value == LOW)
  {
    Serial.println("fourth NON-metal box is empty");
    LDRR = 4;
  }
  else
  {
    LDR = 0;
  }

  if (proximityValue == LOW)
  {
    switch (LDR)
    {
    case 1:
      Serial.println("Moving to first metal box");
      customMoveForward(myStepperr, 69);
      delay(3000);
      digitalWrite(relayPin, LOW); // Deactivate the relay
      stopMotor(myStepperr);
      delay(3000);
      customMoveBackward(myStepperr, 50);
      delay(3000);
      digitalWrite(relayPin, HIGH);
      delay(3000);
      customMoveBackward(myStepperr, 13);
      stopMotor(myStepperr);
      delay(6000);
      break;

    case 2:
      Serial.println("Moving to second metal box");
      customMoveForward(myStepperr, 69);
      delay(3000);
      digitalWrite(relayPin, LOW); // Deactivate the relay
      stopMotor(myStepperr);
      delay(3000);
      customMoveBackward(myStepperr, 50);
      delay(2000);
      customMoveForward(myStepper2, 16);
      delay(5000);
      digitalWrite(relayPin, HIGH);
      Serial.println("Returning second motor to initial position");
      customMoveBackward(myStepper2, 16);
      delay(3000);
      customMoveBackward(myStepperr, 16);
      stopMotor(myStepperr);
      delay(6000);
      break;

    case 3:
      Serial.println("Moving to third metal box");
      customMoveForward(myStepperr, 69);
      delay(3000);
      digitalWrite(relayPin, LOW); // Deactivate the relay
      stopMotor(myStepperr);
      delay(3000);
      customMoveBackward(myStepperr, 69);
      delay(3000);
      customMoveForward(myStepper2, 16);
      delay(5000);
      digitalWrite(relayPin, HIGH);
      delay(3000);
      Serial.println("Returning second motor to initial position");
      customMoveBackward(myStepper2, 16);
      delay(3000);
      break;

    case 4:
      Serial.println("Moving to forth metal box");
      customMoveForward(myStepperr, 69);
      delay(3000);
      digitalWrite(relayPin, LOW); // Deactivate the relay
      stopMotor(myStepperr);
      delay(3000);
      customMoveBackward(myStepperr, 69);
      delay(3000);
      digitalWrite(relayPin, HIGH);
      delay(3000);
      break;

    default:
      break;
    }

  }
  else
  {
    switch (LDRR)
    {
    case 1:
      Serial.println("Moving to first NONmetal box");
      customMoveForward(myStepperr, 69);
      delay(3000);
      digitalWrite(relayPin, LOW); // Deactivate the relay
      stopMotor(myStepperr);
      delay(3000);
      customMoveBackward(myStepperr, 50);
      delay(3000);
      customMoveBackward(myStepper2, 27);
      delay(3000);
      digitalWrite(relayPin, HIGH);
      delay(2000);
      Serial.println("Moving to original position");
     customMoveForward(myStepper2, 27);
     delay(2000);
      customMoveBackward(myStepperr, 13);
      stopMotor(myStepperr);
      delay(6000);
      break;

    case 2:
      Serial.println("Moving to second  NONmetal box");
      customMoveForward(myStepperr, 69);
      delay(3000);
      digitalWrite(relayPin, LOW); // Deactivate the relay
      stopMotor(myStepperr);
      delay(3000);
      customMoveBackward(myStepperr, 50);
      delay(6000);
      customMoveBackward(myStepper2, 14);
      delay(3000);
      digitalWrite(relayPin, HIGH);
      Serial.println("Moving to original position");
     customMoveForward(myStepper2, 14);
     delay(2000);
      customMoveBackward(myStepperr, 13);
      stopMotor(myStepperr);
      delay(6000);
      break;

    case 3:
      Serial.println("Moving to third NONmetal box");
      customMoveForward(myStepperr, 69);
      delay(3000);
      digitalWrite(relayPin, LOW); // Deactivate the relay
      stopMotor(myStepperr);
      delay(3000);
      customMoveBackward(myStepperr, 69);
      delay(3000);
      customMoveBackward(myStepper2, 14);
      delay(3000);
      digitalWrite(relayPin, HIGH);
      Serial.println("Moving to original position");
     customMoveForward(myStepper2, 14);
      delay(3000);
      break;

    case 4:
      Serial.println("Moving to fourth NONmetal box");
      customMoveForward(myStepperr, 69);
      delay(3000);
      digitalWrite(relayPin, LOW); // Deactivate the relay
      stopMotor(myStepperr);
      delay(3000);
      customMoveBackward(myStepperr, 69);
      delay(3000);
      customMoveBackward(myStepper2, 27);
      delay(3000);
      digitalWrite(relayPin, HIGH);
      delay(2000);
      Serial.println("Moving to original position");
     customMoveForward(myStepper2, 27);
     delay(2000);
      break;

    default:
      break;
    }
  }
}