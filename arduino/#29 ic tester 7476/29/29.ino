int pinJ = 7;
int pinK = 6;
int clk = 5;
int out = 14;
int _7476count = 0;
int x = 0;
int Logic_gate[4] = {0, 0, 1, 0}; //7476
int Read_gate [4];
void setup()
{
  pinMode(out, INPUT);
  pinMode(pinJ, OUTPUT);
  pinMode(pinK, OUTPUT);
  pinMode(clk, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  while (x < 4) {
    digitalWrite(pinJ, LOW);
    digitalWrite(pinK, LOW);
    digitalWrite(clk, HIGH);
    digitalWrite(clk, LOW);
    Read_gate[x] = digitalRead(out);
    delay(250);
    Read_gate[x] = digitalRead(out);
    if (Read_gate[x] == Logic_gate[x]) {
      _7476count++;
    }
    x = x + 1;

    digitalWrite(pinJ, LOW);
    digitalWrite(pinK, HIGH);
    digitalWrite(clk, HIGH);
    digitalWrite(clk, LOW);
    Read_gate[x] = digitalRead(out);
    Read_gate[x] = digitalRead(out);
    delay(250);
    Read_gate[x] = digitalRead(out);
    if (Read_gate[x] == Logic_gate[x]) {
      _7476count++;
    }
    x = x + 1;

    digitalWrite(pinJ, HIGH);
    digitalWrite(pinK, LOW);
    digitalWrite(clk, HIGH);
    digitalWrite(clk, LOW);
    Read_gate[x] = digitalRead(out);
    delay(250);
    Read_gate[x] = digitalRead(out);
    if (Read_gate[x] == Logic_gate[x]) {
      _7476count++;
    }
    x = x + 1;

    digitalWrite(pinJ, HIGH);
    digitalWrite(pinK, HIGH);
    digitalWrite(clk, HIGH);
    digitalWrite(clk, LOW);
    Read_gate[x] = digitalRead(out);
    Read_gate[x] = digitalRead(out);
    delay(250);
    Read_gate[x] = digitalRead(out);
    if (Read_gate[x] == Logic_gate[x]) {
      _7476count++;
    }
    x = x + 1;

    if (_7476count == 4) {
      Serial.print("\n7476 IC is good.\n");
      break;
    }
    else {
      Serial.print("\nNothing connect or IC is another one.\n");
      break;
    }
  }

}
