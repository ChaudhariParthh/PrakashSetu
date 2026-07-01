#define RELAY1 8
#define RELAY2 9
#define RELAY3 10

void setup() {
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);

  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
}

void loop() {

  digitalWrite(RELAY1, LOW);   // ON
  delay(2000);
  digitalWrite(RELAY1, HIGH);  // OFF

  digitalWrite(RELAY2, LOW);   // ON
  delay(2000);
  digitalWrite(RELAY2, HIGH);  // OFF

  digitalWrite(RELAY3, LOW);   // ON
  delay(2000);
  digitalWrite(RELAY3, HIGH);  // OFF

  delay(2000);
}