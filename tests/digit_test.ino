int segs[] = {2,3,4,5,6,7,9};
int digits[] = {10,11,12,A0};

void setup() {
  for (int i = 0; i < 7; i++) pinMode(segs[i], OUTPUT);
  for (int i = 0; i < 4; i++) pinMode(digits[i], OUTPUT);

  // Display "8"
  for (int i = 0; i < 7; i++) digitalWrite(segs[i], HIGH);
}

void loop() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(digits[i], HIGH);
    delay(800);
    digitalWrite(digits[i], LOW);
    delay(200);
  }
}
