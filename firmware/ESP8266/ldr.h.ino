#define LDR 2

void setup() {
  Serial.begin(9600);
  pinMode(LDR, INPUT);
}

void loop() {

  int ldr = digitalRead(LDR);

  if (ldr == LOW) {
    Serial.println("NIGHT MODE");
  } else {
    Serial.println("DAY MODE");
  }

  delay(300);
}