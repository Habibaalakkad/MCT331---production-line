#include <Arduino_FreeRTOS.h>
#include <Stepper.h>
#include "semphr.h"

const int sensor1 = 2;
const int sensor2 = 3;
const int stop = 7;
const int enablePin = 9;   // Enable pin of the H-bridge
const int in1Pin = 10;     // Input 1 pin of the H-bridge
const int in2Pin = 11;     // Input 2 pin of the H-bridge

SemaphoreHandle_t xBinarySemaphore1;
SemaphoreHandle_t xBinarySemaphore2;

int speed = 200;  // Speed of the actuator (adjust as needed)

// Actuator control functions
void extendActuator() {
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  analogWrite(enablePin, speed);
}

void retractActuator() {
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
  analogWrite(enablePin, speed);
}

void taskActuator1(void* pvParameters) {
  while (1) {
    if (digitalRead(sensor2) == LOW) {
      Serial.println("Extend");
      xSemaphoreGive(xBinarySemaphore1);
    }
    vTaskDelay(10);
  }
}

void taskExtend(void* pvParameters) {
  while (1) {
    xSemaphoreTake(xBinarySemaphore1, portMAX_DELAY);
    extendActuator();
    delay(1000);
  }
}

void taskActuator2(void* pvParameters) {
  while (1) {
    if (digitalRead(sensor1) == LOW) {
      Serial.println("Retract");
      xSemaphoreGive(xBinarySemaphore2);
    }
    vTaskDelay(10);
  }
}

void taskRetract(void* pvParameters) {
  while (1) {
    xSemaphoreTake(xBinarySemaphore2, portMAX_DELAY);
    retractActuator();
    delay(1000);
  }
}

// Stepper motor control
const int stepsPerRevolution = 200;
const byte TB6600_CW_Pin = 5;   // Connect to CW (Clockwise) input of TB6600
const byte TB6600_CLK_Pin = 6;  // Connect to CLK (Pulse) input of TB6600
const int irSensorPin = 4;      // Connect to the IR sensor

Stepper myStepper(stepsPerRevolution, TB6600_CW_Pin, TB6600_CLK_Pin);
SemaphoreHandle_t xBinarySemaphore;

void taskStepperControl(void *pvParameters) {
  (void)pvParameters;

  while (1) {
    if (digitalRead(irSensorPin) == HIGH) {
      // IR sensor is not triggered, move the stepper motor
      xSemaphoreGive(xBinarySemaphore);
      myStepper.step(stepsPerRevolution);
    } else {
      // IR sensor is triggered, stop the stepper motor
      myStepper.step(0);
    }
    //vTaskDelay(pdMS_TO_TICKS(10));  // Adjust delay as needed
  }
}

void setup() {
  Serial.begin(9600);

  // Actuator setup
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);

  xBinarySemaphore1 = xSemaphoreCreateBinary();
  xBinarySemaphore2 = xSemaphoreCreateBinary();

  xTaskCreate(taskActuator1, "Task1", 100, NULL, 2, NULL);
  xTaskCreate(taskExtend, "Task2", 100, NULL, 3, NULL);
  xTaskCreate(taskActuator2, "Task3", 100, NULL, 4, NULL);
  xTaskCreate(taskRetract, "Task4", 100, NULL, 5, NULL);

  // Stepper motor setup
  myStepper.setSpeed(200);
  pinMode(irSensorPin, INPUT_PULLUP);  // Assuming active LOW IR sensor

  xBinarySemaphore = xSemaphoreCreateBinary();

  if (xBinarySemaphore != NULL) {
    xTaskCreate(taskStepperControl, "StepperControl", 100, NULL, 1, NULL);
  }
}

void loop() {
  // FreeRTOS is being used, loop can be empty
}