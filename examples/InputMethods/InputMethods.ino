#include <ShiftRegister74595.h>
#include <examples/printPause.h>

/* This example demonstrates all of the ways we can load data into the
 * shift register. For simplicity, we use a barebones shift register.
 * Only the "output-" methods are used. The "shift-" methods can be
 * used to load an input stream, followed by a call to 'updateOutput()'
 * function to change ouptut pin values.
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

    /* shift a single logic HIGH bit unto the registers */
    SR595::BIT highBit = SR595::BIT::HI;
    s1.outputBit(highBit);
    // verify that output Q_A is HIGH
    printPauseMessage();

    /* now shift by a single logic LOW bit */
    s1.outputBit(SR595::BIT::LO);
    // verify that output Q_B is HIGH & Q_A is LOW
    printPauseMessage();

    /* output N number of bits from given byte */
    byte halfByte = B00001010;
    s1.outputNBits(halfByte, 4);
    // verify that the output is now 1010 0000 (Q_H - Q_A)
    printPauseMessage();

    /* output 8 bits, or 1 byte */
    s1.outputByte(B11010010);
    // verify that the output is now 0100 1011
    printPauseMessage();

    /* Turn ON all registers */
    s1.outputAllOn();
    // verify that all outputs are HIGH
    printPauseMessage();

    /* Turn OFF all registers */
    s1.outputAllOff();
    // verify that all outputs are LOW
    printPauseMessage();
}

void loop() {}
