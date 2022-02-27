/* Buttons to USB Keyboard Example

   You must select Keyboard from the "Tools > USB Type" menu

   This example code is in the public domain.
*/

#include <Bounce.h>

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button1 = Bounce(12, 10);  // 10 = 10 ms debounce time
Bounce button2 = Bounce(11, 10);  // which is appropriate for
Bounce button3 = Bounce(10, 10);  // most mechanical pushbuttons
Bounce button4 = Bounce(9, 10);
Bounce button5 = Bounce(8, 10);  // if a button is too "sensitive"
Bounce button6 = Bounce(7, 10);  // to rapid touch, you can
Bounce button7 = Bounce(6, 10);  // increase this time.
Bounce button8 = Bounce(5, 10);
Bounce button9 = Bounce(4, 10);
Bounce button10 = Bounce(3, 10);
Bounce button11 = Bounce(2, 10);
Bounce button12 = Bounce(1, 10);

void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.  LOW for "on", and HIGH for "off" may seem
  // backwards, but using the on-chip pullup resistors is very
  // convenient.  The scheme is called "active low", and it's
  // very commonly used in electronics... so much that the chip
  // has built-in pullup resistors!
  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);  // Teensy++ LED, may need 1k resistor pullup
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();
  button10.update();
  button11.update();
  button12.update();

  // Check each button for "falling" edge.
  // Type a message on the Keyboard when each button presses
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  // to low (pressed - button connects pin to ground)

  if (button1.fallingEdge()) {
 uint8_t tmp = USB0_CTL;
    USB0_CTL |= USB_CTL_RESUME;
    delay(12);
    USB0_CTL = tmp;
  }
  if (button2.fallingEdge()) {
    Keyboard.press(MODIFIERKEY_SHIFT);
    Keyboard.press(KEY_F7);
    Keyboard.release(MODIFIERKEY_SHIFT);
    Keyboard.release(KEY_F7);
  }
  if (button3.fallingEdge()) {
    Keyboard.press(MODIFIERKEY_SHIFT);
    Keyboard.press(KEY_F6);
    Keyboard.release(MODIFIERKEY_SHIFT);
    Keyboard.release(KEY_F6);
  }
  if (button4.fallingEdge()) {
    Keyboard.press(MODIFIERKEY_SHIFT);
    Keyboard.press(KEY_F3);
    Keyboard.release(MODIFIERKEY_SHIFT);
    Keyboard.release(KEY_F3);
  }
  if (button5.fallingEdge()) {
    Keyboard.press(KEY_SYSTEM_SLEEP);
    Keyboard.release(KEY_SYSTEM_SLEEP);
  }
  if (button6.fallingEdge()) {
    Keyboard.press(KEY_MEDIA_MUTE);
    Keyboard.release(KEY_MEDIA_MUTE);
  }
  if (button7.fallingEdge()) {
    Keyboard.press(MODIFIERKEY_SHIFT);
    Keyboard.press(KEY_F4);
    Keyboard.release(MODIFIERKEY_SHIFT);
    Keyboard.release(KEY_F4);
  }
  if (button8.fallingEdge()) {
    Keyboard.press(MODIFIERKEY_SHIFT);
    Keyboard.press(KEY_F5);
    Keyboard.release(MODIFIERKEY_SHIFT);
    Keyboard.release(KEY_F5);
  }
  if (button9.fallingEdge()) {
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
  }
  if (button10.fallingEdge()) {
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
  }
  if (button11.fallingEdge()) {
    Keyboard.press(MODIFIERKEY_SHIFT);
    Keyboard.press(KEY_F2);
    Keyboard.release(MODIFIERKEY_SHIFT);
    Keyboard.release(KEY_F2);
    
  }
  if (button12.fallingEdge()) {
    Keyboard.press(MODIFIERKEY_SHIFT);
    Keyboard.press(KEY_F1);
    Keyboard.release(MODIFIERKEY_SHIFT);
    Keyboard.release(KEY_F1);
  }

}
