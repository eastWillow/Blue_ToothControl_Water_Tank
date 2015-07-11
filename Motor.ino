#define  PWMA  3
#define  REVA  2
#define  FORA  4
#define  PWMB  9
#define  REVB  8
#define  FORB  10
#define  RELAY  12

void initialMotor() {
  pinMode(RELAY, OUTPUT);
  pinMode(REVA, OUTPUT);
  pinMode(FORA, OUTPUT);
  pinMode(REVB, OUTPUT);
  pinMode(FORB, OUTPUT);
  digitalWrite(RELAY, LOW);
  digitalWrite(REVA, LOW);
  digitalWrite(FORA, LOW);
  digitalWrite(REVB, LOW);
  digitalWrite(FORB, LOW);
}
void leftMotor(unsigned int leftMotor, boolean FOR,boolean REV) {
  analogWrite(PWMA, leftMotor);
  digitalWrite(FORA, FOR);
  digitalWrite(REVA, REV);
}
void rightMotor(unsigned int rightMotor, boolean FOR,boolean REV) {
  analogWrite(PWMB, rightMotor);
  digitalWrite(FORB, FOR);
  digitalWrite(REVB, REV);
}

