#include <EEPROM.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//アスキーコードプログラム
int asciicode[3] = { 0x30, 0xb1, 0x41 };
int eeprom = 1;
//行、列プログラム
int linw = 0;
int letter = 0;
int linwlinw = 0;
int letterletter = -1;
//スイッチプログラム
int nippon[9] = { 0 };
int switshState[9] = { 0 };
//音プログラム
int sound0[9] = { 750, 775, 825, 850, 875, 900, 925, 950 };
//決定ボタン改良プログラム
int countline = 0;
//ゲームプログラム//
//カウント
int road = 0;
int road2 = 0;
int explanation = 0;
//♡プログラム
int heart1 = 15;
int heart2 = 3;
//jumpプログラム
int jump = 0;
//障害物
int foe1 = 15;
int foe2 = 17;
int foe3 = 19;
int foe4 = 21;
int foe5 = 200;
// m
int count = 0;
int runrunrun = 1;
//
int GameCount = 1;
int countmode = 1;
int countms = 0;
int count2 = 4;
int countmovie = 0;
int highScore = 0;
int gameover = 0;
int gameclear = 0;
int gamechoose = 0;
int ONOFF = 0;
int Maintenance = 0;

//カスタム文字
byte crackedheart1[8] = {
  B00000,
  B00010,
  B00111,
  B00110,
  B00011,
  B00001,
  B00000,
  B00000
};

byte crackedheart2[8] = {
  B00000,
  B01000,
  B01100,
  B11100,
  B01000,
  B00000,
  B00000,
  B00000
};

byte stickman[8] = {
  B00100,
  B01010,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B10001
};

byte stickman2[8] = {
  B00000,
  B00100,
  B01010,
  B00100,
  B00111,
  B00100,
  B01011,
  B11001
};

byte stickman3[8] = {
  B00000,
  B00100,
  B01010,
  B00100,
  B11100,
  B00100,
  B01010,
  B01010
};

byte stickman4[8] = {
  B00000,
  B00010,
  B00101,
  B01010,
  B01000,
  B00100,
  B00010,
  B01110
};

byte flower[8] = {
  B00100,
  B01110,
  B00100,
  B01000,
  B01000,
  B00100,
  B00010,
  B00100
};

byte run[8] = {
  B00100,
  B01010,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B01001
};

byte runrun[8] = {
  B00100,
  B01010,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B10010
};

byte jumping[8] = {
  B00010,
  B00101,
  B00010,
  B00100,
  B01000,
  B00100,
  B11010,
  B00001
};

byte cactus[8] = {
  B00100,
  B00101,
  B10101,
  B10111,
  B11100,
  B00100,
  B00100,
  B00100
};

byte bone[8] = {
  B00000,
  B01110,
  B11111,
  B10101,
  B11011,
  B01110,
  B01110,
  B00000
};

byte chance[8] = {
  B00000,
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};

byte purasuchance[8] = {
  B01000,
  B11100,
  B01000,
  B00000,
  B01010,
  B11111,
  B01110,
  B00100
};

byte sound[8] = {
  B00110,
  B00111,
  B00101,
  B00101,
  B00100,
  B11100,
  B11100,
  B11100
};

byte ghost[8] = {
  B01110,
  B11111,
  B10101,
  B11111,
  B11010,
  B11110,
  B11100,
  B10000
};

byte pixel0[8] = {
  B00000,
  B00000,
  B00000,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000
};

byte pixel1[8] = {
  B00000,
  B00000,
  B00000,
  B01010,
  B00000,
  B11111,
  B01110,
  B00000
};

byte pixel2[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000
};

