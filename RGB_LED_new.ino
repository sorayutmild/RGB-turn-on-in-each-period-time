const unsigned long periodRed = 1000;
const unsigned long periodGreen = 5000;
const unsigned long periodBlue = 10000;
unsigned long previousTimeRed =0;
unsigned long previousTimeGreen =0;
unsigned long previousTimeBlue =0;
int redPin = 3;
int greenPin = 5;
int bluePin = 6;
int swR = 255,swG = 255, swB = 255; //switch of each color
int i = 1;
int swRed (int,int,int);
int swGreen (int,int,int);
int swBlue (int,int,int);
unsigned long currentTime = millis();
struct openLED
{
  int sw;
  unsigned long previousTime;
};



void setup(){  
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  analogWrite(greenPin,255);
  analogWrite(redPin,255);
  analogWrite(bluePin,255);
  Serial.begin(9600);

  }

  void loop(){
   
    while(i<=5){
   unsigned long currentTime = millis();
   struct openLED Red,Green,Blue;
   Red.sw = swRed(currentTime,previousTimeRed,periodRed,swR);
   Green.sw = swGreen(currentTime,previousTimeGreen,periodGreen,swG);
   Blue.sw = swBlue(currentTime,previousTimeBlue,periodBlue,swB);
   analogWrite(redPin,Red.sw); // for open LEDs
   analogWrite(greenPin,Green.sw);
   analogWrite(bluePin,Blue.sw);


  while(millis() < currentTime + 500){

    }  
   analogWrite(redPin,255); // for close LEDs
   analogWrite(greenPin,255);
   analogWrite(bluePin,255); 
    Red.sw= 255; 
    Green.sw= 255;
    Blue.sw= 255;
   Serial.println(i);
    }
  
 }


  
  int swRed(int currentTime, int PreviousTimeRed, int periodRed,int swR){
    if (currentTime -  PreviousTimeRed >= periodRed){
       PreviousTimeRed = currentTime;
      swR = 0;
      } 
    return swR;
  }
  
  int swGreen(int currentTime, int PreviousTimeGreen, int periodGreen,int swG){
    if (currentTime - PreviousTimeGreen >= periodGreen){
      PreviousTimeGreen = currentTime;
      swG = 153;
      } 
    return swG;
  }
  int swBlue(int currentTime, int PreviousTimeBlue, int periodBlue,int swB){
    if (currentTime -  PreviousTimeBlue >= periodBlue){
       PreviousTimeBlue = currentTime;
       swB = 153;
       i++;
      } 
    return swB;
  }
