/**
 * 7セグLEDを光らせる

 c      A      10
 2  F | | | B  9
 3      G      8
 4  E | | | C  D.P
 5      D      c
*/

/*
 * R(抵抗) = V(電圧) / I(電流)
 * 5V / 60mA = 83Ω 最小
 * 5V / 20mA = 250Ω 最大
 * 
 * アノード LA-401MD
 * https://www.rohm.co.jp/products/led-displays/led-numeric-displays/single-digit/la-401md-product
Common    1       10  a
      f   2       9   b
      g   3       8   c
      e   4       7   D.P
      d   5       6   Common

 * Common: GRDにつなぐ
 * a～f: 抵抗、DIGITAL OUTPUTにつなぐ、LOWのとき光る
 */

const int ASeg = 2;
const int BSeg = 3;
const int CSeg = 4;
const int DSeg = 5;
const int ESeg = 6;
const int FSeg = 7;
const int GSeg = 8;
const int AllSeg[] = {ASeg,BSeg,CSeg,DSeg,ESeg,FSeg,GSeg};

const int DLAY_mSEC = 1000 * 2;

void setup() {
  Serial.begin(9600); // シリアルモニタの設定
  pinMode(ASeg, OUTPUT);
  pinMode(BSeg, OUTPUT);
  pinMode(CSeg, OUTPUT);
  pinMode(DSeg, OUTPUT);
  pinMode(ESeg, OUTPUT);
  pinMode(FSeg, OUTPUT);
  pinMode(GSeg, OUTPUT);
}

void loop() {
  number(LOW, HIGH);
}

void demo(int ON, int OFF) {
  for(unsigned int i = 0; i < (sizeof(AllSeg)/sizeof(int)); i++){
    Serial.print(i);
    Serial.print(" -> ");
    Serial.print(AllSeg[i]);
    Serial.println();
    
    digitalWrite(ASeg, OFF);
    digitalWrite(BSeg, OFF);
    digitalWrite(CSeg, OFF);
    digitalWrite(DSeg, OFF);
    digitalWrite(ESeg, OFF);
    digitalWrite(FSeg, OFF);
    digitalWrite(GSeg, OFF);
    
    digitalWrite(AllSeg[i], ON);
    delay(DLAY_mSEC);
  }
}

void number(int ON, int OFF) {
  zero(ON, OFF);
  delay(DLAY_mSEC);
  one(ON, OFF);
  delay(DLAY_mSEC);
  two(ON, OFF);
  delay(DLAY_mSEC);
  three(ON, OFF);
  delay(DLAY_mSEC);
  four(ON, OFF);
  delay(DLAY_mSEC);
  five(ON, OFF);
  delay(DLAY_mSEC);
  six(ON, OFF);
  delay(DLAY_mSEC);
  seven(ON, OFF);
  delay(DLAY_mSEC);
  eight(ON, OFF);
  delay(DLAY_mSEC);
  nine(ON, OFF);
  delay(DLAY_mSEC);
}

void zero(int ON, int OFF) {
  Serial.println(0);
  digitalWrite(ASeg, ON);
  digitalWrite(BSeg, ON);
  digitalWrite(CSeg, ON);
  digitalWrite(DSeg, ON);
  digitalWrite(ESeg, ON);
  digitalWrite(FSeg, ON);
  digitalWrite(GSeg, OFF);
}
void one(int ON, int OFF) {
  Serial.println(1);
  digitalWrite(ASeg, OFF);
  digitalWrite(BSeg, ON);
  digitalWrite(CSeg, ON);
  digitalWrite(DSeg, OFF);
  digitalWrite(ESeg, OFF);
  digitalWrite(FSeg, OFF);
  digitalWrite(GSeg, OFF);
}
void two(int ON, int OFF) {
  Serial.println(2);
  digitalWrite(ASeg, ON);
  digitalWrite(BSeg, ON);
  digitalWrite(CSeg, OFF);
  digitalWrite(DSeg, ON);
  digitalWrite(ESeg, ON);
  digitalWrite(FSeg, OFF);
  digitalWrite(GSeg, ON);
}
void three(int ON, int OFF) {
  Serial.println(3);
  digitalWrite(ASeg, ON);
  digitalWrite(BSeg, ON);
  digitalWrite(CSeg, ON);
  digitalWrite(DSeg, ON);
  digitalWrite(ESeg, OFF);
  digitalWrite(FSeg, OFF);
  digitalWrite(GSeg, ON);
}
void four(int ON, int OFF) {
  Serial.println(4);
  digitalWrite(ASeg, OFF);
  digitalWrite(BSeg, ON);
  digitalWrite(CSeg, ON);
  digitalWrite(DSeg, OFF);
  digitalWrite(ESeg, OFF);
  digitalWrite(FSeg, ON);
  digitalWrite(GSeg, ON);
}
void five(int ON, int OFF) {
  Serial.println(5);
  digitalWrite(ASeg, ON);
  digitalWrite(BSeg, OFF);
  digitalWrite(CSeg, ON);
  digitalWrite(DSeg, ON);
  digitalWrite(ESeg, OFF);
  digitalWrite(FSeg, ON);
  digitalWrite(GSeg, ON);
}
void six(int ON, int OFF) {
  Serial.println(6);
  digitalWrite(ASeg, ON);
  digitalWrite(BSeg, OFF);
  digitalWrite(CSeg, ON);
  digitalWrite(DSeg, ON);
  digitalWrite(ESeg, ON);
  digitalWrite(FSeg, ON);
  digitalWrite(GSeg, ON);
}
void seven(int ON, int OFF) {
  Serial.println(7);
  digitalWrite(ASeg, ON);
  digitalWrite(BSeg, ON);
  digitalWrite(CSeg, ON);
  digitalWrite(DSeg, OFF);
  digitalWrite(ESeg, OFF);
  digitalWrite(FSeg, ON);
  digitalWrite(GSeg, OFF);
}
void eight(int ON, int OFF) {
  Serial.println(8);
  digitalWrite(ASeg, ON);
  digitalWrite(BSeg, ON);
  digitalWrite(CSeg, ON);
  digitalWrite(DSeg, ON);
  digitalWrite(ESeg, ON);
  digitalWrite(FSeg, ON);
  digitalWrite(GSeg, ON);
}
void nine(int ON, int OFF) {
  Serial.println(9);
  digitalWrite(ASeg, ON);
  digitalWrite(BSeg, ON);
  digitalWrite(CSeg, ON);
  digitalWrite(DSeg, ON);
  digitalWrite(ESeg, OFF);
  digitalWrite(FSeg, ON);
  digitalWrite(GSeg, ON);
}
