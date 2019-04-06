#define KEY_LEFT_CTRL  0x80
#define KEY_LEFT_SHIFT 0x81
#define KEY_LEFT_ALT   0x82
#define KEY_LEFT_GUI   0x83
#define KEY_RIGHT_CTRL 0x84
#define KEY_RIGHT_SHIFT    0x85
#define KEY_RIGHT_ALT  0x86
#define KEY_RIGHT_GUI  0x87

#define KEY_UP_ARROW   0xDA
#define KEY_DOWN_ARROW 0xD9
#define KEY_LEFT_ARROW 0xD8
#define KEY_RIGHT_ARROW    0xD7
#define KEY_BACKSPACE  0xB2
#define KEY_TAB        0xB3
#define KEY_RETURN 0xB0
#define KEY_ESC        0xB1
#define KEY_INSERT 0xD1
#define KEY_DELETE 0xD4
#define KEY_PAGE_UP    0xD3
#define KEY_PAGE_DOWN  0xD6
#define KEY_HOME   0xD2
#define KEY_END        0xD5
#define KEY_CAPS_LOCK  0xC1
#define KEY_F1     0xC2
#define KEY_F2     0xC3
#define KEY_F3     0xC4
#define KEY_F4     0xC5
#define KEY_F5     0xC6
#define KEY_F6     0xC7
#define KEY_F7     0xC8
#define KEY_F8     0xC9
#define KEY_F9     0xCA
#define KEY_F10        0xCB
#define KEY_F11        0xCC
#define KEY_F12        0xCD

#include "Keyboard.h"

// constants won't change. They're used here to set pin numbers:
const int row_1[4]={11,7,3,12};
const int row_2[4]={10,6,2,13};
const int row_3[4]={9,5,1,19};
const int row_4[4]={8,4,0,18};
const int output[4]={14,15,16,17};

// variables will change:
int buttonState = 0;         //variable for reading the pushbutton status
int buttonPressed = 0;       //variable for reading the pushbutton number

void LED_Enable (int row, int column) 
{
  //Sends a Bit-level style message to the lighting controller
  //through setting certain pins to high or low
  /*
  Serial.print("[");
  Serial.print(row);
  Serial.print(",");
  Serial.print(column);
  Serial.println("]");
  */
  if(row == 1)
  {
    switch(column){
      case 1:
      {
        digitalWrite(14, HIGH);
        digitalWrite(15, LOW);
        digitalWrite(16, LOW);
        digitalWrite(17, LOW);
        break;
      }
      case 2:
      {
        digitalWrite(14, LOW);
        digitalWrite(15, HIGH);
        digitalWrite(16, LOW);
        digitalWrite(17, LOW);
        break;
      }
      case 3:
      {
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, LOW);
        digitalWrite(17, LOW);
        break;
      }
      case 4:
      {
        digitalWrite(14, LOW);
        digitalWrite(15, LOW);
        digitalWrite(16, HIGH);
        digitalWrite(17, LOW);
        break;
      }
    }
  }
  else if(row == 2)
  {
    switch (column){
      case 1:
      {
        digitalWrite(14, HIGH);
        digitalWrite(15, LOW);
        digitalWrite(16, HIGH);
        digitalWrite(17, LOW);
        break;
      }
      case 2:
      {
        digitalWrite(14, LOW);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, LOW);
        break;
      }
      case 3:
      {
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, LOW);
        break;
      }
      case 4:
      {
        digitalWrite(14, LOW);
        digitalWrite(15, LOW);
        digitalWrite(16, LOW);
        digitalWrite(17, HIGH);
        break;
      }
    }
  }
  else if(row == 3){
    switch (column)
    {
      case 1:
      {
        digitalWrite(14, HIGH);
        digitalWrite(15, LOW);
        digitalWrite(16, LOW);
        digitalWrite(17, HIGH);
        break;
      }
      case 2:
      {
        digitalWrite(14, LOW);
        digitalWrite(15, HIGH);
        digitalWrite(16, LOW);
        digitalWrite(17, HIGH);
        break;
      }
      case 3:
      {
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, LOW);
        digitalWrite(17, HIGH);
        break;
      }
      case 4:
      {
        digitalWrite(14, LOW);
        digitalWrite(15, LOW);
        digitalWrite(16, HIGH);
        digitalWrite(17, HIGH);
        break;
      }
    }
  }
  else if(row == 4){
    switch (column)
    {
      case 1:
      {
        digitalWrite(14, HIGH);
        digitalWrite(15, LOW);
        digitalWrite(16, HIGH);
        digitalWrite(17, HIGH);
        break;
      }
      case 2:
      {
        digitalWrite(14, LOW);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, HIGH);
        break;
      }
      case 3:
      {
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, HIGH);
        break;
      }
      case 4:
      {
        digitalWrite(14, LOW);
        digitalWrite(15, LOW);
        digitalWrite(16, LOW);
        digitalWrite(17, LOW);
        break;
      }
    }
  }
}

