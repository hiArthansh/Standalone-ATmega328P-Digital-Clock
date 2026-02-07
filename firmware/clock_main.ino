

// int segs[] = {2,3,4,5,6,7,9};
// int d1 = 10;
// int d2 = 11;

// //clock logic
// unsigned long lastTick = 0;
// int hours = 12;
// int minutes = 0;
// int seconds = 0;


// byte digits[10][7] = {
//   {1,1,1,1,1,1,0}, // 0
//   {0,1,1,0,0,0,0}, // 1
//   {1,1,0,1,1,0,1}, // 2
//   {1,1,1,1,0,0,1}, // 3
//   {0,1,1,0,0,1,1}, // 4
//   {1,0,1,1,0,1,1}, // 5
//   {1,0,1,1,1,1,1}, // 6
//   {1,1,1,0,0,0,0}, // 7
//   {1,1,1,1,1,1,1}, // 8
//   {1,1,1,1,0,1,1}  // 9
// };

// //clock function
// void updateClock() {
//   if (millis() - lastTick >= 1000) {
//     lastTick = millis();
//     seconds++;

//     if (seconds >= 60) {
//       seconds = 0;
//       minutes++;
//     }

//     if (minutes >= 60) {
//       minutes = 0;
//       hours++;
//     }

//     if (hours >= 24) {
//       hours = 0;
//     }
//   }
// }


// void showDigit(int num) {
//   for (int i = 0; i < 7; i++) {
//     digitalWrite(segs[i], digits[num][i]);
//   }
// }

// void setup() {
//   for (int i = 0; i < 7; i++) pinMode(segs[i], OUTPUT);
//   pinMode(d1, OUTPUT);
//   pinMode(d2, OUTPUT);
//   pinMode(LED_BUILTIN, OUTPUT);
//   Serial.begin(9600);

// }

// void loop() {

//   // Blink LED simply
//   digitalWrite(LED_BUILTIN, HIGH);


//   updateClock();

//   int d1val = hours / 10;
//   int d2val = hours % 10;

//  for (int i = 0; i < 50; i++) {
//     digitalWrite(d2, LOW);
//     digitalWrite(d1, HIGH);
//     showDigit(d1val);
//     delay(3);

//     digitalWrite(d1, LOW);
//     digitalWrite(d2, HIGH);
//     showDigit(d2val);
//     delay(3);
//   }
//   digitalWrite(LED_BUILTIN, LOW);
//   Serial.println("LED off");

// }




//code for hour common cathode working

// int segs[] = {2,3,4,5,6,7,9};
// int d1 = 10;
// int d2 = 11;

// // ---- Clock ----
// unsigned long lastTick = 0;
// int hours = 12;
// int minutes = 0;
// int seconds = 0;

// // ---- Display multiplex ----
// unsigned long lastMux = 0;
// bool muxState = false;

// // ---- Heartbeat LED ----
// unsigned long lastBeat = 0;
// bool beatState = false;

// // ---- Digit map (common cathode, active HIGH) ----
// byte digits[10][7] = {
//   {1,1,1,1,1,1,0}, // 0
//   {0,1,1,0,0,0,0}, // 1
//   {1,1,0,1,1,0,1}, // 2
//   {1,1,1,1,0,0,1}, // 3
//   {0,1,1,0,0,1,1}, // 4
//   {1,0,1,1,0,1,1}, // 5
//   {1,0,1,1,1,1,1}, // 6
//   {1,1,1,0,0,0,0}, // 7
//   {1,1,1,1,1,1,1}, // 8
//   {1,1,1,1,0,1,1}  // 9
// };

// // ---- Clock update ----
// void updateClock() {
//   if (millis() - lastTick >= 1000) {
//     lastTick += 1000;
//     seconds++;

//     if (seconds >= 60) { seconds = 0; minutes++; }
//     if (minutes >= 60) { minutes = 0; hours++; }
//     if (hours >= 24)   { hours = 0; }
//   }
// }

// // ---- Segment output ----
// void showDigit(int num) {
//   for (int i = 0; i < 7; i++) {
//     digitalWrite(segs[i], digits[num][i]);
//   }
// }

