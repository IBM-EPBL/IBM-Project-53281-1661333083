// C++ code
//
int temp = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  temp = (-40 + 0.488155 * (analogRead(A0) - 20));
  Serial.print((-40 + 0.488155 * (analogRead(A0) - 20)));
  Serial.println("c");
  if (temp < 20) {
    digitalWrite(12, HIGH);
    tone(5, 29, 500); // play tone 10 (A#0 = 29 Hz)
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(12, LOW);
    noTone(5);
    delay(1500); // Wait for 1500 millisecond(s)
  }
  if (temp > 30) {
    digitalWrite(13, HIGH);
    tone(5, 29, 500); // play tone 10 (A#0 = 29 Hz)
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(13, LOW);
    noTone(5);
    delay(1500); // Wait for 1500 millisecond(s)
  }
  if (temp >= 20 && temp <= 30) {
    digitalWrite(5, LOW);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }
}