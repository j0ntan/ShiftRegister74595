#include <ShiftRegister74595.h>
#include <examples/printPause.h>

/* Here we create an instance of a shift register that can enable or
 * disable the output pins, for a tri-state shift register. When the
 * ouptut is enabled, the output pins take on the value that was
 * previously stored within the latch memory of the chip. By default,
 * the output state is enabled on initilization. When the output is
 * disabled, the output pins go into a state of high impedance. We
 * assume that the shift register clear pin is never used, or that
 * the pin is fixed to Vcc.
 *
 * Hardware:
 *      - Pin 10 of the IC must be wired to Vcc.
 *      - We'll use the following connections
 *      Shift register      Arduino
 *      pin                 pin
 *      ==============      =======
 *      14 (serial)         6
 *      13 (output          5
 *          enable)
 *      12 (storage clk)    4
 *      11 (shift clk)      3
 */

void setup() {
    Serial.begin(9600);
    Serial.print("ready\n\n");


    SR595::ShiftRegisterEnable s1(6, 4, 3, 5);
    // verify that output pins are enabled and  initialized to zero/OFF
    printPauseMessage();

    /* we can change the ouptut, as usual */
    byte value = B00000101;
    s1.outputByte(value);
    // verify that output pins have now changed to
    // byte value, 1010 0000 (Q_H - Q_A)
    printPauseMessage();

    /* we can disable the output */
    s1.disableOutput();
    // verify that output pins are in high impedance state
    printPauseMessage();

    /* while disabled, we can modify internal shift registers */
    s1.shiftByte(B10010110);
    // verify that output pins are STILL in high impedance state
    printPauseMessage();

    /* re-enable output, we expect same values as before, taken from latch memory */
    s1.enableOutput();
    // verify that output pins still have previous values
    // of 1010 0000
    printPauseMessage();

    /* update latch and output values that were loaded while disabled */
    s1.updateOutput();
    // verify that output pins have now changed to 0110 1001
    printPauseMessage();

    /* but calling this results in compilation error */
    // s1.clearShiftRegisters();
}

void loop() {}