// // ---- Non-blocking multiplex ----
// void refreshDisplay(int left, int right) {
//   if (micros() - lastMux >= 3000) {   // 3 ms per digit
//     lastMux = micros();

//     if (muxState) {
//       digitalWrite(d2, LOW);
//       digitalWrite(d1, HIGH);
//       showDigit(left);
//     } else {
//       digitalWrite(d1, LOW);
//       digitalWrite(d2, HIGH);
//       showDigit(right);
//     }

//     muxState = !muxState;
//   }
// }

// // ---- Heartbeat LED (1 Hz) ----
// void heartbeat() {
//   if (millis() - lastBeat >= 500) {
//     lastBeat = millis();
//     beatState = !beatState;
//     digitalWrite(LED_BUILTIN, beatState);
//   }
// }

// void setup() {
//   for (int i = 0; i < 7; i++) pinMode(segs[i], OUTPUT);
//   pinMode(d1, OUTPUT);
//   pinMode(d2, OUTPUT);
//   pinMode(LED_BUILTIN, OUTPUT);
// }

// void loop() {
//   updateClock();
//   heartbeat();

//   int left  = hours / 10;
//   int right = hours % 10;

//   refreshDisplay(left, right);
// }




// int segs[] = {2,3,4,5,6,7,9};

// // ---- Digit enable pins ----
// int d1 = 10;   // Hour tens
// int d2 = 11;   // Hour ones
// int d3 = 12;   // Minute tens
// int d4 = A0;   // Minute ones

// // ---- Clock ----
// unsigned long lastTick = 0;
// int hours = 12;
// int minutes = 0;
// int seconds = 0;

// // ---- Display multiplex ----
// unsigned long lastMux = 0;
// int muxIndex = 0;

// // ---- Heartbeat LED ----
// unsigned long lastBeat = 0;
// bool beatState = false;

// // ---- Digit map (common cathode, active HIGH) ----
// byte digits[10][7] = {
//   {1,1,1,1,1,1,0}, // 0
//   {0,1,1,0,0,0,0}, // 1
//   {1,1,0,1,1,0,1}, // 2
//   {1,1,1,1,0,0,1}, // 3
//   {0,1,1,0,0,1,1}, // 4
//   {1,0,1,1,0,1,1}, // 5
//   {1,0,1,1,1,1,1}, // 6
//   {1,1,1,0,0,0,0}, // 7
//   {1,1,1,1,1,1,1}, // 8
//   {1,1,1,1,0,1,1}  // 9
// };

// // ---- Clock update ----
// void updateClock() {
//   if (millis() - lastTick >= 1000) {
//     lastTick += 1000;
//     seconds++;

//     if (seconds >= 60) { seconds = 0; minutes++; }
//     if (minutes >= 60) { minutes = 0; hours++; }
//     if (hours >= 24)   { hours = 0; }
//   }
// }

// // ---- Segment output ----
// void showDigit(int num) {
//   for (int i = 0; i < 7; i++) {
//     digitalWrite(segs[i], digits[num][i]);
//   }
// }

// // ---- 4-digit multiplex ----
// void refreshDisplay() {
//   if (micros() - lastMux >= 2500) {   // ~400 Hz total refresh
//     lastMux = micros();

//     // Turn all digits OFF first
//     digitalWrite(d1, LOW);
//     digitalWrite(d2, LOW);
//     digitalWrite(d3, LOW);
//     digitalWrite(d4, LOW);

//     int hT = hours / 10;
//     int hO = hours % 10;
//     int mT = minutes / 10;
//     int mO = minutes % 10;

//     switch (muxIndex) {
//       case 0:
//         showDigit(hT);
//         digitalWrite(d1, HIGH);
//         break;
//       case 1:
//         showDigit(hO);
//         digitalWrite(d2, HIGH);
//         break;
//       case 2:
//         showDigit(mT);
//         digitalWrite(d3, HIGH);
//         break;
//       case 3:
//         showDigit(mO);
//         digitalWrite(d4, HIGH);
//         break;
//     }

//     muxIndex++;
//     if (muxIndex > 3) muxIndex = 0;
//   }
// }

// // ---- Heartbeat LED (1 Hz) ----
// void heartbeat() {
//   if (millis() - lastBeat >= 500) {
//     lastBeat = millis();
//     beatState = !beatState;
//     digitalWrite(LED_BUILTIN, beatState);
//   }
// }

