#include <ShiftRegister74595.h>
#include <examples/printPause.h>

/* The 74xx595 integrated circuit (IC) chip contains two memories,
 * a set of internal shift registers and a latch memory. The shift
 * functions allow us to store values to the internal shift registers.
 * We update the latch to bring those values to the output pins of the
 * IC. Both steps can be done in a single step with the output
 * functions.
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

    /* 2-step ouptut, STEP 1: shift data */
    byte value1 = B00000001;
    s1.shiftByte(value1);
    // verify that output pins are still all zero/OFF
    printPauseMessage();

    /* 2-step output, STEP 2: load unto output pins */
    s1.updateOutput();
    // verify that output pins have now changed to
    // byte value, 0000 0001 (Q_H - Q_A)
    printPauseMessage();

    /* Single-step output */
    byte value2 = B00000101;
    s1.shiftByte(value2);
    // verify that output pins have now changed to
    // byte value, 1010 0000
    printPauseMessage();
}

void loop() {}
