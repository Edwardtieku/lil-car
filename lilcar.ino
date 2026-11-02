// --- Pin Definitions ---
// Motor A (Left Motor)
const int IN1 = 5;
const int IN2 = 6;

// Motor B (Right Motor)
const int IN3 = 10;
const int IN4 = 11;

char command;

void setup() {
  // Set motor control pins as outputs
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(10, OUTPUT);

  // Initialize serial communication for HC-05
  Serial.begin(9600);

  // Stop the car initially
  stopCar();
}

void loop() {
  // Check if data is available from the Bluetooth module
  if (Serial.available() > 0) {
    command = Serial.read();

    switch (command) {
      case 'F': moveForward();  break;
      case 'B': moveBackward(); break;
      case 'L': turnLeft();     break;
      case 'R': turnRight();    break;
      case 'S': stopCar();      break;
      default:  stopCar();      break;
    }
  }
}

// --- Movement Functions ---

void moveForward() {
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void moveBackward() {
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void turnLeft() {
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void turnRight() {
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void stopCar() {
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}