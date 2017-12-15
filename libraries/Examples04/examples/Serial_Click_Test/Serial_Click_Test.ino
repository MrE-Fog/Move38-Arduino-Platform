#include "blinklib.h"
#include "Serial.h"

// ClickTest with Serial print
// Blinks RED   for a single click
// Blinks GREEN for a double click
// Blinks BLUE  for a triple click

// More than 3 clicks will blink out the count in WHITE.

// Remember that holding the button down will abort any click in progress

ServicePortSerial Serial;

void setup() {

  // No setup needed for this simple example!  
  Serial.begin(); 

  Serial.println("Click Tester");  
}

void loop() {

  if (buttonSingleClicked()) {
    setColor( RED );    // Blink red for 1/20th of a second
    Serial.println("Button was just clicked once");
  } else if (buttonDoubleClicked()) {
    setColor( GREEN );    // Blink red for 1/20th of a second
    Serial.println("Button was just clicked twice");
  } else if (buttonMultiClicked()) {
    byte count=buttonClickCount();
    if (count==3) {     // Tripple click
      setColor( BLUE );    // Blink red for 1/20th of a second
      Serial.println("Button was just clicked three times");     
    } else {
      // If more than 3 clicks, then quickly blink out the click count in white
      Serial.print("Button was just clicked ");
      Serial.print(count);
      Serial.println(" times");
      while (count--) {
        setColor( WHITE );
        delay(100);
        setColor( OFF );
        delay(100);
      }
    }
  } else {
    return;              // No clicks detected. 
  }

  delay(100);       // Show the color long enough to see
  setColor(OFF);
      
}

