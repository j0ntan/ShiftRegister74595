#include <ShiftRegister74595.h>
#include <examples/printPause.h>

/* Here we create an instance of a simple shift register. This assumes
 * that the output is always enabled and that the shift register clear
 * pin is never used. This is equivalent to setting the output enable
 * pin fixed to ground and the shift register clear pin fixed to Vcc.
 *
 * Hardware:
 *      - Pin 13 of the IC must be wired to ground, and pin 10 of the IC
 *        must be wired to Vcc.
 *      - We'll use the following connections
 *      Shift register      Arduino
 *      pin                 pin
 *      ==============      =======
 *      14 (serial)         6
 *      12 (storage clk)    4
 *      11 (shift clk)      3
 */

void setup() {
    Serial.begin(9600);
    Serial.print("ready\n\n");


    SR595::ShiftRegisterBase s1(6, 4, 3);
    // verify that output pins are all initialized to zero/OFF
    printPauseMessage();

    /* we can change the ouptut, as usual */
    byte value = B00000101;
    s1.outputByte(value);
    // verify that output pins have now changed to
    // byte value, 1010 0000 (Q_H - Q_A)
    printPauseMessage();

    /* but calling these result in compilation error */
    // s1.clearShiftRegisters();
    // s1.enableOutput();
    // s1.disableOutput();
}

void loop() {}
