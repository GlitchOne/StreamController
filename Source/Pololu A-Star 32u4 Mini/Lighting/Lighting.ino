#include <Adafruit_NeoPixel.h>

const int row_1[4]={17,18,11,7};
const int row_2[4]={15,19,10,6};
const int row_3[4]={16,20,9,5};
const int row_4[4]={14,21,8,4};
const int full_button_list[16]={17,18,11,7,15,19,10,6,16,20,9,5,14,21,8,4};
const int output[4]={3,2,1,0};

int button1 = 0;
int button2 = 0;
int button4 = 0;
int button8 = 0;
int buttonLight = 0;
int buttonState = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(6, 13, NEO_GRB + NEO_KHZ800);

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void changeColor(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    delay(wait);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void live_lights()
{
  strip.setPixelColor(0, strip.Color(0, 100, 150));
  strip.setPixelColor(1, strip.Color(0, 100, 150));
  strip.setPixelColor(4, strip.Color(0, 100, 150));
  strip.setPixelColor(5, strip.Color(0, 100, 150));
  strip.show();
}

void outro_lights()
{
  colorWipe(strip.Color(255, 0, 0), 20);
  colorWipe(strip.Color(255, 255, 0), 20);
  colorWipe(strip.Color(255, 255, 255), 20);
  delay(200);
  changeColor(strip.Color(0, 0, 0));
}

void kill_lights()
{
  changeColor(strip.Color(150, 0, 0));
  live_lights();
  changeColor(strip.Color(150, 0, 0));
  live_lights();
}

void mic_on_lights()
{
  strip.setPixelColor(3, strip.Color(100, 0, 150));
  strip.show();
}

void mic_off_lights()
{
  strip.setPixelColor(3, strip.Color(200, 0, 0));
  strip.show();
}

void desktop_on_lights()
{
  strip.setPixelColor(2, strip.Color(100, 0, 150));
  strip.show();
}

void desktop_off_lights()
{
  strip.setPixelColor(2, strip.Color(200, 0, 0));
  strip.show();
}

void animate_lights(int pressed_button)
{
  switch (pressed_button)
  {
    case 0:
    {
      break;
    }
    case 1:
    {
      //Mic Audio On
      mic_on_lights();
      break;
    }
    case 2:
    {
      //Mic Audio Off
      mic_off_lights();
      break;
    }
    case 3:
    {
      //Replay Buffer On
      break;
    }
    case 4:
    {
      //Kill
      kill_lights();
      break;
    }
    case 5:
    {
      //Desktop Audio On
      desktop_on_lights();
      break;
    }
    case 6:
    {
      //Desktop Audio Off
      desktop_off_lights();
      break;
    }
    case 7:
    {
      //Save Replay Buffer
      break;
    }
    case 8:
    {
      //Win
      rainbow(5);
      live_lights();
      break;
    }
    case 9:
    {
      //Stream Live
      live_lights();
      break;
    }
    case 10:
    {
      //Stream Intro
      changeColor(strip.Color(0, 150, 0));
      break;
    }
    case 11:
    {
      //Stream Pause
      changeColor(strip.Color(100, 0, 150));
      break;
    }
    case 12:
    {
      //Stream Outro
      outro_lights();
      break;
    }
    case 13:
    {
      //Misc 1
      break;
    }
    case 14:
    {
      //Misc 2
      break;
    }
    case 15:
    {
      //Misc 3
      rainbow(100);
      changeColor(strip.Color(0, 0, 0));
      break;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  for (int i=0;i<16;i++)
  {
    pinMode(full_button_list[i],OUTPUT);
  }
  for (int i=0;i<=3;i++)
  {
    pinMode(output[i],INPUT);
  }

  strip.begin();
  changeColor(strip.Color(0, 0, 0));
  colorWipe(strip.Color(255, 0, 0), 20);
}

void loop() 
{
  button1 = digitalRead(3);
  button2 = digitalRead(1);
  button4 = digitalRead(2);
  button8 = digitalRead(0);

  if (button1 == 1) buttonLight = buttonLight+1;
  if (button2 == 1) buttonLight = buttonLight+2;
  if (button4 == 1) buttonLight = buttonLight+4;
  if (button8 == 1) buttonLight = buttonLight+8;

  digitalWrite(full_button_list[buttonLight-1],HIGH);

  if (buttonLight == 0)
  {
    for (int i=0;i<16;i++)
    {
      digitalWrite(full_button_list[i],LOW);
    }
  }

  if(buttonLight !=0)
    animate_lights(buttonLight);
  
  buttonLight = 0;
}

