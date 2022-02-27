// Custom Macropad for your favourite apps

#include <BleKeyboard.h>

BleKeyboard bleKeyboard;
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2; // the number of the pushbutton pin
const int ledPin = 4;    // the number of the LED pin

// Variables will change:
int ledState = HIGH;       // the current state of the output pin
int buttonState;           // the current reading from the input pin
int lastButtonState = LOW; // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 10;   // the debounce time; increase if the output flickers

/*//primitives
  int x = 1;
  float y = 4.3;
  double z = 4.33;
  char c = 'c';

  char sc[] = {'H','e','l','l','o','w','o','r','l','d'};

  // object
  String s = "Hello World";

*/

class Button
{
    int key;
    int state;
    int lastState = LOW;

  public:
    int pin;

    Button(int _pin, int _key)
    {
      pin = _pin;
      key = _key;
    }

    void readSwitch()
    {
      int reading = digitalRead(pin);
      if (reading != lastState)
      {
        // reset the debouncing timer
        lastDebounceTime = millis();
      }

      if ((millis() - lastDebounceTime) > debounceDelay)
      {
        // whatever the reading is at, it's been there for lonHello world
        if (reading != state)
        {
          state = reading;

          // only toggle the LED if the new button state is HIGH
          if (state == HIGH)
          {
            ledState = !ledState;
            bleKeyboard.write(key);
            delay(250);
            bleKeyboard.releaseAll();
          }
        }
      }

      digitalWrite(ledPin, ledState);
      // save the reading. Next time through the loop, it'll be the lastButtonState:
      lastState = reading;
    }
};

class Keypad
{
    int numberOfButtons;
    Button buttons[];

  public:
    Keypad(Button _buttons[])
    {
      numberOfButtons = sizeof(_buttons) / sizeof(_buttons[0]);

      for (int i = 0; i < numberOfButtons; i++)
      {
        buttons[i] = _buttons[i];
      }
    }

    void setInput()
    {
      for (int i = 0; i < numberOfButtons; i++)
      {
        pinMode(buttons[i].pin, INPUT);
      }
    }

    void updateInputs() {
      for (int i = 0; i < numberOfButtons; i++)
      {
        buttons[i].readSwitch();
      }
    }
};

Button minecraft(0, KEY_F1);
Button inventor(12, KEY_F2);
Button cura(13, KEY_F3);
Button discord(14, KEY_F4);
Button epicgames(15, KEY_F5);
Button github(32, KEY_F6);
Button unity(33, KEY_F7);
Button steam(27, KEY_F8);
Button chrome(34, KEY_F9);
Button youtube(35, KEY_F10);
Button Vup(36, KEY_F11);
Button Vdown(39, KEY_F11);

// Don't Use: 2, 4, 25, 26,
// Use: 0, 12, 13, 14, 15, 32, 33, 27, 34, 35, 36, 39

Button buttonArray[] = {minecraft};

//, inventor, cura, discord, epicgames, github, unity, steam, chrome, youtube

Keypad macropad(buttonArray);

//Button inventor(3, KEY_F2);

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  macropad.setInput();
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
  bleKeyboard.begin();
}

void loop()
{
  if (bleKeyboard.isConnected())
  {
    macropad.updateInputs();
  }
}
