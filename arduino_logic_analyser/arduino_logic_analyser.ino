# define CLOCK 2

const char DATA[] = {22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52};

void setup() {
  
  // sets all of pins as input
  for(int i = 0; i < 16; i++) {
    pinMode(DATA[i], INPUT);
  }

  // defines a pin to function as the clock trigger
  pinMode(CLOCK, INPUT_PULLUP);

  // defines a interrupt
  attachInterrupt(digitalPinToInterrupt(CLOCK), onClock, RISING);
  
  Serial.begin(57600);
}

void onClock() {

  char output[15];
  unsigned int data = 0;
  
  // reads all of pins
  for(int i = 0; i < 16; i++) {
    
    int bit = digitalRead(DATA[i]) ? 1 : 0;
    
    Serial.print(bit);

    data = (data << 1) + bit;
  }

  sprintf(output, "  %04x", data);
  
  Serial.println(output);
}

void loop() {
}
