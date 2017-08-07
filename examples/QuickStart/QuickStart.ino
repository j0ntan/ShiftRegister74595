#include <ShiftRegister74595.h>
#include <examples/printPause.h>

/* A simple way to output a byte value is shown. We create an instance
 * of the shift register class with a chosen set of Arduino pins. Then,
 * the output byte is passed to the shift register output pins.
 *
 * Hardware:
 *      - In this example, we'll use the following connections
 *      Shift register      Arduino
 *      pin                 pin
 *      ==============      =======
 *      14 (serial)         6
 *      13 (output          5
 *          enable)
 *      12 (storage clk)    4
 *      11 (shift clk)      3
 *      10 (serial clear)   2
 */

void setup() {
    Serial.begin(9600);
    Serial.print("ready\n\n");


    SR595::ShiftRegister s1(6, 4, 3, 5, 2);
    // verify that output pins are all initialized to zero/OFF
    printPauseMessage();

    byte outputValue = B10110010;
    s1.outputByte(outputValue);
    // verify that the shift register output pins Q_A - Q_H
    // follow the chosen byte value, 1011 0010
    printPauseMessage();
}

void loop() {}