void send_command(int pressed_button)
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
      Keyboard.press(KEY_LEFT_CTRL);
      delay(100);
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(100);
      Keyboard.press('-');
      delay(100);
      Keyboard.releaseAll();
      break;
    }
    case 2:
    {
      //Mic Audio Off
      Keyboard.press(KEY_LEFT_CTRL);
      delay(100);
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(100);
      Keyboard.press('=');
      delay(100);
      Keyboard.releaseAll();
      break;
    }
    case 3:
    {
      //Replay Buffer On
      Keyboard.press(KEY_LEFT_CTRL);
      delay(100);
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(100);
      Keyboard.press('\\');
      delay(100);
      Keyboard.releaseAll();
      break;
    }
    case 4:
    {
      //Kill
      break;
    }
    case 5:
    {
      //Desktop Audio On
      Keyboard.press(KEY_LEFT_CTRL);
      delay(100);
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(100);
      Keyboard.press('8');
      delay(100);
      Keyboard.releaseAll();
      break;
    }
    case 6:
    {
      //Desktop Audio Off
      Keyboard.press(KEY_LEFT_CTRL);
      delay(100);
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(100);
      Keyboard.press('9');
      delay(100);
      Keyboard.releaseAll();
      break;
    }
    case 7:
    {
      //Save Replay Buffer
      Keyboard.press(KEY_LEFT_CTRL);
      delay(100);
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(100);
      Keyboard.press('/');
      delay(100);
      Keyboard.releaseAll();
      break;
    }
    case 8:
    {
      //Win
      break;
    }
    case 9:
    {
      //Stream Live
      Keyboard.press(KEY_LEFT_CTRL);
      delay(100);
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(100);
      Keyboard.press('1');
      delay(100);
      Keyboard.releaseAll();
      break;
    }
    case 10:
    {
      //Stream Intro
      Keyboard.press(KEY_LEFT_CTRL);
      delay(100);
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(100);
      Keyboard.press('2');
      delay(100);
      Keyboard.releaseAll();
      break;
    }
    case 11:
    {
      //Stream Pause
      Keyboard.press(KEY_LEFT_CTRL);
      delay(100);
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(100);
      Keyboard.press('3');
      delay(100);
      Keyboard.releaseAll();
      break;
    }
    case 12:
    {
      //Stream Outro
      Keyboard.press(KEY_LEFT_CTRL);
      delay(100);
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(100);
      Keyboard.press('4');
      delay(100);
      Keyboard.releaseAll();
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
      break;
    }
  }
}

void setup() {
  for (int i=0;i<=3;i++)
  {
    pinMode(row_1[i],INPUT);
  }
  for (int i=0;i<=3;i++)
  {
    pinMode(row_2[i],INPUT);
  }
  for (int i=0;i<=3;i++)
  {
    pinMode(row_3[i],INPUT);
  }
  for (int i=0;i<=3;i++)
  {
    pinMode(row_4[i],INPUT);
  }
  for (int i=0;i<=3;i++)
  {
    pinMode(output[i],OUTPUT);
  }
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, LOW);
  Keyboard.begin();
}

void loop() {
  buttonPressed = 0;
  for (int i=0;i<=3;i++)
  {
    buttonState=digitalRead(row_1[i]);
    if(buttonState == HIGH)
    {
      buttonPressed = 1+i;
      LED_Enable(1,i+1);
    }
  }
  for (int i=0;i<=3;i++)
  {
    buttonState=digitalRead(row_2[i]);
    if(buttonState == HIGH)
    {
      buttonPressed = 5+i;
      LED_Enable(2,i+1);
    }
  }
  for (int i=0;i<=3;i++)
  {
    buttonState=digitalRead(row_3[i]);
    if(buttonState == HIGH)
    {
      buttonPressed = 9+i;
      LED_Enable(3,i+1);
    }
  }
  for (int i=0;i<=3;i++)
  {
    buttonState=digitalRead(row_4[i]);
    if(buttonState == HIGH)
    {
      buttonPressed = 13+i;
      LED_Enable(4,i+1);
    }
  }
  
  if (buttonPressed == 0)
  {
    digitalWrite(14, LOW);
    digitalWrite(15, LOW);
    digitalWrite(16, LOW);
    digitalWrite(17, LOW);
  }
  else
  {
    send_command(buttonPressed);
  }
}
