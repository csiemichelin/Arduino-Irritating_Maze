byte i = 6;//設定時間為60
byte j = 0;
boolean touch;//碰撞
boolean finish;//終點
boolean button = 0;//按鈕
const byte LEDs[10] = {
  B01111110,
  B00110000,
  B01101101,
  B01111001,
  B00110011,
  B01011011,
  B01011111,
  B01110000,
  B01111111,
  B01111011
};
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
}
void loop() {
  if (!button)//按下按鈕時
  {
    button = digitalRead(8);
    i = 6;
    j = 0;
  }
  if (button)//按鈕鬆開時
  {
    touch = digitalRead(10);
    finish = digitalRead(11);
    if (finish == 0)//是否碰到終點
    {
      for (int k = 0; k < 4; k++)
      {
        digitalWrite(3, LOW);
        shiftOut(2, 4, LSBFIRST, B00000000);
        digitalWrite(3, HIGH);
        digitalWrite(6, LOW);
        shiftOut(5, 7, LSBFIRST, B00000000);
        digitalWrite(6, HIGH);
        delay(500);
        digitalWrite(9, HIGH);
        digitalWrite(3, LOW);
        shiftOut(2, 4, LSBFIRST, LEDs[i]);
        digitalWrite(3, HIGH);
        digitalWrite(6, LOW);
        shiftOut(5, 7, LSBFIRST, LEDs[j]);
        digitalWrite(6, HIGH);
        delay(500);
        digitalWrite(9, LOW);
      }
      digitalWrite(3, LOW);
      shiftOut(2, 4, LSBFIRST, LEDs[i]);
      digitalWrite(3, HIGH);
      digitalWrite(6, LOW);
      shiftOut(5, 7, LSBFIRST, LEDs[j]);
      digitalWrite(6, HIGH);
      delay(2000);
      button = false;//碰到終點時 初始Button
    }
    if (touch == 0)//是否碰撞
    {
      digitalWrite(9, HIGH);
      delay(100);
      digitalWrite(9, LOW);
      if (i>0&&j<2)//碰到扣三秒
      {
        i--;
        j = j + 8;
      }
      else if(i==0&&j<=3)
      {
        i=0;j=0;
      }
      else
      {
        j = j - 2;
      }
      
    }    
    if (i == 0 && j == 0)//時間歸零時
    {
      for (int i = 0; i < 4; i++)
      {
        digitalWrite(3, LOW);
        shiftOut(2, 4, LSBFIRST, B00000000);
        digitalWrite(3, HIGH);
        digitalWrite(6, LOW);
        shiftOut(5, 7, LSBFIRST, B00000000);
        digitalWrite(6, HIGH);
        delay(500);
        digitalWrite(9, HIGH);
        digitalWrite(3, LOW);
        shiftOut(2, 4, LSBFIRST, LEDs[0]);
        digitalWrite(3, HIGH);
        digitalWrite(6, LOW);
        shiftOut(5, 7, LSBFIRST, LEDs[0]);
        digitalWrite(6, HIGH);
        delay(500);
        digitalWrite(9, LOW);
      }
      digitalWrite(3, LOW);
      shiftOut(2, 4, LSBFIRST, LEDs[0]);
      digitalWrite(3, HIGH);
      digitalWrite(6, LOW);
      shiftOut(5, 7, LSBFIRST, LEDs[0]);
      digitalWrite(6, HIGH);
      delay(2000);
      button = false;//時間歸零時 初始button
    }
    else
    {
      digitalWrite(3, LOW);
      shiftOut(2, 4, LSBFIRST, LEDs[i]);
      digitalWrite(3, HIGH);
      digitalWrite(6, LOW);
      shiftOut(5, 7, LSBFIRST, LEDs[j]);
      digitalWrite(6, HIGH);
      delay(1000);
      if (i != 0 && j == 0)//正常時間倒數
      {
        i--;
        j = j + 10;
      }
      j--;
    }
  }
}
