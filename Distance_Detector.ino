const int trigPin = 9;  // Trig pin of the ultrasonic sensor connected to digital pin 9
const int echoPin = 10; // Echo pin of the ultrasonic sensor connected to digital pin 10

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(trigPin, OUTPUT); // Set trigPin as OUTPUT
  pinMode(echoPin, INPUT);  // Set echoPin as INPUT
}

void loop() {
  // Send a pulse to the sensor to trigger a measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse in microseconds
  long duration = pulseIn(echoPin, HIGH);

  // Convert the duration into centimeters and inches
  float distance_cm = duration * 0.034 / 2; // Speed of sound in air is 343 meters per second or 0.0343 cm/microsecond
  float distance_inches = duration * 0.0133 / 2; // Speed of sound in air is 1130 feet per second or 0.0133 inches/microsecond

  // Print the distance in centimeters and inches to the Serial monitor
  Serial.print("Distance in Centimeters: ");
  Serial.print(distance_cm);
  Serial.print(" cm, Inches: ");
  Serial.print(distance_inches);
  Serial.println(" inches");

  delay(1000); // Wait for a second before taking the next measurement
}