// void setup() {
//   for (int i = 0; i < 7; i++) pinMode(segs[i], OUTPUT);

//   pinMode(d1, OUTPUT);
//   pinMode(d2, OUTPUT);
//   pinMode(d3, OUTPUT);
//   pinMode(d4, OUTPUT);

//   pinMode(LED_BUILTIN, OUTPUT);
// }

// void loop() {
//   updateClock();
//   heartbeat();
//   refreshDisplay();
// }
// code with timer interrupt for better accuracy 
// int segs[] = {2,3,4,5,6,7,9};

// // ---- Digit enable pins ----
// int d1 = 10;   // Hour tens
// int d2 = 11;   // Hour ones
// int d3 = 12;   // Minute tens
// int d4 = A0;   // Minute ones

// // ---- Clock time ----
// volatile int seconds = 0;
// volatile int minutes = 0;
// volatile int hours   = 12;

// // ---- Multiplex ----
// unsigned long lastMux = 0;
// int muxIndex = 0;

// // ---- Heartbeat LED ----
// unsigned long lastBeat = 0;
// bool beatState = false;

// // ---- Digit map (common cathode) ----
// byte digits[10][7] = {
//   {1,1,1,1,1,1,0}, // 0
//   {0,1,1,0,0,0,0}, // 1
//   {1,1,0,1,1,0,1}, // 2
//   {1,1,1,1,0,0,1}, // 3
//   {0,1,1,0,0,1,1}, // 4
//   {1,0,1,1,0,1,1}, // 5
//   {1,0,1,1,1,1,1}, // 6
//   {1,1,1,0,0,0,0}, // 7
//   {1,1,1,1,1,1,1}, // 8
//   {1,1,1,1,0,1,1}  // 9
// };

// // ---- Timer1 Interrupt (1 second) ----
// ISR(TIMER1_COMPA_vect) {
//   seconds++;

//   if (seconds >= 60) {
//     seconds = 0;
//     minutes++;
//   }
//   if (minutes >= 60) {
//     minutes = 0;
//     hours++;
//   }
//   if (hours >= 24) {
//     hours = 0;
//   }
// }

// // ---- Segment output ----
// void showDigit(int num) {
//   for (int i = 0; i < 7; i++) {
//     digitalWrite(segs[i], digits[num][i]);
//   }
// }

// // ---- 4-digit multiplex ----
// void refreshDisplay() {
//   if (micros() - lastMux >= 2500) {
//     lastMux = micros();

//     digitalWrite(d1, LOW);
//     digitalWrite(d2, LOW);
//     digitalWrite(d3, LOW);
//     digitalWrite(d4, LOW);

//     int hT = hours / 10;
//     int hO = hours % 10;
//     int mT = minutes / 10;
//     int mO = minutes % 10;

//     switch (muxIndex) {
//       case 0: showDigit(hT); digitalWrite(d1, HIGH); break;
//       case 1: showDigit(hO); digitalWrite(d2, HIGH); break;
//       case 2: showDigit(mT); digitalWrite(d3, HIGH); break;
//       case 3: showDigit(mO); digitalWrite(d4, HIGH); break;
//     }

//     muxIndex++;
//     if (muxIndex > 3) muxIndex = 0;
//   }
// }

// // ---- Heartbeat LED ----
// void heartbeat() {
//   if (millis() - lastBeat >= 500) {
//     lastBeat = millis();
//     beatState = !beatState;
//     digitalWrite(LED_BUILTIN, beatState);
//   }
// }

// // ---- Timer1 setup ----
// void setupTimer1() {
//   cli();                // Disable interrupts
//   TCCR1A = 0;
//   TCCR1B = 0;
//   TCNT1  = 0;

//   // 16 MHz / 1024 = 15625 counts per second
//   OCR1A = 15624;

//   TCCR1B |= (1 << WGM12);              // CTC mode
//   TCCR1B |= (1 << CS12) | (1 << CS10); // Prescaler 1024
//   TIMSK1 |= (1 << OCIE1A);             // Enable compare interrupt
//   sei();                // Enable interrupts
// }

// void setup() {
//   for (int i = 0; i < 7; i++) pinMode(segs[i], OUTPUT);

