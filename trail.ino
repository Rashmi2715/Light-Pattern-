#define delay50 100

int myled[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int num_of_leds;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  num_of_leds = sizeof(myled) / sizeof(int);
  for (int i = 0; i < num_of_leds; i++) {
    pinMode(myled[i], OUTPUT);
  }
}
ino
void loop() {
  if (Serial.available() > 0) {
    int patternNum = Serial.parseInt(); // Read the pattern number from serial input
    displayPattern(patternNum); // Display the selected pattern
  }
}

void displayPattern(int patternNum) {
  switch (patternNum) {
    case 1:
      pattern1();
      break;
    case 2:
      pattern2();
      break;
    case 3:
      pattern3();
      break;
    case 4:
      pattern4();
      break;
    case 5:
      pattern5();
      break;
    case 6:
      pattern6();
      break;
    case 7:
      pattern7();
      break;
    case 8:
      pattern8();
      break;
    case 9:
      pattern9();
      break;
    case 10:
      pattern10();
      break;
    case 11:
      pattern11();
      break;
    case 12:
      pattern12();
      break;
    default:
      // Handle invalid input or display a default pattern
      break;
  }
}

void pattern1() {
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], HIGH);
    delay(delay50);
    digitalWrite(myled[i], LOW);
  }
}

void pattern2() {
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], HIGH);
    delay(delay50);
    digitalWrite(myled[i - 1], LOW);
  }
}

void pattern3() {
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], HIGH);
    delay(delay50);
  }
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], LOW);
    delay(delay50);
  }
}

void pattern4() {
  ledonn();
  delay(delay50);
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], LOW);
    delay(delay50);
  }
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], HIGH);
    delay(delay50);
  }
  ledoff();
}

void pattern5() {
  for (int i = 0; i < num_of_leds; i = i + 2) {
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[i + 1], LOW);
  }
  delay(delay50);
  for (int i = 0; i < num_of_leds; i = i + 2) {
    digitalWrite(myled[i], LOW);
    digitalWrite(myled[i + 1], HIGH);
  }
  delay(delay50);
}

void pattern6() {
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], HIGH);
    delay(delay50);
    digitalWrite(myled[i], LOW);
  }
  delay(delay50);
  for (int i = num_of_leds; i > 0; i--) {
    digitalWrite(myled[i - 1], HIGH);
    delay(delay50);
    digitalWrite(myled[i - 1], LOW);
  }
}

void pattern7() {
  for (int i = 0; i < num_of_leds / 2; i++) {
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[num_of_leds - 1 - i], HIGH);
    delay(delay50);
    digitalWrite(myled[i], LOW);
    digitalWrite(myled[num_of_leds - 1 - i], LOW);
  }
}

void pattern8() {
  for (int i = (num_of_leds / 2) - 1; i >= 0; i--) {
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[num_of_leds - 1 - i], HIGH);
    delay(delay50);
    digitalWrite(myled[i], LOW);
    digitalWrite(myled[num_of_leds - 1 - i], LOW);
  }
}

void pattern9() {
  for (int i = 0; i < num_of_leds + 3; i++) {
    if (i <= num_of_leds) {
      digitalWrite(myled[i], HIGH);
    }
    if (i > 2) {
      digitalWrite(myled[i - 3], LOW);
    }
    delay(delay50);
  }
}

void pattern10() {
  for (int i = 2; i < num_of_leds; i++) {
    if (i == 2) {
      digitalWrite(myled[0], HIGH);
      digitalWrite(myled[1], HIGH);
    }
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[i - 3], LOW);
    delay(delay50);
  }
  for (int i = num_of_leds - 4; i > -1; i--) {
    digitalWrite(myled[i], HIGH);
    digitalWrite(myled[i + 3], LOW);
    delay(delay50);
  }
}

void pattern11() {
  int randomnum = random(0, num_of_leds + 1);
  digitalWrite(myled[randomnum], HIGH);
  delay(delay50);
  digitalWrite(myled[randomnum], LOW);
  delay(delay50);
}

void pattern12() {
  int randomonn = random(0, num_of_leds + 1);
  int randomoff = random(0, num_of_leds + 1);
  digitalWrite(myled[randomonn], HIGH);
  digitalWrite(myled[randomoff], LOW);
  delay(delay50);
}

void ledonn() {
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], HIGH);
  }
}

void ledoff() {
  for (int i = 0; i < num_of_leds; i++) {
    digitalWrite(myled[i], LOW);
  }
}
