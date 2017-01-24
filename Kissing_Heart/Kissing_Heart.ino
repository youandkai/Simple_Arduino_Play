
// Red and Blue LEDs
int blue_heart = 10;
int red_heart = 11;
int blue_bright = 0;
int red_bright = 100;
int fadeval_red = 5;
int fadeval_blue = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(blue_heart, OUTPUT);
  pinMode(red_heart, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(red_heart, red_bright);
  analogWrite(blue_heart, blue_bright);
  
  red_bright = red_bright + fadeval_red;
  blue_bright = blue_bright + fadeval_blue;
  
  // reverse the direction of the fading at the ends of the fade:
  if (red_bright <= 0 || red_bright >= 255) {
    fadeval_red = -fadeval_red;
  }
  if (blue_bright <= 0 || blue_bright >= 255) {
    fadeval_blue = -fadeval_blue;
  }
  delay(10);
}