//   pinMode(d1, OUTPUT);
//   pinMode(d2, OUTPUT);
//   pinMode(d3, OUTPUT);
//   pinMode(d4, OUTPUT);

//   pinMode(LED_BUILTIN, OUTPUT);

//   setupTimer1();
// }

// void loop() {
//   refreshDisplay();
//   heartbeat();
// }



//code wiithout interrupt thing but with controlling buttons 
int segs[] = {2,3,4,5,6,7,9};

// ---- Digit enable pins ----
int d1 = 10;   // Hour tens
int d2 = 11;   // Hour ones
int d3 = 12;   // Minute tens
int d4 = A0;   // Minute ones

// ---- Buttons ----
#define MODE_BTN A1
#define INC_BTN  A2

// ---- Clock ----
unsigned long lastTick = 0;
int hours = 12;
int minutes = 0;
int seconds = 0;

// ---- Modes ----
int mode = 0;  
// 0 = normal run
// 1 = set hour
// 2 = set minute

// ---- Debounce ----
unsigned long lastModePress = 0;
unsigned long lastIncPress  = 0;

// ---- Display multiplex ----
unsigned long lastMux = 0;
int muxIndex = 0;

// ---- Heartbeat LED ----
unsigned long lastBeat = 0;
bool beatState = false;

// ---- Digit map (common cathode) ----
byte digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

// ---- Clock update (paused in set mode) ----
void updateClock() {
  if (mode != 0) return;

  if (millis() - lastTick >= 1000) {
    lastTick += 1000;
    seconds++;

    if (seconds >= 60) { seconds = 0; minutes++; }
    if (minutes >= 60) { minutes = 0; hours++; }
    if (hours >= 24)   { hours = 0; }
  }
}

// ---- Buttons ----
void readButtons() {

  if (digitalRead(MODE_BTN) == LOW && millis() - lastModePress > 300) {
    lastModePress = millis();
    mode++;
    if (mode > 2) mode = 0;
  }

  if (digitalRead(INC_BTN) == LOW && millis() - lastIncPress > 300) {
    lastIncPress = millis();

    if (mode == 1) {            // set hour
      hours++;
      if (hours >= 24) hours = 0;
    }

    if (mode == 2) {            // set minute
      minutes++;
      if (minutes >= 60) minutes = 0;
    }
  }
}

// ---- Segment output ----
void showDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segs[i], digits[num][i]);
  }
}

// ---- 4-digit multiplex with blink feedback ----
void refreshDisplay() {
  if (micros() - lastMux >= 2500) {
    lastMux = micros();

    digitalWrite(d1, LOW);
    digitalWrite(d2, LOW);
    digitalWrite(d3, LOW);
    digitalWrite(d4, LOW);

    int hT = hours / 10;
    int hO = hours % 10;
    int mT = minutes / 10;
    int mO = minutes % 10;

    bool blinkOff = (millis() / 300) % 2;

    switch (muxIndex) {
      case 0:
        if (!(mode == 1 && blinkOff)) {
          showDigit(hT);
          digitalWrite(d1, HIGH);
        }
        break;

      case 1:
        if (!(mode == 1 && blinkOff)) {
          showDigit(hO);
          digitalWrite(d2, HIGH);
        }
        break;

      case 2:
        if (!(mode == 2 && blinkOff)) {
          showDigit(mT);
          digitalWrite(d3, HIGH);
        }
        break;

      case 3:
        if (!(mode == 2 && blinkOff)) {
          showDigit(mO);
          digitalWrite(d4, HIGH);
        }
        break;
    }

    muxIndex++;
    if (muxIndex > 3) muxIndex = 0;
  }
}

// ---- Heartbeat LED ----
void heartbeat() {
  if (millis() - lastBeat >= 500) {
    lastBeat = millis();
    beatState = !beatState;
    digitalWrite(LED_BUILTIN, beatState);
  }
}

void setup() {
  for (int i = 0; i < 7; i++) pinMode(segs[i], OUTPUT);

  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);

  pinMode(MODE_BTN, INPUT_PULLUP);
  pinMode(INC_BTN, INPUT_PULLUP);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  updateClock();
  readButtons();
  heartbeat();
  refreshDisplay();
}
