#include <ShiftRegister74595.h>
#include <examples/printPause.h>

/* Here we create an instance of a shift register that has a method to
 * clear the internal shift registers by applying a RESET on the internal
 * flip-flops, simultaneously. This assumes that the output is always
 * enabled, or that the output enable pin is fixed to ground.
 *
 * Hardware:
 *      - Pin 13 of the IC must be wired to ground.
 *      - We'll use the following connections
 *      Shift register      Arduino
 *      pin                 pin
 *      ==============      =======
 *      14 (serial)         6
 *      12 (storage clk)    4
 *      11 (shift clk)      3
 *      10 (serial clear)   2
 */

void setup() {
    Serial.begin(9600);
    Serial.print("ready\n\n");


    SR595::ShiftRegisterClear s1(6, 4, 3, 2);
    // verify that output pins are all initialized to zero/OFF
    printPauseMessage();

    /* we can change the ouptut, as usual */
    byte value = B00000101;
    s1.outputByte(value);
    // verify that output pins have now changed to
    // byte value, 1010 0000 (Q_H - Q_A)
    printPauseMessage();

    /* we can clear the internal shift registers */
    s1.clearShiftRegisters();
    // verify that output pins still have the previous value
    // of 1010 0000
    printPauseMessage();

    /* update latch to change output pins */
    s1.updateOutput();
    // verify that output pins are now all cleared/OFF
    printPauseMessage();

    /* but calling these result in compilation error */
    // s1.enableOutput();
    // s1.disableOutput();
}

void loop() {}
