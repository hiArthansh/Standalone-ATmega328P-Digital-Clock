int segs[] = {2,3,4,5,6,7,9};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segs[i], OUTPUT);
  }

  // Enable all digits manually for test
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A0, OUTPUT);

  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(A0, HIGH);
}

void loop() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segs[i], HIGH);
    delay(500);
    digitalWrite(segs[i], LOW);
    delay(200);
  }
}
