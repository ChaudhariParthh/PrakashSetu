#define LDR A0

#define RELAY1 8
#define RELAY2 9
#define RELAY3 10

int threshold = 500;

void setup() {

  Serial.begin(9600);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);

  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
}

void loop() {

  int ldrValue = analogRead(LDR);

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Fault Detection
  if (ldrValue <= 5) {

    Serial.println("***************");
    Serial.println("FAULT DETECTED!");
    Serial.println("LDR SENSOR FAILURE");
    Serial.println("***************");

    digitalWrite(RELAY1, HIGH);
    digitalWrite(RELAY2, HIGH);
    digitalWrite(RELAY3, HIGH);

    delay(1000);
    return;
  }

  // Night
  if (ldrValue < threshold) {

    Serial.println("Night Mode");
    digitalWrite(RELAY1, LOW);
    digitalWrite(RELAY2, LOW);
    digitalWrite(RELAY3, LOW);
  }

  // Day
  else {

    Serial.println("Day Mode");
    digitalWrite(RELAY1, HIGH);
    digitalWrite(RELAY2, HIGH);
    digitalWrite(RELAY3, HIGH);
  }

  delay(500);
}