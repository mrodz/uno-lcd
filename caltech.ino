#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte custom_square[8] = {
  0b00000,
  0b01110,
  0b01110,
  0b01110,
  0b01110,
  0b01110,
  0b01110,
  0b00000
};

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.createChar(7, custom_square);
  slide_in_text();
}

void slide_in_text() {
  for (int index = 0; index < 5; index++) {
    lcd.setCursor(0, 0);
    for (int i = 0; i < index; i++) {
      lcd.print(" ");
    }
    lcd.print("Caltech STEM");
    for (int i = 0; i < 4 - index; i++) {
      lcd.print(" ");
    }
    lcd.setCursor(0, 1);
    for (int i = 0; i < index; i++) {
      lcd.print(" ");
    }
    lcd.print("Portfolio <3");
    for (int i = 0; i < 4 - index; i++) {
      lcd.print(" ");
    }
    delay(200);
  }
}

int index = 0;

void loop() {
  lcd.setCursor(0, 0);
  if (index) {
    lcd.print(" ");
  }
  lcd.print((char) 7);
  lcd.print(" ");
  lcd.setCursor(0, 1);
  if (!index) {
    lcd.print(" ");
  }
  lcd.print((char) 7);
  lcd.print(" ");
  index = !index;
  delay(200);
}
