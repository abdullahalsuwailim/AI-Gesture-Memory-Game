#include <Wire.h>

int red = 10, yellow = 9, green = 8, white = 7, orange = 6, blue = 5;
int leds[] = {red, yellow, green, white, orange, blue};
char cmds[] = {'R', 'Y', 'G', 'W', 'O', 'B'};

int level = 1;
char sequence[50];
int inputIndex = 0;
bool waitingForInput = false;
unsigned long lastInputTime = 0;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
  }

  randomSeed(analogRead(0));
  startGame();
}

void allOff() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(leds[i], LOW);
  }
}

int getPin(char cmd) {
  switch (cmd) {
    case 'R': return red;
    case 'Y': return yellow;
    case 'G': return green;
    case 'W': return white;
    case 'O': return orange;
    case 'B': return blue;
    default: return -1;
  }
}

void blinkLED(char cmd, int duration = 500) {
  int pin = getPin(cmd);
  if (pin == -1) return;

  digitalWrite(pin, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
  delay(200);
}

bool isValidColorCommand(char c) {
  return c == 'R' || c == 'Y' || c == 'G' ||
         c == 'W' || c == 'O' || c == 'B';
}

void startGame() {
  level = 1;
  delay(1000);
  nextLevel();
}

void nextLevel() {
  Serial.print("LEVEL: ");
  Serial.println(level);

  delay(1000);

  // كل مستوى يولد تسلسل جديد كامل عشوائي
  for (int i = 0; i < level; i++) {
    sequence[i] = cmds[random(6)];
  }

  for (int i = 0; i < level; i++) {
    blinkLED(sequence[i], 500);
  }

  inputIndex = 0;
  waitingForInput = true;
  lastInputTime = millis();

  Serial.println("TURN");
}

void gameOver() {
  Serial.println("GAME OVER");

  for (int i = 0; i < 3; i++) {
    allOff();
    delay(300);

    for (int j = 0; j < 6; j++) {
      digitalWrite(leds[j], HIGH);
    }
    delay(300);
  }

  allOff();
  delay(1000);
  startGame();
}

void loop() {
  if (waitingForInput && Serial.available()) {
    char input = Serial.read();

    if (!isValidColorCommand(input)) {
      return;
    }

    Serial.print("Received: ");
    Serial.println(input);

    if (input == sequence[inputIndex]) {
      blinkLED(input, 300);
      inputIndex++;
      lastInputTime = millis();

      if (inputIndex == level) {
        waitingForInput = false;
        delay(1500);
        level++;
        nextLevel();
      }
    } else {
      waitingForInput = false;
      gameOver();
    }
  }

  if (waitingForInput && millis() - lastInputTime > 20000) {
    waitingForInput = false;
    gameOver();
  }
}