byte pixel3[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte pixel4[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte pixel5[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte pixel6[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte pixel7[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte pixel8[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

//
void blinkLed() {
  clean();
  lcd.setCursor(0, 0);
  lcd.print("GameMode");
  delay(2500);
  lcd.setCursor(0, 0);
  lcd.print("                ");
  switshState[5] = digitalRead(13);
  if (explanation == 0) {
    lcd.setCursor(0, 0);
    lcd.print("How to play this");
    lcd.setCursor(0, 1);
    lcd.print("game.");
    delay(3000);
    clean();
    lcd.setCursor(0, 0);
    lcd.print("If you advance ");
    lcd.setCursor(0, 1);
    lcd.print("to 99999m,");
    delay(3000);
    clean();
    lcd.setCursor(0, 0);
    lcd.print("the game is ");
    lcd.setCursor(0, 1);
    lcd.print("clear.");
    delay(3000);
    clean();
    lcd.setCursor(0, 0);
    lcd.print("The maximum");
    lcd.setCursor(0, 1);
    lcd.print("number of heart ");
    delay(3000);
    clean();
    lcd.setCursor(0, 0);
    lcd.print("is 3.");
    delay(2000);
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("Please enjoy");
    lcd.setCursor(0, 1);
    lcd.print("this game!");
    delay(3000);
    clean();
    explanation++;
  }
  clean();
  heart1 = 15;
  heart2 = 3;
  count = 0;
  foe1 = 15;
  foe2 = 17;
  foe3 = 19;
  foe4 = 21;
  lcd.createChar(0, stickman);
  lcd.createChar(1, run);
  lcd.createChar(2, runrun);
  lcd.createChar(3, jumping);
  lcd.createChar(4, cactus);
  lcd.createChar(5, bone);
  lcd.createChar(6, chance);
  lcd.createChar(7, purasuchance);
  lcd.setCursor(13, 0);
  //heart
  lcd.write(byte(6));
  lcd.setCursor(14, 0);
  //heart
  lcd.write(byte(6));
  lcd.setCursor(15, 0);
  //heart
  lcd.write(byte(6));
  //障害物
  lcd.setCursor(foe1, 1);
  //cactus
  lcd.write(byte(4));
  lcd.setCursor(foe2, 1);
  //cactus
  lcd.write(byte(4));
  lcd.setCursor(foe3, 1);
  //cactus
  lcd.write(byte(4));
  lcd.setCursor(0, 1);
  //stickman
  lcd.write(byte(0));
  lcd.setCursor(0, 0);
  lcd.print("Ready");
  //5s
  delay(5000);
  lcd.setCursor(7, 0);
  lcd.print("Go!!");
  //1.5s
  delay(1500);
  lcd.setCursor(0, 0);
  lcd.print("           ");
  lcd.setCursor(9, 0);
  lcd.print("m");
  lcd.setCursor(2, 0);
  lcd.print(count);
  lcd.setCursor(0, 1);
  //run
  lcd.write(byte(1));
  switshState[5] = digitalRead(13);
  nippon[5] = switshState[5];
  jump = 0;
}

void gameA() {
  //
  if ((jump >= 1) && (jump <= 5)) {
    jump--;
  }
  //
  if (jump == 0) {
    if (runrunrun == 2) {
      lcd.setCursor(0, 0);
      lcd.print(" ");
      lcd.setCursor(0, 1);
      lcd.write(byte(1));
      runrunrun--;
    } else {
      lcd.setCursor(0, 0);
      lcd.print(" ");
      lcd.setCursor(0, 1);
      lcd.write(byte(2));
      runrunrun = 2;
    }
  }
  lcd.setCursor(foe1, 1);
  lcd.print(" ");
  foe1--;
  lcd.setCursor(foe1, 1);
  lcd.write(byte(4));
  lcd.setCursor(foe2, 1);
  lcd.print(" ");
  foe2--;
  lcd.setCursor(foe2, 1);
  lcd.write(byte(4));
  lcd.setCursor(foe3, 1);
  lcd.print(" ");
  foe3--;
  lcd.setCursor(foe3, 1);
  lcd.write(byte(4));
  if ((foe1 != foe4) && (foe2 != foe4) && (foe3 != foe4)) {
    lcd.setCursor(foe4, 1);
    lcd.print(" ");
    foe4--;
    lcd.setCursor(foe4, 1);
    lcd.write(byte(7));
  }
  // m
  count++;
  lcd.setCursor(2, 0);
  lcd.print(count);
  Serial.print("jump:");
  Serial.print(jump);
  Serial.print(" 敵1号:");
  Serial.print(foe1);
  Serial.print(" 敵2号:");
  Serial.print(foe2);
  Serial.print(" 敵3号:");
  Serial.print(foe3);
  Serial.print(" 回復:");
  Serial.print(foe4);
  Serial.print(" 残基:");
  Serial.println(heart2);
  //当たり判定プログラム
  if (jump == 0) {
    if ((foe1 == 0) || (foe2 == 0) || (foe3 == 0)) {
      if (heart2 <= 3) {
        lcd.setCursor(heart1, 0);
        lcd.print(" ");
        tone(A0, foe5, 2000);
        delay(2000);
        heart1--;
        heart2--;
      }
    }
  }
  if (jump == 0) {
    if (foe4 == 0) {
      if (heart2 == 3) {
        //何もしない
      } else if (heart2 == 2) {
        lcd.setCursor(15, 0);
        lcd.write(byte(6));
        heart1++;
        heart2++;
      } else {
        lcd.setCursor(14, 0);
        lcd.write(byte(6));
        heart1++;
        heart2++;
      }
    }
  }
  //loop
  if (foe1 == 0) {
    foe1 = random(20, 30);
  }
  if (foe2 == 0) {
    foe2 = random(20, 30);
  }
  if (foe3 == 0) {
    foe3 = random(20, 30);
  }
  if (foe4 == 0) {
    foe4 = random(16, 19);
  }
}

void gameloop() {
  if (road == 0) {
    road++;
    blinkLed();
  }
  gameA();
  delay(250);
  //
  switshState[5] = digitalRead(13);
  if (jump == 0) {
    if (switshState[5] == LOW) {
      if (nippon[5] != switshState[5]) {
        lcd.setCursor(0, 0);
        //jump
        lcd.write(byte(3));
        lcd.setCursor(0, 1);
        lcd.print(" ");
        //1s
        jump = 5;
      }
    }
  }
  //
  nippon[2] = switshState[2];
  nippon[5] = switshState[5];
  if ((count == 99999) || (heart2 == 0)) {
    if (gamechoose == 0) {
      gamechoose++;
      gamechooseloop();
      return;
    }
    return;
  }
}

void gamechooseloop() {
  if (heart2 == 0) {
    if (gameover == 0) {
      gameover++;
      gameoverloop();
      return;
    }
    return;
  }
  //
  if (count == 99999) {
    if (gameclear == 0) {
      gameclear++;
      gameclearloop();
      return;
    }
    return;
  }
}

void gameoverloop() {
  clean();
  EEPROM.get(0, highScore);
  if (count > highScore) {
    highScore = count;
    EEPROM.put(0, highScore);
  }
  lcd.setCursor(0, 0);
  lcd.print("HI:      m");
  lcd.setCursor(3, 0);
  lcd.print(highScore);
  delay(2500);
  clean();
  tone(A0, 440, 6000);
  lcd.setCursor(0, 0);
  lcd.print("-GAME OVER-");
  lcd.setCursor(11, 0);
  lcd.write(byte(5));
  lcd.setCursor(12, 0);
  lcd.write(byte(5));
  lcd.setCursor(13, 0);
  lcd.write(byte(5));
  lcd.setCursor(14, 0);
  lcd.write(byte(5));
  lcd.setCursor(15, 0);
  lcd.write(byte(5));
  lcd.setCursor(0, 1);
  lcd.print("You're dead.");
  road--;
  delay(6000);
  clean();
  GameCount--;
  return;
}

void gameclearloop() {
  if ((foe1 >= 0 && foe1 <= 15) || (foe2 >= 0 && foe2 <= 15) || (foe3 >= 0 && foe3 <= 15) || (foe4 >= 0 && foe4 <= 15)) {
    count2 = 0;
  }
  while (count2 == 4) {
    delay(125);
    if (jump == 0) {
      if (runrunrun == 2) {
        lcd.setCursor(0, 0);
        lcd.print(" ");
        lcd.setCursor(0, 1);
        lcd.write(byte(1));
        runrunrun--;
      } else {
        lcd.setCursor(0, 0);
        lcd.print(" ");
        lcd.setCursor(0, 1);
        lcd.write(byte(2));
        runrunrun = 2;
      }
    }
    if (foe1 != -1) {
      lcd.setCursor(foe1, 1);
      lcd.print(" ");
      foe1--;
      lcd.setCursor(foe1, 1);
      //cactus
      lcd.write(byte(4));
    }
    if (foe2 != -1) {
      lcd.setCursor(foe2, 1);
      lcd.print(" ");
      foe2--;
      lcd.setCursor(foe2, 1);
      //cactus
      lcd.write(byte(4));
    }
    if (foe3 != -1) {
      lcd.setCursor(foe3, 1);
      lcd.print(" ");
      foe3--;
      lcd.setCursor(foe3, 1);
      //cactus
      lcd.write(byte(4));
    }
    if (foe4 != -1) {
      lcd.setCursor(foe4, 1);
      lcd.print(" ");
      foe4--;
      lcd.setCursor(foe4, 1);
      //
      lcd.write(byte(7));
    }
    if (foe1 == -1) {
      count2++;
    }
    if (foe2 == -1) {
      count2++;
    }
    if (foe3 == -1) {
      count2++;
    }
    if (foe4 == -1) {
      count2++;
    }
    if ((foe1 >= 0 && foe1 <= 1) || (foe2 >= 0 && foe2 <= 1) || (foe3 >= 0 && foe3 <= 1)) {
      lcd.setCursor(0, 1);
      lcd.print(" ");
      lcd.setCursor(0, 0);
      lcd.write(byte(3));
      jump = 1;
    } else {
      jump = 0;
    }
  }
  lcd.createChar(0, flower);
  lcd.createChar(1, crackedheart1);
  lcd.createChar(2, crackedheart2);
  lcd.createChar(3, stickman2);
  lcd.createChar(4, stickman3);
  lcd.createChar(5, stickman4);
  lcd.setCursor(1, 1);
  lcd.write(byte(0));
  delay(1500);
  lcd.setCursor(2, 1);
  lcd.write(byte(0));
  lcd.setCursor(1, 1);
  lcd.write(byte(1));
  lcd.setCursor(0, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(3, 1);
  lcd.write(byte(0));
  lcd.setCursor(2, 1);
  lcd.write(byte(2));
  lcd.setCursor(1, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(4, 1);
  lcd.write(byte(0));
  lcd.setCursor(3, 1);
  lcd.write(byte(1));
  lcd.setCursor(2, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(5, 1);
  lcd.write(byte(0));
  lcd.setCursor(4, 1);
  lcd.write(byte(2));
  lcd.setCursor(3, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(6, 1);
  lcd.write(byte(0));
  lcd.setCursor(5, 1);
  lcd.write(byte(1));
  lcd.setCursor(4, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(7, 1);
  lcd.write(byte(0));
  lcd.setCursor(6, 1);
  lcd.write(byte(2));
  lcd.setCursor(5, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(8, 1);
  lcd.write(byte(0));
  lcd.setCursor(7, 1);
  lcd.write(byte(1));
  lcd.setCursor(6, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(9, 1);
  lcd.write(byte(0));
  lcd.setCursor(8, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(10, 1);
  lcd.write(byte(0));
  lcd.setCursor(9, 1);
  lcd.write(byte(1));
  lcd.setCursor(8, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(11, 1);
  lcd.write(byte(0));
  lcd.setCursor(10, 1);
  lcd.write(byte(2));
  lcd.setCursor(9, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(12, 1);
  lcd.write(byte(0));
  lcd.setCursor(11, 1);
  lcd.write(byte(1));
  lcd.setCursor(10, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(13, 1);
  lcd.write(byte(0));
  lcd.setCursor(12, 1);
  lcd.write(byte(2));
  lcd.setCursor(11, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(14, 1);
  lcd.write(byte(0));
  lcd.setCursor(13, 1);
  lcd.write(byte(1));
  lcd.setCursor(12, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(15, 1);
  lcd.write(byte(0));
  lcd.setCursor(14, 1);
  lcd.write(byte(2));
  lcd.setCursor(13, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(15, 1);
  lcd.write(byte(1));
  lcd.setCursor(14, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(15, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.write(byte(1));
  lcd.setCursor(1, 1);
  lcd.write(byte(0));
  lcd.setCursor(12, 1);
  lcd.write(byte(3));
  lcd.setCursor(14, 1);
  lcd.write(byte(4));
  delay(1500);
  lcd.setCursor(13, 1);
  lcd.write(byte(0));
  delay(1500);
  lcd.setCursor(14, 0);
  lcd.write(byte(6));
  delay(1500);
  lcd.setCursor(0, 1);
  lcd.write(byte(5));
  lcd.setCursor(1, 1);
  lcd.print(" ");
  delay(1500);
  lcd.setCursor(0, 0);
  lcd.write(byte(6));
  delay(1500);
  lcd.setCursor(0, 0);
  lcd.write(byte(1));
  lcd.setCursor(1, 0);
  lcd.write(byte(2));
  delay(1500);
  clean();
  tone(A0, 432, 6000);
  lcd.setCursor(0, 0);
  lcd.print("-GAME CLEAR-");
  lcd.setCursor(0, 1);
  lcd.print("You're so Good!!");
  lcd.setCursor(15, 1);
  //heart
  lcd.write(byte(6));
  road--;
  delay(6000);
  clean();
  GameCount--;
  return;
}

void timemode() {
  //途中
}

void clean() {
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  return;
}

void TamTam() {
  //
}

void pirorin() {
  //
  tone(A0, 784, 80);
  delay(100);
  tone(A0, 988, 80);
  delay(100);
  tone(A0, 1319, 150);
  delay(150);
  return;
}

void hello_world() {
  delay(500);
  digitalWrite(22, LOW);
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.print("Hello World!");
  pirorin();
  delay(2500);
  lcd.setCursor(0, 0);
  lcd.print("                ");
  return;
}

void gamelooploop() {
  //
  while (GameCount == 1) {
    gameloop();
  }
  GameCount++;
}

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
  lcd.createChar(0, stickman);
  lcd.createChar(1, run);
  lcd.createChar(2, runrun);
  lcd.createChar(3, jumping);
  lcd.createChar(4, cactus);
  lcd.createChar(5, bone);
  lcd.createChar(6, chance);
  lcd.createChar(7, purasuchance);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(13, INPUT_PULLUP);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, INPUT);
  pinMode(25, INPUT);
  EEPROM.get(0, highScore);
  if (highScore < 0 || highScore > 100000) {
    highScore = 0;
  }

  EEPROM.get(1, ONOFF);
}

void loop() {
  digitalWrite(22, HIGH);
  if (road2 == 0) {
    road2++;
    hello_world();
    return;
  }
  GameCount = 1;
  //バックドア
  //gameclearloop();
  //ゲーム機能プログラム
  switshState[5] = digitalRead(13);
  if (switshState[5] == LOW) {
    if (nippon[5] != switshState[5]) {
      gamelooploop();
    }
  }
  //time
  switshState[6] = digitalRead(24);
  if (switshState[6] == LOW) {
    if (nippon[6] != switshState[6]) {
      //
      if (ONOFF == 0) {
        EEPROM.put(1, 1);
        ONOFF = 1;
      } else {
        EEPROM.put(1, 0);
        ONOFF = 0;
      }
    }
  }
  if (ONOFF == 1) {
    digitalWrite(23, HIGH);
  } else {
    digitalWrite(23, LOW);
  }
  //moviemode
  switshState[8] = digitalRead(25);
  if (switshState[8] == LOW) {
    if (nippon[8] != switshState[8]) {
      TamTam();
      return;
    }
  }
  //数字プログラム
  switshState[0] = digitalRead(6);
  if (switshState[0] == LOW) {
    if (nippon[0] != switshState[0]) {
      lcd.setCursor(letter, linw);
      lcd.write(asciicode[0]);
      asciicode[0]++;
      asciicode[1] = 0xb1;
      asciicode[2] = 0x41;
      tone(A0, sound[0], 20);
      countline = 0;
    }
  }
  // Enter
  switshState[1] = digitalRead(7);
  if (switshState[1] == LOW) {
    if (nippon[1] != switshState[1]) {
      asciicode[0] = 0x30;
      asciicode[1] = 0xb1;
      asciicode[2] = 0x41;
      letter++;
      letterletter++;
      lcd.setCursor(letter, linw);
      lcd.write(0x5f);
      if (countline == 1) {
        lcd.setCursor(letterletter, linwlinw);
        lcd.print(" ");
      }
      tone(A0, sound[1], 20);
      countline = 1;
    }
  }
  //リセットプログラム
  switshState[2] = digitalRead(8);
  if (switshState[2] == LOW) {
    if (nippon[2] != switshState[2]) {
      clean();
      asciicode[0] = 0x30;
      asciicode[1] = 0xb1;
      asciicode[2] = 0x41;
      linw = 0;
      letter = 0;
      letterletter = 0;
      countline = 0;
      tone(A0, sound[2], 20);
    }
  }
  //カタカナプログラム
  switshState[3] = digitalRead(9);
  if (switshState[3] == LOW) {
    if (nippon[3] != switshState[3]) {
      lcd.setCursor(letter, linw);
      lcd.write(asciicode[1]);
      asciicode[0] = 0x30;
      asciicode[1]++;
      asciicode[2] = 0x41;
      tone(A0, sound[3], 20);
      countline = 0;
    }
  }
  //アルファベットプログラム
  switshState[4] = digitalRead(10);
  if (switshState[4] == LOW) {
    if (nippon[4] != switshState[4]) {
      lcd.setCursor(letter, linw);
      lcd.write(asciicode[2]);
      asciicode[0] = 0x30;
      asciicode[1] = 0xb1;
      asciicode[2]++;
      tone(A0, sound[4], 20);
      countline = 0;
    }
  }
  //ループプログラム
  if (linw == 1) {
    if (letter == 16) {
      linw = 0;
      letter = 0;
    }
  }
  if (linwlinw == 1) {
    if (letterletter == 16) {
      linwlinw = 0;
      letterletter = -1;
    }
  }
  if (asciicode[0] == 0x40) {
    asciicode[0] = 0x21;
  }
  if (asciicode[1] == 0xdf) {
    asciicode[1] = 0xa1;
  }
  if (asciicode[2] == 0x7e) {
    asciicode[2] = 0x41;
  }
  //下へ行くプログラム
  if (letter == 16) {
    linw++;
    letter = 0;
  }
  if (letterletter == 16) {
    linwlinw++;
    letterletter = -1;
  }
  //同期プログラム
  for (int i = 0; i <= 8; i++) {
    nippon[i] = switshState[i];
  }
}
